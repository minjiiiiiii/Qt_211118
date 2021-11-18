/********************************************************************************
** Form generated from reading UI file 'aboutme.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTME_H
#define UI_ABOUTME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AboutMe
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QLabel *label_pic2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AboutMe)
    {
        if (AboutMe->objectName().isEmpty())
            AboutMe->setObjectName(QString::fromUtf8("AboutMe"));
        AboutMe->resize(600, 480);
        centralwidget = new QWidget(AboutMe);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(490, 390, 93, 27));
        label_pic2 = new QLabel(centralwidget);
        label_pic2->setObjectName(QString::fromUtf8("label_pic2"));
        label_pic2->setGeometry(QRect(30, 10, 431, 371));
        AboutMe->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AboutMe);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 600, 22));
        AboutMe->setMenuBar(menubar);
        statusbar = new QStatusBar(AboutMe);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        AboutMe->setStatusBar(statusbar);

        retranslateUi(AboutMe);

        QMetaObject::connectSlotsByName(AboutMe);
    } // setupUi

    void retranslateUi(QMainWindow *AboutMe)
    {
        AboutMe->setWindowTitle(QCoreApplication::translate("AboutMe", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("AboutMe", "&Close", nullptr));
        label_pic2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AboutMe: public Ui_AboutMe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTME_H
