#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include "computer_game.h"
#include <QTableWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_addButton_clicked();
    void on_removeButton_clicked();
    void on_listWidget_itemSelectionChanged();
    void closeEvent(QCloseEvent *event);
    void on_ComputeButton_clicked();
    void on_tableWidget_itemSelectionChanged();

    void on_tableWidget_itemClicked(QTableWidgetItem *item);

private:
    Ui::MainWindow *ui;
    vector<Computer_Game *> computer_games;
};

#endif // MAINWINDOW_H
