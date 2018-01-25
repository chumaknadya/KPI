#include "dialogshedule.h"
#include "ui_dialogshedule.h"

DialogShedule::DialogShedule(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogShedule)
{
    ui->setupUi(this);
    QPalette * palette = new QPalette();
    palette->setBrush(this->backgroundRole(), QBrush(QPixmap(":/doc/gradient-background-2560x1600.jpg")));
    this->setPalette(*palette);
    moveToCenter();
}
void DialogShedule::moveToCenter() {
    QDesktopWidget desktop;
    QRect rect = desktop.availableGeometry(desktop.primaryScreen()); // прямоугольник с размерами экрана
    QPoint center = rect.center(); //координаты центра экрана
    center.setX(center.x() - (this->width()/2));  // учитываем половину ширины окна
    center.setY(center.y() - (this->height()/2));  // .. половину высоты
    move(center);
}
DialogShedule::~DialogShedule()
{
    delete ui;
}
bool DialogShedule::get_Monday() const
{

    return ui->mondaycheckBox->isChecked();
}
bool DialogShedule::get_Tuesday() const
{

    return ui->tuesdaycheckBox->isChecked();
}
bool DialogShedule::get_Wednesday() const
{

    return ui->wednesdaycheckBox->isChecked();
}
bool DialogShedule::get_Thursday() const
{

    return ui->thursdaycheckBox->isChecked();
}
bool DialogShedule::get_Friday() const
{

    return ui->fridaycheckBox->isChecked();
}

bool DialogShedule::get_Saturday() const
{

    return ui->saturdaycheckBox->isChecked();
}
bool DialogShedule::get_Sunday() const
{

    return ui->sundaycheckBox->isChecked();
}
