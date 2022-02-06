#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateEdit>


QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *open;
    QAction *create;
    QAction *info;
    QAction *saveHow;
    QWidget *centralwidget;
    QCalendarWidget *calendarWidget;
    QPushButton *addEvent;
    QPushButton *deleteEvent;
    QPushButton *weather;
    QPushButton *email;
    QLabel *fileName;
    QTextBrowser *textBrowser;
    QLabel *label_3;
    QSpinBox *spinBox;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;
    QGroupBox *generalOptionsGroupBox;
    QLabel *localeLabel;
    QLabel *generalLabel;
    QComboBox *firstDayCombo;
    QComboBox *localeCombo;
    QLabel *firstDayLabel;
    QLabel *selectionModeLabel;
    QComboBox *selectionModeCombo;
    QCheckBox *gridCheckBox;
    QCheckBox *navigationCheckBox;
    QLabel *horizontalHeaderLabel;
    QComboBox *horizontalHeaderCombo;
    QLabel *verticalHeaderLabel;
    QComboBox *verticalHeaderCombo;
    QGroupBox *datesGroupBox;
    QDateEdit *minimumDateEdit;
    QDateEdit *maximumDateEdit;
    QDateEdit *currentDateEdit;
    QLabel *minimumDateLabel;
    QLabel *maximumDateLabel;
    QLabel *currentDateLabel;
    QLabel *datesLabel;
    QGroupBox *textFormatsGroupBox;
    QComboBox *weekdayColorCombo;
    QLabel *weekdayColorLabel;
    QComboBox *weekendColorCombo;
    QLabel *weekendColorLabel;
    QComboBox *headerTextFormatCombo;
    QLabel *headerTextFormatLabel;
    QCheckBox *firstFridayCheckBox;
    QCheckBox *julyFirstCheckBox;
    QLabel *textFormatsLabel;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1200, 650);
        MainWindow->setMinimumSize(QSize(1200, 650));
        MainWindow->setMaximumSize(QSize(7700, 4500));
        open = new QAction(MainWindow);
        open->setObjectName(QString::fromUtf8("open"));
        create = new QAction(MainWindow);
        create->setObjectName(QString::fromUtf8("create"));
        info = new QAction(MainWindow);
        info->setObjectName(QString::fromUtf8("info"));
        saveHow = new QAction(MainWindow);
        saveHow->setObjectName(QString::fromUtf8("saveHow"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        calendarWidget = new QCalendarWidget(centralwidget);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        calendarWidget->setGeometry(QRect(10, 60, 441, 281));
        addEvent = new QPushButton(centralwidget);
        addEvent->setObjectName(QString::fromUtf8("addEvent"));
        addEvent->setGeometry(QRect(40, 350, 90, 40));
        deleteEvent = new QPushButton(centralwidget);
        deleteEvent->setObjectName(QString::fromUtf8("deleteEvent"));
        deleteEvent->setGeometry(QRect(370, 350, 90, 40));
        weather = new QPushButton(centralwidget);
        weather->setObjectName(QString::fromUtf8("weather"));
        weather->setGeometry(QRect(150, 350, 90, 40));
        email = new QPushButton(centralwidget);
        email->setObjectName(QString::fromUtf8("email"));
        email->setGeometry(QRect(260, 350, 90, 40));


        fileName = new QLabel(centralwidget);
        fileName->setObjectName(QString::fromUtf8("fileName"));
        fileName->setGeometry(QRect(10, 20, 441, 31));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        fileName->setFont(font);
        fileName->setFrameShape(QFrame::WinPanel);
        fileName->setFrameShadow(QFrame::Raised);
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(470, 40, 281, 361));
        QFont font1;
        font1.setPointSize(10);
        textBrowser->setFont(font1);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(490, 10, 151, 21));
        spinBox = new QSpinBox(centralwidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(620, 10, 42, 22));
        spinBox->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 770, 24));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(open);
        menu->addAction(saveHow);
        menu->addAction(create);
        menu->addAction(info);


        generalOptionsGroupBox = new QGroupBox(centralwidget);
        generalOptionsGroupBox->setObjectName(QString::fromUtf8("generalOptionsGroupBox"));
        generalOptionsGroupBox->setGeometry(QRect(770, 40, 361, 361));
        generalLabel = new QLabel(centralwidget);
        generalLabel->setObjectName(QString::fromUtf8("generalLabel"));
        generalLabel->setGeometry(QRect(780, 10, 151, 21));
        localeLabel = new QLabel(centralwidget);
        localeLabel->setObjectName(QString::fromUtf8("localeLabel"));
        localeLabel->setGeometry(QRect(790, 50, 151, 21));
        localeCombo = new QComboBox(centralwidget);
        localeCombo->setObjectName(QString::fromUtf8("localeCombo"));
        localeCombo->setGeometry(QRect(920, 50, 181, 21));
        firstDayLabel = new QLabel(centralwidget);
        firstDayLabel->setObjectName(QString::fromUtf8("firstDayLabel"));
        firstDayLabel->setGeometry(QRect(790, 110, 151, 21));
        firstDayCombo = new QComboBox(centralwidget);
        firstDayCombo->setObjectName(QString::fromUtf8("firstDayCombo"));
        firstDayCombo->setGeometry(QRect(920, 110, 181, 21));
        selectionModeLabel = new QLabel(centralwidget);
        selectionModeLabel->setObjectName(QString::fromUtf8("selectionModeLabel"));
        selectionModeLabel->setGeometry(QRect(790, 170, 151, 21));
        selectionModeCombo = new QComboBox(centralwidget);
        selectionModeCombo->setObjectName(QString::fromUtf8("selectionModeCombo"));
        selectionModeCombo->setGeometry(QRect(920, 170, 181, 21));
        gridCheckBox = new QCheckBox(centralwidget);
        gridCheckBox->setObjectName(QString::fromUtf8("gridCheckBox"));
        gridCheckBox->setGeometry(QRect(790, 230, 151, 21));
        navigationCheckBox = new QCheckBox(centralwidget);
        navigationCheckBox->setObjectName(QString::fromUtf8("navigationCheckBox"));
        navigationCheckBox->setGeometry(QRect(980, 230, 151, 21));
        horizontalHeaderLabel = new QLabel(centralwidget);
        horizontalHeaderLabel->setObjectName(QString::fromUtf8("selectionModeLabel"));
        horizontalHeaderLabel->setGeometry(QRect(790, 290, 151, 21));
        horizontalHeaderCombo = new QComboBox(centralwidget);
        horizontalHeaderCombo->setObjectName(QString::fromUtf8("selectionModeCombo"));
        horizontalHeaderCombo->setGeometry(QRect(920, 290, 181, 21));
        verticalHeaderLabel = new QLabel(centralwidget);
        verticalHeaderLabel->setObjectName(QString::fromUtf8("selectionModeLabel"));
        verticalHeaderLabel->setGeometry(QRect(790, 350, 151, 21));
        verticalHeaderCombo = new QComboBox(centralwidget);
        verticalHeaderCombo->setObjectName(QString::fromUtf8("selectionModeCombo"));
        verticalHeaderCombo->setGeometry(QRect(920, 350, 181, 21));


        datesGroupBox = new QGroupBox(centralwidget);
        datesGroupBox->setObjectName(QString::fromUtf8("datesGroupBox"));
        datesGroupBox->setGeometry(QRect(10, 420, 441, 181));
        datesLabel = new QLabel(centralwidget);
        datesLabel->setObjectName(QString::fromUtf8("datesLabel"));
        datesLabel->setGeometry(QRect(10, 400, 151, 21));
        minimumDateLabel = new QLabel(centralwidget);
        minimumDateLabel->setObjectName(QString::fromUtf8("minimumDateLabel"));
        minimumDateLabel->setGeometry(QRect(30, 440, 151, 21));
        minimumDateEdit = new QDateEdit(centralwidget);
        minimumDateEdit->setObjectName(QString::fromUtf8("minimumDateEdit"));
        minimumDateEdit->setGeometry(QRect(200, 440, 151, 21));
        currentDateLabel = new QLabel(centralwidget);
        currentDateLabel->setObjectName(QString::fromUtf8("currentDateLabel"));
        currentDateLabel->setGeometry(QRect(30, 495, 151, 21));
        currentDateEdit = new QDateEdit(centralwidget);
        currentDateEdit->setObjectName(QString::fromUtf8("currentDateEdit"));
        currentDateEdit->setGeometry(QRect(200, 495, 151, 21));
        maximumDateLabel = new QLabel(centralwidget);
        maximumDateLabel->setObjectName(QString::fromUtf8("maximumDateLabel"));
        maximumDateLabel->setGeometry(QRect(30, 550, 151, 21));
        maximumDateEdit = new QDateEdit(centralwidget);
        maximumDateEdit->setObjectName(QString::fromUtf8("maximumDateEdit"));
        maximumDateEdit->setGeometry(QRect(200, 550, 151, 21));



        textFormatsGroupBox = new QGroupBox(centralwidget);
        textFormatsGroupBox->setObjectName(QString::fromUtf8("textFormatsGroupBox"));
        textFormatsGroupBox->setGeometry(QRect(560, 420, 541, 181));
        textFormatsLabel = new QLabel(centralwidget);
        textFormatsLabel->setObjectName(QString::fromUtf8("textFormatsLabel"));
        textFormatsLabel->setGeometry(QRect(470, 420, 151, 21));
        weekdayColorLabel = new QLabel(centralwidget);
        weekdayColorLabel->setObjectName(QString::fromUtf8("weekdayColorLabel"));
        weekdayColorLabel->setGeometry(QRect(580, 440, 151, 21));
        weekdayColorCombo = new QComboBox(centralwidget);
        weekdayColorCombo->setObjectName(QString::fromUtf8("weekdayColorCombo"));
        weekdayColorCombo->setGeometry(QRect(850, 440, 181, 21));
        weekendColorLabel = new QLabel(centralwidget);
        weekendColorLabel->setObjectName(QString::fromUtf8("selectionModeLabel"));
        weekendColorLabel->setGeometry(QRect(580, 480, 151, 21));
        weekendColorCombo = new QComboBox(centralwidget);
        weekendColorCombo->setObjectName(QString::fromUtf8("weekendColorCombo"));
        weekendColorCombo->setGeometry(QRect(850, 480, 181, 21));
        headerTextFormatLabel = new QLabel(centralwidget);
        headerTextFormatLabel->setObjectName(QString::fromUtf8("headerTextFormatLabel"));
        headerTextFormatLabel->setGeometry(QRect(580, 520, 151, 21));
        headerTextFormatCombo = new QComboBox(centralwidget);
        headerTextFormatCombo->setObjectName(QString::fromUtf8("headerTextFormatCombo"));
        headerTextFormatCombo->setGeometry(QRect(850, 520, 181, 21));
        firstFridayCheckBox = new QCheckBox(centralwidget);
        firstFridayCheckBox->setObjectName(QString::fromUtf8("firstFridayCheckBox"));
        firstFridayCheckBox->setGeometry(QRect(580, 565, 151, 21));
        julyFirstCheckBox = new QCheckBox(centralwidget);
        julyFirstCheckBox->setObjectName(QString::fromUtf8("julyFirstCheckBox"));
        julyFirstCheckBox->setGeometry(QRect(850, 565, 251, 21));


        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Kalendar", nullptr));
        open->setText(QCoreApplication::translate("MainWindow", "Open file", nullptr));
        create->setText(QCoreApplication::translate("MainWindow", "Create", nullptr));
        info->setText(QCoreApplication::translate("MainWindow", "Info", nullptr));
