#include "housemaid.h"
#include "ui_housemaid.h"

Housemaid::Housemaid(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Housemaid)
{
    ui->setupUi(this);
}

Housemaid::~Housemaid()
{
    delete ui;
}
