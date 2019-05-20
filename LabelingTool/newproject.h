#ifndef NEWPROJECT_H
#define NEWPROJECT_H

#include <QDialog>
#include <QFileDialog>
#include <QMessageBox>

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
    QString ProjType();

private:
    Ui::NewProject *ui;
    QFileDialog *dirSelectDialog;
    QString projDirectory;
    QString projFullPath;
    QString projJob;
public slots:
    void SelectDir(QString);
    void CreateProj();
};

#endif // NEWPROJECT_H
