#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWidget>
#include <QString>
#include <QMessageBox>
#include <QPixmap>
#include <QApplication>
#include <Qt>
#include <QLabel>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/img_sgu/img/image_SGU.png");

    int w = ui->label_pic->width();
    int h = ui->label_pic->height();
    ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    //ui->label_pic->setPixmap(pix.scaled(1280,720,Qt::KeepAspectRatio));  //resize the image as you want


}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::openAbout()
{
    winAbout = new AboutMe(this);
    winAbout->show();
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::on_pushButton_clicked()
{
    openAbout();
}

void MainWindow::on_pushButton_2_clicked()
{
    exit(1);
}
void MainWindow::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if(username == "test" && password =="test") {
        QMessageBox::information(this,"Login","Username and password is correct!");
        //hide();
        winAbout = new AboutMe(this);
        winAbout->show();
    }
    else {
        QMessageBox::warning(this,"Login","Username and password is not correct!");
    }
}


/*
void MainWindow::on_pushButton_3_clicked()
{
    if(ui->checkBox->isChecked()) {
        QMessageBox::information(this,"title","Yes --------");
    } else{
        QMessageBox::information(this,"title","No --------");
    }

}

void MainWindow::on_checkBox_stateChanged(int arg1)
{

    if(arg1) {
        QMessageBox::information(this,"title","Yes --------");
    } else{
        QMessageBox::information(this,"title","No --------");
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    if(ui->radioButton->isChecked()){
        QMessageBox::information(this,"title","Authorized user");
    }
    if(ui->radioButton_2->isChecked()){
        QMessageBox::information(this,"title","Unauthorized user");
        exit(1);
    }
}

*/
