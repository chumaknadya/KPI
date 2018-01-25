#include "dialogreservation.h"
#include "ui_dialogreservation.h"

DialogReservation::DialogReservation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogReservation)
{
    ui->setupUi(this);
    addItemToPaymentMethodComboBox();
    addItemToWayToOrderComboBox();
}

DialogReservation::~DialogReservation()
{
    delete ui;
}
void DialogReservation::addItemToPaymentMethodComboBox() {
   ui->paymentmethodcomboBox->addItem("Credit");
   ui->paymentmethodcomboBox->addItem("Cash");
   ui->paymentmethodcomboBox->addItem("Check");
}
void DialogReservation::addItemToWayToOrderComboBox() {
   ui->waytoordercomboBox->addItem("orders received");
   ui->waytoordercomboBox->addItem("the order will be received personally");
   ui->waytoordercomboBox->addItem("order sent");
   ui->waytoordercomboBox->addItem("order be sending");
}
QString DialogReservation::get_Client() const
{
    return ui->clientlineEdit->text();
}
QString DialogReservation::get_ServiceProvider() const
{
    return ui->servicelineEdit->text();
}
QString DialogReservation::get_Cost() const
{
    return ui->spinBox->value();
}
QString DialogReservation::get_LengthOfStaying() const
{
    return ui->dateTimeEdit->text();
}
void DialogReservation::setData() {

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
int  FormWorkers::get_ID() const
{
    return ui->IDspinBox->value();
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
void FormWorkers::setID(QString & data) {

   ui->IDspinBox->setSpecialValueText(data);
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
