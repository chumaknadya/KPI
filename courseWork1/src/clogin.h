#ifndef CLOGIN_H
#define CLOGIN_H
#include <QDesktopWidget>
#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <QPalette>
#include <QBrush>
#include <QWidget>
#include <QDebug>
#include "QSqlQuery"
#include "QtSql/QSqlDatabase"
#include "QtSql/QSqlError"
#include "QtSql/QSqlQuery"
#include <QFileInfo>
#include "director.h"
#include "administrator.h"
#include "doorman.h"
#include "housemaid.h"
#include "manager.h"
namespace Ui {
class Clogin;
}

class Clogin : public QDialog
{
    Q_OBJECT

public:
 //   QSqlDatabase myDB;
//    void connClose() {
//        myDB.close();
//        myDB.removeDatabase(QSqlDatabase::defaultConnection);
//    }

//    bool connOpen() {
//            myDB = QSqlDatabase::addDatabase("QSQLITE");
//            myDB.setDatabaseName("/home/ziom/progbase3/progbase3/cursova/staff");
//            QFileInfo checkFile("/home/ziom/progbase3/progbase3/cursova/staff");
//            if (checkFile.isFile()) {
//                if(myDB.open()) {
//                    qDebug()<<"Connected";
//                    return true;
//                }
//            } else {
//                    qDebug()<<"Failed";
//                    return false;
//            }
//    }

    explicit Clogin(QWidget *parent = 0);
    ~Clogin();

private slots:
    void on_LogInButton_clicked();
private:

    Ui::Clogin *ui;
    Director * direct;
    Administrator * admin;
    Manager * manager;
    Housemaid * house_maid;
    Doorman * door_man;
    QSqlDatabase myDB;
};

#endif // CLOGIN_H



