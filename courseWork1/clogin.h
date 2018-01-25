#ifndef CLOGIN_H
#define CLOGIN_H

#include <QDialog>
#include "administrator.h"
#include "doorman.h"
#include "director.h"
#include "housemaid.h"
#include "manager.h"
#include "clogin.h"
#include <QWidget>
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include "QtSql/QSqlError"
#include "QtSql/QSqlQuery"
#include <QFileInfo>
namespace Ui {
class Clogin;
}

class Clogin : public QDialog
{
    Q_OBJECT

public:
    explicit Clogin(QWidget *parent = 0);
    ~Clogin();

private slots:
    void on_LogInButton_clicked();
  //  QString lineEditUserName() const;
   // QString lineEditPassword() const;



private:
    Ui::Clogin *ui;
    QSqlDatabase myDB;
};

#endif // CLOGIN_H



