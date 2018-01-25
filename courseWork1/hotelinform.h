#ifndef HOTELINFORM_H
#define HOTELINFORM_H

#include <QDialog>

namespace Ui {
class HotelInform;
}

class HotelInform : public QDialog
{
    Q_OBJECT

public:
    explicit HotelInform(QWidget *parent = 0);
    ~HotelInform();
     void setPicture(QString & picture);
private:
    Ui::HotelInform *ui;
};

#endif // HOTELINFORM_H
