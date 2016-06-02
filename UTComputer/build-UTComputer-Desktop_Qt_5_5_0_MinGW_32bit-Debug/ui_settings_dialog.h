/********************************************************************************
** Form generated from reading UI file 'settings_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_DIALOG_H
#define UI_SETTINGS_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsDialog
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QDialogButtonBox *buttonBox;
    QSpinBox *nbLiterals;
    QLabel *label;
    QCheckBox *sound;
    QCheckBox *keyboard;

    void setupUi(QDialog *SettingsDialog)
    {
        if (SettingsDialog->objectName().isEmpty())
            SettingsDialog->setObjectName(QStringLiteral("SettingsDialog"));
        SettingsDialog->resize(400, 190);
        gridLayoutWidget = new QWidget(SettingsDialog);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(9, 9, 381, 171));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        buttonBox = new QDialogButtonBox(gridLayoutWidget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setLayoutDirection(Qt::LeftToRight);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Apply|QDialogButtonBox::Close);
        buttonBox->setCenterButtons(false);

        gridLayout->addWidget(buttonBox, 3, 1, 1, 1);

        nbLiterals = new QSpinBox(gridLayoutWidget);
        nbLiterals->setObjectName(QStringLiteral("nbLiterals"));
        nbLiterals->setMinimum(1);
        nbLiterals->setMaximum(10);
        nbLiterals->setValue(5);

        gridLayout->addWidget(nbLiterals, 2, 1, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 2, 0, 1, 1);

        sound = new QCheckBox(gridLayoutWidget);
        sound->setObjectName(QStringLiteral("sound"));

        gridLayout->addWidget(sound, 1, 0, 1, 2);

        keyboard = new QCheckBox(gridLayoutWidget);
        keyboard->setObjectName(QStringLiteral("keyboard"));

        gridLayout->addWidget(keyboard, 0, 0, 1, 2);


        retranslateUi(SettingsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), SettingsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SettingsDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *SettingsDialog)
    {
        SettingsDialog->setWindowTitle(QApplication::translate("SettingsDialog", "Dialog", 0));
        label->setText(QApplication::translate("SettingsDialog", "Nombre d'\303\251l\303\251ments de la pile \303\240 afficher", 0));
        sound->setText(QApplication::translate("SettingsDialog", "Jouer un son lors d'un message", 0));
        keyboard->setText(QApplication::translate("SettingsDialog", "Afficher le clavier cliquable", 0));
    } // retranslateUi

};

namespace Ui {
    class SettingsDialog: public Ui_SettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_DIALOG_H
