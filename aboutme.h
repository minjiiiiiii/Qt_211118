#ifndef ABOUTME_H
#define ABOUTME_H

#include <QMainWindow>
#include <QDialog>
#include <QImage>
#include <QPixmap>
#include <QtMultimedia/QCamera>
#include <QDebug>
#include <QtMultimedia/QCameraInfo>
#include <QtMultimedia/QAbstractVideoSurface>
#include <QLabel>
#include <QDateTime>


namespace Ui {
    class AboutMe;
}

class AboutMe : public QMainWindow {
    Q_OBJECT



protected:
    void changeEvent(QEvent *e);

private:
    Ui::AboutMe *ui;
    void *reader;
    bool is_detecting;

public:
    AboutMe(QWidget *parent=0);
    ~AboutMe();

    void reset();

    QList<QVideoFrame::PixelFormat>
    supportedPixelFormats(QAbstractVideoBuffer::HandleType type) const;

    bool present(const QVideoFrame &frame);



private slots:
    void on_pushButton_clicked();
};

#endif // ABOUTME_H
