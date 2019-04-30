#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newproject.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowIcon(QPixmap("./Assets/icon.png"));
    QObject::connect(ui->b_label0, SIGNAL(clicked()), this, SLOT(AssociateLabel()));
    QObject::connect(ui->b_label1, SIGNAL(clicked()), this, SLOT(AssociateLabel()));
    QObject::connect(ui->b_label2, SIGNAL(clicked()), this, SLOT(AssociateLabel()));
    QObject::connect(ui->b_addlabel, SIGNAL(clicked()), this, SLOT(AddLabel()));
    QObject::connect(ui->b_undo, SIGNAL(clicked()), this, SLOT(Undo()));
    lastLabelButton = ui->b_label2;

    QObject::connect(ui->actionQuit, SIGNAL(triggered()), QApplication::instance(), SLOT(quit()));
    QObject::connect(ui->actionNew_Project, SIGNAL(triggered()), this, SLOT(CreateNewProject()));

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
    additionalLabelButtons = new QLinkedList<QPushButton *>();
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

    currentLabel = new QLabel(imageLabel);
    currentLabel->setMinimumSize(QSize(150,40));
    currentLabel->setGeometry(870, 0, 150, 40);
    currentLabel->setText("No Label");
    currentLabel->setAlignment(Qt::AlignCenter);
    currentLabel->setFont(QFont("Ubuntu", 15, -20));
    currentLabel->setStyleSheet("background: #1AC8F5; color:white; border-bottom-left-radius: 25px; border-bottom-right-radius: 25px");
    currentLabel->setHidden(true);

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
        if(imgLabels->contains(iter->path))
            currentLabel->setText(imgLabels->value(iter->path));
        else
            currentLabel->setText("No Label");
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
        if(imgLabels->contains(iter->path))
            currentLabel->setText(imgLabels->value(iter->path));
        else
            currentLabel->setText("No Label");
    }
}

void MainWindow::ClearImgList()
{
    images->clear();
    imageLabel->setPixmap(QPixmap("./Assets/placeholder.jpg"));
}

void MainWindow::EnableLabels()
{
    ui->b_label0->setEnabled(true);
    ui->b_label1->setEnabled(true);
    ui->b_label2->setEnabled(true);
    currentLabel->setHidden(false);
}

void MainWindow::SelectDir(QString path)
{
    imgDirectory = path;
    dirNameBox->setText(imgDirectory);
    QDirIterator *dir = new QDirIterator(imgDirectory, QDirIterator::Subdirectories);
    ClearImgList();
    while(dir->hasNext())
    {
        QFileInfo fi = dir->fileInfo();
        if(fi.completeSuffix() == "jpeg" || fi.completeSuffix() == "png" || fi.completeSuffix() == "jpg"
           || fi.completeSuffix() == "svg" || fi.completeSuffix() == "gif" || fi.completeSuffix() == "bmp")
            images->append(Image(QPixmap(dir->filePath()), dir->fileName()));
        dir->next();
    }
    EnableLabels();
    iter = images->begin();
    if(!images->isEmpty())
        imageLabel->setPixmap(iter->pic);
}

void MainWindow::UpdateCurrLabel(QString s)
{
    QPushButton *button = this->centralWidget()->findChild<QPushButton *>(s, Qt::FindDirectChildrenOnly);
    currentLabel->setText(button->text());
}

void MainWindow::AssociateLabel()
{
    if(images->isEmpty())
        return;

    QObject *snd = QObject::sender();
    QString label = (this->centralWidget()->findChild<QPushButton *>(snd->objectName(), Qt::FindDirectChildrenOnly))->text();
    QString currentImage = QString(iter->path);

    if(label != imgLabels->value(currentImage))
    {
        if(imgLabels->contains(currentImage))
            labelsHistory->insert(currentImage, imgLabels->value(currentImage));
        imgLabels->insert(currentImage, label);
        ui->b_undo->setEnabled(true);
    }
    UpdateCurrLabel(snd->objectName());

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
    ui->b_undo->setEnabled(false);
    if(imgLabels->contains(currentImage))
        currentLabel->setText(imgLabels->value(currentImage));
    else
        currentLabel->setText("No Label");

    //qDebug() << "History Hash" << currentImage << (labelsHistory->contains(currentImage) ? labelsHistory->value(currentImage) : "empty");
    //qDebug() << "Hash" << currentImage << (imgLabels->contains(currentImage) ? imgLabels->value(currentImage) : "empty");
}

void MainWindow::CreateNewProject()
{
    NewProject *np = new NewProject();
    np->exec();
    projectPath = np->FullPath();
    if(projectPath != "")
        this->setWindowTitle("LabelingTool  -  " + projectPath);
}

void MainWindow::AddLabel()
{
    if(additionalLabelButtons->count() == 8)
        return;

    QPoint loc = (lastLabelButton->geometry()).topLeft();
    loc.setY(loc.y()+60);
    QPushButton *newButton = new QPushButton(this->centralWidget());
    newButton -> setGeometry(loc.x(), loc.y(), 190, 40);
    newButton -> setText("New Label");
    newButton -> setObjectName("b_label" + QString::number(additionalLabelButtons->count()+3));
    additionalLabelButtons->push_back(newButton);
    newButton->show();
    QObject::connect(newButton, SIGNAL(clicked()), this, SLOT(AssociateLabel()));
    lastLabelButton = additionalLabelButtons->last();
}

//TODO: saving project state (saving QHash+dirname object on a file) + load project menù entry -> QDataStream+QFile;
//      saving output on a txt file -> QTextStream+QFile
//      editing label names
