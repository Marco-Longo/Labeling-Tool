#include "storedata.h"

StoreData::StoreData()
{
    directory = "";
    job = "";
    labels = nullptr;
    buttons = nullptr;
}

StoreData::StoreData(QString dir, QString type, QHash<QString, QString> *lab, QVector<QString>* but)
{
    directory = dir;
    job = type;
    labels = lab;
    buttons = but;
}

QString StoreData::getDirectory()
{
    return directory;
}

QHash<QString, QString>* StoreData::getLabels()
{
    return labels;
}

QString StoreData::getJob()
{
    return job;
}

QVector<QString>* StoreData::getButtons()
{
    return buttons;
}

void StoreData::setDirectory(QString s)
{
    directory = s;
}

void StoreData::setLabels(QHash<QString, QString>* l)
{
    labels = l;
}

void StoreData::setJob(QString j)
{
    job = j;
}

void StoreData::setButtons(QVector<QString>* b)
{
    buttons = b;
}
