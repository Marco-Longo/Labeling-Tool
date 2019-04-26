#ifndef IMAGE_H
#define IMAGE_H

#include <QPixmap>
#include <QString>

class Image
{
public:
    QPixmap pic;
    QString path;
    Image(QPixmap, QString);
    void setPic(QPixmap);
    void setPath(QString);
private:
};

#endif // IMAGE_H
