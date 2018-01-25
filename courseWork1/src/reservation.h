#ifndef RESERVATION_H
#define RESERVATION_H
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include "QtSql/QSqlError"
#include "QtSql/QSqlQuery"
#include <QWidget>
#include <QDesktopWidget>
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
    void design();
    void moveToCenter();
signals:
      void reservationWindow();
private slots:


      void on_tableWidget_cellDoubleClicked(int row, int column);
      void on_tableWidget_cellClicked(int row, int column);
      void on_textEdit_textChanged();

private:
    QSqlDatabase database;
    Ui::Reservation *ui;
};

#endif // RESERVATION_H
