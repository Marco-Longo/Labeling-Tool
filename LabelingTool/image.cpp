#include "image.h"

Image::Image(QPixmap i, QString p)
{
    pic = i;
    path = p;
}

void Image::setPic(QPixmap i)
{
    pic = i;
}

void Image::setPath(QString p)
{
    path = p;
}
