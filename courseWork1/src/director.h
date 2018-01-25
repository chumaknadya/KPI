#ifndef DIRECTOR_H
#define DIRECTOR_H
#include <QDesktopWidget>
#include <QWidget>
#include <QUrl>
#include <QtWebView>
#include <QDesktopServices>
#include "statusroom.h"
#include "workshedule.h"
#include "staff.h"
#include "scheme.h"
namespace Ui {
class Director;
}

class Director : public QWidget
{
    Q_OBJECT

public:
    void moveToCenter();
    explicit Director(QWidget *parent = 0);
    ~Director();
signals:
    void firstWindow();
private slots:
    void on_shedulepushButton_clicked();

    void on_statuspushButton_clicked();

    void on_staffpushButton_clicked();

    void on_statepushButton_clicked();

private:
    Ui::Director *ui;
    StatusRoom * statusroom;
    WorkShedule * shedule;
    Staff * staff;
    Scheme * scheme;

};

#endif // DIRECTOR_H
