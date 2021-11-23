#include "aboutme.h"
#include "ui_aboutme.h"
#include <QString>
#include <QMessageBox>
#include <QPixmap>
#include <QApplication>
#include <Qt>
#include "mainwindow.h"
#include <glib.h>
#include <gst/gst.h>
#include <gst/video/videooverlay.h>
#include <QTimer>
#include <QWidget>
#include <iostream>






AboutMe::AboutMe(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AboutMe)
{
    ui->setupUi(this);
   /*

    QPixmap pix(":/img2/img/testimage2.jpeg");

    int w = ui->label_pic2->width();
    int h = ui->label_pic2->height();
    ui->label_pic2->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    //ui->label_pic->setPixmap(pix.scaled(1280,720,Qt::KeepAspectRatio));  //resize the image as you want
    */
    timer = new QTimer(this);



}

AboutMe::~AboutMe()
{
    delete ui;
}

void AboutMe::changeEvent(QEvent *e)
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

void AboutMe::on_pushButton_clicked()
{
    close();
}

void AboutMe::on_pushButton_open_webcam_clicked()
{
        cap.open(0);

        if(!cap.isOpened())  // Check if we succeeded
        {
            std::cout << "camera is not open" << endl;
        }
        else
        {
             std::cout  << "camera is open" << endl;

            connect(timer, SIGNAL(timeout()), this, SLOT(update_window()));
            timer->start(20);
        }
}

void AboutMe::on_pushButton_close_webcam_clicked()
{
        disconnect(timer, SIGNAL(timeout()), this, SLOT(update_window()));
        cap.release();

        Mat image = Mat::zeros(frame.size(),CV_8UC3);

        qt_image = QImage((const unsigned char*) (image.data), image.cols, image.rows, QImage::Format_RGB888);

        ui->label_pic2->setPixmap(QPixmap::fromImage(qt_image));

        ui->label_pic2->resize(ui->label_pic2->pixmap()->size());

         std::cout  << "camera is closed" << endl;
}


void AboutMe::update_window()
{
    cap >> frame;
    QRCodeDetector detector;

    if (frame.empty()) {
               std::cerr << "Frame load failed!" << endl;
               //return;
           }

           cvtColor(frame, gray, COLOR_BGR2GRAY);

           std::vector<Point> points;
           if (detector.detect(gray, points)) {
               polylines(frame, points, true, Scalar(0, 255, 255), 2);

               String info = detector.decode(gray, points);

               if (!info.empty()) {
                   polylines(frame, points, true, Scalar(0, 0, 255), 2);
                   //std::cout << info << endl;
                QString qinfo = QString::fromStdString(info);

                ui->label_detect->setText(qinfo);

               }
           }


    cvtColor(frame, frame, cv::COLOR_BGR2RGB );

    qt_image = QImage((const unsigned char*) (frame.data), frame.cols, frame.rows, QImage::Format_RGB888);

    ui->label_pic2->setPixmap(QPixmap::fromImage(qt_image));

    ui->label_pic2->resize(ui->label_pic2->pixmap()->size());





}



