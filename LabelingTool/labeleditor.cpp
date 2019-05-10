#include "labeleditor.h"
#include "ui_labeleditor.h"

LabelEditor::LabelEditor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LabelEditor)
{
    ui->setupUi(this);
    entries = new QHash<int, QLineEdit *>();
    ready = false;
    entries -> insert(0, ui->lineEdit0);
    entries -> insert(1, ui->lineEdit1);
    entries -> insert(2, ui->lineEdit2);

    QObject::connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(SendLabels()));
}

LabelEditor::~LabelEditor()
{
    delete ui;
}

void LabelEditor::setDimension(unsigned long n)
{
    labelsCount = int(n);
    int shiftY = int(60*(n-3));
    this->setGeometry(1350, 107, 537, 260+shiftY);
    ui->buttonBox->setGeometry(350, 210+shiftY, 180, 40);

    for(int i=1; i<=labelsCount-3; i++)
    {
        QLineEdit *line = new QLineEdit(this);
        line->setObjectName("lineEdit" + QString::number(i+2));
        line->setGeometry(40, 150+60*i, 460, 40);
        line->setPlaceholderText("Insert Label " + QString::number(i+2) + " name");
        line->show();
        entries -> insert(i+2, line);
    }
}

void LabelEditor::SendLabels()
{
    ready = true;
}

bool LabelEditor::Ready()
{
    return ready;
}

QString LabelEditor::getEntry(int i)
{
    return entries->value(i)->text();
}
