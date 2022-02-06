//Email Service
//Vivian Liang
//2021-11-26

#ifndef EMAILWINDOW_H
#define EMAILWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QMessageBox>
#include <QFileDialog>
#include "smtp.h"


namespace Ui {
class EmailWindow;
}

class EmailWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit EmailWindow(QWidget *parent = 0);
    ~EmailWindow();

private slots:
    void sendMail();
    void Attachment();
    void mailSent(QString);

    
private:
    QStringList files;
    Ui::EmailWindow *ui;
};

#endif // EMAILWINDOW_H
