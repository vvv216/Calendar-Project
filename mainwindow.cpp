#include "mainwindow.h"
#include "weatherDisplay.h"
#include <QApplication>
#include "QDebug"

/**
 @brief The class is to set up the language, dates, text formats and others details into the ui
 @author Jiawei Li, Han Gao
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->setWindowTitle("Kalendar");
    on_calendarWidget_clicked();

    w= new WeatherDisPlay();
    e= new EmailWindow();

    colorSelected.setBackground(Qt::green);
    colorHighlight.setBackground(Qt::red);

    ui->spinBox->setMaximum(0);

    nameOfFile = "Kalendar";
    ui->fileName->setText(nameOfFile);
    ui->calendarWidget->setMinimumDate(QDate(1900, 1, 1));
    ui->calendarWidget->setMaximumDate(QDate(3000, 1, 1));
    ui->calendarWidget->setGridVisible(true);


    int curLocaleIndex = -1;
    int index = 0;
    for (int _lang = QLocale::C; _lang <= QLocale::LastLanguage; ++_lang) {
        QLocale::Language lang = static_cast<QLocale::Language>(_lang);
        QList<QLocale::Country> countries = QLocale::countriesForLanguage(lang);
        for (int i = 0; i < countries.count(); ++i) {
            QLocale::Country country = countries.at(i);
            QString label = QLocale::languageToString(lang);
            label += QLatin1Char('/');
            label += QLocale::countryToString(country);
            QLocale locale(lang, country);
            if (this->locale().language() == lang && this->locale().country() == country)
                curLocaleIndex = index;
            ui->localeCombo->addItem(label, locale);
            ++index;
        }
    }
    if (curLocaleIndex != -1)
        ui->localeCombo->setCurrentIndex(curLocaleIndex);
    connect(ui->localeCombo, &QComboBox::currentIndexChanged,
            this, &MainWindow::localeChanged);

    
    ui->firstDayCombo->addItem(tr("Sunday"), Qt::Sunday);
    ui->firstDayCombo->addItem(tr("Monday"), Qt::Monday);
    ui->firstDayCombo->addItem(tr("Tuesday"), Qt::Tuesday);
    ui->firstDayCombo->addItem(tr("Wednesday"), Qt::Wednesday);
    ui->firstDayCombo->addItem(tr("Thursday"), Qt::Thursday);
    ui->firstDayCombo->addItem(tr("Friday"), Qt::Friday);
    ui->firstDayCombo->addItem(tr("Saturday"), Qt::Saturday);
    connect(ui->firstDayCombo, &QComboBox::currentIndexChanged,
            this, &MainWindow::firstDayChanged);
    firstDayChanged(ui->firstDayCombo->currentIndex());



    ui->selectionModeCombo->addItem(tr("Single selection"), QCalendarWidget::SingleSelection);
    ui->selectionModeCombo->addItem(tr("None"), QCalendarWidget::NoSelection);
    connect(ui->selectionModeCombo, &QComboBox::currentIndexChanged,
            this, &MainWindow::selectionModeChanged);
    selectionModeChanged(ui->selectionModeCombo->currentIndex());



    ui->horizontalHeaderCombo->addItem(tr("Single letter day names"),
                                   QCalendarWidget::SingleLetterDayNames);
    ui->horizontalHeaderCombo->addItem(tr("Short day names"),
                                   QCalendarWidget::ShortDayNames);
    ui->horizontalHeaderCombo->addItem(tr("None"),
                                   QCalendarWidget::NoHorizontalHeader);
    ui->horizontalHeaderCombo->setCurrentIndex(1);
    connect(ui->horizontalHeaderCombo, &QComboBox::currentIndexChanged,
            this, &MainWindow::horizontalHeaderChanged);
    horizontalHeaderChanged(ui->horizontalHeaderCombo->currentIndex());



    ui->verticalHeaderCombo->addItem(tr("ISO week numbers"),
                                 QCalendarWidget::ISOWeekNumbers);
    ui->verticalHeaderCombo->addItem(tr("None"), QCalendarWidget::NoVerticalHeader);

    connect(ui->verticalHeaderCombo, &QComboBox::currentIndexChanged,
            this, &MainWindow::verticalHeaderChanged);
    verticalHeaderChanged(ui->verticalHeaderCombo->currentIndex());



    ui->gridCheckBox->setChecked(ui->calendarWidget->isGridVisible());
    connect(ui->gridCheckBox, &QCheckBox::toggled,
            ui->calendarWidget, &QCalendarWidget::setGridVisible);



    ui->navigationCheckBox->setChecked(true);
    connect(ui->navigationCheckBox, &QCheckBox::toggled,
            ui->calendarWidget, &QCalendarWidget::setNavigationBarVisible);


    ui->minimumDateEdit->setDisplayFormat("MMM d yyyy");
    ui->minimumDateEdit->setDateRange(ui->calendarWidget->minimumDate(),
                                  ui->calendarWidget->maximumDate());
    ui->minimumDateEdit->setDate(ui->calendarWidget->minimumDate());



    ui->currentDateEdit->setDisplayFormat("MMM d yyyy");
    ui->currentDateEdit->setDate(ui->calendarWidget->selectedDate());
    ui->currentDateEdit->setDateRange(ui->calendarWidget->minimumDate(),
                                  ui->calendarWidget->maximumDate());


    ui->maximumDateEdit->setDisplayFormat("MMM d yyyy");
    ui->maximumDateEdit->setDateRange(ui->calendarWidget->minimumDate(),
                                  ui->calendarWidget->maximumDate());
    ui->maximumDateEdit->setDate(ui->calendarWidget->maximumDate());

    connect(ui->currentDateEdit, &QDateEdit::dateChanged,
            ui->calendarWidget, &QCalendarWidget::setSelectedDate);
    connect(ui->calendarWidget, &QCalendarWidget::selectionChanged,
            this, &MainWindow::selectedDateChanged);
    connect(ui->minimumDateEdit, &QDateEdit::dateChanged,
            this, &MainWindow::minimumDateChanged);
    connect(ui->maximumDateEdit, &QDateEdit::dateChanged,
            this, &MainWindow::maximumDateChanged);



    ui->weekdayColorCombo->addItem(tr("Black"), QColor(Qt::black));
    ui->weekdayColorCombo->addItem(tr("Red"), QColor(Qt::red));
    ui->weekdayColorCombo->addItem(tr("Blue"), QColor(Qt::blue));
    ui->weekdayColorCombo->addItem(tr("Magenta"), QColor(Qt::magenta));


    ui->weekendColorCombo->addItem(tr("Red"), QColor(Qt::red));
    ui->weekendColorCombo->addItem(tr("Blue"), QColor(Qt::blue));
    ui->weekendColorCombo->addItem(tr("Black"), QColor(Qt::black));
    ui->weekendColorCombo->addItem(tr("Magenta"), QColor(Qt::magenta));



    ui->headerTextFormatCombo->addItem(tr("Bold"));
    ui->headerTextFormatCombo->addItem(tr("Italic"));
    ui->headerTextFormatCombo->addItem(tr("Plain"));



    connect(ui->weekdayColorCombo, &QComboBox::currentIndexChanged,
            this, &MainWindow::weekdayFormatChanged);
    connect(ui->weekdayColorCombo, &QComboBox::currentIndexChanged,
            this, &MainWindow::reformatCalendarPage);
    connect(ui->weekendColorCombo, &QComboBox::currentIndexChanged,
            this, &MainWindow::weekendFormatChanged);
    connect(ui->weekendColorCombo, &QComboBox::currentIndexChanged,
            this, &MainWindow::reformatCalendarPage);
    connect(ui->headerTextFormatCombo, &QComboBox::currentIndexChanged,
            this, &MainWindow::reformatHeaders);
    connect(ui->firstFridayCheckBox, &QCheckBox::toggled,
            this, &MainWindow::reformatCalendarPage);
    connect(ui->julyFirstCheckBox, &QCheckBox::toggled,
            this, &MainWindow::reformatCalendarPage);


}
/**
 @brief deconstructor
 @author Jiawei Li, Han Gao
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/**
 @brief The class is to click the dates of the calendarWidget
 @author Jiawei Li, Han Gao
 */


