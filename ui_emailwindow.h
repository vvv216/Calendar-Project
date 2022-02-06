/********************************************************************************
** Form generated from reading UI file 'emailwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMAILWINDOW_H
#define UI_EMAILWINDOW_H

#include <QtCore/QVariant>
//#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EmailWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label_5;
    QLineEdit *rcpt;
    QLabel *label_6;
    QLineEdit *subject;
    QLabel *label_7;
    QPlainTextEdit *msg;
    QHBoxLayout *horizontalLayout;
    QPushButton *AttachmentButton;
    QLineEdit *fileName;
    QSpacerItem *horizontalSpacer;
    QPushButton *sendButton;
    QPushButton *exitButton;
    QMenuBar *menuBar;
    QMenu *menuEmail;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *EmailWindow)
    {
        if (EmailWindow->objectName().isEmpty())
            EmailWindow->setObjectName(QString::fromUtf8("EmailWindow"));
        EmailWindow->resize(484, 487);
        centralWidget = new QWidget(EmailWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        formLayout->setRowWrapPolicy(QFormLayout::WrapLongRows);
        formLayout->setVerticalSpacing(9);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_5);

        rcpt = new QLineEdit(centralWidget);
        rcpt->setObjectName(QString::fromUtf8("rcpt"));

        formLayout->setWidget(0, QFormLayout::FieldRole, rcpt);

        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_6);

        subject = new QLineEdit(centralWidget);
        subject->setObjectName(QString::fromUtf8("subject"));

        formLayout->setWidget(1, QFormLayout::FieldRole, subject);

        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_7);

        msg = new QPlainTextEdit(centralWidget);
        msg->setObjectName(QString::fromUtf8("msg"));

        formLayout->setWidget(2, QFormLayout::FieldRole, msg);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        AttachmentButton = new QPushButton(centralWidget);
        AttachmentButton->setObjectName(QString::fromUtf8("AttachmentButton"));

        horizontalLayout->addWidget(AttachmentButton);

        fileName = new QLineEdit(centralWidget);
        fileName->setObjectName(QString::fromUtf8("fileName"));

        horizontalLayout->addWidget(fileName);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        sendButton = new QPushButton(centralWidget);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));

        horizontalLayout->addWidget(sendButton);

        exitButton = new QPushButton(centralWidget);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));

        horizontalLayout->addWidget(exitButton);


        verticalLayout->addLayout(horizontalLayout);

        EmailWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(EmailWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 484, 24));
        menuEmail = new QMenu(menuBar);
        menuEmail->setObjectName(QString::fromUtf8("menuEmail"));
        EmailWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(EmailWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        EmailWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(EmailWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        EmailWindow->setStatusBar(statusBar);

        menuBar->addAction(menuEmail->menuAction());

        retranslateUi(EmailWindow);

        QMetaObject::connectSlotsByName(EmailWindow);
    } // setupUi

    void retranslateUi(QMainWindow *EmailWindow)
    {
        EmailWindow->setWindowTitle(QCoreApplication::translate("EmailWindow", "Email Service", nullptr));
        label_5->setText(QCoreApplication::translate("EmailWindow", "To:", nullptr));
        label_6->setText(QCoreApplication::translate("EmailWindow", "Subject:", nullptr));
        label_7->setText(QCoreApplication::translate("EmailWindow", "Message:", nullptr));
        AttachmentButton->setText(QCoreApplication::translate("EmailWindow", "Attachment", nullptr));
        sendButton->setText(QCoreApplication::translate("EmailWindow", "Send", nullptr));
        exitButton->setText(QCoreApplication::translate("EmailWindow", "Exit", nullptr));
        menuEmail->setTitle(QCoreApplication::translate("EmailWindow", "Email", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EmailWindow: public Ui_EmailWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMAILWINDOW_H
