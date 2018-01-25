#ifndef PIXMAPPAIR_H
#define PIXMAPPAIR_H

#endif // PIXMAPPAIR_H
#include <QPixmap>
#include <QIcon>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
class PixmapPair : public QObject
{
    Q_OBJECT
public:
    PixmapPair(QString file, QGridLayout * gridLayout, QLabel* rp)
        : rightPane(rp), largePixmap(file)
    {
        smallPixmap = largePixmap.scaled(QSize(100,100), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        QPushButton* pushButton = new QPushButton;
        pushButton->setIcon(QIcon(smallPixmap));
        pushButton->setFlat(true);
        pushButton->setIconSize(QSize(100,100));
        QObject::connect(pushButton, SIGNAL(clicked()), SLOT(displayInRightPane()));
        gridLayout->addWidget(pushButton);
    }
public slots:
    void displayInRightPane()
    {
        rightPane->setPixmap(largePixmap);
    }
private:
    QLabel* rightPane;
    QPixmap largePixmap;
    QPixmap smallPixmap;
};
