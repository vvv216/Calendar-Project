#include "weatherDisplay.h"
/**
 * @authors Dazhuang Teng and Qingwen Xu
 * @brief WeatherDisPlay::WeatherDisPlay
 * @note  constructor function
 * @param parent pointer of parent window
 */
WeatherDisPlay::WeatherDisPlay(QWidget *parent)
    : QMainWindow(parent)
{
    initUI();
    connect(searchBtn, &QPushButton::clicked, this, &WeatherDisPlay::onSearchBtnClicked);
}

/**
 * @authors Dazhuang Teng and Qingwen Xu
 * @brief WeatherDisPlay::~WeatherDisPlay
 * @note descontructor function
 */
WeatherDisPlay::~WeatherDisPlay()
{
}

/**
 * @authors Dazhuang Teng and Qingwen Xu
 * @brief WeatherDisPlay::initUI
 * @note  construct the ui
 */
void WeatherDisPlay::initUI()
{
    this->setFixedSize(QSize(400, 150));
    widget = new QWidget();

    // button
    searchBtn = new QPushButton(this);
    searchBtn->setText("search");

    // groupbox
    resGBox = new QGroupBox(this);
    resGBox->setTitle("today weather");

    // result label
    weatherLabel = new QLabel(this);
    weatherLabel->setText("weather: ---");

    temperateLabel = new QLabel(this);
    temperateLabel->setText("temperature: ---");

    QHBoxLayout *labelHbox = new QHBoxLayout();
    labelHbox->addStretch(0);
    labelHbox->addWidget(weatherLabel);
    labelHbox->addStretch(0);
    labelHbox->addWidget(temperateLabel);
    labelHbox->addStretch(0);
    resGBox->setLayout(labelHbox);

    QString basePath = QCoreApplication::applicationDirPath();
    qDebug()<<"file path: " + basePath;
    getMsgFromFile(basePath + "/city.json", basePath + "/config.json");

    countryCom = new QComboBox(this);
    countryCom->addItems(countryList);
    countryCom->setEditable(false);

    cityCom = new QComboBox(this);
    QStringList cityList = country_city_map.find(countryCom->currentText()).value();

    if(cityList.length()==0)
    {
        cityCom->addItem("no city");
        cityCom->setEnabled(false);
    }else {
        cityCom->addItems(cityList);
    }


    // bilid final layout
    QHBoxLayout *hLayout = new QHBoxLayout();
    hLayout->addWidget(countryCom);
    hLayout->addSpacing(10);
    hLayout->addWidget(cityCom);
    hLayout->addSpacing(20);
    hLayout->addWidget(searchBtn);

    QVBoxLayout *finalLayout = new QVBoxLayout();
    finalLayout->addItem(hLayout);
    finalLayout->addWidget(resGBox);

    widget->setLayout(finalLayout);
    this->setCentralWidget(widget);

}

/**
 * @authors Dazhuang Teng and Qingwen Xu
 * @brief WeatherDisPlay::getMsgFromFile
 * @note  get country and city info from json file
 * @param pathCity  city data path
 * @param pathConfig  other config path
 */
void WeatherDisPlay::getMsgFromFile(QString pathCity, QString pathConfig)
{
    QFile loadCityInfo(pathCity);

    if(!loadCityInfo.open(QIODevice::ReadOnly))
    {
        qDebug() << "could't open projects json";
        return;
    }

    QByteArray allData = loadCityInfo.readAll();
    loadCityInfo.close();

    qDebug()<<"file data: " + allData;

    // parse json
    QJsonParseError err_rpt;
    QJsonDocument  root_Doc = QJsonDocument::fromJson(allData, &err_rpt);

    if(err_rpt.error != QJsonParseError::NoError)
    {
        qDebug() << "json parse error";
        return;
    }

    QJsonObject root_obj = root_Doc.object();
    // init countriy
    countryList =  root_obj.keys();

    // init map countiy->citylist
    for(int i = 0; i< countryList.length(); i++)
    {
        QString tempCountry = countryList.at(i);
        QJsonValue tempCityJson = root_obj.value(tempCountry);

        QJsonObject city_json_obj = tempCityJson.toObject();

        // now country's city list
        QStringList cityList = city_json_obj.keys();
        country_city_map.insert(tempCountry, cityList);

        // init city map
        for(int j = 0; j< cityList.length(); j++)
        {
            QString tempCity = cityList.at(j);
            QString cityCode = city_json_obj.value(tempCity).toString();
            city_code_map.insert(tempCity, cityCode);
        }
    }

    // read request url and appkey info
    QFile loadConfig(pathConfig);

    if(!loadConfig.open(QIODevice::ReadOnly))
    {
        qDebug() << "could't open config json";
        return;
    }

    QByteArray allConfigData = loadConfig.readAll();
    loadConfig.close();

    // parse json
    QJsonParseError err_rpt1;
    QJsonDocument  root_Doc1 = QJsonDocument::fromJson(allConfigData, &err_rpt1);

    if(err_rpt1.error != QJsonParseError::NoError)
    {
        qDebug() << "json parse error";
        return;
    }

    QJsonObject root_obj1 = root_Doc1.object();

    weather_url = root_obj1.value("baseurl").toString();

    apikey = root_obj1.value("apikey").toString();
}

/**
 * @authors Dazhuang Teng and Qingwen Xu
 * @brief WeatherDisPlay::parseAndSetUIinfo
 * @note  parse the result request by api
 * @param weainfo the result request by api
 */
void WeatherDisPlay::parseAndSetUIinfo(QByteArray weainfo)
{
    QJsonParseError err_rpt;
    QJsonDocument  root_Doc = QJsonDocument::fromJson(weainfo, &err_rpt);

    if(err_rpt.error != QJsonParseError::NoError)
    {
        qDebug() << "json parse error";
        return;
    }

    QJsonObject root_obj = root_Doc.object();

    QString code = root_obj.value("code").toString();
    if("200" != code)
    {
        QMessageBox msgBox;
        msgBox.warning(this, "info", "search weather info failed");
        return;
    }

    QJsonObject weaDeatilinfo = root_obj.value("now").toObject();

    QString text = weaDeatilinfo.value("text").toString();

    QString temp = weaDeatilinfo.value("temp").toString();

    // update ui info
    weatherLabel->setText("weather: " + text);
    temperateLabel->setText("temperature: " + temp + "°C");
}

/**
 * @authors Dazhuang Teng and Qingwen Xu
 * @brief WeatherDisPlay::onSearchBtnClicked
 * @note  the slot function of the search button
 */
void WeatherDisPlay::onSearchBtnClicked()
{
    QString currentCity = cityCom->currentText();
    QString cityCode = city_code_map.find(currentCity).value();

    // request weather result
    QString urlTemp = weather_url+"?location=%1&key=%2&lang=en";
    QString url = urlTemp.arg(cityCode, apikey);
    qDebug()<<url;

    // do request
    QByteArray result = info.receiveData(url);
    qDebug()<< "result: " + result;

    if("" == result)
    {
        QMessageBox msgBox;
        msgBox.warning(this, "warn", "search failed, maybe openssl error");
        return;
    }
    parseAndSetUIinfo(result);

}

