#include "weatherinfo.h"
/**
 * @authors Dazhuang Teng and Qingwen Xu
 * @brief weatherInfo::weatherInfo
 * @param parent  pointer of base class
 */
weatherInfo::weatherInfo(QObject *parent) : QObject(parent)
{

}

/**
 * @authors Dazhuang Teng and Qingwen Xu
 * @brief weatherInfo::receiveData
 * @param url the url for get request
 * @return result of the request
 */
QByteArray weatherInfo::receiveData(const QString &url)
{
    assert(!url.isEmpty());
    QUrl qUrl = QUrl::fromUserInput(url);
    QNetworkAccessManager manager;
    QNetworkRequest request;
    request.setUrl(qUrl);

    QNetworkReply *reply = manager.get(request);

    //wait until the api reply to do the next step
    QEventLoop eventloop;
    QObject::connect(reply, &QNetworkReply::finished, &eventloop, &QEventLoop::quit);
    eventloop.exec(QEventLoop::ExcludeUserInputEvents);

    QString temp = reply->readAll();
    auto fromUtf16 = QStringEncoder(QStringEncoder::Utf8);

    QByteArray result = fromUtf16(temp);

    return result;
}
