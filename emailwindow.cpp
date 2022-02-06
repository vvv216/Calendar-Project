//Email Service Window
//Vivian Liang
//2021-11-26

#include "emailwindow.h"
#include "ui_emailwindow.h"

EmailWindow::EmailWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EmailWindow)
{
    //connect to the Email Window UI button
    ui->setupUi(this);
    connect(ui->sendButton, SIGNAL(clicked()),this, SLOT(sendMail()));
    connect(ui->exitButton, SIGNAL(clicked()),this, SLOT(close()));
    connect(ui->AttachmentButton, SIGNAL(clicked()), this, SLOT(Attachment()));
}


void EmailWindow::sendMail()
{
    //set the sender address, password, server and port
    const char* sender = "vvivianliang@gmail.com";
    const char* pswd = "UWO250994979";
    const char* server = "smtp.gmail.com";
    int port = 465;
    
    //connect the information to the smtp
    Smtp* smtp = new Smtp(sender, pswd, server, port);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    //send the email information to the smtp
    smtp->sendMail( ui->rcpt->text(),ui->subject->text(),ui->msg->toPlainText(),files);
}

void EmailWindow::Attachment()
{
    //QFileDialog enables to select files or directory.
    QFileDialog dialog(this);
    
    //the user must select an existing file or Directory
    dialog.setFileMode(QFileDialog::ExistingFile);
    
    //search the file from the user's home directory
    dialog.setDirectory(QDir::homePath());
    
    //Each file in the current directory can be selected using seletedFiles()
    if (dialog.exec()){
        files = dialog.selectedFiles();
    }
    
    //put the attachment name into a text box
    QString fileList;
    QListIterator<QString> i(files);
    while (i.hasNext()){
        //QFileInfo provides information about a file's name and path
        fileList.append( "\"" + QFileInfo(i.next()).fileName() + "\" " );
    }
    ui->fileName->setText(fileList);
}

void EmailWindow::mailSent(QString status)
{
    //if the email sent successfully
    //a pop-up window will notify the users
    if(status == "Email sent"){
        QMessageBox::warning(this, tr("Notification"), tr("Email sent!\n\n"), QMessageBox::Close);
    }
        //clear all the data in the email window
        this->ui->rcpt->clear();
        this->ui->subject->clear();
        this->ui->msg->clear();
        this->ui->fileName->clear();
        files.clear();
}

EmailWindow::~EmailWindow()
{
    delete ui;
}
