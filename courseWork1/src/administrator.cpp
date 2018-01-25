#include "administrator.h"
#include "ui_administrator.h"

Administrator::Administrator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Administrator)
{
    ui->setupUi(this);
    shedule = new WorkShedule();
    connect(shedule, &WorkShedule::sheduleWindow, this, &Administrator::show);

    scheme = new Scheme();
    connect(scheme, &Scheme::viewWindow, this, &Administrator::show);

    reservation = new Reservation();
    connect(reservation, &Reservation::reservationWindow, this, &Administrator::show);
    QPalette * palette = new QPalette();
    palette->setBrush(this->backgroundRole(), QBrush(QPixmap(":/doc/gradient-background-2560x1600.jpg")));
    this->setPalette(*palette);
    moveToCenter();
}
void Administrator::moveToCenter() {
    QDesktopWidget desktop;
    QRect rect = desktop.availableGeometry(desktop.primaryScreen()); // прямоугольник с размерами экрана
    QPoint center = rect.center(); //координаты центра экрана
    center.setX(center.x() - (this->width()/2));  // учитываем половину ширины окна
    center.setY(center.y() - (this->height()/2));  // .. половину высоты
    move(center);
}
Administrator::~Administrator()
{
    delete ui;
}

void Administrator::on_sheduleButton_clicked()
{
    shedule->show();
}

void Administrator::on_reservationButton_clicked()
{
    reservation->show();
}

void Administrator::on_schemeButton_clicked()
{
    scheme->show();
}
