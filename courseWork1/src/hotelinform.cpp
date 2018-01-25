#include "hotelinform.h"
#include "ui_hotelinform.h"

HotelInform::HotelInform(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HotelInform)
{
    ui->setupUi(this);
    QPalette * palette = new QPalette();
    palette->setBrush(this->backgroundRole(), QBrush(QPixmap(":/doc/1389933279_1837065964.jpg")));
    this->setPalette(*palette);
    moveToCenter();
}
void HotelInform::moveToCenter() {
    QDesktopWidget desktop;
    QRect rect = desktop.availableGeometry(desktop.primaryScreen()); // прямоугольник с размерами экрана
    QPoint center = rect.center(); //координаты центра экрана
    center.setX(center.x() - (this->width()/2));  // учитываем половину ширины окна
    center.setY(center.y() - (this->height()/2));  // .. половину высоты
    move(center);
}
HotelInform::~HotelInform()
{
    delete ui;
}
void HotelInform::setPicture(QString & picture) {
    QPixmap image(picture);
    ui->label->setPixmap(image);
}
void HotelInform::setName(QString  name) {
    ui->label->setText(name);
}
