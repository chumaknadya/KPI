#ifndef HOUSEMAID_H
#define HOUSEMAID_H
#include <QDesktopWidget>
#include <QWidget>
#include "statusroom.h"
#include "workshedule.h"
namespace Ui {
class Housemaid;
}

class Housemaid : public QWidget
{
    Q_OBJECT
signals:
    void fourthWindow();
public:
    void moveToCenter();
    explicit Housemaid(QWidget *parent = 0);
    ~Housemaid();

private slots:
    void on_sheduleButton_clicked();

    void on_stateButton_clicked();

private:
    StatusRoom * statusroom;
    WorkShedule * shedule;
    Ui::Housemaid *ui;
};

#endif // HOUSEMAID_H
