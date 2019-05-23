#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newproject.h"
#include "labeleditor.h"
#include "storedata.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowIcon(QPixmap("./Assets/icon.png"));
    ui->b_addlabel->setIcon(QIcon("./Assets/add.png"));
    ui->b_removelabel->setIcon(QIcon("./Assets/remove.png"));
    ui->scrollArea->widget()->setLayout(ui->verticalLayout);

    QObject::connect(ui->b_label0, SIGNAL(clicked()), this, SLOT(AssociateLabel()));
    QObject::connect(ui->b_label1, SIGNAL(clicked()), this, SLOT(AssociateLabel()));
    QObject::connect(ui->b_label2, SIGNAL(clicked()), this, SLOT(AssociateLabel()));
    QObject::connect(ui->b_undo, SIGNAL(clicked()), this, SLOT(Undo()));
    lastLabelButton = ui->b_label2;

    QObject::connect(ui->actionQuit, SIGNAL(triggered()), QApplication::instance(), SLOT(quit()));
    QObject::connect(ui->actionNew_Project, SIGNAL(triggered()), this, SLOT(CreateNewProject()));

    loadDialog = new QFileDialog(this);
    loadDialog->setFileMode(QFileDialog::DirectoryOnly);
    QObject::connect(ui->actionLoad_Project, SIGNAL(triggered()), loadDialog, SLOT(open()));
    QObject::connect(loadDialog, SIGNAL(fileSelected(QString)), this, SLOT(LoadProject(QString)));

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
    InitImageFrame();
    QObject::connect(forward, SIGNAL(clicked()), this, SLOT(NextImage()));
    QObject::connect(backward, SIGNAL(clicked()), this, SLOT(PreviousImage()));

    imgLabels = new QHash<QString, QString>();
    labelsHistory = new QHash<QString, QString>();
    additionalLabelButtons = new QLinkedList<QPushButton *>();
    //Hiding SL buttons
    ui->b_label0->setHidden(true);
    ui->b_label1->setHidden(true);
    ui->b_label2->setHidden(true);
    ui->b_undo->setHidden(true);
    ui->b_addlabel->setHidden(true);
    ui->b_removelabel->setHidden(true);
    ui->b_editlabels->setHidden(true);

    //MULTI LABEL
    multiGroup = new QButtonGroup(this);
    multiGroup->setExclusive(false);
    QFile File("./Assets/QSS/checkbox.qss");
    File.open(QFile::ReadOnly);
    checkbox_qss = QString(File.readAll());
    imgMultiLabels = new QHash<QString, QVector<QString>>();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ErrorMsg(QString msg)
{
    QMessageBox err;
    err.setIcon(QMessageBox::Critical);
    err.setText(msg);
    err.exec();
}

int MainWindow::WarningMsg(QString msg, QString query)
{
    QMessageBox warn;
    warn.setIcon(QMessageBox::Warning);
    warn.setText(msg);
    warn.setInformativeText(query);
    warn.setStandardButtons(QMessageBox::No | QMessageBox::Yes);
    warn.setDefaultButton(QMessageBox::Yes);
    return warn.exec();
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
    forward->setIcon(QPixmap("./Assets/go-next.png"));
    forward->setIconSize(QSize(40,40));

    backward = new QCommandLinkButton(this);
    backward->setGeometry(460,860,53,57);
    backward->setIcon(QPixmap("./Assets/go-previous.png"));
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
        UpdateUI();
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
        UpdateUI();
    }
}

void MainWindow::UpdateUI()
{
    if(projectJob == "SingleLabel")
    {
        ui->b_undo->setEnabled(false);
        if(imgLabels->contains(iter->path))
            currentLabel->setText(imgLabels->value(iter->path));
        else
            currentLabel->setText("No Label");
    }
    else if(projectJob == "MultiLabel")
    {
        foreach(QAbstractButton *button, multiGroup->buttons())
        {
            if(imgMultiLabels->contains(iter->path))
            {
                if(imgMultiLabels->value(iter->path).contains(button->text()))
                    button->setChecked(true);
                else
                    button->setChecked(false);
            }
            else
                button->setChecked(false);
        }
    }
    else if(projectJob == "Segmentation")
    {
        //UI updates based on data structures' values for the current image
    }
}

void MainWindow::LoadUI()
{
    if(projectJob == "SingleLabel")
        ShowSingleLabel();
    else if(projectJob == "MultiLabel")
        ShowMultiLabel();
    else if(projectJob == "Segmentation")
        ShowSegmentation();
}

