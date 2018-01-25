#include "doorman.h"
#include "ui_doorman.h"

Doorman::Doorman(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Doorman)
{
    ui->setupUi(this);
}

Doorman::~Doorman()
{
    delete ui;
}
