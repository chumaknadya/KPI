#ifndef WORKSHEDULE_H
#define WORKSHEDULE_H
#include <QDesktopWidget>
#include <QWidget>
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include "QtSql/QSqlError"
#include "QtSql/QSqlQuery"
namespace Ui {
class WorkShedule;
}

class WorkShedule : public QWidget
{
    Q_OBJECT
signals:
    void sheduleWindow();

public:
    void create_table ();
    void moveToCenter();
    explicit WorkShedule(QWidget *parent = 0);
    ~WorkShedule();

private slots:
    void on_tableWidget_cellDoubleClicked(int row, int column);

private:
    QSqlDatabase database;
    Ui::WorkShedule *ui;
};

#endif // WORKSHEDULE_H
