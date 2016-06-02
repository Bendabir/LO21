#include "settings_dialog.h"
#include "ui_settings_dialog.h"
#include "settings.h"

SettingsDialog::SettingsDialog(Settings* s, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog),
    settings(s)
{
    ui->setupUi(this);

    this->setWindowTitle("UTComputer - Paramètres");
    this->setFixedSize(400, 190);

    // On charge les paramètres
    ui->keyboard->setChecked(settings->getDisplayKeyboard());
    ui->sound->setChecked(settings->getPlaySound());
    ui->nbLiterals->setValue(settings->getNbLiteralsOnStack());
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::save(){

}
