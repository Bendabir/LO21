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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditAtomDialog
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *close;
    QPushButton *apply;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *lineEdit;
    QComboBox *comboBox;
    QLineEdit *errorLine;

    void setupUi(QDialog *EditAtomDialog)
    {
        if (EditAtomDialog->objectName().isEmpty())
            EditAtomDialog->setObjectName(QStringLiteral("EditAtomDialog"));
        EditAtomDialog->resize(640, 190);
        gridLayoutWidget = new QWidget(EditAtomDialog);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 621, 171));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 0, 1, 1);

        close = new QPushButton(gridLayoutWidget);
        close->setObjectName(QStringLiteral("close"));

        gridLayout->addWidget(close, 3, 1, 1, 1);

        apply = new QPushButton(gridLayoutWidget);
        apply->setObjectName(QStringLiteral("apply"));

        gridLayout->addWidget(apply, 3, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 3, 3, 1, 1);

        lineEdit = new QLineEdit(gridLayoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(lineEdit, 2, 0, 1, 4);

        comboBox = new QComboBox(gridLayoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(comboBox, 1, 0, 1, 4);

        errorLine = new QLineEdit(gridLayoutWidget);
        errorLine->setObjectName(QStringLiteral("errorLine"));
        errorLine->setMinimumSize(QSize(0, 30));
        QFont font;
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        errorLine->setFont(font);
        errorLine->setReadOnly(true);

        gridLayout->addWidget(errorLine, 0, 0, 1, 4);


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
