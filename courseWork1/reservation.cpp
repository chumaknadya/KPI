#include "reservation.h"
#include "ui_reservation.h"
#include <QFileDialog>
#include <QDesktopServices>
#include <QUrl>
#include <QDialog>
#include <QDebug>
#include "clogin.h"
#include <QErrorMessage>
#include "formworkers.h"
#include <QCompleter>
#include <QMessageBox>
#include "dialogreservation.h"
#include "hotelinform.h"
#include "qwordcompleter.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QDateTime>
Reservation::Reservation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Reservation)
{

    ui->setupUi(this);
    design();
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

     create_table();
     moveToCenter();
     ui->spinBox->clear();




}
void Reservation::moveToCenter() {
    QDesktopWidget desktop;
    QRect rect = desktop.availableGeometry(desktop.primaryScreen()); // прямоугольник с размерами экрана
    QPoint center = rect.center(); //координаты центра экрана
    center.setX(center.x() - (this->width()/2));  // учитываем половину ширины окна
    center.setY(center.y() - (this->height()/2));  // .. половину высоты
    move(center);
}

void Reservation::design() {
    ui->tableWidget->horizontalHeader()->resizeSections(QHeaderView::ResizeToContents);
    ui->tableWidget->hideColumn(0);
    ui->tableWidget->setSelectionBehavior( QAbstractItemView::SelectItems );
    ui->tableWidget->setSelectionMode( QAbstractItemView::SingleSelection );
    ui->tableWidget->setColumnWidth(4,100);
    ui->tableWidget->setColumnWidth(3,160);
    ui->tableWidget->setColumnWidth(6,200);
    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section { background-color: rgb(192, 237, 238)}");
    ui->tableWidget->verticalHeader()->setStyleSheet("QHeaderView::section { background-color: rgb(192, 237, 238)}");
    QPalette * palette = new QPalette();
    palette->setBrush(this->backgroundRole(), QBrush(QPixmap(":/doc/aesthetic-background-gradient-green-Favim.com-2877559.jpg")));
    this->setPalette(*palette);
}
void Reservation::currDate(){
    QDateTime curTime = QDateTime::currentDateTime();
    QString data = curTime.toString("dd.MM.yyyy");
    for ( int i = 0 ; i < ui->tableWidget->rowCount();i++) {


           QString stringOfLength = ui->tableWidget->item(i,7)->text();
           if(stringOfLength != " " && stringOfLength != "") {
               QStringList lengthOfStaying = ui->tableWidget->item(i,7)->text().split(": ");
               int  length = lengthOfStaying[1].toInt();
               qDebug()<<length;
               QString dateOfStaying = stringOfLength.left(10);
               qDebug()<<dateOfStaying;
               QDate Date = QDate::fromString(dateOfStaying,"dd.MM.yyyy");
               QDate dateDeparture = Date.addDays(length);
               QString dateOfDeparture = dateDeparture.toString("dd.MM.yyyy");
               qDebug()<<dateOfDeparture;
               if(dateOfDeparture == data) {
                   qDebug()<<"equals";
                   departure(i);
               }
           }

    }
}

Reservation::~Reservation()
{
    database.close();
    delete ui;
}
void Reservation::create_table () {
         QSqlQuery q(database);


         int num_rows,r,c;
         if(!q.exec("SELECT count(id) as num_rows FROM reservation"))
          {
               qDebug() << q.lastError().text();
          }
         q.first();
         num_rows = q.value(0).toInt();
         ui->tableWidget->setRowCount(num_rows);
         if(!q.exec("SELECT id,hotel_room , type_of_room, convenience, cost, service_provider, client,length_of_stay,payment_method,way_to_order FROM reservation ORDER BY id")){
                qDebug() << q.lastError().text();
         }
         int count = 10;
         for(r = 0,q.first(); q.isValid(); q.next(),++r) {
             for (c = 0;c < count;++c) {
                 ui->tableWidget->setItem(r,c,new QTableWidgetItem(q.value(c).toString()));
              }
         }
         currDate();

}



