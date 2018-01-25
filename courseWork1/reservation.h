#ifndef RESERVATION_H
#define RESERVATION_H
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include "QtSql/QSqlError"
#include "QtSql/QSqlQuery"
#include <QWidget>

namespace Ui {
class Reservation;
}

class Reservation : public QWidget
{
    Q_OBJECT
signals:
     void mainWindow();
public:
    explicit Reservation(QWidget *parent = 0);
    ~Reservation();
      void create_table ();

private slots:
      void on_radioButton_clicked();

      void on_radioButton_2_clicked();

      void on_radioButton_3_clicked();

      void on_lineEdit_cursorPositionChanged(int arg1, int arg2);

private:
    QSqlDatabase database;
    Ui::Reservation *ui;
};

#endif // RESERVATION_H
