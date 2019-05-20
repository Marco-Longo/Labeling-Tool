#ifndef STOREDATA_H
#define STOREDATA_H

#include <QWidget>
#include <QHash>

class StoreData
{
public:
    StoreData();
    StoreData(QString, QString, QHash<QString, QString>*, QVector<QString>*);
    QString getDirectory();
    QString getJob();
    QHash<QString, QString>* getLabels();
    QVector<QString>* getButtons();
    void setDirectory(QString);
    void setJob(QString);
    void setLabels(QHash<QString, QString>*);
    void setButtons(QVector<QString>*);

private:
    QString directory;
    QString job;
    QHash<QString, QString> *labels;
    QVector<QString> *buttons;
};

#endif // STOREDATA_H
