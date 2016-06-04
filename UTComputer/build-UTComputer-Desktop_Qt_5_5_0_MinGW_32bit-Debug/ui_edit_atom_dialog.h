/********************************************************************************
** Form generated from reading UI file 'edit_atom_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDIT_ATOM_DIALOG_H
#define UI_EDIT_ATOM_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditAtomDialog
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *close;
    QPushButton *apply;
    QLineEdit *lineEdit;
    QComboBox *comboBox;

    void setupUi(QDialog *EditAtomDialog)
    {
        if (EditAtomDialog->objectName().isEmpty())
            EditAtomDialog->setObjectName(QStringLiteral("EditAtomDialog"));
        EditAtomDialog->resize(640, 140);
        gridLayoutWidget = new QWidget(EditAtomDialog);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 621, 121));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        close = new QPushButton(gridLayoutWidget);
        close->setObjectName(QStringLiteral("close"));

        gridLayout->addWidget(close, 2, 0, 1, 1);

        apply = new QPushButton(gridLayoutWidget);
        apply->setObjectName(QStringLiteral("apply"));

        gridLayout->addWidget(apply, 2, 1, 1, 1);

        lineEdit = new QLineEdit(gridLayoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(lineEdit, 1, 0, 1, 2);

        comboBox = new QComboBox(gridLayoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout->addWidget(comboBox, 0, 0, 1, 2);


        retranslateUi(EditAtomDialog);

        QMetaObject::connectSlotsByName(EditAtomDialog);
    } // setupUi

    void retranslateUi(QDialog *EditAtomDialog)
    {
        EditAtomDialog->setWindowTitle(QApplication::translate("EditAtomDialog", "Dialog", 0));
        close->setText(QApplication::translate("EditAtomDialog", "Fermer", 0));
        apply->setText(QApplication::translate("EditAtomDialog", "Appliquer", 0));
    } // retranslateUi

};

namespace Ui {
    class EditAtomDialog: public Ui_EditAtomDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDIT_ATOM_DIALOG_H
