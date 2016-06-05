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

    QObject::connect(this, SIGNAL(isShown()), this, SLOT(updateVariablesList()));

    updateVariablesList();
}

EditAtomDialog::~EditAtomDialog()
{
    delete ui;
}

void EditAtomDialog::showAtomContent(){
    // Affiche le contenu d'une variable
    ui->lineEdit->setText(ui->comboBox->currentData().toString());
}

void EditAtomDialog::updateVariablesList(){
    // On efface tout et on ré-affiche
    ui->comboBox->clear();

    // On ajoute les atomes
    for(LiteralFactory::iterator literal = factory->begin(); literal != factory->end(); ++literal)
        if((*literal).isAtom())
            ui->comboBox->addItem((*literal).toString(), (*literal).eval());

    QObject::connect(ui->comboBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(showAtomContent()));
    QObject::connect(ui->close, SIGNAL(pressed()), this, SLOT(close()));

    showAtomContent();
}

void EditAtomDialog::improvedShow(){
    // Permet de savoir quand la fenêtre est ouverte, utile pour mettre à jour l'affichage à chaque ouverture.
    show();
    emit isShown();
}
