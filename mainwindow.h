#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Ui_MainWindow.h"
#include "taskitem.h"
#include "QTextCharFormat"
#include <QMainWindow>
#include "QFileDialog"
#include "QMessageBox"
#include "QInputDialog"
#include "QGroupBox"
#include "QComboBox"
#include "QCheckBox"
#include "QDateEdit"
#include "weatherDisplay.h"
#include "emailwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_calendarWidget_clicked();

    void printTasks(bool ignore);

    void sort();

    void clearAll();

    void on_open_triggered();

    void on_create_triggered();

    void on_info_triggered();

    void on_addEvent_clicked();

    void on_deleteEvent_clicked();

    void on_spinBox_textChanged();

    void on_saveHow_triggered();

    void on_weather_clicked();

    void on_email_clicked();

private:
    void localeChanged(int index);
    void firstDayChanged(int index);
    void selectionModeChanged(int index);
    void horizontalHeaderChanged(int index);
    void verticalHeaderChanged(int index);
    void selectedDateChanged();
    void minimumDateChanged(QDate date);
    void maximumDateChanged(QDate date);
    void weekdayFormatChanged();
    void weekendFormatChanged();
    void reformatHeaders();
    void reformatCalendarPage();
    Ui::MainWindow *ui;

    QDate date;

    int pages = 0;
    QString name = "";
    QString today = "";
    bool saved = true;

    QString nameOfFile = "";

    QTextCharFormat colorSelected, colorUnSelected, colorHighlight;

    QList<taskitem>::iterator iterList;
    QList<taskitem> tasks;

    bool change = false;

    QGroupBox *generalOptionsGroupBox;
    QLabel *localeLabel;
    QLabel *firstDayLabel;
    QComboBox *localeCombo;
    QComboBox *firstDayCombo;
    QComboBox *selectionModeCombo;
    QLabel *selectionModeLabel;
    QCheckBox *gridCheckBox;
    QCheckBox *navigationCheckBox;
    QComboBox *horizontalHeaderCombo;
    QLabel *horizontalHeaderLabel;
    QComboBox *verticalHeaderCombo;
    QLabel *verticalHeaderLabel;

    QGroupBox *datesGroupBox;
    QDateEdit *minimumDateEdit;
    QDateEdit *maximumDateEdit;
    QDateEdit *currentDateEdit;
    QLabel *minimumDateLabel;
    QLabel *maximumDateLabel;
    QLabel *currentDateLabel;

    QGroupBox *textFormatsGroupBox;
    QComboBox *weekdayColorCombo;
    QLabel *weekdayColorLabel;
    QComboBox *weekendColorCombo;
    QLabel *weekendColorLabel;
    QComboBox *headerTextFormatCombo;
    QLabel *headerTextFormatLabel;
    QCheckBox *firstFridayCheckBox;
    QCheckBox *julyFirstCheckBox;
    WeatherDisPlay *w;
    EmailWindow *e;

};
#endif // MAINWINDOW_H
