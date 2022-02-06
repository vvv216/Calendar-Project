#include "login.h"

/**
 * @authors Dazhuang Teng and Qingwen Xu
 * @brief Login::Login
 * @param parent pointer of parent window
 * @note constructor function
 */
Login::Login(QWidget *parent) : QWidget(parent)
{
    setFixedSize(500, 350);
    setWindowTitle("LoginUI");
    signupUI = new signUp(this);
    success = new MainWindow();

    //user name
    loginUser = new QLabel;
    loginUser->setText("Username:");
    inputUser = new QLineEdit;

    //passward
    loginPassword = new QLabel;
    loginPassword->setText("Password:");
    inputPassword = new QLineEdit;
    inputPassword->setEchoMode(QLineEdit::EchoMode::Password);

    //init all session
    login = new QPushButton(this);
    login->setText("log in");
    //pSignIn->setGeometry(160, 185, 75, 35);
    connect(login, &QPushButton::clicked, this, &Login::logInSucess);

    signup = new QPushButton(this);
    signup->setText("New user? Sign up here!");
    connect(signup, &QPushButton::clicked, this, &Login::newUser);

    //layout
    loginLayout = new QGridLayout;
    loginLayout->addWidget(loginUser, 0, 0);
    loginLayout->addWidget(inputUser, 0, 1);

    loginLayout->addWidget(loginPassword, 1, 0);
    loginLayout->addWidget(inputPassword, 1, 1);

    loginLayout->addWidget(login, 2, 0, 1, 2);
    loginLayout->addWidget(signup, 3, 0, 1, 2);

    setLayout(loginLayout);
}

/**
 * @authors Dazhuang Teng and Qingwen Xu
 * @brief Login::newUser
 * @note display the sign up window
 */
void Login::newUser(){
    inputUser->clear();
    inputPassword->clear();
    this->hide();
    signupUI->show();
}


/**
 * @authors Dazhuang Teng and Qingwen Xu
 * @brief Login::logInSucess
 * @note read the userdatabse file and check the login info
 */
void Login::logInSucess()
{
    QFile file("userDatabase.txt");
    if (!file.open(QIODevice::ReadWrite)) {
        QMessageBox::warning(this, "Warning!", "File open failed!");
        return;
    }

    QTextStream stream(&file);
    QString str = stream.readAll();
    file.close();

    QString user;
    if(inputUser->text().toStdString()!=""){
        user.append(QString("(^|\\b)"));
        user.append(inputUser->text());
        user.append(QString(","));
    }else{
        QMessageBox::warning(this, "Warning!", "Empty username!");
        return;
    }

    if (str.indexOf(QRegularExpression(user)) == -1) {
        QMessageBox::warning(this, "Warning!", "No such account!");
        return;
    }

    if(inputPassword->text().toStdString()!=""){
        user.append(inputPassword->text());
        user.append(QString("($|\\b)"));
    }else{
        QMessageBox::warning(this, "Warning!", "Empty passward!");
        return;
    }

    qDebug() << user;
    if (str.indexOf(QRegularExpression(user)) != -1) {
        this->hide();
        success->show();
    } else {
        QMessageBox::warning(this, "Warning!", "Incorrect password!");
        return;
    }

}

/**
 * @authors Dazhuang Teng and Qingwen Xu
 * @brief Login::~Login
 * @note descontructor function
 */
Login::~Login(){

}
