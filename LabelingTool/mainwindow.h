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
#include <QMessageBox>
#include <QCheckBox>
#include <QButtonGroup>
#include <QShortcut>

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
    void UpdateCurrLabel(QString);
    void LoadLabelButtons(QVector<QString>*);
    void ShowSingleLabel();
    void ShowMultiLabel();
    void ShowSegmentation();
    void LoadUI();
    void UpdateUI();
    void ErrorMsg(QString);
    int WarningMsg(QString, QString);
    void SingleLoading();
    void CheckDuplicates(std::vector<QPushButton *>*);
    void RemoveEntries(QString);
    void MultiLoading();
    void CheckMultiDuplicates(QVector<QCheckBox *>*);
    void RemoveMultiEntries(QString);
    void LoadMultiLabelButtons(QVector<QString>*);
    void SegmLoading();

private:
    Ui::MainWindow *ui;
    QPushButton *dirSelectButton;
    QFileDialog *dirSelectDialog;
    QLineEdit *dirNameBox;
    QString imgDirectory;
    QLabel *imageLabel;
    QCommandLinkButton *forward, *backward;
    QLinkedList<Image> *images; //List of all the images in the selected directory
    QLinkedList<Image>::const_iterator iter; //Iterator for the images list
    QHash<QString, QString> *imgLabels; //Associates an image name with a label
    QHash<QString, QString> *labelsHistory; //History hasmap for imgLabels
    QString projectPath;
    QString projectJob;
    QDataStream *dataInputStream;
    QLabel *currentLabel;
    QPushButton *lastLabelButton;
    QLinkedList<QPushButton *> *additionalLabelButtons;
    QFileDialog *loadDialog;
    //MULTI LABEL
    QButtonGroup *multiGroup;
    QString checkbox_qss;
    QHash<QString, QVector<QString>> *imgMultiLabels; //Associates an image name with multiple labels


public slots:
    void NextImage();
    void PreviousImage();
    void SelectDir(QString dir);
    void AssociateLabel();
    void Undo();
    void CreateNewProject();
    void AddLabel();
    void RemoveLabel();
    void EditLabels();
    void FinalizeProject();
    void SaveProject();
    void LoadProject(QString);
    //MULTI LABEL
    void AddMultiLabel();
    void RemoveMultiLabel();
    void EditMultiLabels();
    void AssociateMultiLabel(bool);
    void MultiSaveProject();
    void MultiFinalizeProject();
};

#endif // MAINWINDOW_H
