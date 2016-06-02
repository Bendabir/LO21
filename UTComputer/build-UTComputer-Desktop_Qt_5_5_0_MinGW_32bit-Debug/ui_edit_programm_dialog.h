/********************************************************************************
** Form generated from reading UI file 'edit_programm_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDIT_PROGRAMM_DIALOG_H
#define UI_EDIT_PROGRAMM_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditProgrammDialog
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPlainTextEdit *plainTextEdit;
    QDialogButtonBox *buttonBox;
    QComboBox *comboBox;

    void setupUi(QDialog *EditProgrammDialog)
    {
        if (EditProgrammDialog->objectName().isEmpty())
            EditProgrammDialog->setObjectName(QStringLiteral("EditProgrammDialog"));
        EditProgrammDialog->resize(640, 480);
        EditProgrammDialog->setMinimumSize(QSize(640, 480));
        EditProgrammDialog->setMaximumSize(QSize(640, 480));
        EditProgrammDialog->setBaseSize(QSize(640, 480));
        gridLayoutWidget = new QWidget(EditProgrammDialog);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(9, 9, 621, 461));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        plainTextEdit = new QPlainTextEdit(gridLayoutWidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));

        gridLayout->addWidget(plainTextEdit, 1, 0, 1, 1);

        buttonBox = new QDialogButtonBox(gridLayoutWidget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close|QDialogButtonBox::Save);

        gridLayout->addWidget(buttonBox, 2, 0, 1, 1);

        comboBox = new QComboBox(gridLayoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout->addWidget(comboBox, 0, 0, 1, 1);


        retranslateUi(EditProgrammDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), EditProgrammDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), EditProgrammDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(EditProgrammDialog);
    } // setupUi

    void retranslateUi(QDialog *EditProgrammDialog)
    {
        EditProgrammDialog->setWindowTitle(QApplication::translate("EditProgrammDialog", "Dialog", 0));
        comboBox->setCurrentText(QString());
    } // retranslateUi

};

namespace Ui {
    class EditProgrammDialog: public Ui_EditProgrammDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDIT_PROGRAMM_DIALOG_H