void MainWindow::on_calendarWidget_clicked()
{
    date = ui->calendarWidget->selectedDate();
}

/**
 @brief The class is to accomplish the function button of open from the menu bar. The purpose is to open the a possible existing file in from the local space and give a warning if the file does not exist
 @author Jiawei Li, Han Gao
 */

void MainWindow::on_open_triggered()
{
    if(change)
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, QString::fromUtf8("Attention"),
                              QString::fromUtf8("Do you want to store this " + nameOfFile.toUtf8() + " ?" ),
                              QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
        if (reply == QMessageBox::Yes)
            on_saveHow_triggered();
        else if (reply == QMessageBox::No)
        {

        }
    }

    change = false;


    QString fileName = QFileDialog::getOpenFileName(this,
                                QString::fromUtf8("Open File"),
                                QDir::currentPath(),
                                "Documents (*.txt);;All files (*.*)");

    if(fileName.isEmpty()){
        return;
    }

    clearAll();

    nameOfFile = fileName.right(fileName.length() - fileName.lastIndexOf("/") - 1);
    ui->fileName->setText(nameOfFile);

    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly)) {
        qWarning("Cannot open file for reading");
        return;
    }

    QTextStream in(&file);

    while (!in.atEnd())
    {
        QString line = in.readLine();
        tasks.append(taskitem(line));

    }
    file.close();

    for(int i = 0;i < tasks.size();i++)
    {
        ui->calendarWidget->setDateTextFormat(tasks[i].getDate(),colorSelected);
    }
    printTasks(true);
}

