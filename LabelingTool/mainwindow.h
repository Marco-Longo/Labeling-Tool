#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
    void clearImgList();

private:
    Ui::MainWindow *ui;
    QPushButton *dirSelectButton;
    QFileDialog *dirSelectDialog;
    QLineEdit *dirNameBox;
    QString imgDirectory;
    QString currentImage;
    QLabel *imageLabel;
    QCommandLinkButton *forward, *backward;
    QLinkedList<QPixmap> *images; //List of all the images in the directory
    QLinkedList<QPixmap>::const_iterator iter; //Iterator for the images list
    QHash<QString, QString> *imgLabels; //Associates an image name with a label

public slots:
    void NextImage();
    void PreviousImage();
    void SelectDir(QString dir);
    void AssociateLabel();
};

#endif // MAINWINDOW_H
