#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H
#include <QDesktopWidget>
#include <QWidget>
#include "workshedule.h"
#include "scheme.h"
#include "reservation.h"
namespace Ui {
class Administrator;
}

class Administrator : public QWidget
{
    Q_OBJECT
signals:
    void secondWindow();
public:
    explicit Administrator(QWidget *parent = 0);
    ~Administrator();
    void moveToCenter();

private slots:
    void on_sheduleButton_clicked();

    void on_reservationButton_clicked();

    void on_schemeButton_clicked();

private:
    Ui::Administrator *ui;
    WorkShedule * shedule;
    Scheme * scheme;
    Reservation * reservation;
};

#endif // ADMINISTRATOR_H
