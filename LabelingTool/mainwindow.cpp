#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->actionQuit, SIGNAL(triggered()), QApplication::instance(), SLOT(quit()));
    QObject::connect(ui->b_label0, SIGNAL(clicked()), this, SLOT(AssociateLabel()));
    QObject::connect(ui->b_label1, SIGNAL(clicked()), this, SLOT(AssociateLabel()));
    QObject::connect(ui->b_label2, SIGNAL(clicked()), this, SLOT(AssociateLabel()));
    QObject::connect(ui->b_undo, SIGNAL(clicked()), this, SLOT(Undo()));

    dirSelectButton = new QPushButton(this);
    dirSelectButton->setFont(QFont("Ubuntu", 12));
    dirSelectButton->setText("Browse...");
    dirSelectButton->setGeometry(930,40,110,30);
    dirNameBox = new QLineEdit(this);
    dirNameBox->setGeometry(40,40,850,30);
    dirNameBox->setPlaceholderText("Browse for an input directory...");
    dirNameBox->setReadOnly(true);
    dirSelectDialog = new QFileDialog(this);
    dirSelectDialog->setFileMode(QFileDialog::DirectoryOnly);
    QObject::connect(dirSelectButton, SIGNAL(clicked()), dirSelectDialog, SLOT(open()));
    QObject::connect(dirSelectDialog, SIGNAL(fileSelected(QString)), this, SLOT(SelectDir(QString)));

    images = new QLinkedList<Image>();
    imgLabels = new QHash<QString, QString>();
    labelsHistory = new QHash<QString, QString>();
    InitImageFrame();
    QObject::connect(forward, SIGNAL(clicked()), this, SLOT(NextImage()));
    QObject::connect(backward, SIGNAL(clicked()), this, SLOT(PreviousImage()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::InitImageFrame()
{
    imageLabel = new QLabel(this);
    imageLabel->setStyleSheet("border: 2px solid gray");
    imageLabel->setGeometry(30,80,1024,768);
    imageLabel->setScaledContents(true);
    imageLabel->setPixmap(QPixmap("./Assets/placeholder.jpg"));

    forward = new QCommandLinkButton(this);
    forward->setGeometry(580,860,53,57);
    forward->setIcon(QPixmap("./Assets/go-next.svg"));
    forward->setIconSize(QSize(40,40));

    backward = new QCommandLinkButton(this);
    backward->setGeometry(460,860,53,57);
    backward->setIcon(QPixmap("./Assets/go-previous.svg"));
    backward->setIconSize(QSize(40,40));
}

void MainWindow::NextImage()
{
    if(!images->isEmpty())
    {
        iter++;
        if(iter == images->end())
            iter = images->begin();
        imageLabel->setPixmap(iter->pic);
        ui->b_undo->setEnabled(false);
    }
}

void MainWindow::PreviousImage()
{
    if(!images->isEmpty())
    {
        if(iter == images->begin())
            iter = images->end()-1;
        else
            iter--;
        imageLabel->setPixmap(iter->pic);
        ui->b_undo->setEnabled(false);
    }
}

void MainWindow::clearImgList()
{
    images->clear();
    imageLabel->setPixmap(QPixmap("./Assets/placeholder.jpg"));
}

void MainWindow::enableLabels()
{
    ui->b_label0->setEnabled(true);
    ui->b_label1->setEnabled(true);
    ui->b_label2->setEnabled(true);
}

void MainWindow::SelectDir(QString path)
{
    imgDirectory = path;
    dirNameBox->setText(imgDirectory);
    QDirIterator *dir = new QDirIterator(imgDirectory, QDirIterator::Subdirectories);
    clearImgList();
    while(dir->hasNext())
    {
        QFileInfo fi = dir->fileInfo();
        if(fi.completeSuffix() == "jpeg" || fi.completeSuffix() == "png" || fi.completeSuffix() == "jpg"
           || fi.completeSuffix() == "svg" || fi.completeSuffix() == "gif" || fi.completeSuffix() == "bmp")
            images->append(Image(QPixmap(dir->filePath()), dir->fileName()));
        dir->next();
    }
    enableLabels();
    iter = images->begin();
    if(!images->isEmpty())
        imageLabel->setPixmap(iter->pic);
}

void MainWindow::AssociateLabel()
{
    if(images->isEmpty())
        return;

    QObject *snd = QObject::sender();
    QString label = snd->objectName();
    label.remove(0, label.length()-1);
    QString currentImage = QString(iter->path);

    if(label != imgLabels->value(currentImage))
    {
        if(imgLabels->contains(currentImage))
            labelsHistory->insert(currentImage, imgLabels->value(currentImage));
        imgLabels->insert(currentImage, label);
    }
    ui->b_undo->setEnabled(true);

    //qDebug() << "History Hash" << currentImage << (labelsHistory->contains(currentImage) ? labelsHistory->value(currentImage) : "empty");
    //qDebug() << "Hash" << currentImage << (imgLabels->contains(currentImage) ? imgLabels->value(currentImage) : "empty");
}

void MainWindow::Undo()
{
    QString currentImage = QString(iter->path);
    if(labelsHistory->contains(currentImage))
        imgLabels->insert(currentImage, labelsHistory->value(currentImage));
    else
        imgLabels->remove(currentImage);
    labelsHistory->remove(currentImage);
}

//TODO: new project/load project buttons; saving output on a txt file; saving project state (saving QHash+dirname object on a file)
