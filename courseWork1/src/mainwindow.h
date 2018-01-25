#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "clogin.h"
#include <QMainWindow>
#include <QUrl>
#include <QtWebView>
#include <QDesktopServices>
#include <QPalette>
#include <QBrush>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void moveToCenter();
private slots:
    void on_signInpushButton_clicked();

    void on_reviewspushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
