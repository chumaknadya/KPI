#include "clogin.h"
#include "ui_clogin.h"


Clogin::Clogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Clogin)
{
    ui->setupUi(this);
    direct = new Director();

    connect(direct, &Director::firstWindow, this, &Clogin::show);
    admin = new Administrator();

    connect(admin, &Administrator::secondWindow, this, &Clogin::show);
    door_man = new Doorman();
    connect(door_man, &Doorman::thirdWindow, this, &Clogin::show);
    house_maid = new Housemaid();
    connect(house_maid, &Housemaid::fourthWindow, this, &Clogin::show);
    manager = new Manager();
    connect(manager, &Manager::fifthWindow, this, &Clogin::show);
    QPalette * palette = new QPalette();
    palette->setBrush(this->backgroundRole(), QBrush(QPixmap(":/doc/gradient15.png")));
    this->setPalette(*palette);

    myDB = QSqlDatabase::addDatabase("QSQLITE");
    myDB.setDatabaseName("/home/ziom/progbase3/progbase3/cursova/staff");
    QFileInfo checkFile("/home/ziom/progbase3/progbase3/cursova/staff");
    if (checkFile.isFile()) {
        if(myDB.open()) {
            ui->label->setText("Connected");
        }
    } else {
            ui ->label->setText("Failed");
    }


}

Clogin::~Clogin()
{
    delete ui;

}

void Clogin::on_LogInButton_clicked()
{
    auto director = "director";
    auto manag = "manager";
    auto doorman = "doorman";
    auto administrator = "administrator";
    auto housemaid = "housemaid";
    if(!myDB.isOpen()){
        qDebug() << "No connection to db";
        return;
    }
    QString Username, Password;
    Username = ui->usernamelineEdit->text();
    Password = ui->PasswordlineEdit->text();
    QSqlQuery qry;
    if(qry.exec("SELECT username, password, role FROM users WHERE username =\'" + Username + "\' AND password=\'" + Password + "\'"))
    {

        if(qry.next()) {
             ui->label->setText("[+] Valid Username and Password");
             QString msg = "Username = " + qry.value(0).toString() + "\n " +
             "Password = " + qry.value(1).toString() + " \n " +
             "Role = " + qry.value(2).toString();
             QMessageBox::warning(this,"Login was successful",msg);
             this->hide();
             if(qry.value(2).toString() == director) {
                           // connClose();
                            direct->show();
                            this->close();

             }
             if(qry.value(2).toString() == manag) {

                          qDebug() << "Closing the connection to DB";
                          manager->show();

//                          myDB.close();
//                          myDB.removeDatabase(QSqlDatabase::defaultConnection);

             }
            if(qry.value(2).toString() == doorman) {
                         qDebug() << "Closing the connection to DB";
                         door_man->show();
                         this->close();
             }
             if(qry.value(2).toString() == housemaid) {
                           qDebug() << "Closing the connection to DB";
                           house_maid->show();
                           this->close();
             }
             if(qry.value(2).toString() == administrator) {
                           qDebug() << "Closing the connection to DB";
                              admin->show();
                              this->close();

             }

        } else {

            QMessageBox::critical(
                  this,
                  tr("Error"),
                  tr("Wrong username or password") );

            ui->PasswordlineEdit->clear();
            ui->usernamelineEdit->clear();
        }
    }


}




