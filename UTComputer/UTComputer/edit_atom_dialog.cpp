#include "edit_atom_dialog.h"
#include "ui_edit_atom_dialog.h"

#include "literal.h"
#include "literal_factory.h"

EditAtomDialog::EditAtomDialog(LiteralFactory* f, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditAtomDialog),
    factory(f)
{
    ui->setupUi(this);

    this->setWindowTitle("UTComputer - Edition des variables");

    // On ajoute les atomes
    for(LiteralFactory::iterator literal = factory->begin(); literal != factory->end(); ++literal)
        if((*literal).isAtom())
            ui->comboBox->addItem((*literal).toString(), (*literal).eval());

    QObject::connect(ui->comboBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(showAtomContent()));
    QObject::connect(ui->close, SIGNAL(pressed()), this, SLOT(close()));

    showAtomContent();
}

EditAtomDialog::~EditAtomDialog()
{
    delete ui;
}

void EditAtomDialog::showAtomContent(){
    ui->lineEdit->setText(ui->comboBox->currentData().toString());
}
