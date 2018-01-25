#include "scheme.h"
#include "ui_scheme.h"

Scheme::Scheme(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Scheme)
{
    ui->setupUi(this);
    QPalette * palette = new QPalette();
    palette->setBrush(this->backgroundRole(), QBrush(QPixmap(":/doc/20-aerografiya.jpg")));
    this->setPalette(*palette);
    moveToCenter();
}

Scheme::~Scheme()
{
    delete ui;
}
void Scheme::moveToCenter() {
    QDesktopWidget desktop;
    QRect rect = desktop.availableGeometry(desktop.primaryScreen()); // прямоугольник с размерами экрана
    QPoint center = rect.center(); //координаты центра экрана
    center.setX(center.x() - (this->width()/2));  // учитываем половину ширины окна
    center.setY(center.y() - (this->height()/2));  // .. половину высоты
    move(center);
}
void Scheme::on_viewButton_clicked()
{
     QDesktopServices::openUrl(QUrl("https://www.youtube.com/watch?v=uqpL-Y74K2A"));
}
