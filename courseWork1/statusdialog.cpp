#include "statusdialog.h"
#include "ui_statusdialog.h"

StatusDialog::StatusDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StatusDialog)
{
    ui->setupUi(this);
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
