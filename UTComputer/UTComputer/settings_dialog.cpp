#include <QDebug>

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

    // On connecte nos slots
    QObject::connect(ui->closeButton, SIGNAL(pressed()), this, SLOT(close()));
    QObject::connect(ui->applyButton, SIGNAL(pressed()), this, SLOT(apply()));
    QObject::connect(ui->keyboard, SIGNAL(pressed()), this, SLOT(enableApply()));
    QObject::connect(ui->sound, SIGNAL(pressed()), this, SLOT(enableApply()));
    QObject::connect(ui->nbLiterals, SIGNAL(valueChanged(int)), this, SLOT(enableApply()));
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::apply(){
    // On applique les modifs
    settings->setDisplayKeyboard(ui->keyboard->isChecked());
    settings->setPlaySound(ui->sound->isChecked());
    settings->setNbLiteralsOnStack(ui->nbLiterals->value());

    ui->applyButton->setDisabled(true);

    emit settingsChanged();
}

void SettingsDialog::enableApply(){
    ui->applyButton->setDisabled(false);
}
