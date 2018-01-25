#include "periodofstaying.h"
#include "ui_periodofstaying.h"

PeriodOfStaying::PeriodOfStaying(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PeriodOfStaying)
{
    ui->setupUi(this);
    tableWidgetdesign();
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
    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section { background-color: rgb(192, 237, 238)}");
    ui->tableWidget->verticalHeader()->setStyleSheet("QHeaderView::section { background-color: rgb(192, 237, 238)}");
    QPalette * palette = new QPalette();
    palette->setBrush(this->backgroundRole(), QBrush(QPixmap(":/doc/aesthetic-background-gradient-green-Favim.com-2877559.jpg")));
    this->setPalette(*palette);
    ui->tableWidget->setColumnWidth(1,230);
    ui->tableWidget->setColumnWidth(2,230);
    moveToCenter();
}
void PeriodOfStaying::moveToCenter() {
    QDesktopWidget desktop;
    QRect rect = desktop.availableGeometry(desktop.primaryScreen()); // прямоугольник с размерами экрана
    QPoint center = rect.center(); //координаты центра экрана
    center.setX(center.x() - (this->width()/2));  // учитываем половину ширины окна
    center.setY(center.y() - (this->height()/2));  // .. половину высоты
    move(center);
}
PeriodOfStaying::~PeriodOfStaying()
{
    delete ui;
}
void PeriodOfStaying::tableWidgetdesign()
{
    ui->tableWidget->horizontalHeader()->resizeSections(QHeaderView::ResizeToContents);
    ui->tableWidget->hideColumn(0);
    ui->tableWidget->setSelectionBehavior( QAbstractItemView::SelectItems );
    ui->tableWidget->setSelectionMode( QAbstractItemView::SingleSelection );
}


void PeriodOfStaying::create_table() {
    QSqlQuery q(database);

    int num_rows,r,c;
    if(!q.exec("SELECT count(id) as num_rows FROM reservation"))
     {
          qDebug() << q.lastError().text();
     }

    q.first();
    num_rows = q.value(0).toInt();
    ui->tableWidget->setRowCount(num_rows);
    if(!q.exec("SELECT id, hotel_room,length_of_stay  FROM reservation ORDER BY id")){
           qDebug() << q.lastError().text();
    }
    int count = 10;
    for(r = 0,q.first(); q.isValid(); q.next(),++r) {
        for (c = 0;c < count;++c) {
            ui->tableWidget->setItem(r,c,new QTableWidgetItem(q.value(c).toString()));
         }
    }

}

void PeriodOfStaying::on_textEdit_textChanged()
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
