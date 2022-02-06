#include "taskitem.h"
#include "QDebug"

/**
 @brief The class is to set up default name and date
 @author Jiawei Li, Han Gao
 @param QString name, QDate date
 */
taskitem::taskitem(QString name, QDate date)
{
    this->name = name;
    this->date = date;
}

/**
 @brief The class is to get the format of input event
 @author Jiawei Li, Han Gao
 @return return the format of event which input by the user
 */

QString taskitem::getItemString()
{
    return QString::number(date.day()) + ":" + QString::number(date.month()) + ":" +  QString::number(date.year()) + ":" + " " + name;
}


/**
 @brief The class is to remove the shown of event line which previously stored by the user
 @author Jiawei Li, Han Gao
 @param QString line
 */
taskitem::taskitem(QString line)
{
    int el[3];
    int iter = 0;

    bool ok;
    for(int i = 0;i<3;i++)
    {
        el[i] = line.mid(iter,line.indexOf(":",iter) - iter).toInt(&ok);
        iter = line.indexOf(":",iter) + 1;
    }

    if(!ok)
    {
        qDebug()<<"error toInt setItemString";

    }
    else
    {
        date.setDate(el[2],el[1],el[0]);
        name = line.mid(iter + 1, line.length() - iter);

    }
}


/**
 @brief The class is to get the date of event
 @author Jiawei Li, Han Gao
 @return return the date
 */
QDate taskitem::getDate()
{
    return  date;
}
