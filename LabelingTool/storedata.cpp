#include "storedata.h"

StoreData::StoreData(QString dir, QHash<QString, QString> *lab, QHash<QString, QString> *his)
{
    directory = dir;
    labels = lab;
    history = his;
}

QString StoreData::getDirectory()
{
    return directory;
}

QHash<QString, QString>* StoreData::getLabels()
{
    return labels;
}

QHash<QString, QString>* StoreData::getHistory()
{
    return history;
}
