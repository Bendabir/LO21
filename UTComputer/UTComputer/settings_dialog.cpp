#include "settings_dialog.h"
#include "ui_settings_dialog.h"

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);

    this->setWindowTitle("UTComputer - Paramètres");
    this->setFixedSize(400, 190);
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}
