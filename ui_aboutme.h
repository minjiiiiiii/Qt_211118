/********************************************************************************
** Form generated from reading UI file 'aboutme.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTME_H
#define UI_ABOUTME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AboutMe
{
public:
    QWidget *centralwidget;
    QLabel *label_pic2;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_open_webcam;
    QPushButton *pushButton_close_webcam;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AboutMe)
    {
        if (AboutMe->objectName().isEmpty())
            AboutMe->setObjectName(QStringLiteral("AboutMe"));
        AboutMe->resize(921, 800);
        centralwidget = new QWidget(AboutMe);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label_pic2 = new QLabel(centralwidget);
        label_pic2->setObjectName(QStringLiteral("label_pic2"));
        label_pic2->setGeometry(QRect(20, 10, 701, 491));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(740, 10, 171, 181));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_open_webcam = new QPushButton(widget);
        pushButton_open_webcam->setObjectName(QStringLiteral("pushButton_open_webcam"));

        verticalLayout->addWidget(pushButton_open_webcam);

        pushButton_close_webcam = new QPushButton(widget);
        pushButton_close_webcam->setObjectName(QStringLiteral("pushButton_close_webcam"));

        verticalLayout->addWidget(pushButton_close_webcam);

        AboutMe->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AboutMe);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 921, 22));
        AboutMe->setMenuBar(menubar);
        statusbar = new QStatusBar(AboutMe);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        AboutMe->setStatusBar(statusbar);

        retranslateUi(AboutMe);

        QMetaObject::connectSlotsByName(AboutMe);
    } // setupUi

    void retranslateUi(QMainWindow *AboutMe)
    {
        AboutMe->setWindowTitle(QApplication::translate("AboutMe", "MainWindow", Q_NULLPTR));
        label_pic2->setText(QString());
        pushButton->setText(QApplication::translate("AboutMe", "&Close", Q_NULLPTR));
        pushButton_open_webcam->setText(QApplication::translate("AboutMe", "Open Webcam", Q_NULLPTR));
        pushButton_close_webcam->setText(QApplication::translate("AboutMe", "Close Webcam", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AboutMe: public Ui_AboutMe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTME_H