void MainWindow::EnableLabels()
{
    if(projectJob == "SingleLabel")
    {
        ui->b_label0->setEnabled(true);
        ui->b_label1->setEnabled(true);
        ui->b_label2->setEnabled(true);
        ui->b_addlabel->setEnabled(true);
        UpdateUI();
        currentLabel->setHidden(false);
    }
    else if(projectJob == "MultiLabel")
    {
        foreach(QAbstractButton *button, multiGroup->buttons())
            button->setEnabled(true);
        ui->b_addlabel->setEnabled(true);
        UpdateUI();
    }
    else if(projectJob == "Segmentation")
    {
        //SEGMENT UI enable

        //UpdateUI();
    }
}

void MainWindow::ClearImgList()
{
    images->clear();
    imageLabel->setPixmap(QPixmap("./Assets/placeholder.jpg"));
}

void MainWindow::SelectDir(QString path)
{
    imgDirectory = path;
    dirNameBox->setText(imgDirectory);
    QDirIterator *dir = new QDirIterator(imgDirectory, QDirIterator::Subdirectories);
    ClearImgList();

    bool containsImgs = false;
    while(dir->hasNext())
    {
        QFileInfo fi = dir->fileInfo();
        if(fi.completeSuffix() == "jpeg" || fi.completeSuffix() == "png" || fi.completeSuffix() == "jpg"
           || fi.completeSuffix() == "svg" || fi.completeSuffix() == "gif" || fi.completeSuffix() == "bmp")
          {
            images->append(Image(QPixmap(dir->filePath()), dir->fileName()));
            containsImgs = true;
          }
        dir->next();
    }
    iter = images->begin();
    if(!images->isEmpty())
        imageLabel->setPixmap(iter->pic);
    if(containsImgs)
        EnableLabels();
}

void MainWindow::ShowSingleLabel()
{
    ui->b_label0->setHidden(false);
    ui->b_label1->setHidden(false);
    ui->b_label2->setHidden(false);
    ui->b_undo->setHidden(false);
    ui->b_addlabel->setHidden(false);
    ui->b_removelabel->setHidden(false);
    ui->b_editlabels->setHidden(false);
    ui->verticalLayout->addWidget(ui->b_label0);
    ui->verticalLayout->addWidget(ui->b_label1);
    ui->verticalLayout->addWidget(ui->b_label2);

    QObject::connect(ui->actionFinalize_Project, SIGNAL(triggered()), this, SLOT(FinalizeProject()));
    QObject::connect(ui->actionSave_Project, SIGNAL(triggered()), this, SLOT(SaveProject()));
    QObject::connect(ui->b_addlabel, SIGNAL(clicked()), this, SLOT(AddLabel()));
    QObject::connect(ui->b_removelabel, SIGNAL(clicked()), this, SLOT(RemoveLabel()));
    QObject::connect(ui->b_editlabels, SIGNAL(clicked()), this, SLOT(EditLabels()));
}

void MainWindow::UpdateCurrLabel(QString s)
{
    QPushButton *button = this->centralWidget()->findChild<QPushButton *>(s, Qt::FindChildrenRecursively);
    currentLabel->setText(button->text());
}

void MainWindow::AssociateLabel()
{
    if(images->isEmpty())
        return;

    QObject *snd = QObject::sender();
    QString label = (this->centralWidget()->findChild<QPushButton *>(snd->objectName(), Qt::FindChildrenRecursively))->text();
    QString currentImage = QString(iter->path);

    if(label != imgLabels->value(currentImage))
    {
        if(imgLabels->contains(currentImage))
            labelsHistory->insert(currentImage, imgLabels->value(currentImage));
        imgLabels->insert(currentImage, label);
        ui->b_undo->setEnabled(true);
    }
    UpdateCurrLabel(snd->objectName());
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
}

void MainWindow::CreateNewProject()
{
    if(projectPath != "")
    {
        ErrorMsg("Please save your current project, close the client and then restart it to create a new project");
        return;
    }

    NewProject *np = new NewProject();
    np->exec();
    projectPath = np->FullPath();
    projectJob = np ->ProjType();
    if(projectPath != "" && projectJob != "")
    {
        LoadUI();
        ui->actionSave_Project->setEnabled(true);
        ui->actionFinalize_Project->setEnabled(true);
        this->setWindowTitle("LabelingTool  -  " + projectPath);
    }
}

