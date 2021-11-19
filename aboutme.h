#ifndef ABOUTME_H
#define ABOUTME_H

#include <QMainWindow>
#include <QDialog>
#include <QImage>
#include <QPixmap>
#include <QDebug>
#include <QLabel>
#include <QDateTime>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QCloseEvent>
#include <QMessageBox>
#include <QTimer>


#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
using namespace cv;


namespace Ui {
    class AboutMe;
}

class AboutMe : public QMainWindow {
    Q_OBJECT



protected:
    void changeEvent(QEvent *e);
    //void closeEvent(QCloseEvent *event); //undefined reference error

private:
    Ui::AboutMe *ui;
    QGraphicsPixmapItem pixmap;
    //cv::VideoCapture video; //undefined reference error

    QTimer *timer;
    VideoCapture cap;

    Mat frame;
    QImage qt_image;


public:
    AboutMe(QWidget *parent=0);
    ~AboutMe();



private slots:
    void on_pushButton_clicked();
    void on_pushButton_open_webcam_clicked();
    void on_pushButton_close_webcam_clicked();
    void update_window();
};

#endif // ABOUTME_H
