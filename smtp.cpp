//Email Service
//Vivian Liang
//2021-11-26

#include "smtp.h"

Smtp::Smtp(const QString &user, const QString &pass, const QString &server, int port)
{
    socket = new QSslSocket(this);

    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));

    this->user = user;
    this->pass = pass;
    this->server = server;
    this->port = port;
}

void Smtp::sendMail(const QString &to, const QString &subject, const QString &body, QStringList files)
{
    
    //the format of an email
    //including sender, recipient address and subject
    message = "To: " + to + "\n";
    message.append("From: CS3307 Group48 \n");
    message.append("Subject: " + subject + "\n");
    
    //cutting boundary between email body text and the attachment file
    //seperate email text body and attachment file
    message.append("MIME-Version: 1.0\n");
    message.append("Content-Type: multipart/mixed; boundary=frontier\n\n");
    message.append( "--frontier\n" );
    message.append( "Content-Type: text/plain\n\n" );
    message.append(body);
    message.append("\n\n");
    
    //set up for adding the attachment files in the email
    if(!files.isEmpty())
    {
        QListIterator<QString> i(files);
        while (i.hasNext())
        {
            //initiate the file and its corresponding path
            QFile file(i.next());
            
            //The attachment file is open for reading in the email
            file.open(QIODevice::ReadOnly);
            
            //convert the file content into bytes
            //the original file becomes a binary files
            QByteArray bytes = file.readAll();
            
            //add the seleted file name to the line text box
            //MIME attachment in binary bytes
            //because smtp using base 64 to encrypt the information
            message.append("--frontier\n" );
            message.append("Content-Type: application/octet-stream\nContent-Disposition: attachment; filename="+ QFileInfo(file.fileName()).fileName() +";\nContent-Transfer-Encoding: base64\n\n");
            //decode the content
            message.append(bytes.toBase64());
            message.append("\n");
            }
        }

    message.append("--frontier--\n");
    message.replace(QString::fromLatin1("\n"), QString::fromLatin1("\r\n"));
    message.replace( QString::fromLatin1("\r\n.\r\n"),QString::fromLatin1("\r\n..\r\n" ));
    
    rcpt = to;
    state = Init;
    
    //connect to the email server and its port
    socket->connectToHostEncrypted(server, port);
    
    //streaming operators to generate text
    text = new QTextStream(socket);
}

//destructor
Smtp::~Smtp()
{
    delete text;
    delete socket;
}

//read the smtp command
void Smtp::readyRead()
{
    QString responseCode;
    responseCode = socket->readLine();
    while (socket->canReadLine() && responseCode[3] != ' ')
    {
        responseCode = socket->readLine();
    }

    //Truncates the response code at the first 3 position
    responseCode.truncate(3);

    //initiate conversation with the SMTP server
    //After receives the 220, the handshaking starts.
    if (state == Init && responseCode == "220")
    {
        //Send EHLO to smtp
        //SMTP server identify client with corresponding information
        *text << "EHLO localhost" <<"\r\n";
        
        //hanshaking stage
        //the server can identify themselves the services they can provide
        //identify the identities of the sender and the recipient of the email.
        state = HandShake;
    }

    //the first digit of the response code
    //2: The requested action has been successfully completed.
    //3: The command accepted, but the requested more information and action
    //4: The command was not accepted, but the error condition is temporary
    //5: The command was not accepted and SMTP client SHOULD NOT repeat the request
    
    //The second digit of the response code
    //0: syntax errors of the command
    //1: requests for information
    //2: referring to the transmission channel
    //5: indicate the status of the receiver mail system
    else if (state == HandShake && responseCode == "250")
    {
        socket->startClientEncryption();
        *text << "EHLO localhost" << "\r\n";
        state = Auth;
    }
    else if (state == Auth && responseCode == "250")
    {
        //authenticate the client to the server
        //sends the clients username and password to the e-mail server
        //server asks for information by sending BASE64 encoded text to the client
        *text << "AUTH LOGIN" << "\r\n";
        state = User;
    }
    else if (state == User && responseCode == "334")
    {
        //request the input for sender username
        //transfer the sender username into base64 format
        *text << QByteArray().append(user.toStdString()).toBase64()  << "\r\n";
        state = Pass;
    }
    else if (state == Pass && responseCode == "334")
    {
        //request the input for sender password
        //transfer the sender password into base64 format
        *text << QByteArray().append(pass.toStdString()).toBase64() << "\r\n";
        state = Mail;
    }
    else if (state == Mail && responseCode == "235")
    {
        //Specifies the e-mail address of the sender
        *text << "MAIL FROM:<" << from << ">\r\n";
        state = Rcpt;
    }
    else if (state == Rcpt && responseCode == "250")
    {
        //Specifies the e-mail address of the recipient
        *text << "RCPT TO:<" << rcpt << ">\r\n"; 
        state = Data;
    }
    else if (state == Data && responseCode == "250")
    {
        //client request to transfer the email body part
        *text << "DATA\r\n";
        state = Body;
    }
    else if (state == Body && responseCode == "354")
    {
        //request to input the email body
        *text << message << "\r\n.\r\n";
        state = Quit;
    }
    else if (state == Quit && responseCode == "250")
    {
        //if the email sent successfully
        //Asks the server to close the connection
        *text << "QUIT\r\n";
        emit status(tr( "Email sent" ));
        state = Close;
    }
    else if(state == Close)
    {
        return;
    }
    else
    {
        //if the email sent failed
        emit status(tr( "Email Sent Failed" ));
        state = Close;
    }
    //Flushes any buffered data
    text->flush();
}
