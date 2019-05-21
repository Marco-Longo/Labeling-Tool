#include "labeleditor.h"
#include "ui_labeleditor.h"

LabelEditor::LabelEditor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LabelEditor)
{
    ui->setupUi(this);
    ui->scrollArea->widget()->setLayout(ui->verticalLayout);
    ui->verticalLayout->addWidget(ui->lineEdit0);
    ui->verticalLayout->addWidget(ui->lineEdit1);
    ui->verticalLayout->addWidget(ui->lineEdit2);

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
    this->setGeometry(1370, 127, 537, 295+shiftY);
    if(shiftY >= 480)
        ui->buttonBox->setGeometry(350, 710, 180, 40);
    else
        ui->buttonBox->setGeometry(350, 245+shiftY, 180, 40);
    ui->scrollArea->setGeometry(10, 10, 521, 241+shiftY);

    for(int i=1; i<=labelsCount-3; i++)
    {
        QLineEdit *line = new QLineEdit(this);
        line->setObjectName("lineEdit" + QString::number(i+2));
        line->setGeometry(25, 145+60*i, 460, 40);
        line->setMinimumHeight(40);
        line->setPlaceholderText("Insert Label " + QString::number(i+2) + " name");
        line->show();
        ui->verticalLayout->addWidget(line);
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
