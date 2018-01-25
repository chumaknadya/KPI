#ifndef STATUSROOM_H
#define STATUSROOM_H

#include <QWidget>
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include "QtSql/QSqlError"
#include "QtSql/QSqlQuery"
namespace Ui {
class StatusRoom;
}

class StatusRoom : public QWidget
{
    Q_OBJECT
signals:
     void mainWindow();
public:
    explicit StatusRoom(QWidget *parent = 0);
    ~StatusRoom();
    void create_table();

private slots:
    void on_tableWidget_cellDoubleClicked(int row, int column);

private:
    Ui::StatusRoom *ui;
    QSqlDatabase database;
};

#endif // STATUSROOM_H