/**
 @brief The class is to accomplish the function button of create from the menu bar. The purpose is to create a new text file which can be named by the users and store the events of the specific dates.
 @author Jiawei Li, Han Gao
 */

void MainWindow::on_create_triggered()
{
    if(change)
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, QString::fromUtf8("Attention"),
                              QString::fromUtf8("Save " + nameOfFile.toUtf8() + " ?" ),
                              QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
        if (reply == QMessageBox::Yes)
            on_saveHow_triggered();
        else if (reply == QMessageBox::No)
        {

        }
    }

    change = false;

    on_saveHow_triggered();

    clearAll();

}


/**
 @brief The class is to sort the event in the list by the time sequence
 @author Jiawei Li, Han Gao
 */

void MainWindow::sort()
{
    for(int i = tasks.size() - 1;i >= 0; i--)
    {
        for(int j = tasks.size() - 1;j >= 0; j--)
        {
            if(tasks[j].getDate() < tasks[i].getDate())
            {
                tasks.swapItemsAt(i,j);
            }
        }
    }
}

/**
 @brief The class is to print the events from the users' adding into the list
 @author Jiawei Li, Han Gao
 */

void MainWindow::printTasks(bool ignore){

    if((!change)&&(!ignore))
    {
        change = true;
        ui->fileName->setText("*" + nameOfFile);
    }

    int size = tasks.size();
    ui->spinBox->setMaximum( (size == 0) ? size : size - 1 );
    ui->spinBox->setValue(0);

    ui->textBrowser->clear();

    sort();


    for(int i = 0;i<tasks.size();i++)
    {
        ui->textBrowser->append(tasks[i].getItemString());
    }

}

/**
 @brief The class is to accomplish the function button of info from the menu bar. The purpose is to introduce the current version of our system and whcih group made the system
 @author Jiawei Li, Han Gao
 */

void MainWindow::on_info_triggered()
{
    QMessageBox::information(this, "info", "VERSION 1.0\nThis program is designed by CS 3307 group06");

}

/**
 @brief The class is to accomplish the push button of Add from the ui. The purpose is to add the events and store events into the list for the users
 @author Jiawei Li, Han Gao
 */
void MainWindow::on_addEvent_clicked()
{
    for(int i = 0;i<tasks.size();i++)
    {
        if(tasks[i].getDate() == ui->calendarWidget->selectedDate())
        {
            return;
        }
    }

    bool ok;
    QString text = QInputDialog::getText(this,
                                 QString::fromUtf8("Adding Events"),
                                 QString::fromUtf8("Event Text:"),
                                 QLineEdit::Normal,
                                 "", &ok);
    if (ok && !text.isEmpty())
    {
        ui->calendarWidget->setDateTextFormat(ui->calendarWidget->selectedDate(),colorSelected);
        tasks.append(taskitem(text, ui->calendarWidget->selectedDate()));
        printTasks(false);
    }
}

/**
 @brief The class is to accomplish the push button of Delete from the ui. The purpose is to delet the events from the list for the users and not shown on the list anymore
 @author Jiawei Li, Han Gao
 */
void MainWindow::on_deleteEvent_clicked()
{

    for (iterList = tasks.begin(); iterList != tasks.end(); iterList++)
    {
        if(iterList->getDate() == ui->calendarWidget->selectedDate())
        {
            ui->calendarWidget->setDateTextFormat(ui->calendarWidget->selectedDate(),colorUnSelected);
            tasks.erase(iterList);

            printTasks(false);

            break;
        }
    }

}

