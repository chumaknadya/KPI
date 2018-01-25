#include "manager.h"
#include "ui_manager.h"

Manager::Manager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Manager)
{
    ui->setupUi(this);
    shedule = new WorkShedule();
    connect(shedule, &WorkShedule::sheduleWindow, this, &Manager::show);
    staff = new Staff();
    connect(staff, &Staff::staff_Window, this, &Manager::show);
    QPalette * palette = new QPalette();
    palette->setBrush(this->backgroundRole(), QBrush(QPixmap(":/doc/gradient-background-2560x1600.jpg")));
    this->setPalette(*palette);
    moveToCenter();
}
void Manager::moveToCenter() {
    QDesktopWidget desktop;
    QRect rect = desktop.availableGeometry(desktop.primaryScreen()); // прямоугольник с размерами экрана
    QPoint center = rect.center(); //координаты центра экрана
    center.setX(center.x() - (this->width()/2));  // учитываем половину ширины окна
    center.setY(center.y() - (this->height()/2));  // .. половину высоты
    move(center);
}
Manager::~Manager()
{
    delete ui;
}

void Manager::on_sheduleButton_clicked()
{
    shedule->show();
}

void Manager::on_staffButton_clicked()
{
    staff->show();
}

void Manager::on_reviewsButton_clicked()
{
   QDesktopServices::openUrl(QUrl("https://chumaknadya19.wixsite.com/mysite"));
}
