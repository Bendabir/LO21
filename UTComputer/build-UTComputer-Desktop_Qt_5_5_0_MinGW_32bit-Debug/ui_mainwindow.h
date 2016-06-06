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
    QAction *actionAfficher_le_clavier_cliquable;
    QAction *actionSauvegarder;
    QAction *actionCharger;
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *errorInput;
    QTableWidget *tableWidget;
    QLineEdit *commandInput;
    QGridLayout *gridLayout_10;
    QGridLayout *gridLayout_9;
    QGridLayout *logicalButtons;
    QPushButton *orb;
    QPushButton *notb;
    QPushButton *equalb;
    QPushButton *notEqual;
    QPushButton *lte;
    QPushButton *gt;
    QPushButton *gte;
    QPushButton *lt;
    QPushButton *andb;
    QGridLayout *conditionalButtons;
    QPushButton *ift;
    QPushButton *ifte;
    QPushButton *rightBracket;
    QPushButton *leftBracket;
    QPushButton *whileb;
    QGridLayout *trigoButtons;
    QPushButton *arcsin;
    QPushButton *arccos;
    QPushButton *arctan;
    QPushButton *cos;
    QPushButton *sin;
    QPushButton *tan;
    QGridLayout *complexButtons;
    QPushButton *im;
    QPushButton *re;
    QPushButton *arg;
    QPushButton *norm;
    QPushButton *dollar;
    QGridLayout *powerButtons;
    QPushButton *exp;
    QPushButton *ln;
    QPushButton *comma;
    QPushButton *sqrt;
    QPushButton *pow;
    QGridLayout *integerButtons;
    QPushButton *leftParenthesis;
    QPushButton *div;
    QPushButton *mod;
    QPushButton *den;
    QPushButton *num;
    QPushButton *rightParenthesis;
    QWidget *widgetPad;
    QGridLayout *gridLayout;
    QGridLayout *numericPad;
    QPushButton *neg;
    QPushButton *b5;
    QPushButton *b0;
    QPushButton *b8;
    QPushButton *b9;
    QPushButton *divide;
    QPushButton *b4;
    QPushButton *b1;
    QPushButton *b7;
    QPushButton *b3;
    QPushButton *minus;
    QPushButton *times;
    QPushButton *b6;
    QPushButton *dot;
    QPushButton *b2;
    QPushButton *plus;
    QPushButton *eval;
    QPushButton *enter;
    QPushButton *edit;
    QPushButton *clear;
    QPushButton *quote;
    QPushButton *backspace;
    QGridLayout *stackButtons;
    QPushButton *swap;
    QPushButton *lastargs;
    QPushButton *redo;
    QPushButton *sto;
    QPushButton *dup;
    QPushButton *forget;
    QPushButton *lastop;
    QPushButton *undo;
    QPushButton *drop;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QMenu *menuEdition;
    QMenu *menuA_propos;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1020, 610);
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
        actionAfficher_le_clavier_cliquable = new QAction(MainWindow);
        actionAfficher_le_clavier_cliquable->setObjectName(QStringLiteral("actionAfficher_le_clavier_cliquable"));
        actionAfficher_le_clavier_cliquable->setCheckable(true);
        actionAfficher_le_clavier_cliquable->setChecked(true);
        actionSauvegarder = new QAction(MainWindow);
        actionSauvegarder->setObjectName(QStringLiteral("actionSauvegarder"));
        actionCharger = new QAction(MainWindow);
        actionCharger->setObjectName(QStringLiteral("actionCharger"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(9, 9, 1001, 571));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        errorInput = new QLineEdit(verticalLayoutWidget);
        errorInput->setObjectName(QStringLiteral("errorInput"));
        errorInput->setMinimumSize(QSize(0, 30));
        errorInput->setMaximumSize(QSize(16777215, 30));
        errorInput->setBaseSize(QSize(0, 30));
        errorInput->setReadOnly(true);

        verticalLayout_2->addWidget(errorInput);

        tableWidget = new QTableWidget(verticalLayoutWidget);
        if (tableWidget->columnCount() < 1)
            tableWidget->setColumnCount(1);
        if (tableWidget->rowCount() < 5)
            tableWidget->setRowCount(5);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
        tableWidget->setRowCount(5);
        tableWidget->setColumnCount(1);

        verticalLayout_2->addWidget(tableWidget);

        commandInput = new QLineEdit(verticalLayoutWidget);
        commandInput->setObjectName(QStringLiteral("commandInput"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(commandInput->sizePolicy().hasHeightForWidth());
        commandInput->setSizePolicy(sizePolicy1);
        commandInput->setMinimumSize(QSize(0, 30));
        commandInput->setMaximumSize(QSize(16777215, 30));
        commandInput->setBaseSize(QSize(0, 30));

        verticalLayout_2->addWidget(commandInput);

        gridLayout_10 = new QGridLayout();
        gridLayout_10->setSpacing(6);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        gridLayout_9 = new QGridLayout();
        gridLayout_9->setSpacing(6);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        logicalButtons = new QGridLayout();
        logicalButtons->setSpacing(6);
        logicalButtons->setObjectName(QStringLiteral("logicalButtons"));
        orb = new QPushButton(verticalLayoutWidget);
        orb->setObjectName(QStringLiteral("orb"));
        sizePolicy.setHeightForWidth(orb->sizePolicy().hasHeightForWidth());
        orb->setSizePolicy(sizePolicy);
        orb->setBaseSize(QSize(30, 30));

        logicalButtons->addWidget(orb, 1, 0, 1, 1);

        notb = new QPushButton(verticalLayoutWidget);
        notb->setObjectName(QStringLiteral("notb"));
        sizePolicy.setHeightForWidth(notb->sizePolicy().hasHeightForWidth());
        notb->setSizePolicy(sizePolicy);
        notb->setBaseSize(QSize(30, 30));

        logicalButtons->addWidget(notb, 2, 0, 1, 1);

        equalb = new QPushButton(verticalLayoutWidget);
        equalb->setObjectName(QStringLiteral("equalb"));
        sizePolicy.setHeightForWidth(equalb->sizePolicy().hasHeightForWidth());
        equalb->setSizePolicy(sizePolicy);
        equalb->setBaseSize(QSize(30, 30));

        logicalButtons->addWidget(equalb, 0, 1, 1, 1);

        notEqual = new QPushButton(verticalLayoutWidget);
        notEqual->setObjectName(QStringLiteral("notEqual"));
        sizePolicy.setHeightForWidth(notEqual->sizePolicy().hasHeightForWidth());
        notEqual->setSizePolicy(sizePolicy);
        notEqual->setBaseSize(QSize(30, 30));

        logicalButtons->addWidget(notEqual, 0, 2, 1, 1);

        lte = new QPushButton(verticalLayoutWidget);
        lte->setObjectName(QStringLiteral("lte"));
        sizePolicy.setHeightForWidth(lte->sizePolicy().hasHeightForWidth());
        lte->setSizePolicy(sizePolicy);
        lte->setBaseSize(QSize(30, 30));

        logicalButtons->addWidget(lte, 1, 2, 1, 1);

        gt = new QPushButton(verticalLayoutWidget);
        gt->setObjectName(QStringLiteral("gt"));
        sizePolicy.setHeightForWidth(gt->sizePolicy().hasHeightForWidth());
        gt->setSizePolicy(sizePolicy);
        gt->setBaseSize(QSize(30, 30));

        logicalButtons->addWidget(gt, 2, 1, 1, 1);

        gte = new QPushButton(verticalLayoutWidget);
        gte->setObjectName(QStringLiteral("gte"));
        sizePolicy.setHeightForWidth(gte->sizePolicy().hasHeightForWidth());
        gte->setSizePolicy(sizePolicy);
        gte->setBaseSize(QSize(30, 30));

        logicalButtons->addWidget(gte, 2, 2, 1, 1);

        lt = new QPushButton(verticalLayoutWidget);
        lt->setObjectName(QStringLiteral("lt"));
        sizePolicy.setHeightForWidth(lt->sizePolicy().hasHeightForWidth());
        lt->setSizePolicy(sizePolicy);
        lt->setBaseSize(QSize(30, 30));

        logicalButtons->addWidget(lt, 1, 1, 1, 1);

        andb = new QPushButton(verticalLayoutWidget);
        andb->setObjectName(QStringLiteral("andb"));
        sizePolicy.setHeightForWidth(andb->sizePolicy().hasHeightForWidth());
        andb->setSizePolicy(sizePolicy);
        andb->setBaseSize(QSize(30, 30));

        logicalButtons->addWidget(andb, 0, 0, 1, 1);


        gridLayout_9->addLayout(logicalButtons, 4, 1, 1, 1);

        conditionalButtons = new QGridLayout();
        conditionalButtons->setSpacing(6);
        conditionalButtons->setObjectName(QStringLiteral("conditionalButtons"));
        ift = new QPushButton(verticalLayoutWidget);
        ift->setObjectName(QStringLiteral("ift"));
        sizePolicy.setHeightForWidth(ift->sizePolicy().hasHeightForWidth());
        ift->setSizePolicy(sizePolicy);

        conditionalButtons->addWidget(ift, 2, 0, 1, 1);

        ifte = new QPushButton(verticalLayoutWidget);
        ifte->setObjectName(QStringLiteral("ifte"));
        sizePolicy.setHeightForWidth(ifte->sizePolicy().hasHeightForWidth());
        ifte->setSizePolicy(sizePolicy);

        conditionalButtons->addWidget(ifte, 2, 1, 1, 1);

        rightBracket = new QPushButton(verticalLayoutWidget);
        rightBracket->setObjectName(QStringLiteral("rightBracket"));

        conditionalButtons->addWidget(rightBracket, 3, 1, 1, 1);

        leftBracket = new QPushButton(verticalLayoutWidget);
        leftBracket->setObjectName(QStringLiteral("leftBracket"));

        conditionalButtons->addWidget(leftBracket, 3, 0, 1, 1);

        whileb = new QPushButton(verticalLayoutWidget);
        whileb->setObjectName(QStringLiteral("whileb"));
        sizePolicy.setHeightForWidth(whileb->sizePolicy().hasHeightForWidth());
        whileb->setSizePolicy(sizePolicy);

        conditionalButtons->addWidget(whileb, 1, 0, 1, 2);


        gridLayout_9->addLayout(conditionalButtons, 2, 1, 1, 1);


        gridLayout_10->addLayout(gridLayout_9, 1, 0, 1, 1);

        trigoButtons = new QGridLayout();
        trigoButtons->setSpacing(6);
        trigoButtons->setObjectName(QStringLiteral("trigoButtons"));
        arcsin = new QPushButton(verticalLayoutWidget);
        arcsin->setObjectName(QStringLiteral("arcsin"));
        sizePolicy.setHeightForWidth(arcsin->sizePolicy().hasHeightForWidth());
        arcsin->setSizePolicy(sizePolicy);
        arcsin->setBaseSize(QSize(30, 30));

        trigoButtons->addWidget(arcsin, 1, 1, 1, 1);

        arccos = new QPushButton(verticalLayoutWidget);
        arccos->setObjectName(QStringLiteral("arccos"));
        sizePolicy.setHeightForWidth(arccos->sizePolicy().hasHeightForWidth());
        arccos->setSizePolicy(sizePolicy);
        arccos->setBaseSize(QSize(30, 30));

        trigoButtons->addWidget(arccos, 0, 1, 1, 1);

        arctan = new QPushButton(verticalLayoutWidget);
        arctan->setObjectName(QStringLiteral("arctan"));
        sizePolicy.setHeightForWidth(arctan->sizePolicy().hasHeightForWidth());
        arctan->setSizePolicy(sizePolicy);
        arctan->setBaseSize(QSize(30, 30));

        trigoButtons->addWidget(arctan, 2, 1, 1, 1);

        cos = new QPushButton(verticalLayoutWidget);
        cos->setObjectName(QStringLiteral("cos"));
        sizePolicy.setHeightForWidth(cos->sizePolicy().hasHeightForWidth());
        cos->setSizePolicy(sizePolicy);
        cos->setBaseSize(QSize(30, 30));

        trigoButtons->addWidget(cos, 0, 0, 1, 1);

        sin = new QPushButton(verticalLayoutWidget);
        sin->setObjectName(QStringLiteral("sin"));
        sizePolicy.setHeightForWidth(sin->sizePolicy().hasHeightForWidth());
        sin->setSizePolicy(sizePolicy);
        sin->setBaseSize(QSize(30, 30));

        trigoButtons->addWidget(sin, 1, 0, 1, 1);

        tan = new QPushButton(verticalLayoutWidget);
        tan->setObjectName(QStringLiteral("tan"));
        sizePolicy.setHeightForWidth(tan->sizePolicy().hasHeightForWidth());
        tan->setSizePolicy(sizePolicy);
        tan->setBaseSize(QSize(30, 30));

        trigoButtons->addWidget(tan, 2, 0, 1, 1);


        gridLayout_10->addLayout(trigoButtons, 0, 3, 1, 1);

        complexButtons = new QGridLayout();
        complexButtons->setSpacing(6);
        complexButtons->setObjectName(QStringLiteral("complexButtons"));
        im = new QPushButton(verticalLayoutWidget);
        im->setObjectName(QStringLiteral("im"));
        sizePolicy.setHeightForWidth(im->sizePolicy().hasHeightForWidth());
        im->setSizePolicy(sizePolicy);
        im->setBaseSize(QSize(30, 30));

        complexButtons->addWidget(im, 2, 0, 1, 1);

        re = new QPushButton(verticalLayoutWidget);
        re->setObjectName(QStringLiteral("re"));
        sizePolicy.setHeightForWidth(re->sizePolicy().hasHeightForWidth());
        re->setSizePolicy(sizePolicy);
        re->setBaseSize(QSize(30, 30));

        complexButtons->addWidget(re, 1, 0, 1, 1);

        arg = new QPushButton(verticalLayoutWidget);
        arg->setObjectName(QStringLiteral("arg"));
        sizePolicy.setHeightForWidth(arg->sizePolicy().hasHeightForWidth());
        arg->setSizePolicy(sizePolicy);
        arg->setBaseSize(QSize(30, 30));

        complexButtons->addWidget(arg, 1, 1, 1, 1);

        norm = new QPushButton(verticalLayoutWidget);
        norm->setObjectName(QStringLiteral("norm"));
        sizePolicy.setHeightForWidth(norm->sizePolicy().hasHeightForWidth());
        norm->setSizePolicy(sizePolicy);
        norm->setBaseSize(QSize(30, 30));

        complexButtons->addWidget(norm, 2, 1, 1, 1);

        dollar = new QPushButton(verticalLayoutWidget);
        dollar->setObjectName(QStringLiteral("dollar"));
        sizePolicy.setHeightForWidth(dollar->sizePolicy().hasHeightForWidth());
        dollar->setSizePolicy(sizePolicy);
        dollar->setBaseSize(QSize(30, 30));

        complexButtons->addWidget(dollar, 0, 0, 1, 2);


        gridLayout_10->addLayout(complexButtons, 0, 2, 1, 1);

        powerButtons = new QGridLayout();
        powerButtons->setSpacing(6);
        powerButtons->setObjectName(QStringLiteral("powerButtons"));
        exp = new QPushButton(verticalLayoutWidget);
        exp->setObjectName(QStringLiteral("exp"));
        sizePolicy.setHeightForWidth(exp->sizePolicy().hasHeightForWidth());
        exp->setSizePolicy(sizePolicy);
        exp->setBaseSize(QSize(30, 30));

        powerButtons->addWidget(exp, 2, 0, 1, 1);

        ln = new QPushButton(verticalLayoutWidget);
        ln->setObjectName(QStringLiteral("ln"));
        sizePolicy.setHeightForWidth(ln->sizePolicy().hasHeightForWidth());
        ln->setSizePolicy(sizePolicy);
        ln->setBaseSize(QSize(30, 30));

        powerButtons->addWidget(ln, 2, 1, 1, 1);

        comma = new QPushButton(verticalLayoutWidget);
        comma->setObjectName(QStringLiteral("comma"));
        sizePolicy.setHeightForWidth(comma->sizePolicy().hasHeightForWidth());
        comma->setSizePolicy(sizePolicy);
        comma->setBaseSize(QSize(30, 30));

        powerButtons->addWidget(comma, 3, 0, 1, 2);

        sqrt = new QPushButton(verticalLayoutWidget);
        sqrt->setObjectName(QStringLiteral("sqrt"));
        sizePolicy.setHeightForWidth(sqrt->sizePolicy().hasHeightForWidth());
        sqrt->setSizePolicy(sizePolicy);
        sqrt->setBaseSize(QSize(30, 30));

        powerButtons->addWidget(sqrt, 1, 0, 1, 2);

        pow = new QPushButton(verticalLayoutWidget);
        pow->setObjectName(QStringLiteral("pow"));
        sizePolicy.setHeightForWidth(pow->sizePolicy().hasHeightForWidth());
        pow->setSizePolicy(sizePolicy);
        pow->setBaseSize(QSize(30, 30));

        powerButtons->addWidget(pow, 0, 0, 1, 2);


        gridLayout_10->addLayout(powerButtons, 1, 3, 1, 1);

        integerButtons = new QGridLayout();
        integerButtons->setSpacing(6);
        integerButtons->setObjectName(QStringLiteral("integerButtons"));
        leftParenthesis = new QPushButton(verticalLayoutWidget);
        leftParenthesis->setObjectName(QStringLiteral("leftParenthesis"));
        sizePolicy.setHeightForWidth(leftParenthesis->sizePolicy().hasHeightForWidth());
        leftParenthesis->setSizePolicy(sizePolicy);
        leftParenthesis->setBaseSize(QSize(30, 30));

        integerButtons->addWidget(leftParenthesis, 5, 2, 1, 1);

        div = new QPushButton(verticalLayoutWidget);
        div->setObjectName(QStringLiteral("div"));
        sizePolicy.setHeightForWidth(div->sizePolicy().hasHeightForWidth());
        div->setSizePolicy(sizePolicy);
        div->setBaseSize(QSize(30, 30));

        integerButtons->addWidget(div, 4, 2, 1, 1);

        mod = new QPushButton(verticalLayoutWidget);
        mod->setObjectName(QStringLiteral("mod"));
        sizePolicy.setHeightForWidth(mod->sizePolicy().hasHeightForWidth());
        mod->setSizePolicy(sizePolicy);
        mod->setBaseSize(QSize(30, 30));

        integerButtons->addWidget(mod, 4, 3, 1, 1);

        den = new QPushButton(verticalLayoutWidget);
        den->setObjectName(QStringLiteral("den"));
        sizePolicy.setHeightForWidth(den->sizePolicy().hasHeightForWidth());
        den->setSizePolicy(sizePolicy);
        den->setBaseSize(QSize(30, 30));

        integerButtons->addWidget(den, 3, 2, 1, 2);

        num = new QPushButton(verticalLayoutWidget);
        num->setObjectName(QStringLiteral("num"));
        sizePolicy.setHeightForWidth(num->sizePolicy().hasHeightForWidth());
        num->setSizePolicy(sizePolicy);
        num->setBaseSize(QSize(30, 30));

        integerButtons->addWidget(num, 2, 2, 1, 2);

        rightParenthesis = new QPushButton(verticalLayoutWidget);
        rightParenthesis->setObjectName(QStringLiteral("rightParenthesis"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(rightParenthesis->sizePolicy().hasHeightForWidth());
        rightParenthesis->setSizePolicy(sizePolicy2);

        integerButtons->addWidget(rightParenthesis, 5, 3, 1, 1);


        gridLayout_10->addLayout(integerButtons, 1, 2, 1, 1);

        widgetPad = new QWidget(verticalLayoutWidget);
        widgetPad->setObjectName(QStringLiteral("widgetPad"));
        sizePolicy.setHeightForWidth(widgetPad->sizePolicy().hasHeightForWidth());
        widgetPad->setSizePolicy(sizePolicy);
        widgetPad->setMinimumSize(QSize(0, 0));
        widgetPad->setAutoFillBackground(false);
        gridLayout = new QGridLayout(widgetPad);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        numericPad = new QGridLayout();
        numericPad->setSpacing(6);
        numericPad->setObjectName(QStringLiteral("numericPad"));
        neg = new QPushButton(widgetPad);
        neg->setObjectName(QStringLiteral("neg"));
        sizePolicy.setHeightForWidth(neg->sizePolicy().hasHeightForWidth());
        neg->setSizePolicy(sizePolicy);
        neg->setBaseSize(QSize(30, 30));

        numericPad->addWidget(neg, 0, 3, 1, 1);

        b5 = new QPushButton(widgetPad);
        b5->setObjectName(QStringLiteral("b5"));
        sizePolicy.setHeightForWidth(b5->sizePolicy().hasHeightForWidth());
        b5->setSizePolicy(sizePolicy);
        b5->setBaseSize(QSize(30, 30));

        numericPad->addWidget(b5, 2, 1, 1, 1);

        b0 = new QPushButton(widgetPad);
        b0->setObjectName(QStringLiteral("b0"));
        sizePolicy.setHeightForWidth(b0->sizePolicy().hasHeightForWidth());
        b0->setSizePolicy(sizePolicy);
        b0->setBaseSize(QSize(30, 30));

        numericPad->addWidget(b0, 4, 0, 1, 2);

        b8 = new QPushButton(widgetPad);
        b8->setObjectName(QStringLiteral("b8"));
        sizePolicy.setHeightForWidth(b8->sizePolicy().hasHeightForWidth());
        b8->setSizePolicy(sizePolicy);
        b8->setBaseSize(QSize(30, 30));

        numericPad->addWidget(b8, 1, 1, 1, 1);

        b9 = new QPushButton(widgetPad);
        b9->setObjectName(QStringLiteral("b9"));
        sizePolicy.setHeightForWidth(b9->sizePolicy().hasHeightForWidth());
        b9->setSizePolicy(sizePolicy);
        b9->setBaseSize(QSize(30, 30));

        numericPad->addWidget(b9, 1, 2, 1, 1);

        divide = new QPushButton(widgetPad);
        divide->setObjectName(QStringLiteral("divide"));
        sizePolicy.setHeightForWidth(divide->sizePolicy().hasHeightForWidth());
        divide->setSizePolicy(sizePolicy);
        divide->setBaseSize(QSize(30, 30));

        numericPad->addWidget(divide, 1, 3, 1, 1);

        b4 = new QPushButton(widgetPad);
        b4->setObjectName(QStringLiteral("b4"));
        sizePolicy.setHeightForWidth(b4->sizePolicy().hasHeightForWidth());
        b4->setSizePolicy(sizePolicy);
        b4->setBaseSize(QSize(30, 30));

        numericPad->addWidget(b4, 2, 0, 1, 1);

        b1 = new QPushButton(widgetPad);
        b1->setObjectName(QStringLiteral("b1"));
        sizePolicy.setHeightForWidth(b1->sizePolicy().hasHeightForWidth());
        b1->setSizePolicy(sizePolicy);
        b1->setBaseSize(QSize(30, 30));

        numericPad->addWidget(b1, 3, 0, 1, 1);

        b7 = new QPushButton(widgetPad);
        b7->setObjectName(QStringLiteral("b7"));
        sizePolicy.setHeightForWidth(b7->sizePolicy().hasHeightForWidth());
        b7->setSizePolicy(sizePolicy);
        b7->setBaseSize(QSize(30, 30));

        numericPad->addWidget(b7, 1, 0, 1, 1);

        b3 = new QPushButton(widgetPad);
        b3->setObjectName(QStringLiteral("b3"));
        sizePolicy.setHeightForWidth(b3->sizePolicy().hasHeightForWidth());
        b3->setSizePolicy(sizePolicy);
        b3->setBaseSize(QSize(30, 30));

        numericPad->addWidget(b3, 3, 2, 1, 1);

        minus = new QPushButton(widgetPad);
        minus->setObjectName(QStringLiteral("minus"));
        sizePolicy.setHeightForWidth(minus->sizePolicy().hasHeightForWidth());
        minus->setSizePolicy(sizePolicy);
        minus->setBaseSize(QSize(30, 30));

        numericPad->addWidget(minus, 3, 3, 1, 1);

        times = new QPushButton(widgetPad);
        times->setObjectName(QStringLiteral("times"));
        sizePolicy.setHeightForWidth(times->sizePolicy().hasHeightForWidth());
        times->setSizePolicy(sizePolicy);
        times->setBaseSize(QSize(30, 30));

        numericPad->addWidget(times, 2, 3, 1, 1);

        b6 = new QPushButton(widgetPad);
        b6->setObjectName(QStringLiteral("b6"));
        sizePolicy.setHeightForWidth(b6->sizePolicy().hasHeightForWidth());
        b6->setSizePolicy(sizePolicy);
        b6->setBaseSize(QSize(30, 30));

        numericPad->addWidget(b6, 2, 2, 1, 1);

        dot = new QPushButton(widgetPad);
        dot->setObjectName(QStringLiteral("dot"));
        sizePolicy.setHeightForWidth(dot->sizePolicy().hasHeightForWidth());
        dot->setSizePolicy(sizePolicy);
        dot->setBaseSize(QSize(30, 30));

        numericPad->addWidget(dot, 4, 2, 1, 1);

        b2 = new QPushButton(widgetPad);
        b2->setObjectName(QStringLiteral("b2"));
        sizePolicy.setHeightForWidth(b2->sizePolicy().hasHeightForWidth());
        b2->setSizePolicy(sizePolicy);
        b2->setBaseSize(QSize(30, 30));

        numericPad->addWidget(b2, 3, 1, 1, 1);

        plus = new QPushButton(widgetPad);
        plus->setObjectName(QStringLiteral("plus"));
        sizePolicy.setHeightForWidth(plus->sizePolicy().hasHeightForWidth());
        plus->setSizePolicy(sizePolicy);
        plus->setBaseSize(QSize(30, 30));

        numericPad->addWidget(plus, 4, 3, 1, 1);

        eval = new QPushButton(widgetPad);
        eval->setObjectName(QStringLiteral("eval"));
        sizePolicy.setHeightForWidth(eval->sizePolicy().hasHeightForWidth());
        eval->setSizePolicy(sizePolicy);
        eval->setBaseSize(QSize(30, 30));

        numericPad->addWidget(eval, 2, 4, 1, 1);

        enter = new QPushButton(widgetPad);
        enter->setObjectName(QStringLiteral("enter"));
        sizePolicy.setHeightForWidth(enter->sizePolicy().hasHeightForWidth());
        enter->setSizePolicy(sizePolicy);
        enter->setBaseSize(QSize(30, 30));
        enter->setLayoutDirection(Qt::LeftToRight);
        enter->setAutoFillBackground(false);
        enter->setFlat(false);

        numericPad->addWidget(enter, 3, 4, 2, 1);

        edit = new QPushButton(widgetPad);
        edit->setObjectName(QStringLiteral("edit"));
        sizePolicy.setHeightForWidth(edit->sizePolicy().hasHeightForWidth());
        edit->setSizePolicy(sizePolicy);

        numericPad->addWidget(edit, 1, 4, 1, 1);

        clear = new QPushButton(widgetPad);
        clear->setObjectName(QStringLiteral("clear"));
        sizePolicy.setHeightForWidth(clear->sizePolicy().hasHeightForWidth());
        clear->setSizePolicy(sizePolicy);

        numericPad->addWidget(clear, 0, 4, 1, 1);

        quote = new QPushButton(widgetPad);
        quote->setObjectName(QStringLiteral("quote"));
        sizePolicy2.setHeightForWidth(quote->sizePolicy().hasHeightForWidth());
        quote->setSizePolicy(sizePolicy2);

        numericPad->addWidget(quote, 0, 2, 1, 1);

        backspace = new QPushButton(widgetPad);
        backspace->setObjectName(QStringLiteral("backspace"));
        sizePolicy.setHeightForWidth(backspace->sizePolicy().hasHeightForWidth());
        backspace->setSizePolicy(sizePolicy);
        backspace->setBaseSize(QSize(30, 30));
        QFont font;
        font.setPointSize(24);
        font.setKerning(false);
        backspace->setFont(font);

        numericPad->addWidget(backspace, 0, 0, 1, 2);


        gridLayout->addLayout(numericPad, 0, 0, 1, 1);


        gridLayout_10->addWidget(widgetPad, 0, 4, 2, 1);

        stackButtons = new QGridLayout();
        stackButtons->setSpacing(6);
        stackButtons->setObjectName(QStringLiteral("stackButtons"));
        swap = new QPushButton(verticalLayoutWidget);
        swap->setObjectName(QStringLiteral("swap"));
        sizePolicy.setHeightForWidth(swap->sizePolicy().hasHeightForWidth());
        swap->setSizePolicy(sizePolicy);

        stackButtons->addWidget(swap, 2, 2, 1, 1);

        lastargs = new QPushButton(verticalLayoutWidget);
        lastargs->setObjectName(QStringLiteral("lastargs"));
        sizePolicy.setHeightForWidth(lastargs->sizePolicy().hasHeightForWidth());
        lastargs->setSizePolicy(sizePolicy);

        stackButtons->addWidget(lastargs, 4, 2, 1, 1);

        redo = new QPushButton(verticalLayoutWidget);
        redo->setObjectName(QStringLiteral("redo"));
        sizePolicy.setHeightForWidth(redo->sizePolicy().hasHeightForWidth());
        redo->setSizePolicy(sizePolicy);

        stackButtons->addWidget(redo, 5, 2, 1, 1);

        sto = new QPushButton(verticalLayoutWidget);
        sto->setObjectName(QStringLiteral("sto"));

        stackButtons->addWidget(sto, 3, 2, 1, 1);

        dup = new QPushButton(verticalLayoutWidget);
        dup->setObjectName(QStringLiteral("dup"));
        sizePolicy.setHeightForWidth(dup->sizePolicy().hasHeightForWidth());
        dup->setSizePolicy(sizePolicy);

        stackButtons->addWidget(dup, 2, 1, 1, 1);

        forget = new QPushButton(verticalLayoutWidget);
        forget->setObjectName(QStringLiteral("forget"));

        stackButtons->addWidget(forget, 3, 1, 1, 1);

        lastop = new QPushButton(verticalLayoutWidget);
        lastop->setObjectName(QStringLiteral("lastop"));
        sizePolicy.setHeightForWidth(lastop->sizePolicy().hasHeightForWidth());
        lastop->setSizePolicy(sizePolicy);

        stackButtons->addWidget(lastop, 4, 1, 1, 1);

        undo = new QPushButton(verticalLayoutWidget);
        undo->setObjectName(QStringLiteral("undo"));
        sizePolicy.setHeightForWidth(undo->sizePolicy().hasHeightForWidth());
        undo->setSizePolicy(sizePolicy);

        stackButtons->addWidget(undo, 5, 1, 1, 1);

        drop = new QPushButton(verticalLayoutWidget);
        drop->setObjectName(QStringLiteral("drop"));
        sizePolicy.setHeightForWidth(drop->sizePolicy().hasHeightForWidth());
        drop->setSizePolicy(sizePolicy);

        stackButtons->addWidget(drop, 1, 1, 1, 2);


        gridLayout_10->addLayout(stackButtons, 0, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout_10);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1020, 21));
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
        menuFichier->addAction(actionSauvegarder);
        menuFichier->addSeparator();
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
        actionQuitter->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0));
        actionAide->setText(QApplication::translate("MainWindow", "Aide", 0));
        actionOptions->setText(QApplication::translate("MainWindow", "Param\303\250tres", 0));
        actionEdition_des_variables->setText(QApplication::translate("MainWindow", "Edition des variables", 0));
        actionEdition_des_programmes->setText(QApplication::translate("MainWindow", "Edition des programmes", 0));
        actionA_propos_de_l_application->setText(QApplication::translate("MainWindow", "A propos de l'application", 0));
        actionAnnuler->setText(QApplication::translate("MainWindow", "Annuler", 0));
        actionAnnuler->setShortcut(QApplication::translate("MainWindow", "Ctrl+Z", 0));
        actionR_tablir->setText(QApplication::translate("MainWindow", "R\303\251tablir", 0));
        actionR_tablir->setShortcut(QApplication::translate("MainWindow", "Ctrl+Y", 0));
        actionAfficher_le_clavier_cliquable->setText(QApplication::translate("MainWindow", "Afficher le clavier cliquable", 0));
        actionSauvegarder->setText(QApplication::translate("MainWindow", "Sauvegarder", 0));
        actionCharger->setText(QApplication::translate("MainWindow", "Charger", 0));
        orb->setText(QApplication::translate("MainWindow", "OR", 0));
        notb->setText(QApplication::translate("MainWindow", "NOT", 0));
        equalb->setText(QApplication::translate("MainWindow", "=", 0));
        notEqual->setText(QApplication::translate("MainWindow", "!=", 0));
        lte->setText(QApplication::translate("MainWindow", "<=", 0));
        gt->setText(QApplication::translate("MainWindow", ">", 0));
        gte->setText(QApplication::translate("MainWindow", ">=", 0));
        lt->setText(QApplication::translate("MainWindow", "<", 0));
        andb->setText(QApplication::translate("MainWindow", "AND", 0));
        ift->setText(QApplication::translate("MainWindow", "IFT", 0));
        ifte->setText(QApplication::translate("MainWindow", "IFTE", 0));
        rightBracket->setText(QApplication::translate("MainWindow", "]", 0));
        leftBracket->setText(QApplication::translate("MainWindow", "[", 0));
        whileb->setText(QApplication::translate("MainWindow", "WHILE", 0));
        arcsin->setText(QApplication::translate("MainWindow", "ARCSIN", 0));
        arccos->setText(QApplication::translate("MainWindow", "ARCCOS", 0));
        arctan->setText(QApplication::translate("MainWindow", "ARCTAN", 0));
        cos->setText(QApplication::translate("MainWindow", "COS", 0));
        sin->setText(QApplication::translate("MainWindow", "SIN", 0));
        tan->setText(QApplication::translate("MainWindow", "TAN", 0));
        im->setText(QApplication::translate("MainWindow", "IM", 0));
        re->setText(QApplication::translate("MainWindow", "RE", 0));
        arg->setText(QApplication::translate("MainWindow", "ARG", 0));
        norm->setText(QApplication::translate("MainWindow", "NORM", 0));
        dollar->setText(QApplication::translate("MainWindow", "$", 0));
        exp->setText(QApplication::translate("MainWindow", "EXP", 0));
        ln->setText(QApplication::translate("MainWindow", "LN", 0));
        comma->setText(QApplication::translate("MainWindow", ",", 0));
        sqrt->setText(QApplication::translate("MainWindow", "SQRT", 0));
        pow->setText(QApplication::translate("MainWindow", "POW", 0));
        leftParenthesis->setText(QApplication::translate("MainWindow", "(", 0));
        div->setText(QApplication::translate("MainWindow", "DIV", 0));
        mod->setText(QApplication::translate("MainWindow", "MOD", 0));
        den->setText(QApplication::translate("MainWindow", "DEN", 0));
        num->setText(QApplication::translate("MainWindow", "NUM", 0));
        rightParenthesis->setText(QApplication::translate("MainWindow", ")", 0));
        neg->setText(QApplication::translate("MainWindow", "NEG", 0));
        b5->setText(QApplication::translate("MainWindow", "5", 0));
        b0->setText(QApplication::translate("MainWindow", "0", 0));
        b8->setText(QApplication::translate("MainWindow", "8", 0));
        b9->setText(QApplication::translate("MainWindow", "9", 0));
        divide->setText(QApplication::translate("MainWindow", "/", 0));
        b4->setText(QApplication::translate("MainWindow", "4", 0));
        b1->setText(QApplication::translate("MainWindow", "1", 0));
        b7->setText(QApplication::translate("MainWindow", "7", 0));
        b3->setText(QApplication::translate("MainWindow", "3", 0));
        minus->setText(QApplication::translate("MainWindow", "-", 0));
        times->setText(QApplication::translate("MainWindow", "*", 0));
        b6->setText(QApplication::translate("MainWindow", "6", 0));
        dot->setText(QApplication::translate("MainWindow", ".", 0));
        b2->setText(QApplication::translate("MainWindow", "2", 0));
        plus->setText(QApplication::translate("MainWindow", "+", 0));
        eval->setText(QApplication::translate("MainWindow", "EVAL", 0));
        enter->setText(QApplication::translate("MainWindow", "=", 0));
        edit->setText(QApplication::translate("MainWindow", "EDIT", 0));
        clear->setText(QApplication::translate("MainWindow", "CLEAR", 0));
        quote->setText(QApplication::translate("MainWindow", "'", 0));
        backspace->setText(QApplication::translate("MainWindow", "\342\206\220", 0));
        swap->setText(QApplication::translate("MainWindow", "SWAP", 0));
        lastargs->setText(QApplication::translate("MainWindow", "LASTARGS", 0));
        redo->setText(QApplication::translate("MainWindow", "REDO", 0));
        sto->setText(QApplication::translate("MainWindow", "STO", 0));
        dup->setText(QApplication::translate("MainWindow", "DUP", 0));
        forget->setText(QApplication::translate("MainWindow", "FORGET", 0));
        lastop->setText(QApplication::translate("MainWindow", "LASTOP", 0));
        undo->setText(QApplication::translate("MainWindow", "UNDO", 0));
        drop->setText(QApplication::translate("MainWindow", "DROP", 0));
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
