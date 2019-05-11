#include "storedata.h"

StoreData::StoreData()
{
    directory = "";
    labels = nullptr;
    history = nullptr;
    buttons = nullptr;
}

StoreData::StoreData(QString dir, QHash<QString, QString> *lab, QHash<QString, QString> *his, QVector<QString>* but)
{
    directory = dir;
    labels = lab;
    history = his;
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

QHash<QString, QString>* StoreData::getHistory()
{
    return history;
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

void StoreData::setHistory(QHash<QString, QString>* h)
{
    history = h;
}

void StoreData::setButtons(QVector<QString>* b)
{
    buttons = b;
}
