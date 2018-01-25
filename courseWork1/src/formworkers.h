#ifndef FORMWORKERS_H
#define FORMWORKERS_H
#include <QDesktopWidget>
#include <QDialog>

namespace Ui {
class FormWorkers;
}

class FormWorkers : public QDialog
{
    Q_OBJECT

public:
    void moveToCenter();
    explicit FormWorkers(QWidget *parent = 0);
    ~FormWorkers();
    QString get_Name() const;
    QString get_Surname() const;
    QString get_Email() const;
    QString get_Birthdate() const;
    QString get_Status() const;

    double get_Salary() const;
    void defaultText();
    void setEmail(QString & data);
    void setName(QString & data);
    void setSurname(QString & data);
    void setBirthdate(QString & data);
    void setStatus(QString & data);
    void setSalary(QString & data);
    void setData(QString & name,QString & surname,QString & birthdate,QString & email,QString & status,double salary);

private slots:

   void on_NamelineEdit_editingFinished();

   void on_SurnamelineEdit_editingFinished();

   void on_BirthdatelineEdit_editingFinished();

   void on_EmaillineEdit_editingFinished();

   void on_StatuslineEdit_editingFinished();



private:

    Ui::FormWorkers *ui;
};

#endif // FORMWORKERS_H
