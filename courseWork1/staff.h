#ifndef STAFF_H
#define STAFF_H

#include <QDialog>
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include "QtSql/QSqlError"
#include "QtSql/QSqlQuery"
namespace Ui {
class Staff;
}

class Staff : public QDialog
{
    Q_OBJECT

public:
    explicit Staff(QWidget *parent = 0);
    ~Staff();

private slots:

    void create_table_of_staff ();


    void on_AddpushButton_clicked();

    void on_DeletepushButton_clicked();

   // void on_tableWidget_cellChanged(int row, int column);

    void on_lineEdit_cursorPositionChanged(int arg1, int arg2);

    void on_tableWidget_cellDoubleClicked(int row, int column);

    //void on_tableWidget_doubleClicked(const QModelIndex &index);

    //void on_tableWidget_cellPressed(int row, int column);

private:
    Ui::Staff *ui;
    QSqlDatabase database;
//    bool loading;
//   void create_table_of_staff ();
};

#endif // STAFF_H