void MainWindow::AddLabel()
{
    if(images->isEmpty())
    {
        ErrorMsg("The input directory you selected does not contain any supported image file");
        return;
    }

    QPoint loc = (lastLabelButton->geometry()).topLeft();
    loc.setY(loc.y()+60);
    QPushButton *newButton = new QPushButton(this->centralWidget());
    newButton -> setGeometry(loc.x(), loc.y(), 190, 40);
    newButton -> setText("New Label " + QString::number(additionalLabelButtons->count()+3));
    newButton -> setObjectName("b_label" + QString::number(additionalLabelButtons->count()+3));
    newButton -> setMinimumHeight(40);
    newButton -> setMaximumWidth(190);
    newButton -> show();
    ui->verticalLayout->addWidget(newButton);
    additionalLabelButtons->push_back(newButton);

    QObject::connect(newButton, SIGNAL(clicked()), this, SLOT(AssociateLabel()));
    lastLabelButton = additionalLabelButtons->last();

    if(additionalLabelButtons->count() == 1)
        ui->b_removelabel->setEnabled(true);
}

void MainWindow::RemoveLabel()
{
    if(additionalLabelButtons->isEmpty())
        return;
    if(WarningMsg("By deleting a label, the relative entry for all the images will be removed.", "Do you still want to continue?") == QMessageBox::No)
        return;

    QString label = additionalLabelButtons->last()->text();
    additionalLabelButtons->pop_back();
    lastLabelButton->hide();
    delete lastLabelButton;
    if(!additionalLabelButtons->isEmpty())
        lastLabelButton = additionalLabelButtons->last();
    else
        lastLabelButton = ui->b_label2;
    RemoveEntries(label);

    if(additionalLabelButtons->isEmpty())
        ui->b_removelabel->setEnabled(false);
}

void MainWindow::RemoveEntries(QString label)
{
    QLinkedList<Image>::const_iterator tmp_iter = iter;
    for(iter = images->begin(); iter != images->end(); iter++)
    {
        if(imgLabels->value(iter->path) == label)
            imgLabels->remove(iter->path);
    }
    iter = tmp_iter;
    UpdateUI();
}

void MainWindow::EditLabels()
{
    LabelEditor *labEdit = new LabelEditor();
    std::vector<QPushButton *> *editingList = new std::vector<QPushButton *>();
    editingList->push_back(ui->b_label0);
    editingList->push_back(ui->b_label1);
    editingList->push_back(ui->b_label2);
    if(!additionalLabelButtons->isEmpty())
        for(int i=3; i<additionalLabelButtons->count()+3; i++)
        {
            QString nextButton = "b_label";
            nextButton += QString::number(i);
            editingList->push_back(this->centralWidget()->findChild<QPushButton *>(nextButton, Qt::FindChildrenRecursively));
        }
    labEdit->setDimension(editingList->size());
    labEdit->exec();
    if(!labEdit->Ready())
        return;

    for(int i=0; i<int(editingList->size()); i++)
    {
        if(labEdit->getEntry(i) != "")
            editingList->at(static_cast<std::make_unsigned<decltype(i)>::type>(i)) -> setText(labEdit->getEntry(i));
    }
    CheckDuplicates(editingList);
}

void MainWindow::CheckDuplicates(std::vector<QPushButton *> *editingList)
{
    QVector<QString> *labelsList = new QVector<QString>();
    bool error = false;

    for(int i=0; i<int(editingList->size()); i++)
    {
        if(labelsList->contains(editingList->at(static_cast<unsigned long>(i))->text()))
        {
            editingList->at(static_cast<unsigned long>(i))->setText("New Label " + QString::number(i));
            error = true;
        }
        labelsList->push_back(editingList->at(static_cast<unsigned long>(i))->text());
    }
    delete labelsList;
    if(error)
        ErrorMsg("Some of the labels you entered already existed. Their text has been reset to a default value");
}

void MainWindow::FinalizeProject()
{
    if(projectPath == "" || images->isEmpty())
    {
        ErrorMsg("You must first select an image directory");
        return;
    }

    QString filename = projectPath + "/labels.txt";
    QFile file(filename);

    if(file.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        QTextStream stream(&file);
        QLinkedList<Image>::const_iterator tmp_iter = iter;
        for(iter = images->begin(); iter != images->end(); iter++)
        {
            stream << iter->path;
            stream << " ";
            if(imgLabels->value(iter->path) != "")
                stream << imgLabels->value(iter->path);
            else
                stream << "NoLabel";
            stream << endl;
        }
        iter = tmp_iter;
    }
}

