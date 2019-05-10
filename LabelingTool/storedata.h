#ifndef STOREDATA_H
#define STOREDATA_H

#include <QWidget>
#include <QHash>

class StoreData
{
public:
    StoreData(QString, QHash<QString, QString>*, QHash<QString, QString>*);
    QString getDirectory();
    QHash<QString, QString>* getLabels();
    QHash<QString, QString>* getHistory();

private:
    QString directory;
    QHash<QString, QString> *labels;
    QHash<QString, QString> *history;
};

#endif // STOREDATA_H
