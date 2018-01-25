#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "administrator.h"
#include "doorman.h"
#include "director.h"
#include "housemaid.h"
#include "manager.h"
#include <QWidget>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("background-image: url(/home/ziom/Завантаження/siniy_pyatna_fon_odnotonnyy_2560x1600.jpg)");
   // this->setWindowFlags(Qt::FramelessWindowHint);// skril schappky formu
   // this->setAttribute(Qt::gray);
   // this->setAttribute(Qt::WA_TranslucentBackground);
}

MainWindow::~MainWindow()
{
    delete ui;
}






void MainWindow::on_signInButton_clicked()
{
    Clogin   login;
    login.exec();
}
