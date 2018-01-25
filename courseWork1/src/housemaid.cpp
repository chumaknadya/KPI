#include "housemaid.h"
#include "ui_housemaid.h"

Housemaid::Housemaid(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Housemaid)
{
    ui->setupUi(this);
    statusroom = new StatusRoom();
    connect(statusroom, &StatusRoom::statusWindow, this, &Housemaid::show);
    shedule = new WorkShedule();
    connect(shedule, &WorkShedule::sheduleWindow, this, &Housemaid::show);

    QPalette * palette = new QPalette();
    palette->setBrush(this->backgroundRole(), QBrush(QPixmap(":/doc/gradient-background-2560x1600.jpg")));
    this->setPalette(*palette);
    moveToCenter();
}
void Housemaid::moveToCenter() {
    QDesktopWidget desktop;
    QRect rect = desktop.availableGeometry(desktop.primaryScreen()); // прямоугольник с размерами экрана
    QPoint center = rect.center(); //координаты центра экрана
    center.setX(center.x() - (this->width()/2));  // учитываем половину ширины окна
    center.setY(center.y() - (this->height()/2));  // .. половину высоты
    move(center);
}
Housemaid::~Housemaid()
{
    delete ui;
}

void Housemaid::on_sheduleButton_clicked()
{
    shedule->show();
}

void Housemaid::on_stateButton_clicked()
{
    statusroom->show();
}
