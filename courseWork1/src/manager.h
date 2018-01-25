#ifndef MANAGER_H
#define MANAGER_H
#include <QDesktopWidget>
#include <QWidget>
#include <QUrl>
#include <QtWebView>
#include <QDesktopServices>
#include "workshedule.h"
#include "staff.h"

namespace Ui {
class Manager;
}

class Manager : public QWidget
{
    Q_OBJECT
signals:
    void fifthWindow();
public:
    void moveToCenter();
    explicit Manager(QWidget *parent = 0);
    ~Manager();

private slots:
    void on_sheduleButton_clicked();

    void on_staffButton_clicked();

    void on_reviewsButton_clicked();

private:
    Staff * staff;
    WorkShedule * shedule;
    Ui::Manager *ui;
};

#endif // MANAGER_H
