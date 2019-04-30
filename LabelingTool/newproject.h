#ifndef NEWPROJECT_H
#define NEWPROJECT_H

#include <QDialog>
#include <QFileDialog>

namespace Ui {
class NewProject;
}

class NewProject : public QDialog
{
    Q_OBJECT

public:
    explicit NewProject(QWidget *parent = nullptr);
    ~NewProject();
    QString FullPath();

private:
    Ui::NewProject *ui;
    QFileDialog *dirSelectDialog;
    QString projDirectory;
    QString projFullPath;
public slots:
    void SelectDir(QString);
    void CreateProj();
};

#endif // NEWPROJECT_H
