#include "staff.h"
#include "ui_staff.h"
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include <QDebug>
#include <QFileDialog>
#include <QDesktopServices>
#include <QUrl>
#include <QDialog>
#include "clogin.h"
#include <QErrorMessage>
#include <formworkers.h>
#include <QCompleter>
#include <QMessageBox>

Staff::Staff(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Staff)
{
    ui->setupUi(this);

    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("/home/ziom/progbase3/progbase3/cursova/staff");
    QFileInfo checkFile("/home/ziom/progbase3/progbase3/cursova/staff");
    if (checkFile.isFile()) {
        if(database.open()) {
            ui->label->setText("Connected");
        }
    } else {
       ui ->label->setText("Failed");
    }

    QPalette pal(ui->tableWidget->horizontalHeader()->palette());
     pal.setColor(QPalette::Button, Qt::red);
      ui->tableWidget->horizontalHeader()->setPalette(pal);
    ui->tableWidget->hideColumn(0);
 //   ui->tableWidget->setStyleSheet("QTableView{selection-background-color: #ece9d8;selection-color: #FFFFFF}");
    ui->tableWidget->setStyleSheet(
                    "QTableView::item:selected:active {"
                    "background: rgb(191, 255,191);"
                    "border: 1px solid transparent;"
                    "selection-color: #f00;"
                    "}"

                    "QTableView::item:selected:!active {"
                    "background: rgb(191, 255,191);"
                    "border: 1px solid transparent;"
                    "selection-color: #f00;"
                    "}"
                    );
//    QTableWidgetItem* item = new QTableWidgetItem;
//           item->setIcon( QIcon( "/home/ziom/Завантаження/boss_woman-512.png" ));
//             ui->tableWidget->setItem( 1, 2, item );
//    ui->tableWidget->setShowGrid(true);
//      ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
   //  ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    //  ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
     create_table_of_staff();
//         qDebug()<< staff.lastError().text();
//     }
//     else {
//        ui->label->setText("Connected");
//     }
//    auto table = ui->tableWidget;
//    table->setColumnCount(6);
//    table->setColumnCount(6);
   // id,name,surname,birthdate,email,status,salary
     // ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"Id"<<"Name"<< "Surname"<<"Birthdate"<<"Email"<<"Status"<<"Salary");
   //    table->setVerticalHeaderLabels(QStringList()<<"1"<< "2"<<"3"<<"4"<<"5"<<"6");
   // QSqlDatabase staff;
//    staff = QSqlDatabase::addDatabase("QSQLITE");
//    staff.setDatabaseName("/home/ziom/progbase3/progbase3/cursova/staff");
//    if(!staff.open()) {
//       qDebug()<< staff.lastError().text();
//    }
//    ui->tableWidget->hideColumn(0);
//    create_table_of_staff();

   // table->setStyleSheet("QTableView {selection-background-color: red;}"); // you can use CSS

}

Staff::~Staff()
{
    qDebug() << "Closing the connection to DB";
    database.close();
   // database.removeDatabase(QSqlDatabase::defaultConnection);
    delete ui;
}


void Staff::create_table_of_staff () {
         QSqlQuery q(database);


         int num_rows,r,c;
         if(!q.exec("SELECT count(id) as num_rows FROM workstaff"))
          {
               qDebug()<< q.lastError().text();
          }
         q.first();
         num_rows = q.value(0).toInt();
         ui->tableWidget->setRowCount(num_rows);
         if(!q.exec("SELECT id, name, surname, birthdate, email, status, salary FROM workstaff ORDER BY id")){
                qDebug()<< q.lastError().text();
         }
         int count = 7;
         for(r = 0,q.first(); q.isValid(); q.next(),++r) {
             for (c = 0;c < count;++c) {
                 ui->tableWidget->setItem(r,c,new QTableWidgetItem(q.value(c).toString()));
              }
         }



}




/*void Staff::on_openpushButton_clicked()
{
//      QSqlQueryModel *modal = new QSqlQueryModel();

//      QSqlQuery *query = new  QSqlQuery(database);
//      query->prepare("SELECT * from users");
//      query->exec();
//      modal->setQuery(*query);
//      ui->tableView->setModel(modal);
//      qDebug() << (modal);
}*/

