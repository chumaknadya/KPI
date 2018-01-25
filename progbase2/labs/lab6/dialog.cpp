#include "dialog.h"
#include "ui_dialog.h"
#include "computer_game.h"
#include "mainwindow.h"
#include <vector>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}
QString Dialog::lineEditFullname() const
{

    return ui->fullnameLineEdit->text();
}
QString Dialog::lineEditGenre() const
{
    return ui->GenreLineEdit->text();
}
QString Dialog::lineEditPlatform() const
{
    return ui->platformLineEdit->text();
}
int  Dialog::yearSpinBox() const
{
    return ui->yearSpinBox->value();
}
float  Dialog::raitingSpinBox() const
{
    return ui->doubleSpinBox->value();
}
int  Dialog::NumberSpinBox() const
{
    return ui->NumberSpinBox->value();
}
void Dialog::on_buttonBox_accepted()
{
    accept();

}
