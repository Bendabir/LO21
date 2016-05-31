/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuitter;
    QAction *actionAide;
    QAction *actionOptions;
    QAction *actionEdition_des_variables;
    QAction *actionEdition_des_programmes;
    QAction *actionA_propos_de_l_application;
    QAction *actionAnnuler;
    QAction *actionR_tablir;
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit;
    QTableWidget *tableWidget;
    QLineEdit *lineEdit_2;
    QGridLayout *gridLayout_10;
    QGridLayout *gridLayout_6;
    QPushButton *pushButton_23;
    QPushButton *pushButton_25;
    QPushButton *pushButton_22;
    QPushButton *pushButton_28;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_37;
    QPushButton *pushButton_38;
    QPushButton *pushButton_39;
    QPushButton *pushButton_40;
    QGridLayout *gridLayout_8;
    QPushButton *pushButton_52;
    QPushButton *pushButton_55;
    QPushButton *pushButton_56;
    QPushButton *pushButton_51;
    QPushButton *pushButton_50;
    QPushButton *pushButton_53;
    QPushButton *pushButton_57;
    QGridLayout *gridLayout_9;
    QGridLayout *gridLayout_7;
    QPushButton *pushButton_48;
    QPushButton *pushButton_49;
    QPushButton *pushButton_41;
    QPushButton *pushButton_44;
    QPushButton *pushButton_45;
    QPushButton *pushButton_43;
    QPushButton *pushButton_46;
    QPushButton *pushButton_42;
    QPushButton *pushButton_47;
    QGridLayout *gridLayout_11;
    QPushButton *pushButton_19;
    QPushButton *pushButton_20;
    QGridLayout *gridLayout;
    QPushButton *pushButton_61;
    QPushButton *pushButton_60;
    QPushButton *pushButton_58;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_17;
    QPushButton *pushButton_11;
    QPushButton *pushButton_7;
    QPushButton *pushButton_6;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton_8;
    QPushButton *pushButton_16;
    QPushButton *pushButton_15;
    QPushButton *pushButton_14;
    QPushButton *pushButton_13;
    QPushButton *pushButton_12;
    QPushButton *pushButton_10;
    QPushButton *pushButton_9;
    QPushButton *pushButton_21;
    QPushButton *pushButton;
    QPushButton *pushButton_59;
    QPushButton *pushButton_54;
    QPushButton *pushButton_18;
    QGridLayout *gridLayout_5;
    QPushButton *pushButton_32;
    QPushButton *pushButton_30;
    QPushButton *pushButton_35;
    QPushButton *pushButton_26;
    QPushButton *pushButton_27;
    QPushButton *pushButton_34;
    QGridLayout *gridLayout_4;
    QPushButton *pushButton_31;
    QPushButton *pushButton_29;
    QPushButton *pushButton_33;
    QPushButton *pushButton_36;
    QPushButton *pushButton_24;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QMenu *menuEdition;
    QMenu *menuA_propos;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1079, 674);
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QStringLiteral("actionQuitter"));
        actionAide = new QAction(MainWindow);
        actionAide->setObjectName(QStringLiteral("actionAide"));
        actionOptions = new QAction(MainWindow);
        actionOptions->setObjectName(QStringLiteral("actionOptions"));
        actionEdition_des_variables = new QAction(MainWindow);
        actionEdition_des_variables->setObjectName(QStringLiteral("actionEdition_des_variables"));
        actionEdition_des_programmes = new QAction(MainWindow);
        actionEdition_des_programmes->setObjectName(QStringLiteral("actionEdition_des_programmes"));
        actionA_propos_de_l_application = new QAction(MainWindow);
        actionA_propos_de_l_application->setObjectName(QStringLiteral("actionA_propos_de_l_application"));
        actionAnnuler = new QAction(MainWindow);
        actionAnnuler->setObjectName(QStringLiteral("actionAnnuler"));
        actionAnnuler->setShortcutContext(Qt::ApplicationShortcut);
        actionR_tablir = new QAction(MainWindow);
        actionR_tablir->setObjectName(QStringLiteral("actionR_tablir"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(9, 9, 1061, 634));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(verticalLayoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setReadOnly(true);

        verticalLayout_2->addWidget(lineEdit);

        tableWidget = new QTableWidget(verticalLayoutWidget);
        if (tableWidget->columnCount() < 1)
            tableWidget->setColumnCount(1);
        if (tableWidget->rowCount() < 5)
            tableWidget->setRowCount(5);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setRowCount(5);
        tableWidget->setColumnCount(1);

        verticalLayout_2->addWidget(tableWidget);

        lineEdit_2 = new QLineEdit(verticalLayoutWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        verticalLayout_2->addWidget(lineEdit_2);

        gridLayout_10 = new QGridLayout();
        gridLayout_10->setSpacing(6);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        pushButton_23 = new QPushButton(verticalLayoutWidget);
        pushButton_23->setObjectName(QStringLiteral("pushButton_23"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_23->sizePolicy().hasHeightForWidth());
        pushButton_23->setSizePolicy(sizePolicy);
        pushButton_23->setBaseSize(QSize(30, 30));

        gridLayout_6->addWidget(pushButton_23, 1, 0, 1, 1);

        pushButton_25 = new QPushButton(verticalLayoutWidget);
        pushButton_25->setObjectName(QStringLiteral("pushButton_25"));
        sizePolicy.setHeightForWidth(pushButton_25->sizePolicy().hasHeightForWidth());
        pushButton_25->setSizePolicy(sizePolicy);
        pushButton_25->setBaseSize(QSize(30, 30));

        gridLayout_6->addWidget(pushButton_25, 2, 0, 1, 1);

        pushButton_22 = new QPushButton(verticalLayoutWidget);
        pushButton_22->setObjectName(QStringLiteral("pushButton_22"));
        sizePolicy.setHeightForWidth(pushButton_22->sizePolicy().hasHeightForWidth());
        pushButton_22->setSizePolicy(sizePolicy);
        pushButton_22->setBaseSize(QSize(30, 30));

        gridLayout_6->addWidget(pushButton_22, 0, 0, 1, 1);

        pushButton_28 = new QPushButton(verticalLayoutWidget);
        pushButton_28->setObjectName(QStringLiteral("pushButton_28"));
        sizePolicy.setHeightForWidth(pushButton_28->sizePolicy().hasHeightForWidth());
        pushButton_28->setSizePolicy(sizePolicy);
        pushButton_28->setBaseSize(QSize(30, 30));

        gridLayout_6->addWidget(pushButton_28, 3, 0, 1, 1);


        gridLayout_10->addLayout(gridLayout_6, 1, 3, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        pushButton_37 = new QPushButton(verticalLayoutWidget);
        pushButton_37->setObjectName(QStringLiteral("pushButton_37"));
        sizePolicy.setHeightForWidth(pushButton_37->sizePolicy().hasHeightForWidth());
        pushButton_37->setSizePolicy(sizePolicy);
        pushButton_37->setBaseSize(QSize(30, 30));

        gridLayout_3->addWidget(pushButton_37, 5, 2, 1, 1);

        pushButton_38 = new QPushButton(verticalLayoutWidget);
        pushButton_38->setObjectName(QStringLiteral("pushButton_38"));
        sizePolicy.setHeightForWidth(pushButton_38->sizePolicy().hasHeightForWidth());
        pushButton_38->setSizePolicy(sizePolicy);
        pushButton_38->setBaseSize(QSize(30, 30));

        gridLayout_3->addWidget(pushButton_38, 4, 2, 1, 1);

        pushButton_39 = new QPushButton(verticalLayoutWidget);
        pushButton_39->setObjectName(QStringLiteral("pushButton_39"));
        sizePolicy.setHeightForWidth(pushButton_39->sizePolicy().hasHeightForWidth());
        pushButton_39->setSizePolicy(sizePolicy);
        pushButton_39->setBaseSize(QSize(30, 30));

        gridLayout_3->addWidget(pushButton_39, 3, 2, 1, 1);

        pushButton_40 = new QPushButton(verticalLayoutWidget);
        pushButton_40->setObjectName(QStringLiteral("pushButton_40"));
        sizePolicy.setHeightForWidth(pushButton_40->sizePolicy().hasHeightForWidth());
        pushButton_40->setSizePolicy(sizePolicy);
        pushButton_40->setBaseSize(QSize(30, 30));

        gridLayout_3->addWidget(pushButton_40, 2, 2, 1, 1);


        gridLayout_10->addLayout(gridLayout_3, 1, 2, 1, 1);

        gridLayout_8 = new QGridLayout();
        gridLayout_8->setSpacing(6);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        pushButton_52 = new QPushButton(verticalLayoutWidget);
        pushButton_52->setObjectName(QStringLiteral("pushButton_52"));
        sizePolicy.setHeightForWidth(pushButton_52->sizePolicy().hasHeightForWidth());
        pushButton_52->setSizePolicy(sizePolicy);

        gridLayout_8->addWidget(pushButton_52, 2, 0, 1, 1);

        pushButton_55 = new QPushButton(verticalLayoutWidget);
        pushButton_55->setObjectName(QStringLiteral("pushButton_55"));
        sizePolicy.setHeightForWidth(pushButton_55->sizePolicy().hasHeightForWidth());
        pushButton_55->setSizePolicy(sizePolicy);

        gridLayout_8->addWidget(pushButton_55, 0, 1, 1, 1);

        pushButton_56 = new QPushButton(verticalLayoutWidget);
        pushButton_56->setObjectName(QStringLiteral("pushButton_56"));
        sizePolicy.setHeightForWidth(pushButton_56->sizePolicy().hasHeightForWidth());
        pushButton_56->setSizePolicy(sizePolicy);

        gridLayout_8->addWidget(pushButton_56, 2, 1, 1, 1);

        pushButton_51 = new QPushButton(verticalLayoutWidget);
        pushButton_51->setObjectName(QStringLiteral("pushButton_51"));
        sizePolicy.setHeightForWidth(pushButton_51->sizePolicy().hasHeightForWidth());
        pushButton_51->setSizePolicy(sizePolicy);

        gridLayout_8->addWidget(pushButton_51, 1, 0, 1, 2);

        pushButton_50 = new QPushButton(verticalLayoutWidget);
        pushButton_50->setObjectName(QStringLiteral("pushButton_50"));
        sizePolicy.setHeightForWidth(pushButton_50->sizePolicy().hasHeightForWidth());
        pushButton_50->setSizePolicy(sizePolicy);

        gridLayout_8->addWidget(pushButton_50, 0, 0, 1, 1);

        pushButton_53 = new QPushButton(verticalLayoutWidget);
        pushButton_53->setObjectName(QStringLiteral("pushButton_53"));
        sizePolicy.setHeightForWidth(pushButton_53->sizePolicy().hasHeightForWidth());
        pushButton_53->setSizePolicy(sizePolicy);

        gridLayout_8->addWidget(pushButton_53, 3, 0, 1, 1);

        pushButton_57 = new QPushButton(verticalLayoutWidget);
        pushButton_57->setObjectName(QStringLiteral("pushButton_57"));
        sizePolicy.setHeightForWidth(pushButton_57->sizePolicy().hasHeightForWidth());
        pushButton_57->setSizePolicy(sizePolicy);

        gridLayout_8->addWidget(pushButton_57, 3, 1, 1, 1);


        gridLayout_10->addLayout(gridLayout_8, 0, 0, 1, 1);

        gridLayout_9 = new QGridLayout();
        gridLayout_9->setSpacing(6);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setSpacing(6);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        pushButton_48 = new QPushButton(verticalLayoutWidget);
        pushButton_48->setObjectName(QStringLiteral("pushButton_48"));
        sizePolicy.setHeightForWidth(pushButton_48->sizePolicy().hasHeightForWidth());
        pushButton_48->setSizePolicy(sizePolicy);
        pushButton_48->setBaseSize(QSize(30, 30));

        gridLayout_7->addWidget(pushButton_48, 1, 0, 1, 1);

        pushButton_49 = new QPushButton(verticalLayoutWidget);
        pushButton_49->setObjectName(QStringLiteral("pushButton_49"));
        sizePolicy.setHeightForWidth(pushButton_49->sizePolicy().hasHeightForWidth());
        pushButton_49->setSizePolicy(sizePolicy);
        pushButton_49->setBaseSize(QSize(30, 30));

        gridLayout_7->addWidget(pushButton_49, 2, 0, 1, 1);

        pushButton_41 = new QPushButton(verticalLayoutWidget);
        pushButton_41->setObjectName(QStringLiteral("pushButton_41"));
        sizePolicy.setHeightForWidth(pushButton_41->sizePolicy().hasHeightForWidth());
        pushButton_41->setSizePolicy(sizePolicy);
        pushButton_41->setBaseSize(QSize(30, 30));

        gridLayout_7->addWidget(pushButton_41, 0, 1, 1, 1);

        pushButton_44 = new QPushButton(verticalLayoutWidget);
        pushButton_44->setObjectName(QStringLiteral("pushButton_44"));
        sizePolicy.setHeightForWidth(pushButton_44->sizePolicy().hasHeightForWidth());
        pushButton_44->setSizePolicy(sizePolicy);
        pushButton_44->setBaseSize(QSize(30, 30));

        gridLayout_7->addWidget(pushButton_44, 0, 2, 1, 1);

        pushButton_45 = new QPushButton(verticalLayoutWidget);
        pushButton_45->setObjectName(QStringLiteral("pushButton_45"));
        sizePolicy.setHeightForWidth(pushButton_45->sizePolicy().hasHeightForWidth());
        pushButton_45->setSizePolicy(sizePolicy);
        pushButton_45->setBaseSize(QSize(30, 30));

        gridLayout_7->addWidget(pushButton_45, 1, 2, 1, 1);

        pushButton_43 = new QPushButton(verticalLayoutWidget);
        pushButton_43->setObjectName(QStringLiteral("pushButton_43"));
        sizePolicy.setHeightForWidth(pushButton_43->sizePolicy().hasHeightForWidth());
        pushButton_43->setSizePolicy(sizePolicy);
        pushButton_43->setBaseSize(QSize(30, 30));

        gridLayout_7->addWidget(pushButton_43, 2, 1, 1, 1);

        pushButton_46 = new QPushButton(verticalLayoutWidget);
        pushButton_46->setObjectName(QStringLiteral("pushButton_46"));
        sizePolicy.setHeightForWidth(pushButton_46->sizePolicy().hasHeightForWidth());
        pushButton_46->setSizePolicy(sizePolicy);
        pushButton_46->setBaseSize(QSize(30, 30));

        gridLayout_7->addWidget(pushButton_46, 2, 2, 1, 1);

        pushButton_42 = new QPushButton(verticalLayoutWidget);
        pushButton_42->setObjectName(QStringLiteral("pushButton_42"));
        sizePolicy.setHeightForWidth(pushButton_42->sizePolicy().hasHeightForWidth());
        pushButton_42->setSizePolicy(sizePolicy);
        pushButton_42->setBaseSize(QSize(30, 30));

        gridLayout_7->addWidget(pushButton_42, 1, 1, 1, 1);

        pushButton_47 = new QPushButton(verticalLayoutWidget);
        pushButton_47->setObjectName(QStringLiteral("pushButton_47"));
        sizePolicy.setHeightForWidth(pushButton_47->sizePolicy().hasHeightForWidth());
        pushButton_47->setSizePolicy(sizePolicy);
        pushButton_47->setBaseSize(QSize(30, 30));

        gridLayout_7->addWidget(pushButton_47, 0, 0, 1, 1);


        gridLayout_9->addLayout(gridLayout_7, 5, 1, 1, 1);

        gridLayout_11 = new QGridLayout();
        gridLayout_11->setSpacing(6);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        pushButton_19 = new QPushButton(verticalLayoutWidget);
        pushButton_19->setObjectName(QStringLiteral("pushButton_19"));
        sizePolicy.setHeightForWidth(pushButton_19->sizePolicy().hasHeightForWidth());
        pushButton_19->setSizePolicy(sizePolicy);

        gridLayout_11->addWidget(pushButton_19, 1, 0, 1, 1);

        pushButton_20 = new QPushButton(verticalLayoutWidget);
        pushButton_20->setObjectName(QStringLiteral("pushButton_20"));
        sizePolicy.setHeightForWidth(pushButton_20->sizePolicy().hasHeightForWidth());
        pushButton_20->setSizePolicy(sizePolicy);

        gridLayout_11->addWidget(pushButton_20, 1, 1, 1, 1);


        gridLayout_9->addLayout(gridLayout_11, 2, 1, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton_61 = new QPushButton(verticalLayoutWidget);
        pushButton_61->setObjectName(QStringLiteral("pushButton_61"));

        gridLayout->addWidget(pushButton_61, 0, 1, 1, 1);

        pushButton_60 = new QPushButton(verticalLayoutWidget);
        pushButton_60->setObjectName(QStringLiteral("pushButton_60"));

        gridLayout->addWidget(pushButton_60, 0, 0, 1, 1);


        gridLayout_9->addLayout(gridLayout, 4, 1, 1, 1);

        pushButton_58 = new QPushButton(verticalLayoutWidget);
        pushButton_58->setObjectName(QStringLiteral("pushButton_58"));
        sizePolicy.setHeightForWidth(pushButton_58->sizePolicy().hasHeightForWidth());
        pushButton_58->setSizePolicy(sizePolicy);

        gridLayout_9->addWidget(pushButton_58, 1, 1, 1, 1);


        gridLayout_10->addLayout(gridLayout_9, 1, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        pushButton_17 = new QPushButton(verticalLayoutWidget);
        pushButton_17->setObjectName(QStringLiteral("pushButton_17"));
        sizePolicy.setHeightForWidth(pushButton_17->sizePolicy().hasHeightForWidth());
        pushButton_17->setSizePolicy(sizePolicy);
        pushButton_17->setBaseSize(QSize(30, 30));

        gridLayout_2->addWidget(pushButton_17, 0, 3, 1, 1);

        pushButton_11 = new QPushButton(verticalLayoutWidget);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        sizePolicy.setHeightForWidth(pushButton_11->sizePolicy().hasHeightForWidth());
        pushButton_11->setSizePolicy(sizePolicy);
        pushButton_11->setBaseSize(QSize(30, 30));

        gridLayout_2->addWidget(pushButton_11, 4, 0, 1, 2);

        pushButton_7 = new QPushButton(verticalLayoutWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        sizePolicy.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy);
        pushButton_7->setBaseSize(QSize(30, 30));

        gridLayout_2->addWidget(pushButton_7, 2, 1, 1, 1);

        pushButton_6 = new QPushButton(verticalLayoutWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        sizePolicy.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy);
        pushButton_6->setBaseSize(QSize(30, 30));

        gridLayout_2->addWidget(pushButton_6, 3, 0, 1, 1);

        pushButton_5 = new QPushButton(verticalLayoutWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        sizePolicy.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy);
        pushButton_5->setBaseSize(QSize(30, 30));

        gridLayout_2->addWidget(pushButton_5, 2, 0, 1, 1);

        pushButton_4 = new QPushButton(verticalLayoutWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);
        pushButton_4->setBaseSize(QSize(30, 30));

        gridLayout_2->addWidget(pushButton_4, 1, 2, 1, 1);

        pushButton_3 = new QPushButton(verticalLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);
        pushButton_3->setBaseSize(QSize(30, 30));

        gridLayout_2->addWidget(pushButton_3, 1, 1, 1, 1);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        pushButton_2->setBaseSize(QSize(30, 30));

        gridLayout_2->addWidget(pushButton_2, 1, 0, 1, 1);

        pushButton_8 = new QPushButton(verticalLayoutWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        sizePolicy.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy);
        pushButton_8->setBaseSize(QSize(30, 30));

        gridLayout_2->addWidget(pushButton_8, 2, 2, 1, 1);

        pushButton_16 = new QPushButton(verticalLayoutWidget);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));
        sizePolicy.setHeightForWidth(pushButton_16->sizePolicy().hasHeightForWidth());
        pushButton_16->setSizePolicy(sizePolicy);
        pushButton_16->setBaseSize(QSize(30, 30));

        gridLayout_2->addWidget(pushButton_16, 1, 3, 1, 1);

        pushButton_15 = new QPushButton(verticalLayoutWidget);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));
        sizePolicy.setHeightForWidth(pushButton_15->sizePolicy().hasHeightForWidth());
        pushButton_15->setSizePolicy(sizePolicy);
        pushButton_15->setBaseSize(QSize(30, 30));

        gridLayout_2->addWidget(pushButton_15, 2, 3, 1, 1);

        pushButton_14 = new QPushButton(verticalLayoutWidget);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        sizePolicy.setHeightForWidth(pushButton_14->sizePolicy().hasHeightForWidth());
        pushButton_14->setSizePolicy(sizePolicy);
        pushButton_14->setBaseSize(QSize(30, 30));

        gridLayout_2->addWidget(pushButton_14, 3, 3, 1, 1);

        pushButton_13 = new QPushButton(verticalLayoutWidget);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        sizePolicy.setHeightForWidth(pushButton_13->sizePolicy().hasHeightForWidth());
        pushButton_13->setSizePolicy(sizePolicy);
        pushButton_13->setBaseSize(QSize(30, 30));

        gridLayout_2->addWidget(pushButton_13, 4, 3, 1, 1);

        pushButton_12 = new QPushButton(verticalLayoutWidget);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        sizePolicy.setHeightForWidth(pushButton_12->sizePolicy().hasHeightForWidth());
        pushButton_12->setSizePolicy(sizePolicy);
        pushButton_12->setBaseSize(QSize(30, 30));

        gridLayout_2->addWidget(pushButton_12, 4, 2, 1, 1);

        pushButton_10 = new QPushButton(verticalLayoutWidget);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        sizePolicy.setHeightForWidth(pushButton_10->sizePolicy().hasHeightForWidth());
        pushButton_10->setSizePolicy(sizePolicy);
        pushButton_10->setBaseSize(QSize(30, 30));

        gridLayout_2->addWidget(pushButton_10, 3, 2, 1, 1);

        pushButton_9 = new QPushButton(verticalLayoutWidget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        sizePolicy.setHeightForWidth(pushButton_9->sizePolicy().hasHeightForWidth());
        pushButton_9->setSizePolicy(sizePolicy);
        pushButton_9->setBaseSize(QSize(30, 30));

        gridLayout_2->addWidget(pushButton_9, 3, 1, 1, 1);

        pushButton_21 = new QPushButton(verticalLayoutWidget);
        pushButton_21->setObjectName(QStringLiteral("pushButton_21"));
        sizePolicy.setHeightForWidth(pushButton_21->sizePolicy().hasHeightForWidth());
        pushButton_21->setSizePolicy(sizePolicy);
        pushButton_21->setBaseSize(QSize(30, 30));
        pushButton_21->setLayoutDirection(Qt::LeftToRight);
        pushButton_21->setAutoFillBackground(false);
        pushButton_21->setFlat(false);

        gridLayout_2->addWidget(pushButton_21, 3, 4, 2, 1);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setBaseSize(QSize(30, 30));

        gridLayout_2->addWidget(pushButton, 2, 4, 1, 1);

        pushButton_59 = new QPushButton(verticalLayoutWidget);
        pushButton_59->setObjectName(QStringLiteral("pushButton_59"));
        sizePolicy.setHeightForWidth(pushButton_59->sizePolicy().hasHeightForWidth());
        pushButton_59->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(pushButton_59, 1, 4, 1, 1);

        pushButton_54 = new QPushButton(verticalLayoutWidget);
        pushButton_54->setObjectName(QStringLiteral("pushButton_54"));
        sizePolicy.setHeightForWidth(pushButton_54->sizePolicy().hasHeightForWidth());
        pushButton_54->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(pushButton_54, 0, 4, 1, 1);

        pushButton_18 = new QPushButton(verticalLayoutWidget);
        pushButton_18->setObjectName(QStringLiteral("pushButton_18"));
        sizePolicy.setHeightForWidth(pushButton_18->sizePolicy().hasHeightForWidth());
        pushButton_18->setSizePolicy(sizePolicy);
        pushButton_18->setBaseSize(QSize(30, 30));

        gridLayout_2->addWidget(pushButton_18, 0, 0, 1, 3);


        gridLayout_10->addLayout(gridLayout_2, 0, 4, 2, 1);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        pushButton_32 = new QPushButton(verticalLayoutWidget);
        pushButton_32->setObjectName(QStringLiteral("pushButton_32"));
        sizePolicy.setHeightForWidth(pushButton_32->sizePolicy().hasHeightForWidth());
        pushButton_32->setSizePolicy(sizePolicy);
        pushButton_32->setBaseSize(QSize(30, 30));

        gridLayout_5->addWidget(pushButton_32, 1, 1, 1, 1);

        pushButton_30 = new QPushButton(verticalLayoutWidget);
        pushButton_30->setObjectName(QStringLiteral("pushButton_30"));
        sizePolicy.setHeightForWidth(pushButton_30->sizePolicy().hasHeightForWidth());
        pushButton_30->setSizePolicy(sizePolicy);
        pushButton_30->setBaseSize(QSize(30, 30));

        gridLayout_5->addWidget(pushButton_30, 0, 1, 1, 1);

        pushButton_35 = new QPushButton(verticalLayoutWidget);
        pushButton_35->setObjectName(QStringLiteral("pushButton_35"));
        sizePolicy.setHeightForWidth(pushButton_35->sizePolicy().hasHeightForWidth());
        pushButton_35->setSizePolicy(sizePolicy);
        pushButton_35->setBaseSize(QSize(30, 30));

        gridLayout_5->addWidget(pushButton_35, 2, 1, 1, 1);

        pushButton_26 = new QPushButton(verticalLayoutWidget);
        pushButton_26->setObjectName(QStringLiteral("pushButton_26"));
        sizePolicy.setHeightForWidth(pushButton_26->sizePolicy().hasHeightForWidth());
        pushButton_26->setSizePolicy(sizePolicy);
        pushButton_26->setBaseSize(QSize(30, 30));

        gridLayout_5->addWidget(pushButton_26, 0, 0, 1, 1);

        pushButton_27 = new QPushButton(verticalLayoutWidget);
        pushButton_27->setObjectName(QStringLiteral("pushButton_27"));
        sizePolicy.setHeightForWidth(pushButton_27->sizePolicy().hasHeightForWidth());
        pushButton_27->setSizePolicy(sizePolicy);
        pushButton_27->setBaseSize(QSize(30, 30));

        gridLayout_5->addWidget(pushButton_27, 1, 0, 1, 1);

        pushButton_34 = new QPushButton(verticalLayoutWidget);
        pushButton_34->setObjectName(QStringLiteral("pushButton_34"));
        sizePolicy.setHeightForWidth(pushButton_34->sizePolicy().hasHeightForWidth());
        pushButton_34->setSizePolicy(sizePolicy);
        pushButton_34->setBaseSize(QSize(30, 30));

        gridLayout_5->addWidget(pushButton_34, 2, 0, 1, 1);


        gridLayout_10->addLayout(gridLayout_5, 0, 3, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        pushButton_31 = new QPushButton(verticalLayoutWidget);
        pushButton_31->setObjectName(QStringLiteral("pushButton_31"));
        sizePolicy.setHeightForWidth(pushButton_31->sizePolicy().hasHeightForWidth());
        pushButton_31->setSizePolicy(sizePolicy);
        pushButton_31->setBaseSize(QSize(30, 30));

        gridLayout_4->addWidget(pushButton_31, 2, 0, 1, 1);

        pushButton_29 = new QPushButton(verticalLayoutWidget);
        pushButton_29->setObjectName(QStringLiteral("pushButton_29"));
        sizePolicy.setHeightForWidth(pushButton_29->sizePolicy().hasHeightForWidth());
        pushButton_29->setSizePolicy(sizePolicy);
        pushButton_29->setBaseSize(QSize(30, 30));

        gridLayout_4->addWidget(pushButton_29, 1, 0, 1, 1);

        pushButton_33 = new QPushButton(verticalLayoutWidget);
        pushButton_33->setObjectName(QStringLiteral("pushButton_33"));
        sizePolicy.setHeightForWidth(pushButton_33->sizePolicy().hasHeightForWidth());
        pushButton_33->setSizePolicy(sizePolicy);
        pushButton_33->setBaseSize(QSize(30, 30));

        gridLayout_4->addWidget(pushButton_33, 1, 1, 1, 1);

        pushButton_36 = new QPushButton(verticalLayoutWidget);
        pushButton_36->setObjectName(QStringLiteral("pushButton_36"));
        sizePolicy.setHeightForWidth(pushButton_36->sizePolicy().hasHeightForWidth());
        pushButton_36->setSizePolicy(sizePolicy);
        pushButton_36->setBaseSize(QSize(30, 30));

        gridLayout_4->addWidget(pushButton_36, 2, 1, 1, 1);

        pushButton_24 = new QPushButton(verticalLayoutWidget);
        pushButton_24->setObjectName(QStringLiteral("pushButton_24"));
        sizePolicy.setHeightForWidth(pushButton_24->sizePolicy().hasHeightForWidth());
        pushButton_24->setSizePolicy(sizePolicy);
        pushButton_24->setBaseSize(QSize(30, 30));

        gridLayout_4->addWidget(pushButton_24, 0, 0, 1, 2);


        gridLayout_10->addLayout(gridLayout_4, 0, 2, 1, 1);


        verticalLayout_2->addLayout(gridLayout_10);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1079, 21));
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QStringLiteral("menuFichier"));
        menuEdition = new QMenu(menuBar);
        menuEdition->setObjectName(QStringLiteral("menuEdition"));
        menuA_propos = new QMenu(menuBar);
        menuA_propos->setObjectName(QStringLiteral("menuA_propos"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFichier->menuAction());
        menuBar->addAction(menuEdition->menuAction());
        menuBar->addAction(menuA_propos->menuAction());
        menuFichier->addAction(actionQuitter);
        menuEdition->addAction(actionAnnuler);
        menuEdition->addAction(actionR_tablir);
        menuEdition->addSeparator();
        menuEdition->addAction(actionOptions);
        menuEdition->addSeparator();
        menuEdition->addAction(actionEdition_des_variables);
        menuEdition->addAction(actionEdition_des_programmes);
        menuA_propos->addAction(actionAide);
        menuA_propos->addAction(actionA_propos_de_l_application);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionQuitter->setText(QApplication::translate("MainWindow", "Quitter", 0));
        actionAide->setText(QApplication::translate("MainWindow", "Aide", 0));
        actionOptions->setText(QApplication::translate("MainWindow", "Param\303\250tres", 0));
        actionEdition_des_variables->setText(QApplication::translate("MainWindow", "Edition des variables", 0));
        actionEdition_des_programmes->setText(QApplication::translate("MainWindow", "Edition des programmes", 0));
        actionA_propos_de_l_application->setText(QApplication::translate("MainWindow", "A propos de l'application", 0));
        actionAnnuler->setText(QApplication::translate("MainWindow", "Annuler", 0));
        actionR_tablir->setText(QApplication::translate("MainWindow", "R\303\251tablir", 0));
        pushButton_23->setText(QApplication::translate("MainWindow", "SQRT", 0));
        pushButton_25->setText(QApplication::translate("MainWindow", "EXP", 0));
        pushButton_22->setText(QApplication::translate("MainWindow", "POW", 0));
        pushButton_28->setText(QApplication::translate("MainWindow", "LN", 0));
        pushButton_37->setText(QApplication::translate("MainWindow", "MOD", 0));
        pushButton_38->setText(QApplication::translate("MainWindow", "DIV", 0));
        pushButton_39->setText(QApplication::translate("MainWindow", "DEN", 0));
        pushButton_40->setText(QApplication::translate("MainWindow", "NUM", 0));
        pushButton_52->setText(QApplication::translate("MainWindow", "LASTOP", 0));
        pushButton_55->setText(QApplication::translate("MainWindow", "SWAP", 0));
        pushButton_56->setText(QApplication::translate("MainWindow", "LASTARGS", 0));
        pushButton_51->setText(QApplication::translate("MainWindow", "DROP", 0));
        pushButton_50->setText(QApplication::translate("MainWindow", "DUP", 0));
        pushButton_53->setText(QApplication::translate("MainWindow", "UNDO", 0));
        pushButton_57->setText(QApplication::translate("MainWindow", "REDO", 0));
        pushButton_48->setText(QApplication::translate("MainWindow", "OR", 0));
        pushButton_49->setText(QApplication::translate("MainWindow", "NOT", 0));
        pushButton_41->setText(QApplication::translate("MainWindow", "=", 0));
        pushButton_44->setText(QApplication::translate("MainWindow", "!=", 0));
        pushButton_45->setText(QApplication::translate("MainWindow", "<=", 0));
        pushButton_43->setText(QApplication::translate("MainWindow", ">", 0));
        pushButton_46->setText(QApplication::translate("MainWindow", ">=", 0));
        pushButton_42->setText(QApplication::translate("MainWindow", "<", 0));
        pushButton_47->setText(QApplication::translate("MainWindow", "AND", 0));
        pushButton_19->setText(QApplication::translate("MainWindow", "IFT", 0));
        pushButton_20->setText(QApplication::translate("MainWindow", "IFTE", 0));
        pushButton_61->setText(QApplication::translate("MainWindow", "]", 0));
        pushButton_60->setText(QApplication::translate("MainWindow", "[", 0));
        pushButton_58->setText(QApplication::translate("MainWindow", "WHILE", 0));
        pushButton_17->setText(QApplication::translate("MainWindow", "NEG", 0));
        pushButton_11->setText(QApplication::translate("MainWindow", "0", 0));
        pushButton_7->setText(QApplication::translate("MainWindow", "5", 0));
        pushButton_6->setText(QApplication::translate("MainWindow", "1", 0));
        pushButton_5->setText(QApplication::translate("MainWindow", "4", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "9", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "8", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "7", 0));
        pushButton_8->setText(QApplication::translate("MainWindow", "6", 0));
        pushButton_16->setText(QApplication::translate("MainWindow", "/", 0));
        pushButton_15->setText(QApplication::translate("MainWindow", "*", 0));
        pushButton_14->setText(QApplication::translate("MainWindow", "-", 0));
        pushButton_13->setText(QApplication::translate("MainWindow", "+", 0));
        pushButton_12->setText(QApplication::translate("MainWindow", ",", 0));
        pushButton_10->setText(QApplication::translate("MainWindow", "3", 0));
        pushButton_9->setText(QApplication::translate("MainWindow", "2", 0));
        pushButton_21->setText(QApplication::translate("MainWindow", "=", 0));
        pushButton->setText(QApplication::translate("MainWindow", "EVAL", 0));
        pushButton_59->setText(QApplication::translate("MainWindow", "EDIT", 0));
        pushButton_54->setText(QApplication::translate("MainWindow", "CLEAR", 0));
        pushButton_18->setText(QApplication::translate("MainWindow", "BACKSPACE", 0));
        pushButton_32->setText(QApplication::translate("MainWindow", "ARCSIN", 0));
        pushButton_30->setText(QApplication::translate("MainWindow", "ARCCOS", 0));
        pushButton_35->setText(QApplication::translate("MainWindow", "ARCTAN", 0));
        pushButton_26->setText(QApplication::translate("MainWindow", "COS", 0));
        pushButton_27->setText(QApplication::translate("MainWindow", "SIN", 0));
        pushButton_34->setText(QApplication::translate("MainWindow", "TAN", 0));
        pushButton_31->setText(QApplication::translate("MainWindow", "IM", 0));
        pushButton_29->setText(QApplication::translate("MainWindow", "RE", 0));
        pushButton_33->setText(QApplication::translate("MainWindow", "ARG", 0));
        pushButton_36->setText(QApplication::translate("MainWindow", "NORM", 0));
        pushButton_24->setText(QApplication::translate("MainWindow", "$", 0));
        menuFichier->setTitle(QApplication::translate("MainWindow", "Fichier", 0));
        menuEdition->setTitle(QApplication::translate("MainWindow", "Edition", 0));
        menuA_propos->setTitle(QApplication::translate("MainWindow", "A propos", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
