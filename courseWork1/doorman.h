#ifndef DOORMAN_H
#define DOORMAN_H

#include <QDialog>

namespace Ui {
class Doorman;
}

class Doorman : public QDialog
{
    Q_OBJECT

public:
    explicit Doorman(QWidget *parent = 0);
    ~Doorman();

private:
    Ui::Doorman *ui;
};

#endif // DOORMAN_H