/**
 @brief The class is to help the index of list which is used to store events
 @author Jiawei Li, Han Gao
 */
void MainWindow::on_spinBox_textChanged()
{
    ui->calendarWidget->setSelectedDate(tasks[ui->spinBox->value()].getDate());
}

/**
 @brief The class is to accomplish the function button of save from the menu bar. The purpose is to save the events and time as a text file and store into the local space
 @author Jiawei Li, Han Gao
 */
void MainWindow::on_saveHow_triggered()
{

    QString fileName = QFileDialog::getSaveFileName(this,
                                QString::fromUtf8("Save"),
                                QDir::currentPath(),
                                "Documents (*.txt);;All files (*.*)");
    if(fileName.isEmpty())
    {
        return;
    }

    nameOfFile = fileName.right(fileName.length() - fileName.lastIndexOf("/") - 1);
    ui->fileName->setText(nameOfFile);
    change = false;

    QTextStream out(stdout);

    QFile file(nameOfFile);


    if (file.open(QIODevice::WriteOnly)) {
        QTextStream out(&file);
        for(int i = 0;i<tasks.size(); i++)
        {
            out<<tasks[i].getItemString()<<Qt::endl;
        }

    } else {
        qWarning("Could not open file");
      }
      file.close();
}

/**
 @brief The class is to clear all events of the list
 @author Jiawei Li, Han Gao
 */
void MainWindow::clearAll()
{
    for(int i = 0;i < tasks.size();i++)
    {
        ui->calendarWidget->setDateTextFormat(tasks[i].getDate(),colorUnSelected);
    }
    ui->textBrowser->clear();
    tasks.clear();
}

/**
 @brief The class is to accomplish the push button of Weather from the ui. The purpose is to connect the weather function which is used to demonstrate the weather condition of a specific location in canada
 @author Jiawei Li, Han Gao
 */
void MainWindow::on_weather_clicked()
{
    w->show();
}
/**
 @brief The class is to accomplish the push button of Email from the ui. The purpose is to help user and sent emails to the other authorized users and share their events
 @author Jiawei Li, Han Gao
 */
void MainWindow::on_email_clicked()
{
    e->show();
}


/**
 @brief The class is to help find more language version in qt and put into the ui
 @author Jiawei Li, Han Gao
 @param index
 */
void MainWindow::localeChanged(int index)
{
    const QLocale newLocale(ui->localeCombo->itemData(index).toLocale());
    ui->calendarWidget->setLocale(newLocale);
    int newLocaleFirstDayIndex = ui->firstDayCombo->findData(newLocale.firstDayOfWeek());
    ui->firstDayCombo->setCurrentIndex(newLocaleFirstDayIndex);
}

/**
 @brief The class is to help change the first day shown on the calendar
 @author Jiawei Li, Han Gao
 @param index
 */
void MainWindow::firstDayChanged(int index)
{
    ui->calendarWidget->setFirstDayOfWeek(Qt::DayOfWeek(
                                ui->firstDayCombo->itemData(index).toInt()));
}

/**
 @brief The class is to help select the different modes for the calendar
 @author Jiawei Li, Han Gao
 @param index
 */
void MainWindow::selectionModeChanged(int index)
{
    ui->calendarWidget->setSelectionMode(QCalendarWidget::SelectionMode(
                               ui->selectionModeCombo->itemData(index).toInt()));
}
/**
 @brief The class is to help show more possiblities of the horizontal header for the calendar
 @author Jiawei Li, Han Gao
 @parameter index
 */
void MainWindow::horizontalHeaderChanged(int index)
{
    ui->calendarWidget->setHorizontalHeaderFormat(QCalendarWidget::HorizontalHeaderFormat(
        ui->horizontalHeaderCombo->itemData(index).toInt()));
}
/**
 @brief The class is to help show more possiblities of the vertical header for the calendar
 @author Jiawei Li, Han Gao
 @param index
 */
void MainWindow::verticalHeaderChanged(int index)
{
    ui->calendarWidget->setVerticalHeaderFormat(QCalendarWidget::VerticalHeaderFormat(
        ui->verticalHeaderCombo->itemData(index).toInt()));
}

/**
 @brief The class is to help select the date which the user cuurently selecting
 @author Jiawei Li, Han Gao
 */
