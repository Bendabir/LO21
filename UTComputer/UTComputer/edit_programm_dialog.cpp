#include "edit_programm_dialog.h"
#include "ui_edit_programm_dialog.h"

EditProgrammDialog::EditProgrammDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditProgrammDialog)
{
    ui->setupUi(this);

    this->setWindowTitle("UTComputer - Edition des programmes");
    this->setFixedSize(640, 480);
}

EditProgrammDialog::~EditProgrammDialog()
{
    delete ui;
}
