#include <QDebug>

#include "edit_atom_dialog.h"
#include "ui_edit_atom_dialog.h"
#include "atom_literal.h"
#include "literal_factory.h"

EditAtomDialog::EditAtomDialog(LiteralFactory* f, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditAtomDialog),
    factory(f)
{
    ui->setupUi(this);

    this->setWindowTitle("UTComputer - Edition des variables");

    QObject::connect(this, SIGNAL(isShown()), this, SLOT(updateVariablesList()));
    QObject::connect(ui->apply, SIGNAL(pressed()), this, SLOT(editVariable()));
    QObject::connect(ui->comboBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(showAtomContent()));
    QObject::connect(ui->close, SIGNAL(pressed()), this, SLOT(close()));
    QObject::connect(ui->lineEdit, SIGNAL(textChanged(QString)), this, SLOT(enableLineEdit()));

    ui->errorLine->setText("Aucun message pour le moment.");
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
        if((*literal).isAtom()){
            AtomLiteral& atom = dynamic_cast<AtomLiteral&>(*literal);

            if(!atom.getTarget().isProgramm())
                ui->comboBox->addItem((*literal).toString(), (*literal).eval());
        }

    showAtomContent();
}

void EditAtomDialog::improvedShow(){
    // Permet de savoir quand la fenêtre est ouverte, utile pour mettre à jour l'affichage à chaque ouverture.
    show();
    emit isShown();
}

void EditAtomDialog::editVariable(){
    // On va mettre à jour la variable
    QString content = ui->lineEdit->text();

    // On essaye de mettre à jour
    try {
        AtomLiteral& atom = dynamic_cast<AtomLiteral&>(factory->findLiteral(ui->comboBox->currentText()));
        Literal& literal = factory->addLiteralFromString(content);

        // On remplace la cible puis on supprime l'ancienne
        atom.setTarget(literal);

        factory->removeLiteral(atom.getTarget());

        ui->errorLine->setText("Aucun message pour le moment.");

        int index = ui->comboBox->currentIndex();
        updateVariablesList();
        ui->comboBox->setCurrentIndex(index);

        ui->apply->setDisabled(true);
    }
    catch(const CalculatorException& e){
        ui->lineEdit->setText(factory->findLiteral(ui->comboBox->currentText()).eval());
        ui->errorLine->setText(e.what());
    }
}

void EditAtomDialog::enableLineEdit(){
    ui->apply->setEnabled(true);
}
