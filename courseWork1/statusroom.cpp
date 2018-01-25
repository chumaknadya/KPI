#include "statusroom.h"
#include "ui_statusroom.h"
#include <QFileDialog>
#include <QDesktopServices>
#include <QUrl>
#include <QDialog>
#include <QDebug>
#include <statusdialog.h>
StatusRoom::StatusRoom(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StatusRoom)
{
    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->resizeSections(QHeaderView::ResizeToContents);
    ui->tableWidget->hideColumn(0);


    ui->tableWidget->setSelectionBehavior( QAbstractItemView::SelectItems );
    ui->tableWidget->setSelectionMode( QAbstractItemView::SingleSelection );

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
//    for (int i = 0; i < ui->tableWidget->rowCount();i++) {
//         for (int j = 0; j <  ui->tableWidget->columnCount();j++) {
//             if(ui->tableWidget->item(i,3)->text() == "Cleaned") {
//                    ui->tableWidget->item(i,3)->setBackground(Qt::green);
//              }else {
//                    ui->tableWidget->item(i,3)->setBackground(Qt::red);
//                }
//         }
//    }

     create_table();
}

StatusRoom::~StatusRoom()
{
    database.close();
    delete ui;

}
void StatusRoom::create_table() {
        QSqlQuery q(database);


        int num_rows,r,c;
        if(!q.exec("SELECT count(id) as num_rows FROM status_room"))
         {
              qDebug() << q.lastError().text();
         }
        //(SELECT length_of_stay FROM reservation WHERE id = state_id)
        q.first();
        num_rows = q.value(0).toInt();
        ui->tableWidget->setRowCount(num_rows);
        if(!q.exec("SELECT id, number, data,status  FROM status_room ORDER BY id")){
               qDebug() << q.lastError().text();
        }
        int count = 10;
        for(r = 0,q.first(); q.isValid(); q.next(),++r) {
            for (c = 0;c < count;++c) {
                ui->tableWidget->setItem(r,c,new QTableWidgetItem(q.value(c).toString()));
             }
        }
        for (int i = 0; i < ui->tableWidget->rowCount();i++) {
             for (int j = 0; j <  ui->tableWidget->columnCount();j++) {
                 if(ui->tableWidget->item(i,3)->text() == "Cleaned") {
                        ui->tableWidget->item(i,3)->setBackground(Qt::green);
                  }else {
                        ui->tableWidget->item(i,3)->setBackground(Qt::red);
                    }
             }
        }
}


void StatusRoom::on_tableWidget_cellDoubleClicked(int row, int column)
{


            StatusDialog dialog;

//            for (int i = 0; i < ui->tableWidget->rowCount();i++) {
//                 for (int j = 0; j <  ui->tableWidget->columnCount();j++) {
//                     if(ui->tableWidget->item(i,3)->text() == "Cleaned") {
//                            ui->tableWidget->item(i,3)->setBackground(Qt::green);
//                      }else {
//                            ui->tableWidget->item(i,3)->setBackground(Qt::red);
//                        }
//                 }
//            }



          if (dialog.exec()) {

           qDebug() << "Accepted!";

           int id = ui->tableWidget->item(row,0)->text().toInt();

            QString data = dialog.get_Time();
            //qDebug << name.toStdString() ;
            QString status("");

            if (dialog.get_Status()){
                status = "Cleaned";

            } else {
                status  = "Uncleaned";

            }



            QSqlQuery query(database);
            query.exec("UPDATE status_room SET data = '" + data + "', status = '" + status +
                       "' WHERE id = " + QString::number(id) + "");
            qDebug() <<"UPDATE status_room SET data = '" + data + "', status = '" + status +
                       "' WHERE id = " + QString::number(id) + "";
               create_table();
          } else {
              qDebug() << "no";
        }



}