void MainWindow::SaveProject()
{
    if(projectPath == "" || images->isEmpty())
    {
        ErrorMsg("You must first select an image directory");
        return;
    }

    QVector<QString>* buttons = new QVector<QString>();
    buttons->push_back(ui->b_label0->text());
    buttons->push_back(ui->b_label1->text());
    buttons->push_back(ui->b_label2->text());
    if(!additionalLabelButtons->isEmpty())
        for(int i=3; i<additionalLabelButtons->count()+3; i++)
        {
            QString nextButton = "b_label";
            nextButton += QString::number(i);
            buttons->push_back(this->centralWidget()->findChild<QPushButton *>(nextButton, Qt::FindChildrenRecursively)->text());
        }

    StoreData *data = new StoreData(imgDirectory, projectJob, imgLabels, buttons);
    QString filename = projectPath + "/projdata.dat";
    QFile file(filename);
    if(file.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        QDataStream out(&file);
        out << QString(data->getJob());
        out << QString(data->getDirectory());
        out << QHash<QString, QString>(*(data->getLabels()));
        out << QVector<QString>(*(data->getButtons()));
    }
}

void MainWindow::LoadProject(QString path)
{
    if(path == "")
        return;
    if(projectPath != "")
    {
        ErrorMsg("Please close the client and restart it to load another project");
        return;
    }

    projectPath = path;
    QDirIterator *dir = new QDirIterator(projectPath, QDirIterator::Subdirectories);
    bool isProj = false;
    while(dir->hasNext())
    {
        QFileInfo fi = dir->fileInfo();
        if(fi.fileName() == "projdata.dat" || fi.fileName() == "labels.dat")
            isProj = true;
        dir->next();
    }
    if(!isProj)
    {
        ErrorMsg("The directory you selected is invalid");
        return;
    }

    this->setWindowTitle("LabelingTool  -  " + projectPath);
    QString filename = projectPath + "/projdata.dat";
    QFile file(filename);
    if(file.open(QIODevice::ReadOnly))
    {
        dataInputStream = new QDataStream(&file);
        QString job;
        (*dataInputStream) >> job;
        projectJob = job;
        LoadUI();

        QString dir;
        (*dataInputStream) >> dir;
        SelectDir(dir);
    }
    else
    {
        ErrorMsg("There was a problem loading the configuration files for the project");
        return;
    }

    if(projectJob == "SingleLabel")
        SingleLoading();
    else if(projectJob == "MultiLabel")
        MultiLoading();
    else if(projectJob == "Segmentation")
        SegmLoading();
    else
        ErrorMsg("Project type is invalid");
}

void MainWindow::SingleLoading()
{
    StoreData *data = new StoreData();
    QHash<QString, QString> *tmp = new QHash<QString, QString>();
    (*dataInputStream) >> *tmp;
    data->setLabels(tmp);

    QVector<QString> *btmp = new QVector<QString>();
    (*dataInputStream) >> *btmp;
    data->setButtons(btmp);

    imgLabels = data->getLabels();
    LoadLabelButtons(data->getButtons());

    if(imgLabels->value(iter->path) != "")
        currentLabel->setText(imgLabels->value(iter->path));
    else
        currentLabel->setText("No Label");

    ui->actionFinalize_Project->setEnabled(true);
    ui->actionSave_Project->setEnabled(true);
    delete dataInputStream;
}

void MainWindow::LoadLabelButtons(QVector<QString>* buttons)
{
    ui->b_label0->setText(buttons->at(0));
    ui->b_label1->setText(buttons->at(1));
    ui->b_label2->setText(buttons->at(2));
    for(int i=3; i<buttons->count(); i++)
    {
        AddLabel();
        QString buttonName = "b_label" + QString::number(i);
        this->centralWidget()->findChild<QPushButton *>(buttonName, Qt::FindChildrenRecursively)->setText(buttons->at(i));
    }
}

