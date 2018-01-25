#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "computer_game.h"
#include <QDebug>
#include <QDialog>
#include <QString>
#include <QHeaderView>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)


{

    ui->setupUi(this);
    auto table = ui->tableWidget;
       table->setColumnCount(2);
       table->setHorizontalHeaderLabels(QStringList{"Name", "Genre"});
       table->verticalHeader()->hide();
       table->setShowGrid(true);
       table->setEditTriggers(QAbstractItemView::NoEditTriggers);
       table->setSelectionBehavior(QAbstractItemView::SelectRows);
       table->setSelectionMode(QAbstractItemView::SingleSelection);

       table->horizontalHeader()->setSectionResizeMode( QHeaderView::Stretch );

   table->setStyleSheet("QTableView {selection-background-color: blue;}"); // you can use CSS
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_addButton_clicked()
{
    Dialog dialog;
    dialog.setWindowTitle("Create an object");

    if(dialog.exec()){

         QString  fullname = dialog.lineEditFullname();
         QString  genre = dialog.lineEditGenre();
         QString platform  = dialog.lineEditPlatform();
         int year = dialog.yearSpinBox();
         float raiting = dialog.raitingSpinBox();
         int numbers_of_player = dialog.NumberSpinBox();
         Computer_Game * computer_game = new  Computer_Game(fullname, genre, year,raiting,platform,numbers_of_player);
         computer_games.push_back(computer_game);

         //ui->listWidget->addItem(fullname);
         auto table = ui->tableWidget;
         int row = table->rowCount();
         table->insertRow(row);
         table->setItem(row, 0, new QTableWidgetItem(fullname));
         table->setItem(row, 1, new QTableWidgetItem(genre));


        qDebug() << "Accepted";
    } else {
        qDebug() << "Rejected";
    }

}

void MainWindow::on_removeButton_clicked()
{
   /* auto items = ui->tableWidget->selectedItems();
    auto hasSelected = items.size()  > 0;
    qDebug() << items.size();

    if (hasSelected) {

           int i = ui->listWidget->row(items[0]);
      //     computer_games.erase(computer_games.begin() +i);

           delete computer_games[ui->listWidget->row(items[0])];


           computer_games.erase(computer_games.begin() +i);

          qDebug() << computer_games.size();
           ui->fullnameTextLabel->clear();
           ui->genreTextLabel->clear();
           ui->PlatformTextLabel->clear();
           ui->playersTextLabel->clear();
           ui->yearTextLabel->clear();
           ui->raitingTextLabel->clear();*/
     //      delete ui->listWidget->takeItem(ui->listWidget->row(items[0]));
            // ui->listWidget->takeItem(ui->listWidget->row(ui->listWidget->currentItem()));

   //}
       auto table = ui->tableWidget;
       auto items = table->selectedItems();
       auto hasItems = (items.size() > 0);
       if (hasItems) {

           auto item = items[0];
           delete computer_games[table->row(item)];
           computer_games.erase(computer_games.begin() + table->row(item));
           ui->fullnameTextLabel->clear();
           ui->genreTextLabel->clear();
           ui->PlatformTextLabel->clear();
           ui->playersTextLabel->clear();
           ui->yearTextLabel->clear();
           ui->raitingTextLabel->clear();
           table->removeRow(table->row(item));
   }

}







void MainWindow::on_ComputeButton_clicked()
{
    int value = ui->doubleSpinBox->value();
    int i = 0;
    ui->listWidget_2->clear();

    for (Computer_Game * st : computer_games) {
           if(st->raiting() < value) {
               ui->listWidget_2->addItem(computer_games.at(i)->fullname() + " " + computer_games.at(i)->genre());

           }
           i++;
    }
    ui->doubleSpinBox->clear();

}
void MainWindow::closeEvent (QCloseEvent *event)
{
    // use this to cleanup allocated memory

    for (Computer_Game * st : computer_games) {
         delete st;
    }
    qDebug() << "Window closed!";
    event->accept();
}



void MainWindow::on_tableWidget_itemSelectionChanged()
{
          auto table = ui->tableWidget;
          auto items = table->selectedItems();
          auto hasItems = (items.size() > 0);
          ui->removeButton->setEnabled(hasItems);
          ui->ComputeButton->setEnabled(hasItems);
}

void MainWindow::on_tableWidget_itemClicked(QTableWidgetItem *item)
{
    auto table = ui->tableWidget;

            ui->fullnameTextLabel->setText(computer_games.at(ui->tableWidget->row(item))->fullname());
            ui->genreTextLabel->setText(computer_games.at(table->row(item))->genre());
            ui->PlatformTextLabel->setText(computer_games.at(table->row(item))->platform());
            QString qRaiting = QString::number(computer_games.at(table->row(item))->raiting());
            ui->raitingTextLabel->setText(qRaiting);
            QString qPlayers = QString::number(computer_games.at(table->row(item))->numbers_of_player());
            ui->playersTextLabel->setText(qPlayers);
            QString qYear = QString::number(computer_games.at(table->row(item))->year());
            ui->yearTextLabel->setText(qYear);



}