void MainWindow::selectedDateChanged()
{
    ui->currentDateEdit->setDate(ui->calendarWidget->selectedDate());
}
/**
 @brief The class is to help change the minimum date that the calendar can achieve
 @author Jiawei Li, Han Gao
 @param QDate date
 */
void MainWindow::minimumDateChanged(QDate date)
{
    ui->calendarWidget->setMinimumDate(date);
    ui->maximumDateEdit->setDate(ui->calendarWidget->maximumDate());
}
/**
 @brief The class is to help change the maximum date that the calendar can achieve
 @author Jiawei Li, Han Gao
 @param QDate date
 */
void MainWindow::maximumDateChanged(QDate date)
{
    ui->calendarWidget->setMaximumDate(date);
    ui->minimumDateEdit->setDate(ui->calendarWidget->minimumDate());
}

/**
 @brief The class is to help change the color of weekdays of calendar
 @author Jiawei Li, Han Gao
 */
void MainWindow::weekdayFormatChanged()
{
    QTextCharFormat format;

    format.setForeground(qvariant_cast<QColor>(
        ui->weekdayColorCombo->itemData(ui->weekdayColorCombo->currentIndex())));
    ui->calendarWidget->setWeekdayTextFormat(Qt::Monday, format);
    ui->calendarWidget->setWeekdayTextFormat(Qt::Tuesday, format);
    ui->calendarWidget->setWeekdayTextFormat(Qt::Wednesday, format);
    ui->calendarWidget->setWeekdayTextFormat(Qt::Thursday, format);
    ui->calendarWidget->setWeekdayTextFormat(Qt::Friday, format);
}
/**
 @brief The class is to help change the color of weekends of calendar
 @author Jiawei Li, Han Gao
 */
void MainWindow::weekendFormatChanged()
{
    QTextCharFormat format;

    format.setForeground(qvariant_cast<QColor>(
        ui->weekendColorCombo->itemData(ui->weekendColorCombo->currentIndex())));
    ui->calendarWidget->setWeekdayTextFormat(Qt::Saturday, format);
    ui->calendarWidget->setWeekdayTextFormat(Qt::Sunday, format);
}
/**
 @brief The class is to help change the font format for the calendar
 @author Jiawei Li, Han Gao
 */
void MainWindow::reformatHeaders()
{
    QString text = ui->headerTextFormatCombo->currentText();
    QTextCharFormat format;

    if (text == tr("Bold"))
        format.setFontWeight(QFont::Bold);
    else if (text == tr("Italic"))
        format.setFontItalic(true);
    else if (text == tr("Green"))
        format.setForeground(Qt::green);
    ui->calendarWidget->setHeaderTextFormat(format);
}
/**
 @brief The class is to help reformat the color for the first friday of the current month and find the July 1st which is Canada Noational Day and change the for that date
 @author Jiawei Li, Han Gao
 */
void MainWindow::reformatCalendarPage()
{
    QTextCharFormat julyFirstFormat;
    const QDate julyFirst(ui->calendarWidget->yearShown(), 7, 1);

    QTextCharFormat firstFridayFormat;
    QDate firstFriday(ui->calendarWidget->yearShown(), ui->calendarWidget->monthShown(), 1);
    while (firstFriday.dayOfWeek() != Qt::Friday)
        firstFriday = firstFriday.addDays(1);

    if (ui->firstFridayCheckBox->isChecked()) {
        firstFridayFormat.setForeground(Qt::blue);
    } else {
        Qt::DayOfWeek dayOfWeek(static_cast<Qt::DayOfWeek>(firstFriday.dayOfWeek()));
        firstFridayFormat.setForeground(ui->calendarWidget->weekdayTextFormat(dayOfWeek).foreground());
    }

    ui->calendarWidget->setDateTextFormat(firstFriday, firstFridayFormat);
    if (ui->julyFirstCheckBox->isChecked()) {
        julyFirstFormat.setForeground(Qt::red);
    } else if (!ui->firstFridayCheckBox->isChecked() || firstFriday != julyFirst) {
        Qt::DayOfWeek dayOfWeek(static_cast<Qt::DayOfWeek>(julyFirst.dayOfWeek()));
        ui->calendarWidget->setDateTextFormat(julyFirst, ui->calendarWidget->weekdayTextFormat(dayOfWeek));
    }

    ui->calendarWidget->setDateTextFormat(julyFirst, julyFirstFormat);
}


