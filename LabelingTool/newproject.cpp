#include "newproject.h"
#include "ui_newproject.h"
#include "mainwindow.h"

NewProject::NewProject(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewProject)
{
    ui->setupUi(this);
    dirSelectDialog = new QFileDialog(this);
    dirSelectDialog->setFileMode(QFileDialog::DirectoryOnly);
    QObject::connect(ui->b_browse, SIGNAL(clicked()), dirSelectDialog, SLOT(open()));
    QObject::connect(dirSelectDialog, SIGNAL(fileSelected(QString)), this, SLOT(SelectDir(QString)));
    QObject::connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(CreateProj()));
}

NewProject::~NewProject()
{
    delete ui;
}

void NewProject::SelectDir(QString path)
{
    projDirectory = path;
    ui->txtbox_dir->setText(projDirectory);
}

void NewProject::CreateProj()
{
    QString projName = ui->txtbox_name->text();
    QString projDir = ui->txtbox_dir->text();
    QString projType = "";
    if(ui->b_singleLabel->isChecked())
        projType = "SingleLabel";
    else if(ui->b_multiLabel->isChecked())
        projType = "MultiLabel";
    else if(ui->b_segmentation->isChecked())
        projType = "Segmentation";
    if(projName == "" || projDir == "" || projType == "")
    {
        QMessageBox err;
        err.setIcon(QMessageBox::Critical);
        err.setText("You have to specify all fields in the dialog");
        err.exec();
        return;
    }

    projFullPath = projDir + "/" + projName;
    QDir *dir = new QDir();
    dir->mkdir(projFullPath);
    projJob = projType;
}

QString NewProject::FullPath()
{
    return projFullPath;
}

QString NewProject::ProjType()
{
    return projJob;
}
