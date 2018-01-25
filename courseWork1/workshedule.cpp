#include "workshedule.h"
#include "ui_workshedule.h"
#include <QDebug>
#include <QFileDialog>
#include <QDesktopServices>
#include <QUrl>

WorkShedule::WorkShedule(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WorkShedule)
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
//   ui->tableWidget->setShowGrid(true);
//   ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
//   ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
//    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->hideColumn(0);
    create_table();
    for(int j = 0;  j < 5 ; j++){
         ui->tableWidget->item(j,1)->setBackground(Qt::yellow);
    }
    for(int j = 0;  j < 5 ; j++){
         ui->tableWidget->item(j,2)->setBackground(Qt::cyan);
    }
    for(int j = 0;  j < 5 ; j++){
         ui->tableWidget->item(j,3)->setBackground(QColor(255, 0, 0, 127));
    }
    for(int j = 0;  j < 5 ; j++){
         ui->tableWidget->item(j,4)->setBackground(QColor(0, 100, 55, 212));
    }
    for(int j = 0;  j < 5 ; j++){
         ui->tableWidget->item(j,5)->setBackground(QColor(100, 30, 4, 127));
    }
    for(int j = 0;  j < 5 ; j++){
         ui->tableWidget->item(j,6)->setBackground(QColor(212,175,55, 127));
    }
    for(int j = 0;  j < 5 ; j++){
         ui->tableWidget->item(j,7)->setBackground(QColor(127,4,78, 127));
    }
    for(int j = 0;  j < 5 ; j++){
         ui->tableWidget->item(j,8)->setBackground(Qt::red);
    }
}

WorkShedule::~WorkShedule()
{
    delete ui;
    qDebug()<< "cloose";
    database.close();
}
void WorkShedule::create_table () {
         QSqlQuery q(database);


         int num_rows,r,c;
         if(!q.exec("SELECT count(id) as num_rows FROM work_shedule"))
          {
               qDebug()<< q.lastError().text();
          }
         q.first();
         num_rows = q.value(0).toInt();
         ui->tableWidget->setRowCount(num_rows);
         if(!q.exec("SELECT id, role, monday, tuesday, wednesday, thursday, friday,saturday,sunday FROM work_shedule ORDER BY id")){
                qDebug()<< q.lastError().text();
         }
         int count = 9;
         for(r = 0,q.first(); q.isValid(); q.next(),++r) {
             for (c = 0;c < count;++c) {
                 ui->tableWidget->setItem(r,c,new QTableWidgetItem(q.value(c).toString()));
              }
         }
}
