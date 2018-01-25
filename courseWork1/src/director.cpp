#include "director.h"
#include "ui_director.h"

Director::Director(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Director)
{
    ui->setupUi(this);
    statusroom = new StatusRoom();
    connect(statusroom, &StatusRoom::statusWindow, this, &Director::show);
    shedule = new WorkShedule();
    connect(shedule, &WorkShedule::sheduleWindow, this, &Director::show);
    staff = new Staff();
    connect(staff, &Staff::staff_Window, this, &Director::show);
    scheme = new Scheme();
    connect(scheme, &Scheme::viewWindow, this, &Director::show);
    QPalette * palette = new QPalette();
    palette->setBrush(this->backgroundRole(), QBrush(QPixmap(":/doc/gradient-background-2560x1600.jpg")));
    this->setPalette(*palette);
    moveToCenter();
}
void Director::moveToCenter() {
    QDesktopWidget desktop;
    QRect rect = desktop.availableGeometry(desktop.primaryScreen()); // прямоугольник с размерами экрана
    QPoint center = rect.center(); //координаты центра экрана
    center.setX(center.x() - (this->width()/2));  // учитываем половину ширины окна
    center.setY(center.y() - (this->height()/2));  // .. половину высоты
    move(center);
}
Director::~Director()
{
    delete ui;
}

void Director::on_shedulepushButton_clicked()
{

        shedule->show();


}

void Director::on_statuspushButton_clicked()
{
        statusroom->show();
}

void Director::on_staffpushButton_clicked()
{
        staff->show();
}

void Director::on_statepushButton_clicked()
{
        scheme->show();
}
