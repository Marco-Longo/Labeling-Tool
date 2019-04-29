#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "image.h"
#include <QMainWindow>
#include <QLabel>
#include <QCommandLinkButton>
#include <QFileDialog>
#include <QLineEdit>
#include <QDirIterator>
#include <QLinkedList>
#include <QListIterator>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void InitImageFrame();
    void ClearImgList();
    void EnableLabels();

private:
    Ui::MainWindow *ui;
    QButtonGroup *labels;
    QPushButton *dirSelectButton;
    QFileDialog *dirSelectDialog;
    QLineEdit *dirNameBox;
    QString imgDirectory;
    QLabel *imageLabel;
    QCommandLinkButton *forward, *backward;
    QLinkedList<Image> *images; //List of all the images in the directory
    QLinkedList<Image>::const_iterator iter; //Iterator for the images list
    QHash<QString, QString> *imgLabels; //Associates an image name with a label
    QHash<QString, QString> *labelsHistory; //History hasmap for imgLabels

public slots:
    void NextImage();
    void PreviousImage();
    void SelectDir(QString dir);
    void AssociateLabel();
    void Undo();
    void CreateNewProject();
};

#endif // MAINWINDOW_H
