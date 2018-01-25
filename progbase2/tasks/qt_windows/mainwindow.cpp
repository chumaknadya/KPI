#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pensioner.h"
#include <QMessageBox>
#include <QDebug>
#include <QtGlobal>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("/home/ziom/progbase2/tasks/qt_windows/9fe03d62f48cc8b9c7aec22ae52283f2_295x197.jpg");
    ui->label_pic->setPixmap(pix);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_3_clicked()
{
    QMessageBox:: StandardButton reply = QMessageBox::question(this,
                                                          "Exit","Do you really want to exit?",
                                                          QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes){
        for (Pensioner * st : pensioners) {
               delete st;
        }
        QApplication::quit();

    }else {
        qDebug()<< "No is clicked";
    }
}
QString GetRandomString()
{
   const QString possibleCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");
   const int randomStringLength = 12; // assuming you want random strings of 12 characters

   QString randomString;
   for(int i=0; i<randomStringLength; ++i)
   {
       int index = qrand() % possibleCharacters.length();
       QChar nextChar = possibleCharacters.at(index);
       randomString.append(nextChar);
   }
   return randomString;
}
void MainWindow::on_pushButton_clicked()
{

   QString randomStringName = GetRandomString();
   QString randomStringSurname = GetRandomString();
   QString randomStringGrandchildrenName = GetRandomString();
   QString randomStringGrandchildrenSurname = GetRandomString();

   int randomValueDate = qrand() % 31;
   int randomValueYear = qrand() % 517 + 1500;
   ui->lineEdit->setText(randomStringName);
   ui->lineEdit_2->setText(randomStringSurname);
   ui->lineEdit_3->setText(randomStringGrandchildrenName);
   ui->lineEdit_4->setText(randomStringGrandchildrenSurname);
   ui->spinBox->setValue(randomValueDate);
   ui->spinBox_2->setValue(randomValueYear);

   QLineEdit * nameEdit = this->findChild<QLineEdit*>("lineEdit");
   QLineEdit * surnameEdit = this->findChild<QLineEdit*>("lineEdit_2");
   QLineEdit * grandchildrenNameEdit = this->findChild<QLineEdit*>("lineEdit_3");
   QLineEdit * grandchildrenSurnameEdit = this->findChild<QLineEdit*>("lineEdit_4");
   QSpinBox * dataBox = this->findChild<QSpinBox*>("spinBox");
   QSpinBox * ageBox = this->findChild<QSpinBox*>("spinBox_2");

   QString name = nameEdit->text();
   QString surname = surnameEdit->text();
   QString granchildrenName = grandchildrenNameEdit->text();
   QString grandchildrenSurname = grandchildrenSurnameEdit->text();
   int age = ageBox->value();
   int data = dataBox->value();

   Pensioner * newPensioner = new Pensioner;
   newPensioner->set_name(name.toStdString());
   newPensioner->set_surname(surname.toStdString());
   newPensioner->set_grandchildrenName(granchildrenName.toStdString());
   newPensioner->set_grandchildrenSurname(grandchildrenSurname.toStdString());
   newPensioner->set_age(age);
   newPensioner->set_data(data);


    this->pensioners.push_back(newPensioner);
    qDebug() << this->pensioners.size();
    newPensioner->print();

}

void MainWindow::on_pushButton_2_clicked()
{
   foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
      le->clear();
   }
}
