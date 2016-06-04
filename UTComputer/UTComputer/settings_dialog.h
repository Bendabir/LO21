#ifndef SETTINGS_DIALOG_H
#define SETTINGS_DIALOG_H

#include <QDialog>

class Settings;

namespace Ui {
class SettingsDialog;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsDialog(Settings* s, QWidget *parent = 0);
    ~SettingsDialog();

private:
    Ui::SettingsDialog *ui;
    Settings* settings;

public slots:
    void apply();
    void enableApply();

signals:
    void settingsChanged();
};

#endif // SETTINGS_DIALOG_H
