#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDesktopWidget>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    moveToCenter();
    QPalette * palette = new QPalette();
    palette->setBrush(this->backgroundRole(), QBrush(QPixmap(":/doc/pQaLRxZ.jpg")));
    this->setPalette(*palette);


}
void MainWindow::moveToCenter() {
    QDesktopWidget desktop;
    QRect rect = desktop.availableGeometry(desktop.primaryScreen()); // прямоугольник с размерами экрана
    QPoint center = rect.center(); //координаты центра экрана
    center.setX(center.x() - (this->width()/2));  // учитываем половину ширины окна
    center.setY(center.y() - (this->height()/2));  // .. половину высоты
    move(center);
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_signInpushButton_clicked()
{
    Clogin  login;
    login.exec();
}

void MainWindow::on_reviewspushButton_clicked()
{
    QDesktopServices::openUrl(QUrl("https://chumaknadya19.wixsite.com/mysite"));
}
