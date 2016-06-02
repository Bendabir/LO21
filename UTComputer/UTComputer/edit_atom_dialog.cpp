#include "edit_atom_dialog.h"
#include "ui_edit_atom_dialog.h"

EditAtomDialog::EditAtomDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditAtomDialog)
{
    ui->setupUi(this);

    this->setWindowTitle("UTComputer - Edition des variables");
    this->setFixedSize(640, 480);

    ui->listWidget->addItem("X1");
    ui->listWidget->addItem("Y3");
    ui->listWidget->addItem("Y2");
    ui->listWidget->addItem("Z");
}

EditAtomDialog::~EditAtomDialog()
{
    delete ui;
}
