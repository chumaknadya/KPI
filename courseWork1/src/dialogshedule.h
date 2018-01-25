#ifndef DIALOGSHEDULE_H
#define DIALOGSHEDULE_H
#include <QDesktopWidget>
#include <QDialog>

namespace Ui {
class DialogShedule;
}

class DialogShedule : public QDialog
{
    Q_OBJECT

public:
    void moveToCenter();
    explicit DialogShedule(QWidget *parent = 0);
    ~DialogShedule();
    bool get_Monday() const;
    bool get_Tuesday() const;
    bool get_Wednesday() const;
    bool get_Thursday() const;
    bool get_Friday() const;
    bool get_Saturday() const;
    bool get_Sunday() const;

private:
    Ui::DialogShedule *ui;
};

#endif // DIALOGSHEDULE_H