void Reservation::on_tableWidget_cellDoubleClicked(int row, int column)
{
         DialogReservation dialog;
         QString client = ui->tableWidget->item(row,6)->text();
         QStringList roomCost = ui->tableWidget->item(row,4)->text().split(" ");
         int cost = roomCost[0].toInt();
         QString paymentMethod = ui->tableWidget->item(row,8)->text();
         QString seviceProvider = ui->tableWidget->item(row,5)->text();
         QString wayToOrder = ui->tableWidget->item(row,9)->text();
         QString lengthOfStaying = ui->tableWidget->item(row,7)->text();
         dialog.setData(client,seviceProvider,lengthOfStaying,paymentMethod,wayToOrder,cost);
         if (dialog.exec()) {
              int id = ui->tableWidget->item(row,0)->text().toInt();
              QString client = dialog.get_Client();
              QString cost = QString::number(dialog.get_Cost()) + " dollars";
              QString paymentMethod = dialog.get_PaymentMethod();
              QString seviceProvider = dialog.get_ServiceProvider();
              QString wayToOrder = dialog.get_WayToOrder();
              QString lengthOfStaying = dialog.get_LengthOfStaying() + "   days: " + dialog.get_Length();
              QSqlQuery query(database);
              query.exec("UPDATE reservation SET cost = '" + cost + "', service_provider = '" + seviceProvider +
                           "',  client = '" + client + "', length_of_stay = '" + lengthOfStaying +
                           "',  payment_method = '" + paymentMethod +
                           "',  way_to_order = '" + wayToOrder + "' WHERE id = " + QString::number(id) + "");
               qDebug() <<"UPDATE reservation SET cost = '" + cost + "', service_provider = '" + seviceProvider +
                          "',  client = '" + client + "', length_of_stay = '" + lengthOfStaying +
                          "',payment_method = '" + paymentMethod +
                          "', way_to_order = '" + wayToOrder + "' WHERE id = " + QString::number(id) + "";
              create_table();
         } else {
            qDebug() << "close";
        }
}

void Reservation::on_tableWidget_cellClicked(int row, int column)
{
        QStringList wordList;
        wordList << "lanai" << "cabana" << "single room" << "studio" << "twin room" << "sico" << "duplex room"
                 <<"deluxe room" << "hollywood twin room" << "regular suite";
        if(ui->tableWidget->item(row,2)->isSelected() ){
            for (int i = 0 ; i < wordList.size();i++)  {
               if(ui->tableWidget->item(row,2)->text() == wordList.at(i)) {
                   HotelInform inform;
                   QString roomName = wordList.at(i).split(" ")[0];
                   QString path = ":/doc/"+roomName +".jpg";
                   qDebug()<<path;

                   inform.setPicture(path);

                   if(inform.exec()) {

                   }
                   qDebug()<<ui->tableWidget->item(row,2)->text();
                 }
            }

         }
}



