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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditProgrammDialog
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *close;
    QSpacerItem *horizontalSpacer;
    QPushButton *apply;
    QSpacerItem *horizontalSpacer_2;
    QPlainTextEdit *plainTextEdit;
    QComboBox *comboBox;
    QLineEdit *errorLine;

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
        close = new QPushButton(gridLayoutWidget);
        close->setObjectName(QStringLiteral("close"));

        gridLayout->addWidget(close, 3, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 0, 1, 1);

        apply = new QPushButton(gridLayoutWidget);
        apply->setObjectName(QStringLiteral("apply"));

        gridLayout->addWidget(apply, 3, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 3, 3, 1, 1);

        plainTextEdit = new QPlainTextEdit(gridLayoutWidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));

        gridLayout->addWidget(plainTextEdit, 2, 0, 1, 4);

        comboBox = new QComboBox(gridLayoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(comboBox, 1, 0, 1, 4);

        errorLine = new QLineEdit(gridLayoutWidget);
        errorLine->setObjectName(QStringLiteral("errorLine"));
        errorLine->setMinimumSize(QSize(0, 30));
        errorLine->setReadOnly(true);

        gridLayout->addWidget(errorLine, 0, 0, 1, 4);


        retranslateUi(EditProgrammDialog);

        QMetaObject::connectSlotsByName(EditProgrammDialog);
    } // setupUi

    void retranslateUi(QDialog *EditProgrammDialog)
    {
        EditProgrammDialog->setWindowTitle(QApplication::translate("EditProgrammDialog", "Dialog", 0));
        close->setText(QApplication::translate("EditProgrammDialog", "Fermer", 0));
        apply->setText(QApplication::translate("EditProgrammDialog", "Appliquer", 0));
        comboBox->setCurrentText(QString());
    } // retranslateUi

};

namespace Ui {
    class EditProgrammDialog: public Ui_EditProgrammDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDIT_PROGRAMM_DIALOG_H
