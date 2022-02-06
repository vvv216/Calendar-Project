#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QPushButton>
#include <QRegularExpression>
#include <QApplication>
#include "mainwindow.h"
#include "signUp.h"

class signUp;

class Login : public QWidget
{
    Q_OBJECT
public:
    explicit Login(QWidget *parent = Q_NULLPTR);
    ~Login();

private:
    void logInSucess();
    void newUser();
    
private:
    //layout
    QGridLayout *loginLayout;

    //username
    QLabel *loginUser;
    QLineEdit *inputUser;

    //passw0rd
    QLabel *loginPassword;
    QLineEdit *inputPassword;

    //go to sign up
    QPushButton *login;                     //login
    QPushButton *signup;                //signup

    //mainwindow
    MainWindow *success;
    signUp *signupUI;
};

#endif // LOGIN_H
