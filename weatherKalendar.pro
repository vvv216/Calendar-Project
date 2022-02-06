QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = weatherKalendar

SOURCES += \
    main.cpp \
    weatherDisplay.cpp \
    weatherinfo.cpp \
    login.cpp \
    signUp.cpp \
    mainwindow.cpp\
    taskitem.cpp \
    emailwindow.cpp\
    smtp.cpp

HEADERS += \
    weatherDisplay.h \
    weatherinfo.h \
    login.h \
    signUp.h \
    mainwindow.h\
    taskitem.h\
    Ui_MainWindow.h\
    emailwindow.h \
    smtp.h \
    ui_emailwindow.h

FORMS +=\
    mainwindow.ui\
    emailwindow.ui

