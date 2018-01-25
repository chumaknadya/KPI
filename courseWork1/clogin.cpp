#include "clogin.h"
#include "ui_clogin.h"
#include <QDebug>
#include <QMessageBox>
//#define PATH_TO_DB("/home/ziom/progbase3/progbase3/cursova/staff");
Clogin::Clogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Clogin)
{
    ui->setupUi(this);

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
    //qDebug() << "Closing the connection to DB";
   // myDB.close();
}
void Clogin::on_LogInButton_clicked()
{
         auto director = "director";
         auto manager = "manager";
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
    if(qry.exec("SELECT username,password,role FROM users WHERE username =\'" + Username + "\' AND password=\'" + Password + "\'"))
    {

        if(qry.next()) {
             ui->label->setText("[+] Valid Username and Password");
             QString msg = "Username = " + qry.value(0).toString() + "\n " +
             "Password =" + qry.value(1).toString() + " \n " +
             "Role =" + qry.value(2).toString();
             QMessageBox::warning(this,"Login was successful",msg);
              this->hide();
             if(qry.value(2).toString() == director) {
                          qDebug() << "Closing the connection to DB";
                          myDB.close();
                           myDB.removeDatabase(QSqlDatabase::defaultConnection);
                          Director  director;
                          director.exec();
             }
             if(qry.value(2).toString() == manager) {
                          qDebug() << "Closing the connection to DB";
                          myDB.close();
                          myDB.removeDatabase(QSqlDatabase::defaultConnection);
                          Manager   manager;
                          manager.exec();
             }
            if(qry.value(2).toString() == doorman) {
                         qDebug() << "Closing the connection to DB";
                          myDB.close();
                           myDB.removeDatabase(QSqlDatabase::defaultConnection);
                          Doorman  doorman;
                          doorman.exec();
             }
             if(qry.value(2).toString() == housemaid) {
                           qDebug() << "Closing the connection to DB";
                           myDB.close();
                            myDB.removeDatabase(QSqlDatabase::defaultConnection);
                           Housemaid housemaid;
                           housemaid.exec();
             }
             if(qry.value(2).toString() == administrator) {
                           qDebug() << "Closing the connection to DB";
                           myDB.close();
                           myDB.removeDatabase(QSqlDatabase::defaultConnection);
                           Administrator administrator;
                           administrator.exec();
             }

        } else {
            ui->label->setText("Wrong username or password");
            ui->PasswordlineEdit->clear();
            ui->usernamelineEdit->clear();
        }
    }


}
//    //ui->LogInButton->setStyle();
//     ui->LogInButton->setStyleSheet("background-color: rgb(0, 170, 255); border: 1px solid black; border-radius: 15px;");
//   // ui->LogInButton->setStyleSheet(" background-color: red;border-style: outset; border-width: 2px;   border-radius: 10px;border-color: beige;font: bold 14px;  min-width: 10em; padding: 5px;");
//    auto password =  ui->PasswordlineEdit->text();
//    auto username =  ui->usernamelineEdit->text();

//     qDebug()<< username;
//     qDebug()<< password;
//     auto director = "director";
//     auto manager = "manager";
//     auto doorman = "doorman";
//     auto administrator = "administrator";
//     auto housemaid = "housemaid";
//     auto directorPassword = "1234";
//     auto managerPassword = "2345";
//     auto doormanPassword = "3456";
//     auto administratorPassword = "4567";
//     auto housemaidPassword = "5678";

//     if (director == username && directorPassword == password) {
//         Director  director;
//         director.exec();
//     }
//     if (manager == username && managerPassword == password) {
//         Manager   manager;
//         manager.exec();

//     }
//     if (doorman == username && doormanPassword == password) {
//         Doorman  doorman;
//         doorman.exec();
//     }
//     if (housemaid == username && housemaidPassword == password) {
//          Housemaid housemaid;
//          housemaid.exec();
//     }
//     if (administrator == username && administratorPassword == password) {
//          Administrator administrator;
//          administrator.exec();
//     }



