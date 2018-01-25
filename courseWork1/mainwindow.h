#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "administrator.h"
#include "doorman.h"
#include "director.h"
#include "housemaid.h"
#include "manager.h"
#include "clogin.h"
#include <QWidget>

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


    void on_directorButton_clicked();

    void on_administratorButton_clicked();

    void on_managerButton_clicked();

    void on_housemaidButton_clicked();

    void on_conciergeButton_clicked();

    void on_pushButton_2_clicked();

    void on_signInButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