//MULTI LABEL
void MainWindow::ShowMultiLabel()
{
    for(int i=0; i<3; i++)
    {
        QCheckBox *box = new QCheckBox(this);
        box->setObjectName("c_label" + QString::number(i));
        box->setText("Label " + QString::number(i));
        box->setGeometry(1120, 95+i*50, 190, 40);
        box->setMinimumHeight(40);
        box->setMaximumWidth(190);
        box->setStyleSheet(checkbox_qss);
        box->setFont(QFont("Ubuntu", 15, -1));
        box->setEnabled(false);
        box->show();
        QObject::connect(box, SIGNAL(clicked(bool)), this, SLOT(AssociateMultiLabel(bool)));
        ui->verticalLayout->addWidget(box);
        multiGroup->addButton(box, i);
    }

    QObject::connect(ui->b_addlabel, SIGNAL(clicked()), this, SLOT(AddMultiLabel()));
    QObject::connect(ui->b_removelabel, SIGNAL(clicked()), this, SLOT(RemoveMultiLabel()));
    QObject::connect(ui->b_editlabels, SIGNAL(clicked()), this, SLOT(EditMultiLabels()));
    QObject::connect(ui->actionFinalize_Project, SIGNAL(triggered()), this, SLOT(MultiFinalizeProject()));
    QObject::connect(ui->actionSave_Project, SIGNAL(triggered()), this, SLOT(MultiSaveProject()));
    ui->b_addlabel->setHidden(false);
    ui->b_removelabel->setHidden(false);
    ui->b_editlabels->setHidden(false);
    ui->scrollArea->setGeometry(1120, 60, 211, 711);
    ui->verticalLayout->setGeometry(QRect(1120, 60, 191, 711));
}

void MainWindow::AddMultiLabel()
{
    if(images->isEmpty())
    {
        ErrorMsg("The input directory you selected does not contain any supported image file");
        return;
    }

    QCheckBox *lastBox = static_cast<QCheckBox *>(multiGroup->buttons().last());
    QPoint loc = (lastBox->geometry()).topLeft();
    loc.setY(loc.y()+50);
    QCheckBox *newBox = new QCheckBox(this);
    newBox -> setObjectName("c_label" + QString::number(multiGroup->buttons().count()));
    newBox -> setText("New Label " + QString::number(multiGroup->buttons().count()));
    newBox -> setGeometry(loc.x(), loc.y(), 190, 40);
    newBox -> setMinimumHeight(40);
    newBox -> setMaximumWidth(190);
    newBox -> setStyleSheet(checkbox_qss);
    newBox -> setFont(QFont("Ubuntu", 15, -1));
    newBox -> show();
    QObject::connect(newBox, SIGNAL(clicked(bool)), this, SLOT(AssociateMultiLabel(bool)));
    ui->verticalLayout->addWidget(newBox);
    multiGroup->addButton(newBox, multiGroup->buttons().count());

    if(multiGroup->buttons().count() == 4)
        ui->b_removelabel->setEnabled(true);
}

void MainWindow::RemoveMultiLabel()
{
    if(multiGroup->buttons().isEmpty())
        return;
    if(WarningMsg("By deleting a label, the relative entry for all the images will be removed.", "Do you still want to continue?") == QMessageBox::No)
        return;

    QCheckBox *elimBox = static_cast<QCheckBox *>(multiGroup->buttons().last());
    QString label = elimBox->text();
    elimBox->hide();
    delete elimBox;
    multiGroup->buttons().pop_back();
    RemoveMultiEntries(label);

    if(multiGroup->buttons().count() == 3)
        ui->b_removelabel->setEnabled(false);
}

void MainWindow::RemoveMultiEntries(QString label)
{
    QLinkedList<Image>::const_iterator tmp_iter = iter;
    for(iter = images->begin(); iter != images->end(); iter++)
    {
        if(imgMultiLabels->contains(iter->path))
        {
            if(imgMultiLabels->value(iter->path).contains(label))
            {
                QList<QString> aux = imgMultiLabels->value(iter->path).toList();
                aux.removeOne(label);
                imgMultiLabels->insert(iter->path, aux.toVector());
            }
        }
    }
    iter = tmp_iter;
    UpdateUI();
}

void MainWindow::EditMultiLabels()
{
    LabelEditor *labEdit = new LabelEditor();
    QVector<QCheckBox *> *editingList = new QVector<QCheckBox *>();
    foreach(QAbstractButton *button, multiGroup->buttons())
        editingList->push_back(static_cast<QCheckBox *>(button));

    labEdit->setDimension(static_cast<unsigned long>(editingList->size()));
    labEdit->exec();
    if(!labEdit->Ready())
        return;

    for(int i=0; i<int(editingList->size()); i++)
    {
        if(labEdit->getEntry(i) != "")
            editingList->at(i) -> setText(labEdit->getEntry(i));
    }
    CheckMultiDuplicates(editingList);
}

