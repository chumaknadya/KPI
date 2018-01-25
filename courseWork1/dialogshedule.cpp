#include "dialogshedule.h"
#include "ui_dialogshedule.h"

DialogShedule::DialogShedule(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogShedule)
{
    ui->setupUi(this);
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
