#ifndef DIRECTOR_H
#define DIRECTOR_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QListWidget>

namespace Ui {
class Director;
}

class Director : public QDialog
{
    Q_OBJECT

public:
    explicit Director(QWidget *parent = 0);
    ~Director();

private slots:
    void on_listWidget_clicked(const QModelIndex &index);

    void on_listWidget_itemChanged(QListWidgetItem *item);

    void on_pushButton_clicked();

private:
    Ui::Director *ui;
    QSqlDatabase db;
};

#endif // DIRECTOR_H
