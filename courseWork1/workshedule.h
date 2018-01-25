#ifndef WORKSHEDULE_H
#define WORKSHEDULE_H

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
    void mainWindow();

public:
    void create_table ();

    explicit WorkShedule(QWidget *parent = 0);
    ~WorkShedule();

private:
    QSqlDatabase database;
    Ui::WorkShedule *ui;
};

#endif // WORKSHEDULE_H