void Staff::on_AddpushButton_clicked()
{
       FormWorkers staff;
       QString stringEmail = "email@gmail.com";
       QString stringName = "Elena";
       QString stringSurname = "Prekrasnaya";
       QString stringStatus = "administrator";
       QString stringBirthdate= "12-05-1967";
       QString stringID = "12";
       QString stringSalary = "100";
       staff.setEmail(stringEmail);
       staff.setName(stringName);
       staff.setSurname(stringSurname);
       staff.setStatus(stringStatus);
       staff.setBirthdate(stringBirthdate);
       //staff.setID(stringID);

       //staff.setSalary(stringSalary);

       staff.setWindowTitle("Add worker");
       if (staff.exec()) {
          // staff.defaultText();
         qDebug() << "Accepted!";
        // int id = staff.get_ID();
         QString name = staff.get_Name();
         //qDebug << name.toStdString() ;
         QString surname = staff.get_Surname();
        // qDebug<< surname.toStdString() ;
         QString birthdate = staff.get_Birthdate();
        // qDebug<< birthdate.toStdString() ;
         QString status = staff.get_Status();
        // qDebug<< status.toStdString();
         QString email = staff.get_Email();
        // qDebug<< email.toStdString() ;
         double salary = staff.get_Salary();


       QSqlQuery q(database);
       q.prepare("INSERT INTO workstaff(name, surname, birthdate, email, status, salary)"
                     "VALUES ( ?, ?, ?, ?, ?,?)");
                        //q.addBindValue(id);
                        q.addBindValue(name);
                        q.addBindValue(surname);
                        q.addBindValue(birthdate);
                        q.addBindValue(email);
                        q.addBindValue(status);
                        q.addBindValue(salary);

                        q.exec();
                        create_table_of_staff ();

       }else {
           qDebug() << "Rejected!";
      }



}

void Staff::on_DeletepushButton_clicked()
{

        QModelIndex curr = ui->tableWidget->currentIndex();
        int index = curr.sibling(curr.row(), 0).data ().toInt ();
        QSqlQuery q(database);
        q.prepare("DELETE FROM workstaff WHERE (id = "+QString::number(index)+")");
        q.exec();
        create_table_of_staff();


}


void Staff::on_lineEdit_cursorPositionChanged(int arg1, int arg2)
{
    QStringList wordList;
    for ( int i = 0 ; i < ui->tableWidget->rowCount();i++) {
        for (int j = 0; j < ui->tableWidget->columnCount();j++) {
            QTableWidgetItem *item = ui->tableWidget->item( i, j );
            wordList << item->text();
        }
    }

    QCompleter *completer = new QCompleter(wordList,this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    completer->setCompletionMode(QCompleter::PopupCompletion);
    //PopupCompletion InlineCompletion
    ui->lineEdit->setCompleter(completer);
    QString filter = ui->lineEdit->text();
    for( int i = 0; i < ui->tableWidget->rowCount(); ++i )
    {
        bool match = false;
        for( int j = 0; j < ui->tableWidget->columnCount(); ++j )
        {
            QTableWidgetItem *item = ui->tableWidget->item( i, j );
            if( item->text().contains(filter) )
            {
                match = true;
                break;
            }
        }
        ui->tableWidget->setRowHidden( i, !match );
    }
}

void Staff::on_tableWidget_cellDoubleClicked(int row, int column)
{

      FormWorkers staff;
      QString stringEmail = ui->tableWidget->item(row,4)->text();
      QString stringName =  ui->tableWidget->item(row,1)->text() ;
      QString stringSurname = ui->tableWidget->item(row,2)->text();
      QString stringStatus = ui->tableWidget->item(row,5)->text();
      QString stringBirthdate= ui->tableWidget->item(row,3)->text();
      QString stringID = "12";
      double salary = ui->tableWidget->item(row,6)->text().toDouble();
      staff.setData(stringName,stringSurname,stringBirthdate,stringEmail,stringStatus,salary);
      staff.setWindowTitle("Add worker");
      if (staff.exec()) {

       qDebug() << "Accepted!";
        //int id = staff.get_ID();
       int id = ui->tableWidget->item(row,0)->text().toInt();
         //int id = ui->tableWidget->it,0)->text();
        QString name = staff.get_Name();
        //qDebug << name.toStdString() ;
        QString surname = staff.get_Surname();
       // qDebug<< surname.toStdString() ;
        QString birthdate = staff.get_Birthdate();
       // qDebug<< birthdate.toStdString() ;
        QString status = staff.get_Status();
       // qDebug<< status.toStdString();
        QString email = staff.get_Email();
       // qDebug<< email.toStdString() ;
        double salary = staff.get_Salary();
        qDebug() << status ;
        QSqlQuery query(database);
        query.exec("UPDATE workstaff SET name = '" + name+ "', surname = '" + surname +
               "',  birthdate = '" + birthdate + "', email = '" + email +
               "',status = '" + status +
               "', salary = " + QString::number(salary) + " WHERE id = " + QString::number(id) + "");
        qDebug() <<"UPDATE workstaff SET name = '" + name+ "', surname = '" + surname +
           "',  birthdate = '" + birthdate + "', email = '" + email +
           "',status = " + status +
           ", salary = " + QString::number(salary)
           +", id = " +
           QString::number(id) +"' WHERE id = " + QString::number(id) + "";
   create_table_of_staff();
      } else {
          qDebug() << "vu o";
      }

}


