#ifndef STATUSROOM_H
#define STATUSROOM_H
#include <QDesktopWidget>
#include <QWidget>
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include "QtSql/QSqlError"
#include "QtSql/QSqlQuery"
#include <QDesktopServices>
#include <QUrl>
#include <QDialog>
#include <QDebug>
#include <QFileDialog>
#include <QDesktopServices>
#include "statusdialog.h"
#include "qwordcompleter.h"
namespace Ui {
class StatusRoom;
}

class StatusRoom : public QWidget
{
    Q_OBJECT
signals:
     void statusWindow();
public:
    explicit StatusRoom(QWidget *parent = 0);
    ~StatusRoom();
    void create_table();
    void moveToCenter();
private slots:
    void on_tableWidget_cellDoubleClicked(int row, int column);

    void on_textEdit_textChanged();

private:
    Ui::StatusRoom *ui;
    QSqlDatabase database;
};

#endif // STATUSROOM_H
