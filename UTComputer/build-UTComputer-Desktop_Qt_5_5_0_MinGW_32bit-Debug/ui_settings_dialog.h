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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsDialog
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QCheckBox *keyboard;
    QCheckBox *sound;
    QSpinBox *nbLiterals;
    QPushButton *applyButton;
    QPushButton *closeButton;

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
        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 2, 0, 1, 1);

        keyboard = new QCheckBox(gridLayoutWidget);
        keyboard->setObjectName(QStringLiteral("keyboard"));

        gridLayout->addWidget(keyboard, 0, 0, 1, 2);

        sound = new QCheckBox(gridLayoutWidget);
        sound->setObjectName(QStringLiteral("sound"));

        gridLayout->addWidget(sound, 1, 0, 1, 2);

        nbLiterals = new QSpinBox(gridLayoutWidget);
        nbLiterals->setObjectName(QStringLiteral("nbLiterals"));
        nbLiterals->setMinimum(1);
        nbLiterals->setMaximum(10);
        nbLiterals->setValue(5);

        gridLayout->addWidget(nbLiterals, 2, 1, 1, 1);

        applyButton = new QPushButton(gridLayoutWidget);
        applyButton->setObjectName(QStringLiteral("applyButton"));

        gridLayout->addWidget(applyButton, 3, 1, 1, 1);

        closeButton = new QPushButton(gridLayoutWidget);
        closeButton->setObjectName(QStringLiteral("closeButton"));

        gridLayout->addWidget(closeButton, 3, 0, 1, 1);


        retranslateUi(SettingsDialog);

        QMetaObject::connectSlotsByName(SettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *SettingsDialog)
    {
        SettingsDialog->setWindowTitle(QApplication::translate("SettingsDialog", "Dialog", 0));
        label->setText(QApplication::translate("SettingsDialog", "Nombre d'\303\251l\303\251ments de la pile \303\240 afficher", 0));
        keyboard->setText(QApplication::translate("SettingsDialog", "Afficher le clavier cliquable", 0));
        sound->setText(QApplication::translate("SettingsDialog", "Jouer un son lors d'un message", 0));
        applyButton->setText(QApplication::translate("SettingsDialog", "Appliquer", 0));
        closeButton->setText(QApplication::translate("SettingsDialog", "Fermer", 0));
    } // retranslateUi

};

namespace Ui {
    class SettingsDialog: public Ui_SettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_DIALOG_H
