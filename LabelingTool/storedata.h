#ifndef STOREDATA_H
#define STOREDATA_H

#include <QWidget>
#include <QHash>

class StoreData
{
public:
    StoreData();
    StoreData(QString, QHash<QString, QString>*, QHash<QString, QString>*, QVector<QString>*);
    QString getDirectory();
    QHash<QString, QString>* getLabels();
    QHash<QString, QString>* getHistory();
    QVector<QString>* getButtons();
    void setDirectory(QString);
    void setLabels(QHash<QString, QString>*);
    void setHistory(QHash<QString, QString>*);
    void setButtons(QVector<QString>*);

private:
    QString directory;
    QHash<QString, QString> *labels;
    QHash<QString, QString> *history;
    QVector<QString> *buttons;
};

#endif // STOREDATA_H