void Reservation::on_textEdit_textChanged()
{
    QStringList wordList;

    for ( int i = 0 ; i < ui->tableWidget->rowCount();i++) {
        for (int j = 0; j < ui->tableWidget->columnCount();j++) {
            QTableWidgetItem *item = ui->tableWidget->item( i, j );
            if(!wordList.contains(item->text())) {
                wordList << item->text();
            }
        }
    }
    QCompleter *completer = new QWordCompleter(wordList,this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    completer->setWidget(ui->textEdit);
    connect(completer,SIGNAL(activated(QString)),
            completer,SLOT(replaceCurrentWord(QString)));

    QString filter=ui->textEdit->toPlainText();
    QStringList strList=filter.split('\n'); // разбиваем строку из текстедита на отдельные строки
    filter=strList.at(0);

    for( int i = 0; i < ui->tableWidget->rowCount(); ++i )
    {
          bool match = false;
          for( int j = 0; j < ui->tableWidget->columnCount(); ++j )
          {
              QTableWidgetItem *item = ui->tableWidget->item( i, j);
              if( item->text().contains(filter) )
               {
                        match = true;
                        break;
               }
           }
           ui->tableWidget->setRowHidden( i, !match );
    }
}
void Reservation::departure(int index){
    QString id = ui->tableWidget->item(index,0)->text();
    qDebug()<<id;
    QSqlQuery query(database);
    query.exec("UPDATE reservation SET service_provider = ' ', client = ' ' ,"
            " length_of_stay = ' ',"
            " payment_method = ' ',"
            " way_to_order = ' '  WHERE id = " + id + "");
     QString client = ui->tableWidget->item(index,6)->text();
     QString entranceTime = ui->tableWidget->item(index,7)->text();
     QStringList costRoom = ui->tableWidget->item(index,4)->text().split(" ");
     QStringList lengthOfStaying = ui->tableWidget->item(index,7)->text().split(": ");
     int  length = lengthOfStaying[1].toInt();
     int cost = costRoom[0].toInt();
     int  number = ui->tableWidget->item(index,1)->text().toInt();
     QString serviceProvider = ui->tableWidget->item(index,5)->text();
     QJsonObject json;
     json["Client"] = client;
     json["Entrance time"] = entranceTime;
     json["Cost"] = cost;
     json["Hotel Room"] = number;
     json["Service Provider"] = serviceProvider;
     QJsonDocument document;
     document.setObject(json);
     QFile jsonFile("/home/ziom/КПІ/courseWork/src/database.json");
     jsonFile.open(QIODevice::Append);
     jsonFile.write(document.toJson());
     create_table();

}

void Reservation::on_departurepushButton_clicked()
{
    int number = ui->spinBox->value();
    int index = -1;
    for( int i = 0; i < ui->tableWidget->rowCount(); ++i )
    {
          bool match = false;
          for( int j = 0; j < ui->tableWidget->columnCount(); ++j )
          {
              QTableWidgetItem *item = ui->tableWidget->item( i, 1);
              if( item->text().contains(QString::number(number)) )
               {
                        index = i;
                        match = true;
                        break;
               }
           }

     }

     qDebug()<<index;

     if(index != -1 && ui->spinBox->value() != 0) {
        QString id = ui->tableWidget->item(index,0)->text();
        qDebug()<<id;
        QSqlQuery query(database);
        query.exec("UPDATE reservation SET service_provider = ' ', client = ' ' ,"
                " length_of_stay = ' ',"
                " payment_method = ' ',"
                " way_to_order = ' '  WHERE id = " + id + "");
         QString client = ui->tableWidget->item(index,6)->text();
         QString entranceTime = ui->tableWidget->item(index,7)->text();
         QStringList costRoom = ui->tableWidget->item(index,4)->text().split(" ");
         QStringList lengthOfStaying = ui->tableWidget->item(index,7)->text().split(": ");
         int  length = lengthOfStaying[1].toInt();
         int cost = costRoom[0].toInt();
         int  number = ui->tableWidget->item(index,1)->text().toInt();
         QString serviceProvider = ui->tableWidget->item(index,5)->text();
         QJsonObject json;
         json["Client"] = client;
         json["Entrance time"] = entranceTime;
         json["Cost"] = cost;
         json["Hotel Room"] = number;
         json["Service Provider"] = serviceProvider;
         QJsonDocument document;
         document.setObject(json);
         QFile jsonFile("/home/ziom/КПІ/courseWork/src/database.json");
         jsonFile.open(QIODevice::Append);
         jsonFile.write(document.toJson());
         create_table();
         ui->spinBox->clear();
     } else {
         QMessageBox::critical(
               this,
               tr("Error"),
               tr("Please, enter number that exist"));
           ui->spinBox->clear();
     }

}
