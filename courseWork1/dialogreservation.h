#ifndef DIALOGRESERVATION_H
#define DIALOGRESERVATION_H

#include <QDialog>

namespace Ui {
class DialogReservation;
}

class DialogReservation : public QDialog
{
    Q_OBJECT

public:
    explicit DialogReservation(QWidget *parent = 0);
    ~DialogReservation();
    void addItemToPaymentMethodComboBox();
    void addItemToWayToOrderComboBox();
private:
    Ui::DialogReservation *ui;
};

#endif // DIALOGRESERVATION_H
