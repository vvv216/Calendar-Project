#ifndef WEATHERDISPLAY_H
#define WEATHERDISPLAY_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include <QGroupBox>
#include <QCloseEvent>
#include <weatherinfo.h>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QFile>
#include <QtDebug>
#include <QMessageBox>
#include <QCoreApplication>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QStringConverter>

class WeatherDisPlay : public QMainWindow
{
    Q_OBJECT

public:
    WeatherDisPlay(QWidget *parent = nullptr);
    ~WeatherDisPlay();
    void initUI();
    void getMsgFromFile(QString, QString);
    void parseAndSetUIinfo(QByteArray);

private slots:
    void onSearchBtnClicked();
private:
    QPushButton *searchBtn = nullptr;
    QComboBox *countryCom = nullptr;
    QComboBox *cityCom = nullptr;
    QGroupBox *resGBox = nullptr;
    QWidget *widget = nullptr;
    QLabel *weatherLabel = nullptr;
    QLabel *temperateLabel = nullptr;
    QStringList countryList;
    QMap<QString, QStringList> country_city_map;
    QMap<QString, QString> city_code_map;
    QString weather_url = "";
    QString apikey = "";
    weatherInfo info;
};
#endif // WEATHERDISPLAY_H
