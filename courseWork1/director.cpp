#include "director.h"
#include "ui_director.h"
#include <QDebug>
#include <QSqlError>
#include <QSqlRecord>
#include <QSplitter>
#include <QLabel>
#include <QPixmap>
#include <QListView>

#include "imagelistmodel.h"


Director::Director(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Director)
{
    ui->setupUi(this);
   /* QSplitter page;
        QListView *imageList = new QListView(&page);
        ui->imageList->setModel(new ImageListModel({ "/home/ziom/Завантаження/1floor.jpg", "forest.jpg" }, imageList));
        // We tell the list view to show our icon, this mode will call the data function
        // of our model with the role : DecorationRole.
        ui->imageList->setViewMode(QListView::IconMode);
        // We want our list to show data vertically
        ui->imageList->setFlow(QListView::TopToBottom);
        // We allow only one selection at a time in the list
        ui->imageList->setSelectionMode(QListView::SingleSelection);
        QLabel *imagePresenter = new QLabel(&page);

        // We connect to the signal emitted when the selection is changed
        // to update the image presenter.
        QObject::connect(imageList->selectionModel(), &QItemSelectionModel::selectionChanged, [imageList, imagePresenter] {
            QModelIndex selectedIndex = imageList->selectionModel()->selectedIndexes().first();
            // We use our custom role here to retieve the large image using the selected
            // index.
            imagePresenter->setPixmap(selectedIndex.data(ImageListModel::LargePixmapRole).value<QPixmap>());
        });

        page.setWindowTitle("Images");
        page.show();*/
    ui->listWidget->setViewMode(QListWidget::IconMode);

    ui->listWidget->setIconSize(QSize(200,200));

    ui->listWidget->setResizeMode(QListWidget::Adjust);
    ui->listWidget->addItem(new QListWidgetItem(QIcon("/home/ziom/Завантаження/1floor.jpg"),"First floor"));
    ui->listWidget->addItem(new QListWidgetItem(QIcon("/home/ziom/Завантаження/plan.gif"),"Tornado"));
    //ui->listWidget->addItem(new QListWidgetItem(QIcon("../ics.jpg"),"Wallpaper"));
    /*db = SqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("test");
    db.setUserName("root");
    db.setPassword("123456");
    if(!db.open()) {
        qDebug() << db.lastError().text();
    } else {
        qDebug() << "Success!";
    }*/
   // ui->imageList->setModel(new ImageListModel({ "/home/ziom/Завантаження/1floor.jpg", "forest.jpg" }, imageList));
    ui->listView->setModel(new ImageListModel({ "/home/ziom/Завантаження/1floor.jpg", "/home/ziom/Завантаження/plan.gif" }, ui->listView));
    // We tell the list view to show our icon, this mode will call the data function
        // of our model with the role : DecorationRole.
    //change poslidovnist` vertukal`na
    ui->listView->setViewMode(QListView::IconMode);
      ui->listView->setFlow(QListView::TopToBottom);
       // We allow only one selection at a time in the list
      ui->listView->setSelectionMode(QListView::SingleSelection);
//      QObject::connect(ui->listView->selectionModel(), &QItemSelectionModel::selectionChanged, [listView, label] {
//             QModelIndex selectedIndex = ui->listView->selectionModel()->selectedIndexes().first();
//             // We use our custom role here to retieve the large image using the selected
//             // index.
//             ui->label->setPixmap(selectedIndex.data(ImageListModel::LargePixmapRole).value<QPixmap>());
//         });
     // QModelIndex selectedIndex = ui->listView->selectionModel()->selectedIndexes().first();
     // ui->label->setPixmap(selectedIndex.data(ImageListModel::LargePixmapRole).value<QPixmap>());
//      if (ui->listView->selectionModel()->selectedRows().count()==0)
//          return;
//      QModelIndex index=ui->listView->selectionModel()->selectedRows().at(0);
//      QString str=ui->listView->model()->data(index).toString();
//      QPalette pal;
//      pal.setBrush(ui->label->backgroundRole(), QBrush(QPixmap(str)));
//      ui->label->setPalette(pal);
//      ui->label->setAutoFillBackground(true);
}

Director::~Director()
{
    delete ui;
}


void Director::on_listWidget_clicked(const QModelIndex &index)
{
//   QString str=ui->listWidget->selectedItems().at(0)->text();
////   QModelIndex index=ui->listWidget->selectionModel()->selectedRows().at(0);
//  // QString str=ui->listWidget->model()->data(index).toString();
//   QPalette pal;
//   pal.setBrush(ui->label->backgroundRole(), QBrush(QPixmap(str)));
//   ui->label->setPalette(pal);
//   ui->label->setAutoFillBackground(true);
}

void Director::on_listWidget_itemChanged(QListWidgetItem *item)
{
  //  QPalette pal;
    //pal.setBrush(ui->label->backgroundRole(), QBrush(QPixmap(item)));

}

void Director::on_pushButton_clicked()
{
        QSqlDatabase books;
        books = QSqlDatabase::addDatabase("QSQLITE");
        books.setDatabaseName("/home/ziom/progbase3/progbase3/cursova/emloyee");
        books.open();


        QSqlQuery query;
        query.exec("SELECT name FROM client");

        int row = 0;
        while(query.next()){
            QString name = query.value(0).toString();
//            QString title = query.value(1).toString();
//            QString author = query.value(2).toString();
//            QString genre = query.value(3).toString();
//            QString language = query.value(4).toString();
//            QString year = query.value(5).toString();
//            QString rating = query.value(6).toString();
//            QString ageLimit = query.value(7).toString();
//            QString cost = query.value(8).toString();
//            QString numOfCop = query.value(9).toString();

            //ui->textEdit->insertPlainText(id+" | "+title+" | "+author+" | "+genre+" | "+language+" | "+year+" | "+rating+" | "+ageLimit+" | "+cost+" | "+numOfCop+"\n");
            ui->tableWidget->setRowCount(row+1);
            ui->tableWidget->setItem(row, 0, new QTableWidgetItem(name));
//            ui->tableWidget->setItem(row, 1, new QTableWidgetItem(title));
//            ui->tableWidget->setItem(row, 2, new QTableWidgetItem(author));
//            ui->tableWidget->setItem(row, 3, new QTableWidgetItem(genre));
//            ui->tableWidget->setItem(row, 4, new QTableWidgetItem(language));
//            ui->tableWidget->setItem(row, 5, new QTableWidgetItem(year));
//            ui->tableWidget->setItem(row, 6, new QTableWidgetItem(rating));
//            ui->tableWidget->setItem(row, 7, new QTableWidgetItem(ageLimit));
//            ui->tableWidget->setItem(row, 8, new QTableWidgetItem(cost));
//            ui->tableWidget->setItem(row, 9, new QTableWidgetItem(numOfCop));
            row++;
        }
}
