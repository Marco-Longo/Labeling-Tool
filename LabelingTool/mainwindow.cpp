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
    images = new QLinkedList<QPixmap>();
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
        imageLabel->setPixmap(*iter);
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
        imageLabel->setPixmap(*iter);
    }
}

void MainWindow::clearImgList()
{
    images->clear();
    imageLabel->setPixmap(QPixmap("./Assets/placeholder.jpg"));
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
            images->append(dir->filePath());
        dir->next();
    }
    iter = images->begin();
    if(!images->isEmpty())
        imageLabel->setPixmap(*iter);
}

void MainWindow::AssociateLabel()
{
    if(images->isEmpty())
        return;
    if(imgLabels == nullptr)
        imgLabels = new QHash<QString, QString>();

    QObject *snd = QObject::sender();
    QString label = snd->objectName();
    label.remove(0, label.length()-1);

    //TODO: find a way to always have currentImage up to date
    imgLabels->insert(currentImage, label);
    qDebug() << "Hash:" << currentImage << imgLabels->value(currentImage);
}
