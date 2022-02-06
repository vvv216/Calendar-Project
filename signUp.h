#ifndef SIGNUP_H
#define SIGNUP_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QRegularExpression>
#include <QDebug>
#include "login.h"

class Login;

class signUp : public QWidget
{
    Q_OBJECT

public:
    explicit signUp(Login *login = Q_NULLPTR, QWidget *parent = Q_NULLPTR);
    ~signUp();

private:
    void signUpsuccess();
    void closeEvent(QCloseEvent *event);

private:
    //layout
    QGridLayout *signupLayout;

    //username
    QLabel *signuplUser;
    QLineEdit *inputUser;

    //passward
    QLabel *signupPassword1;
    QLineEdit *inputPassword1;

    //verifypassword
    QLabel *signupPassword2;
    QLineEdit *inputPassword2;

    //signup button
    QPushButton *signupButton;

    Login *loginUI;
};

#endif // SIGNUP_H
