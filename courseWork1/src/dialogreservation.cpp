#include "dialogreservation.h"
#include "ui_dialogreservation.h"

DialogReservation::DialogReservation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogReservation)
{
    ui->setupUi(this);
    addItemToPaymentMethodComboBox();
    addItemToWayToOrderComboBox();
    QPalette * palette = new QPalette();
    palette->setBrush(this->backgroundRole(), QBrush(QPixmap(":/doc/aesthetic-background-gradient-green-Favim.com-2877559.jpg")));
    this->setPalette(*palette);
    moveToCenter();
}
void DialogReservation::moveToCenter() {
    QDesktopWidget desktop;
    QRect rect = desktop.availableGeometry(desktop.primaryScreen()); // прямоугольник с размерами экрана
    QPoint center = rect.center(); //координаты центра экрана
    center.setX(center.x() - (this->width()/2));  // учитываем половину ширины окна
    center.setY(center.y() - (this->height()/2));  // .. половину высоты
    move(center);
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
double DialogReservation::get_Cost() const
{
    return ui->spinBox->value();
}
QString DialogReservation::get_LengthOfStaying() const
{
    return ui->lineEdit->text();
}
QString DialogReservation::get_PaymentMethod() const
{
   return ui->paymentmethodcomboBox->currentText();
}
QString DialogReservation::get_WayToOrder() const
{
   return ui->waytoordercomboBox->currentText();
}
void DialogReservation::setData(QString & client,QString & serviceProvider,
                                QString & lengthOfStaying,QString & paymentMethod,
                                QString & wayToOrder,int cost ) {
    ui->lineEdit->setText(lengthOfStaying);
    ui->servicelineEdit->setText(serviceProvider);
    ui->clientlineEdit->setText(client);
    ui->spinBox->setValue(cost);
    ui->paymentmethodcomboBox->setItemText(0,paymentMethod);
     ui->waytoordercomboBox->setItemText(0,wayToOrder);
}




