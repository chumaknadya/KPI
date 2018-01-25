#include "doorman.h"
#include "ui_doorman.h"

Doorman::Doorman(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Doorman)
{
    ui->setupUi(this);
    shedule = new WorkShedule();
    connect(shedule, &WorkShedule::sheduleWindow, this, &Doorman::show);
    period = new PeriodOfStaying();
    connect(period, &PeriodOfStaying::periodWindow, this, &Doorman::show);
    QPalette * palette = new QPalette();
    palette->setBrush(this->backgroundRole(), QBrush(QPixmap(":/doc/gradient-background-2560x1600.jpg")));
    this->setPalette(*palette);
    moveToCenter();
}
void Doorman::moveToCenter() {
    QDesktopWidget desktop;
    QRect rect = desktop.availableGeometry(desktop.primaryScreen()); // прямоугольник с размерами экрана
    QPoint center = rect.center(); //координаты центра экрана
    center.setX(center.x() - (this->width()/2));  // учитываем половину ширины окна
    center.setY(center.y() - (this->height()/2));  // .. половину высоты
    move(center);
}
Doorman::~Doorman()
{
    delete ui;
}

void Doorman::on_sheduleButton_clicked()
{
   shedule->show();
}

void Doorman::on_lengthStayingButton_clicked()
{
    period->show();

}
