#include "statusdialog.h"
#include "ui_statusdialog.h"

StatusDialog::StatusDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StatusDialog)
{
    ui->setupUi(this);
    QPalette * palette = new QPalette();
    palette->setBrush(this->backgroundRole(), QBrush(QPixmap(":/doc/51076.jpg")));
    this->setPalette(*palette);
    moveToCenter();
}
void StatusDialog::moveToCenter() {
    QDesktopWidget desktop;
    QRect rect = desktop.availableGeometry(desktop.primaryScreen()); // прямоугольник с размерами экрана
    QPoint center = rect.center(); //координаты центра экрана
    center.setX(center.x() - (this->width()/2));  // учитываем половину ширины окна
    center.setY(center.y() - (this->height()/2));  // .. половину высоты
    move(center);
}
StatusDialog::~StatusDialog()
{
    delete ui;
}
bool StatusDialog::get_Status() const
{

    return ui->statusCheckBox->isChecked();
}
QString StatusDialog::get_Time() const
{
    return ui->dateTimeEdit->text();
}
