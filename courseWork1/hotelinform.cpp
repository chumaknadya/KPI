#include "hotelinform.h"
#include "ui_hotelinform.h"

HotelInform::HotelInform(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HotelInform)
{
    ui->setupUi(this);
}

HotelInform::~HotelInform()
{
    delete ui;
}
void HotelInform::setPicture(QString & picture) {
    QPixmap image(picture);
    ui->label->setPixmap(image);
}
