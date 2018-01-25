#include "imagelistmodel.h"

/*ImageListModel::ImageListModel(std::initializer_list<QString> files, QObject *parent)
    : QAbstractListModel(parent)
{
    auto iter = files.begin();

    while (iter != files.end())
    {
        QPixmap large(*iter);
        PixmapPair *pair = new PixmapPair();
        pair->_file = *iter;
        pair->_large = large;
        pair->_small = large.scaled(100, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation);

        _data.append(pair);
        ++iter;
    }
}

ImageListModel::~ImageListModel()
{
    qDeleteAll(_data);
}


int ImageListModel::rowCount(const QModelIndex &parent) const
{
    // This function should return the number of rows contains into the parent
    // parameter, the parent parameter is used for trees in order to retrieve the
    // number of rows contains in each nodes, since we are doing a list each element
    // doesn't have child nodes so we return 0
    // By convention an invalid parent means the topmost level of a tree, in our case
    // we return the number of element contains in our data store.
    if (parent.isValid())
        return 0;
    else
        return _data.count();
}

QVariant ImageListModel::data(const QModelIndex &index, int role) const
{
    if (index.isValid())
    {
        switch (role)
        {
            case Qt::DecorationRole:
            {
                // DecorationRole = Icon show for a list
                return _data.value(index.row())->_small;
            }
            case Qt::DisplayRole:
            {
                // DisplayRole = Displayed text
                return _data.value(index.row())->_file;
            }
            case LargePixmapRole:
            {
                // This is a custom role, it will help us getting the pixmap more
                // easily later.
                return _data.value(index.row())->_large;
            }
        }
    }

    // returning a default constructed QVariant, will let Views knows we have nothing
    // to do and we let the default behavior of the view do work for us.
    return QVariant();
}*/
///////////////////////
