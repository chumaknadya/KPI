#ifndef IMAGELISTMODEL_H
#define IMAGELISTMODEL_H


#include <QAbstractListModel>
#include <QPixmap>

/*struct PixmapPair
{
        QString _file;
        QPixmap _small;
        QPixmap _large;
};*/

/*class ImageListModel : public QAbstractListModel
{

   public:
        // QAbstractItemModel retrieve different information (like text, color, ...)
        // from same index using roles. We can define custom ones, however to avoid
        // clash with predefined roles, ours must start at Qt::UserRole.
        // All number below this one are reserved for qt internals.
        enum Roles
        {
            LargePixmapRole = Qt::UserRole + 1
        };

        explicit ImageListModel(std::initializer_list<QString> files, QObject *parent = 0);
        virtual ~ImageListModel();
         ImageListModel();

         // QAbstractItemModel interface ===========================
     public:
         int rowCount(const QModelIndex &parent) const;
         QVariant data(const QModelIndex &index, int role) const;
         // ========================================================

     private:
         QList<PixmapPair*> _data;

};*/

#endif // IMAGELISTMODEL_H
