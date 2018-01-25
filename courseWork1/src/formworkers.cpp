#include "formworkers.h"
#include "ui_formworkers.h"
#include <QLineEdit>
#include <QMessageBox>
#include <QDebug>
#include <QTimer>
using namespace::std;
FormWorkers::FormWorkers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FormWorkers)


{
    ui->setupUi(this);
    QPalette * palette = new QPalette();
    palette->setBrush(this->backgroundRole(), QBrush(QPixmap(":/doc/fonstola.ru-55713.jpg")));
    this->setPalette(*palette);



}
void FormWorkers::moveToCenter() {
    QDesktopWidget desktop;
    QRect rect = desktop.availableGeometry(desktop.primaryScreen()); // прямоугольник с размерами экрана
    QPoint center = rect.center(); //координаты центра экрана
    center.setX(center.x() - (this->width()/2));  // учитываем половину ширины окна
    center.setY(center.y() - (this->height()/2));  // .. половину высоты
    move(center);
}


FormWorkers::~FormWorkers()
{
    delete ui;
}
QString FormWorkers::get_Name() const
{
    return ui->NamelineEdit->text();
}
QString FormWorkers::get_Surname() const
{
    return ui->SurnamelineEdit->text();
}
QString FormWorkers::get_Email() const
{
    return ui->EmaillineEdit->text();
}
QString FormWorkers::get_Status() const
{
    return ui->StatuslineEdit->text();
}
QString FormWorkers::get_Birthdate() const
{
   return ui->BirthdatelineEdit->text();
}

double  FormWorkers::get_Salary() const
{
    return ui->SalarydoubleSpinBox->value();
}
void FormWorkers::setEmail(QString & data) {
  ui->EmaillineEdit->setPlaceholderText(data);
}
void FormWorkers::setSurname(QString & data) {
  ui->SurnamelineEdit->setPlaceholderText(data);
}
void FormWorkers::setName(QString & data) {
   ui->NamelineEdit->setPlaceholderText(data);
}
void FormWorkers::setBirthdate(QString & data) {
    ui->BirthdatelineEdit->setPlaceholderText(data);
}
void FormWorkers::setStatus(QString & data) {
    ui->StatuslineEdit->setPlaceholderText(data);
}

void FormWorkers::setSalary(QString & data) {
   ui->SalarydoubleSpinBox->setPrefix(data);
}
void FormWorkers::setData(QString & name,QString & surname,QString & birthdate,QString & email,QString & status,double salary) {
      ui->EmaillineEdit->setText(email);
      ui->SurnamelineEdit->setText(surname);
      ui->NamelineEdit->setText(name);
      ui->BirthdatelineEdit->setText(birthdate);
      ui->StatuslineEdit->setText(status);

      ui->SalarydoubleSpinBox->setValue(salary);
}







void FormWorkers::on_NamelineEdit_editingFinished()
{

    QString strName =  ui->NamelineEdit->text();
   // qDebug()<<strName;
    if(!strName.isEmpty()) {
        QChar ch = strName.at(0);
        if(!ch.isUpper()) {
        QMessageBox::critical(
              this,
              tr("Error"),
              tr("Please, enter a name with a capital letter"));
        }
    }


}

void FormWorkers::on_SurnamelineEdit_editingFinished()
{

    QString surname =  ui->SurnamelineEdit->text();
    if(!surname.isEmpty()) {
        QChar ch = surname.at(0);
        if(!ch.isUpper()) {
        QMessageBox::critical(
          this,
          tr("Error"),
          tr("Please, enter a surname with a capital letter"));
        }
    }

}

void FormWorkers::on_BirthdatelineEdit_editingFinished()
{

  QString strBirth =  ui->SurnamelineEdit->text();
  if(!strBirth.isEmpty()) {
      QString date("");
      QString month("");
      QString year("");
  }
}

void FormWorkers::on_EmaillineEdit_editingFinished()
{

}

void FormWorkers::on_StatuslineEdit_editingFinished()
{

}



