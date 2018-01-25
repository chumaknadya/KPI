#ifndef DOORMAN_H
#define DOORMAN_H
#include <QDesktopWidget>
#include <QWidget>
#include "workshedule.h"
#include "periodofstaying.h"
#include "qwordcompleter.h"
namespace Ui {
class Doorman;
}

class Doorman : public QWidget
{
    Q_OBJECT
signals:
    void thirdWindow();
public:
    explicit Doorman(QWidget *parent = 0);
    ~Doorman();
    void moveToCenter();
private slots:
    void on_sheduleButton_clicked();

    void on_lengthStayingButton_clicked();

private:
    Ui::Doorman *ui;
    WorkShedule * shedule;
    PeriodOfStaying * period;
};

#endif // DOORMAN_H
