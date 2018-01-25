#ifndef HOUSEMAID_H
#define HOUSEMAID_H

#include <QDialog>

namespace Ui {
class Housemaid;
}

class Housemaid : public QDialog
{
    Q_OBJECT

public:
    explicit Housemaid(QWidget *parent = 0);
    ~Housemaid();

private:
    Ui::Housemaid *ui;
};

#endif // HOUSEMAID_H
