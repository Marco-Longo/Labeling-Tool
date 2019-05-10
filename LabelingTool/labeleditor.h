#ifndef LABELEDITOR_H
#define LABELEDITOR_H

#include <QDialog>
#include <QLineEdit>
#include <QDebug>

namespace Ui {
class LabelEditor;
}

class LabelEditor : public QDialog
{
    Q_OBJECT

public:
    explicit LabelEditor(QWidget *parent = nullptr);
    ~LabelEditor();
    void setDimension(unsigned long);
    bool Ready();
    QString getEntry(int);

private:
    Ui::LabelEditor *ui;
    int labelsCount;
    QHash<int, QLineEdit*> *entries;
    bool ready;

public slots:
    void SendLabels();
};

#endif // LABELEDITOR_H
