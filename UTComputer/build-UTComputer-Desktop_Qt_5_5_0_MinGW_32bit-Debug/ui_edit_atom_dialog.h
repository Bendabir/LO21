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
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditAtomDialog
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QDialogButtonBox *buttonBox;
    QListWidget *listWidget;
    QLineEdit *lineEdit;

    void setupUi(QDialog *EditAtomDialog)
    {
        if (EditAtomDialog->objectName().isEmpty())
            EditAtomDialog->setObjectName(QStringLiteral("EditAtomDialog"));
        EditAtomDialog->resize(640, 480);
        gridLayoutWidget = new QWidget(EditAtomDialog);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 621, 461));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        buttonBox = new QDialogButtonBox(gridLayoutWidget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close|QDialogButtonBox::Save);

        gridLayout->addWidget(buttonBox, 2, 0, 1, 1);

        listWidget = new QListWidget(gridLayoutWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setResizeMode(QListView::Adjust);
        listWidget->setGridSize(QSize(0, 30));
        listWidget->setSortingEnabled(true);

        gridLayout->addWidget(listWidget, 0, 0, 1, 1);

        lineEdit = new QLineEdit(gridLayoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(lineEdit, 1, 0, 1, 1);


        retranslateUi(EditAtomDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), EditAtomDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), EditAtomDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(EditAtomDialog);
    } // setupUi

    void retranslateUi(QDialog *EditAtomDialog)
    {
        EditAtomDialog->setWindowTitle(QApplication::translate("EditAtomDialog", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class EditAtomDialog: public Ui_EditAtomDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDIT_ATOM_DIALOG_H
