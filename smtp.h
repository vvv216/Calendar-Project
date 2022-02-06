//Email Service
//Vivian Liang
//2021-11-26

#ifndef SMTP_H
#define SMTP_H

#include <QtNetwork>
#include <QAbstractSocket>
#include <QSslSocket>
#include <QString>
#include <QTextStream>
#include <QDebug>
#include <QtWidgets>
#include <QMessageBox>
#include <QByteArray>

class Smtp : public QObject
{
    Q_OBJECT

public:
    Smtp(const QString &user, const QString &pass, const QString &server, int port );
    ~Smtp();

    void sendMail(const QString &to, const QString &subject, const QString &body, QStringList files = QStringList());

signals:
    void status( const QString &);

private slots:
    void readyRead();

private:
    enum states{Ssl,Init,HandShake,Auth,User,Pass,Rcpt,Mail,Data,Body,Quit,Close};
    QString from;
    QString rcpt;
    QString response;
    QString user;
    QString pass;
    QString server;
    int port;
    int state;
    QString message;
    QTextStream *text;
    QSslSocket *socket;
};

#endif
