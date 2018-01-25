#include "statusroom.h"
#include "ui_statusroom.h"
#include "clogin.h"
StatusRoom::StatusRoom(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StatusRoom)
{
    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->resizeSections(QHeaderView::ResizeToContents);
    ui->tableWidget->hideColumn(0);



    ui->tableWidget->setSelectionBehavior( QAbstractItemView::SelectItems );
    ui->tableWidget->setSelectionMode( QAbstractItemView::SingleSelection );
//    Clogin con;
//    if(!con.connOpen()) {
//        ui ->label->setText("Failed");
//    }else {
//        ui->label->setText("Connected");
//    }
    ui->tableWidget->setColumnWidth(1,150);
    ui->tableWidget->setColumnWidth(2,150);
    ui->tableWidget->setColumnWidth(3,150);
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

    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section { background-color: rgb(192, 237, 238)}");
    ui->tableWidget->verticalHeader()->setStyleSheet("QHeaderView::section { background-color: rgb(192, 237, 238)}");
    create_table();
    QPalette * palette = new QPalette();
    palette->setBrush(this->backgroundRole(), QBrush(QPixmap(":/doc/aesthetic-background-gradient-green-Favim.com-2877559.jpg")));
    this->setPalette(*palette);
    moveToCenter();
}
void StatusRoom::moveToCenter() {
    QDesktopWidget desktop;
    QRect rect = desktop.availableGeometry(desktop.primaryScreen()); // прямоугольник с размерами экрана
    QPoint center = rect.center(); //координаты центра экрана
    center.setX(center.x() - (this->width()/2));  // учитываем половину ширины окна
    center.setY(center.y() - (this->height()/2));  // .. половину высоты
    move(center);
}
StatusRoom::~StatusRoom()
{
    //database.close();
    delete ui;

}
void StatusRoom::create_table() {
        QSqlQuery q(database);

        int num_rows,r,c;
        if(!q.exec("SELECT count(id) as num_rows FROM status_room"))
         {
              qDebug() << q.lastError().text();
         }

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
         if (dialog.exec()) {

                qDebug() << "Accepted!";
                int id = ui->tableWidget->item(row,0)->text().toInt();
                QString data = dialog.get_Time();
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
              qDebug() << "close dialog status";
          }



}

void StatusRoom::on_textEdit_textChanged()
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