void MainWindow::CheckMultiDuplicates(QVector<QCheckBox *> *editingList)
{
    QVector<QString> *labelsList = new QVector<QString>();
    bool error = false;

    for(int i=0; i<int(editingList->size()); i++)
    {
        if(labelsList->contains(editingList->at(i)->text()))
        {
            editingList->at(i)->setText("New Label " + QString::number(i));
            error = true;
        }
        labelsList->push_back(editingList->at(i)->text());
    }
    delete labelsList;
    if(error)
        ErrorMsg("Some of the labels you entered already existed. Their text has been reset to a default value");
}

void MainWindow::AssociateMultiLabel(bool checked)
{
    if(images->isEmpty())
        return;

    QObject *snd = QObject::sender();
    QString label = (this->findChild<QCheckBox *>(snd->objectName(), Qt::FindChildrenRecursively))->text();
    QString currentImage = QString(iter->path);

    if(checked)
    {
        QList<QString> aux = imgMultiLabels->value(currentImage).toList();
        aux.push_back(label);
        imgMultiLabels->insert(currentImage, aux.toVector());
    }
    else
    {
        QList<QString> aux = imgMultiLabels->value(currentImage).toList();
        aux.removeOne(label);
        imgMultiLabels->insert(currentImage, aux.toVector());
    }
}

void MainWindow::MultiFinalizeProject()
{
    if(projectPath == "" || images->isEmpty())
    {
        ErrorMsg("You must first select an image directory");
        return;
    }

    QString filename = projectPath + "/labels.txt";
    QFile file(filename);
    if(file.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        QTextStream stream(&file);
        QLinkedList<Image>::const_iterator tmp_iter = iter;
        for(iter = images->begin(); iter != images->end(); iter++)
        {
            stream << iter->path;
            stream << " ";
            if(imgMultiLabels->contains(iter->path))
            {
                QVector<QString> tmp = imgMultiLabels->value(iter->path);
                if(tmp.isEmpty())
                    stream << "NoLabel";
                for(int i=0; i<tmp.size(); i++)
                    stream << tmp.at(i) << " ";
            }
            else
                stream << "NoLabel";
            stream << endl;
        }
        iter = tmp_iter;
    }
}

void MainWindow::MultiSaveProject()
{
    if(projectPath == "" || images->isEmpty())
    {
        ErrorMsg("You must first select an image directory");
        return;
    }

    QVector<QString> *checkboxes = new QVector<QString>();
    foreach(QAbstractButton *button, multiGroup->buttons())
        checkboxes->push_back(button->text());

    QString filename = projectPath + "/projdata.dat";
    QFile file(filename);
    if(file.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        QDataStream out(&file);
        out << QString(projectJob);
        out << QString(imgDirectory);
        out << QHash<QString, QVector<QString>>(*imgMultiLabels);
        out << QVector<QString>(*checkboxes);
    }
}

void MainWindow::MultiLoading()
{
    QHash<QString, QVector<QString>> *tmp = new QHash<QString, QVector<QString>>();
    (*dataInputStream) >> *tmp;
    imgMultiLabels = tmp;

    QVector<QString> *ctmp = new QVector<QString>();
    (*dataInputStream) >> *ctmp;
    LoadMultiLabelButtons(ctmp);

    UpdateUI();
    ui->actionFinalize_Project->setEnabled(true);
    ui->actionSave_Project->setEnabled(true);
    delete dataInputStream;
}

void MainWindow::LoadMultiLabelButtons(QVector<QString> *checkboxes)
{
    multiGroup->button(0)->setText(checkboxes->at(0));
    multiGroup->button(1)->setText(checkboxes->at(1));
    multiGroup->button(2)->setText(checkboxes->at(2));

    for(int i=3; i<checkboxes->size(); i++)
    {
        AddMultiLabel();
        multiGroup->button(i)->setText(checkboxes->at(i));
    }
}






















//SEGMENTATION
void MainWindow::ShowSegmentation()
{
    //UI buttons

    //save+finalize connects
}

void MainWindow::SegmLoading()
{

}
