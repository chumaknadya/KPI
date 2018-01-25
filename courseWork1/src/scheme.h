#ifndef SCHEME_H
#define SCHEME_H
#include <QDesktopWidget>
#include <QWidget>
#include <QUrl>
#include <QtWebView>
#include <QDesktopServices>
namespace Ui {
class Scheme;
}

class Scheme : public QWidget
{
    Q_OBJECT
signals:
    void viewWindow();
public:
    explicit Scheme(QWidget *parent = 0);
    ~Scheme();
    void moveToCenter();
private slots:
    void on_viewButton_clicked();

private:
    Ui::Scheme *ui;
};

#endif // SCHEME_H
