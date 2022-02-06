#ifndef WEATHERINFO_H
#define WEATHERINFO_H

#include <QObject>
#include <QUrl>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include<QEventLoop>
class weatherInfo : public QObject
{
    Q_OBJECT

public:
    explicit weatherInfo(QObject *parent = nullptr);
    QByteArray receiveData(const QString &url);
};

#endif // WEATHERINFO_H