#if QT_CONFIG(shortcut)
        info->setShortcut(QCoreApplication::translate("MainWindow", "`", nullptr));
#endif // QT_CONFIG(shortcut)
        saveHow->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
#if QT_CONFIG(shortcut)
        saveHow->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        addEvent->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        deleteEvent->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        weather->setText(QCoreApplication::translate("MainWindow", "Weather", nullptr));
        email->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        fileName->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "Event Index", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "Menu", nullptr));
        localeLabel->setText(QCoreApplication::translate("MainWindow", "Locale:", nullptr));
        generalLabel->setText(QCoreApplication::translate("MainWindow", "General Options", nullptr));
        firstDayLabel->setText(QCoreApplication::translate("MainWindow", "Week starts on:", nullptr));
        selectionModeLabel->setText(QCoreApplication::translate("MainWindow", "Selection mode:", nullptr));
        gridCheckBox->setText(QCoreApplication::translate("MainWindow", "Grid", nullptr));
        navigationCheckBox->setText(QCoreApplication::translate("MainWindow", "Navigation bar", nullptr));
        horizontalHeaderLabel->setText(QCoreApplication::translate("MainWindow", "Horizontal header:", nullptr));
        verticalHeaderLabel->setText(QCoreApplication::translate("MainWindow", "Vertical header:", nullptr));
        datesLabel->setText(QCoreApplication::translate("MainWindow", "Dates", nullptr));
        minimumDateLabel->setText(QCoreApplication::translate("MainWindow", "Minimum Date:", nullptr));
        currentDateLabel->setText(QCoreApplication::translate("MainWindow", "Current Date:", nullptr));
        maximumDateLabel->setText(QCoreApplication::translate("MainWindow", "Maximum Date:", nullptr));
        textFormatsLabel->setText(QCoreApplication::translate("MainWindow", "Text Formats:", nullptr));
        weekdayColorLabel->setText(QCoreApplication::translate("MainWindow", "Weekday Color:", nullptr));
        weekendColorLabel->setText(QCoreApplication::translate("MainWindow", "Weekend Color:", nullptr));
        headerTextFormatLabel->setText(QCoreApplication::translate("MainWindow", "Header text:", nullptr));
        firstFridayCheckBox->setText(QCoreApplication::translate("MainWindow", "First Friday in blue", nullptr));
        julyFirstCheckBox->setText(QCoreApplication::translate("MainWindow", "July 1(National Day) in red", nullptr));


    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
