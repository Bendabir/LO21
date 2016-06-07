#include <QDebug>


#include "edit_programm_dialog.h"
#include "ui_edit_programm_dialog.h"
#include "literal_factory.h"
#include "atom_literal.h"

EditProgrammDialog::EditProgrammDialog(LiteralFactory* f, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditProgrammDialog),
    factory(f)
{
    ui->setupUi(this);

    this->setWindowTitle("UTComputer - Edition des programmes");
    ui->errorLine->setText("Aucun message pour le moment.");

    // On connecte les slots
    QObject::connect(ui->close, SIGNAL(pressed()), this, SLOT(close()));
    QObject::connect(this, SIGNAL(isShown()), this, SLOT(updateVariablesList()));
    QObject::connect(ui->apply, SIGNAL(pressed()), this, SLOT(editVariable()));
    QObject::connect(ui->comboBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(showAtomContent()));
    QObject::connect(ui->plainTextEdit, SIGNAL(textChanged()), this, SLOT(enableApply()));

    updateVariablesList();
}

EditProgrammDialog::~EditProgrammDialog()
{
    delete ui;
}

void EditProgrammDialog::showAtomContent(){
    // Affiche le contenu d'une variable
    ui->plainTextEdit->document()->setPlainText(ui->comboBox->currentData().toString());
}

void EditProgrammDialog::updateVariablesList(){
    // On efface tout et on ré-affiche
    ui->comboBox->clear();

    // On ajoute les atomes
    for(LiteralFactory::iterator literal = factory->begin(); literal != factory->end(); ++literal)
        if((*literal).isAtom()){
            AtomLiteral& atom = dynamic_cast<AtomLiteral&>(*literal);

            if(atom.getTarget().isProgramm())
                ui->comboBox->addItem((*literal).toString(), (*literal).eval());
        }

    showAtomContent();

    if(ui->comboBox->count() == 0){
        ui->comboBox->setDisabled(true);
        ui->plainTextEdit->setDisabled(true);
        ui->apply->setDisabled(true);
        ui->errorLine->setText("Aucun programme à éditer pour le moment.");
    }
    else{
        ui->comboBox->setEnabled(true);
        ui->plainTextEdit->setEnabled(true);
        ui->apply->setEnabled(true);
        ui->errorLine->setText("Aucun message pour le moment.");
    }
}

void EditProgrammDialog::improvedShow(){
    // Permet de savoir quand la fenêtre est ouverte, utile pour mettre à jour l'affichage à chaque ouverture.
    show();
    emit isShown();
}

void EditProgrammDialog::editVariable(){
    // On va mettre à jour la variable
    QString content = ui->plainTextEdit->document()->toPlainText();

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
        ui->plainTextEdit->document()->setPlainText(factory->findLiteral(ui->comboBox->currentText()).eval());
        ui->errorLine->setText(e.what());
    }
}

void EditProgrammDialog::enableApply(){
    ui->apply->setEnabled(true);
}
