#include "signUp.h"
/**
 * @brief signUp::signUp
 * @author Dazhuang Teng,Qingwen Xu
 * @param login
 * @param parent
 * @note construcor function
 */
signUp::signUp(Login *login, QWidget *parent) : QWidget(parent)
{
    loginUI = login;
    setFixedSize(500, 350);
    setWindowTitle("signUp UI");

    //username input
    signuplUser = new QLabel;
    signuplUser->setText("Enter a Username:");
    inputUser = new QLineEdit;

    //first password input
    signupPassword1 = new QLabel;
    signupPassword1->setText("Enter a Password:");
    inputPassword1 = new QLineEdit;
    inputPassword1->setEchoMode(QLineEdit::EchoMode::Password);

    //verify the password
    signupPassword2 = new QLabel;
    signupPassword2->setText("Repeat Password:");
    inputPassword2 = new QLineEdit;
    inputPassword2->setEchoMode(QLineEdit::EchoMode::Password);

    //signin button
    signupButton = new QPushButton;
    signupButton->setText("Register");
    connect (signupButton, &QPushButton::clicked, this, &signUp::signUpsuccess);

    //layout
    signupLayout = new QGridLayout;
    signupLayout->addWidget(signuplUser, 0, 0);
    signupLayout->addWidget(inputUser, 0, 1);

    signupLayout->addWidget(signupPassword1, 1, 0);
    signupLayout->addWidget(inputPassword1, 1, 1);

    signupLayout->addWidget(signupPassword2, 2, 0);
    signupLayout->addWidget(inputPassword2, 2, 1);

    signupLayout->addWidget(signupButton, 3, 0, 1, 2);

    setLayout(signupLayout);
}

/**
 * @brief signUp::closeEvent
 * @note go back to login window after close
 * @author Dazhuang Teng, Qingwen Xu
 */
void signUp::closeEvent(QCloseEvent */*event*/)
{
    loginUI->show();
}

/**
 * @brief signUp::signUpsuccess
 * @note set signup condtion and save the accont info into database
 * @author Dazhuang Teng,Qingwen Xu
 */
void signUp::signUpsuccess()
{
    // user name and password length requirement
    if (inputUser->text().length() > 20) {
        QMessageBox::warning(this, "Warning!", "User name length greater than 20!");
        return;
    }
    if (inputPassword1->text().length() > 20) {
        QMessageBox::warning(this, "Warning!", "Password length greater than 20!");
        return;
    }
    if (inputPassword2->text().length() > 20) {
        QMessageBox::warning(this, "Warning!", "Duplicate password length greater than 20!");
        return;
    }


    //warning if two password dont match
    if (inputPassword1->text() != inputPassword2->text()) {
        QMessageBox::warning(this, "Warning!", "The two input passwords do not match!");
        return;
    }

    // create and open the txt database
    QFile file("userDatabase.txt");
    if (!file.open(QIODevice::ReadWrite)) {
        QMessageBox::warning(this, "Warning!", "File open failed!");
        return;
    }

    QTextStream stream(&file);
    QString str = stream.readAll();

    //warning if the user name existed
    QString user;
    if(inputUser->text().toStdString() !=""){
        user.append(QString("(^|\\b)"));
        user.append(inputUser->text());
        user.append(QString(","));
    }else{
        QMessageBox::warning(this, "Warning!", "No username input!");
        return;
    }

    if (str.indexOf(QRegularExpression(user)) != -1) {
        file.close();
        QMessageBox::warning(this, "Warning!", "This Username already exists!");
        return;
    }

    //write the word into database
    if(inputPassword1->text().toStdString()!=""){
        stream << inputUser->text() << "," << inputPassword1->text() << Qt::endl;
    }else{
        QMessageBox::warning(this, "Warning!", "No passward input!");
        return;
    }

    file.close();
    QMessageBox::information(this, "Information!", "User registration succeeded!", QMessageBox::Yes, QMessageBox::Yes);
    inputUser->clear();
    inputPassword1->clear();
    inputPassword2->clear();
    loginUI->show();
    close();
}

/**
 * @brief signUp::~signUp
 * @author Dazhuang Teng, Qingwen Xu
 * @note Deconstructor
 */
signUp::~signUp(){

}
