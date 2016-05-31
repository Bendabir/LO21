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
    QLineEdit *errorInput;
    QTableWidget *tableWidget;
    QLineEdit *commandInput;
    QGridLayout *gridLayout_10;
    QGridLayout *gridLayout_6;
    QPushButton *sqrt;
    QPushButton *exp;
    QPushButton *pow;
    QPushButton *ln;
    QGridLayout *gridLayout_3;
    QPushButton *mod;
    QPushButton *div;
    QPushButton *den;
    QPushButton *num;
    QGridLayout *gridLayout_8;
    QPushButton *lastop;
    QPushButton *swap;
    QPushButton *lastargs;
    QPushButton *drop;
    QPushButton *dup;
    QPushButton *undo;
    QPushButton *redo;
    QGridLayout *gridLayout_9;
    QGridLayout *gridLayout_7;
    QPushButton *orb;
    QPushButton *notb;
    QPushButton *equalb;
    QPushButton *notEqual;
    QPushButton *lte;
    QPushButton *gt;
    QPushButton *gte;
    QPushButton *lt;
    QPushButton *andb;
    QGridLayout *gridLayout_11;
    QPushButton *ift;
    QPushButton *ifte;
    QGridLayout *gridLayout;
    QPushButton *rightBracket;
    QPushButton *leftBracket;
    QPushButton *pushButton_58;
    QGridLayout *gridLayout_2;
    QPushButton *neg;
    QPushButton *b0;
    QPushButton *b5;
    QPushButton *b1;
    QPushButton *b4;
    QPushButton *b9;
    QPushButton *b8;
    QPushButton *b7;
    QPushButton *b6;
    QPushButton *divide;
    QPushButton *times;
    QPushButton *minus;
    QPushButton *plus;
    QPushButton *comma;
    QPushButton *b3;
    QPushButton *b2;
    QPushButton *enter;
    QPushButton *eval;
    QPushButton *edit;
    QPushButton *clear;
    QPushButton *backspace;
    QGridLayout *gridLayout_5;
    QPushButton *arcsin;
    QPushButton *arccos;
    QPushButton *arctan;
    QPushButton *cos;
    QPushButton *sin;
    QPushButton *tan;
    QGridLayout *gridLayout_4;
    QPushButton *im;
    QPushButton *re;
    QPushButton *arg;
    QPushButton *norm;
    QPushButton *dollar;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QMenu *menuEdition;
    QMenu *menuA_propos;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(997, 633);
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
        verticalLayoutWidget->setGeometry(QRect(9, 9, 980, 591));
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
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        sqrt = new QPushButton(verticalLayoutWidget);
        sqrt->setObjectName(QStringLiteral("sqrt"));
        sizePolicy.setHeightForWidth(sqrt->sizePolicy().hasHeightForWidth());
        sqrt->setSizePolicy(sizePolicy);
        sqrt->setBaseSize(QSize(30, 30));

        gridLayout_6->addWidget(sqrt, 1, 0, 1, 1);

        exp = new QPushButton(verticalLayoutWidget);
        exp->setObjectName(QStringLiteral("exp"));
        sizePolicy.setHeightForWidth(exp->sizePolicy().hasHeightForWidth());
        exp->setSizePolicy(sizePolicy);
        exp->setBaseSize(QSize(30, 30));

        gridLayout_6->addWidget(exp, 2, 0, 1, 1);

        pow = new QPushButton(verticalLayoutWidget);
        pow->setObjectName(QStringLiteral("pow"));
        sizePolicy.setHeightForWidth(pow->sizePolicy().hasHeightForWidth());
        pow->setSizePolicy(sizePolicy);
        pow->setBaseSize(QSize(30, 30));

        gridLayout_6->addWidget(pow, 0, 0, 1, 1);

        ln = new QPushButton(verticalLayoutWidget);
        ln->setObjectName(QStringLiteral("ln"));
        sizePolicy.setHeightForWidth(ln->sizePolicy().hasHeightForWidth());
        ln->setSizePolicy(sizePolicy);
        ln->setBaseSize(QSize(30, 30));

        gridLayout_6->addWidget(ln, 3, 0, 1, 1);


        gridLayout_10->addLayout(gridLayout_6, 1, 3, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        mod = new QPushButton(verticalLayoutWidget);
        mod->setObjectName(QStringLiteral("mod"));
        sizePolicy.setHeightForWidth(mod->sizePolicy().hasHeightForWidth());
        mod->setSizePolicy(sizePolicy);
        mod->setBaseSize(QSize(30, 30));

        gridLayout_3->addWidget(mod, 5, 2, 1, 1);

        div = new QPushButton(verticalLayoutWidget);
        div->setObjectName(QStringLiteral("div"));
        sizePolicy.setHeightForWidth(div->sizePolicy().hasHeightForWidth());
        div->setSizePolicy(sizePolicy);
        div->setBaseSize(QSize(30, 30));

        gridLayout_3->addWidget(div, 4, 2, 1, 1);

        den = new QPushButton(verticalLayoutWidget);
        den->setObjectName(QStringLiteral("den"));
        sizePolicy.setHeightForWidth(den->sizePolicy().hasHeightForWidth());
        den->setSizePolicy(sizePolicy);
        den->setBaseSize(QSize(30, 30));

        gridLayout_3->addWidget(den, 3, 2, 1, 1);

        num = new QPushButton(verticalLayoutWidget);
        num->setObjectName(QStringLiteral("num"));
        sizePolicy.setHeightForWidth(num->sizePolicy().hasHeightForWidth());
        num->setSizePolicy(sizePolicy);
        num->setBaseSize(QSize(30, 30));

        gridLayout_3->addWidget(num, 2, 2, 1, 1);


        gridLayout_10->addLayout(gridLayout_3, 1, 2, 1, 1);

        gridLayout_8 = new QGridLayout();
        gridLayout_8->setSpacing(6);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        lastop = new QPushButton(verticalLayoutWidget);
        lastop->setObjectName(QStringLiteral("lastop"));
        sizePolicy.setHeightForWidth(lastop->sizePolicy().hasHeightForWidth());
        lastop->setSizePolicy(sizePolicy);

        gridLayout_8->addWidget(lastop, 2, 0, 1, 1);

        swap = new QPushButton(verticalLayoutWidget);
        swap->setObjectName(QStringLiteral("swap"));
        sizePolicy.setHeightForWidth(swap->sizePolicy().hasHeightForWidth());
        swap->setSizePolicy(sizePolicy);

        gridLayout_8->addWidget(swap, 0, 1, 1, 1);

        lastargs = new QPushButton(verticalLayoutWidget);
        lastargs->setObjectName(QStringLiteral("lastargs"));
        sizePolicy.setHeightForWidth(lastargs->sizePolicy().hasHeightForWidth());
        lastargs->setSizePolicy(sizePolicy);

        gridLayout_8->addWidget(lastargs, 2, 1, 1, 1);

        drop = new QPushButton(verticalLayoutWidget);
        drop->setObjectName(QStringLiteral("drop"));
        sizePolicy.setHeightForWidth(drop->sizePolicy().hasHeightForWidth());
        drop->setSizePolicy(sizePolicy);

        gridLayout_8->addWidget(drop, 1, 0, 1, 2);

        dup = new QPushButton(verticalLayoutWidget);
        dup->setObjectName(QStringLiteral("dup"));
        sizePolicy.setHeightForWidth(dup->sizePolicy().hasHeightForWidth());
        dup->setSizePolicy(sizePolicy);

        gridLayout_8->addWidget(dup, 0, 0, 1, 1);

        undo = new QPushButton(verticalLayoutWidget);
        undo->setObjectName(QStringLiteral("undo"));
        sizePolicy.setHeightForWidth(undo->sizePolicy().hasHeightForWidth());
        undo->setSizePolicy(sizePolicy);

        gridLayout_8->addWidget(undo, 3, 0, 1, 1);

        redo = new QPushButton(verticalLayoutWidget);
        redo->setObjectName(QStringLiteral("redo"));
        sizePolicy.setHeightForWidth(redo->sizePolicy().hasHeightForWidth());
        redo->setSizePolicy(sizePolicy);

        gridLayout_8->addWidget(redo, 3, 1, 1, 1);


        gridLayout_10->addLayout(gridLayout_8, 0, 0, 1, 1);

        gridLayout_9 = new QGridLayout();
        gridLayout_9->setSpacing(6);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setSpacing(6);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        orb = new QPushButton(verticalLayoutWidget);
        orb->setObjectName(QStringLiteral("orb"));
        sizePolicy.setHeightForWidth(orb->sizePolicy().hasHeightForWidth());
        orb->setSizePolicy(sizePolicy);
        orb->setBaseSize(QSize(30, 30));

        gridLayout_7->addWidget(orb, 1, 0, 1, 1);

        notb = new QPushButton(verticalLayoutWidget);
        notb->setObjectName(QStringLiteral("notb"));
        sizePolicy.setHeightForWidth(notb->sizePolicy().hasHeightForWidth());
        notb->setSizePolicy(sizePolicy);
        notb->setBaseSize(QSize(30, 30));

        gridLayout_7->addWidget(notb, 2, 0, 1, 1);

        equalb = new QPushButton(verticalLayoutWidget);
        equalb->setObjectName(QStringLiteral("equalb"));
        sizePolicy.setHeightForWidth(equalb->sizePolicy().hasHeightForWidth());
        equalb->setSizePolicy(sizePolicy);
        equalb->setBaseSize(QSize(30, 30));

        gridLayout_7->addWidget(equalb, 0, 1, 1, 1);

        notEqual = new QPushButton(verticalLayoutWidget);
        notEqual->setObjectName(QStringLiteral("notEqual"));
        sizePolicy.setHeightForWidth(notEqual->sizePolicy().hasHeightForWidth());
        notEqual->setSizePolicy(sizePolicy);
        notEqual->setBaseSize(QSize(30, 30));

        gridLayout_7->addWidget(notEqual, 0, 2, 1, 1);

        lte = new QPushButton(verticalLayoutWidget);
        lte->setObjectName(QStringLiteral("lte"));
        sizePolicy.setHeightForWidth(lte->sizePolicy().hasHeightForWidth());
        lte->setSizePolicy(sizePolicy);
        lte->setBaseSize(QSize(30, 30));

        gridLayout_7->addWidget(lte, 1, 2, 1, 1);

        gt = new QPushButton(verticalLayoutWidget);
        gt->setObjectName(QStringLiteral("gt"));
        sizePolicy.setHeightForWidth(gt->sizePolicy().hasHeightForWidth());
        gt->setSizePolicy(sizePolicy);
        gt->setBaseSize(QSize(30, 30));

        gridLayout_7->addWidget(gt, 2, 1, 1, 1);

        gte = new QPushButton(verticalLayoutWidget);
        gte->setObjectName(QStringLiteral("gte"));
        sizePolicy.setHeightForWidth(gte->sizePolicy().hasHeightForWidth());
        gte->setSizePolicy(sizePolicy);
        gte->setBaseSize(QSize(30, 30));

        gridLayout_7->addWidget(gte, 2, 2, 1, 1);

        lt = new QPushButton(verticalLayoutWidget);
        lt->setObjectName(QStringLiteral("lt"));
        sizePolicy.setHeightForWidth(lt->sizePolicy().hasHeightForWidth());
        lt->setSizePolicy(sizePolicy);
        lt->setBaseSize(QSize(30, 30));

        gridLayout_7->addWidget(lt, 1, 1, 1, 1);

        andb = new QPushButton(verticalLayoutWidget);
        andb->setObjectName(QStringLiteral("andb"));
        sizePolicy.setHeightForWidth(andb->sizePolicy().hasHeightForWidth());
        andb->setSizePolicy(sizePolicy);
        andb->setBaseSize(QSize(30, 30));

        gridLayout_7->addWidget(andb, 0, 0, 1, 1);


        gridLayout_9->addLayout(gridLayout_7, 5, 1, 1, 1);

        gridLayout_11 = new QGridLayout();
        gridLayout_11->setSpacing(6);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        ift = new QPushButton(verticalLayoutWidget);
        ift->setObjectName(QStringLiteral("ift"));
        sizePolicy.setHeightForWidth(ift->sizePolicy().hasHeightForWidth());
        ift->setSizePolicy(sizePolicy);

        gridLayout_11->addWidget(ift, 1, 0, 1, 1);

        ifte = new QPushButton(verticalLayoutWidget);
        ifte->setObjectName(QStringLiteral("ifte"));
        sizePolicy.setHeightForWidth(ifte->sizePolicy().hasHeightForWidth());
        ifte->setSizePolicy(sizePolicy);

        gridLayout_11->addWidget(ifte, 1, 1, 1, 1);


        gridLayout_9->addLayout(gridLayout_11, 2, 1, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        rightBracket = new QPushButton(verticalLayoutWidget);
        rightBracket->setObjectName(QStringLiteral("rightBracket"));

        gridLayout->addWidget(rightBracket, 0, 1, 1, 1);

        leftBracket = new QPushButton(verticalLayoutWidget);
        leftBracket->setObjectName(QStringLiteral("leftBracket"));

        gridLayout->addWidget(leftBracket, 0, 0, 1, 1);


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
        neg = new QPushButton(verticalLayoutWidget);
        neg->setObjectName(QStringLiteral("neg"));
        sizePolicy.setHeightForWidth(neg->sizePolicy().hasHeightForWidth());
        neg->setSizePolicy(sizePolicy);
        neg->setBaseSize(QSize(30, 30));

        gridLayout_2->addWidget(neg, 0, 3, 1, 1);

        b0 = new QPushButton(verticalLayoutWidget);
        b0->setObjectName(QStringLiteral("b0"));
        sizePolicy.setHeightForWidth(b0->sizePolicy().hasHeightForWidth());
        b0->setSizePolicy(sizePolicy);
        b0->setBaseSize(QSize(30, 30));

        gridLayout_2->addWidget(b0, 4, 0, 1, 2);

        b5 = new QPushButton(verticalLayoutWidget);
        b5->setObjectName(QStringLiteral("b5"));
        sizePolicy.setHeightForWidth(b5->sizePolicy().hasHeightForWidth());
        b5->setSizePolicy(sizePolicy);
        b5->setBaseSize(QSize(30, 30));

        gridLayout_2->addWidget(b5, 2, 1, 1, 1);

        b1 = new QPushButton(verticalLayoutWidget);
        b1->setObjectName(QStringLiteral("b1"));
        sizePolicy.setHeightForWidth(b1->sizePolicy().hasHeightForWidth());
        b1->setSizePolicy(sizePolicy);
        b1->setBaseSize(QSize(30, 30));

        gridLayout_2->addWidget(b1, 3, 0, 1, 1);

        b4 = new QPushButton(verticalLayoutWidget);
        b4->setObjectName(QStringLiteral("b4"));
        sizePolicy.setHeightForWidth(b4->sizePolicy().hasHeightForWidth());
        b4->setSizePolicy(sizePolicy);
        b4->setBaseSize(QSize(30, 30));

        gridLayout_2->addWidget(b4, 2, 0, 1, 1);

        b9 = new QPushButton(verticalLayoutWidget);
        b9->setObjectName(QStringLiteral("b9"));
        sizePolicy.setHeightForWidth(b9->sizePolicy().hasHeightForWidth());
        b9->setSizePolicy(sizePolicy);
        b9->setBaseSize(QSize(30, 30));

        gridLayout_2->addWidget(b9, 1, 2, 1, 1);

        b8 = new QPushButton(verticalLayoutWidget);
        b8->setObjectName(QStringLiteral("b8"));
        sizePolicy.setHeightForWidth(b8->sizePolicy().hasHeightForWidth());
        b8->setSizePolicy(sizePolicy);
        b8->setBaseSize(QSize(30, 30));

        gridLayout_2->addWidget(b8, 1, 1, 1, 1);

        b7 = new QPushButton(verticalLayoutWidget);
        b7->setObjectName(QStringLiteral("b7"));
        sizePolicy.setHeightForWidth(b7->sizePolicy().hasHeightForWidth());
        b7->setSizePolicy(sizePolicy);
        b7->setBaseSize(QSize(30, 30));

        gridLayout_2->addWidget(b7, 1, 0, 1, 1);

        b6 = new QPushButton(verticalLayoutWidget);
        b6->setObjectName(QStringLiteral("b6"));
        sizePolicy.setHeightForWidth(b6->sizePolicy().hasHeightForWidth());
        b6->setSizePolicy(sizePolicy);
        b6->setBaseSize(QSize(30, 30));

        gridLayout_2->addWidget(b6, 2, 2, 1, 1);

        divide = new QPushButton(verticalLayoutWidget);
        divide->setObjectName(QStringLiteral("divide"));
        sizePolicy.setHeightForWidth(divide->sizePolicy().hasHeightForWidth());
        divide->setSizePolicy(sizePolicy);
        divide->setBaseSize(QSize(30, 30));

        gridLayout_2->addWidget(divide, 1, 3, 1, 1);

        times = new QPushButton(verticalLayoutWidget);
        times->setObjectName(QStringLiteral("times"));
        sizePolicy.setHeightForWidth(times->sizePolicy().hasHeightForWidth());
        times->setSizePolicy(sizePolicy);
        times->setBaseSize(QSize(30, 30));

        gridLayout_2->addWidget(times, 2, 3, 1, 1);

        minus = new QPushButton(verticalLayoutWidget);
        minus->setObjectName(QStringLiteral("minus"));
        sizePolicy.setHeightForWidth(minus->sizePolicy().hasHeightForWidth());
        minus->setSizePolicy(sizePolicy);
        minus->setBaseSize(QSize(30, 30));

        gridLayout_2->addWidget(minus, 3, 3, 1, 1);

        plus = new QPushButton(verticalLayoutWidget);
        plus->setObjectName(QStringLiteral("plus"));
        sizePolicy.setHeightForWidth(plus->sizePolicy().hasHeightForWidth());
        plus->setSizePolicy(sizePolicy);
        plus->setBaseSize(QSize(30, 30));

        gridLayout_2->addWidget(plus, 4, 3, 1, 1);

        comma = new QPushButton(verticalLayoutWidget);
        comma->setObjectName(QStringLiteral("comma"));
        sizePolicy.setHeightForWidth(comma->sizePolicy().hasHeightForWidth());
        comma->setSizePolicy(sizePolicy);
        comma->setBaseSize(QSize(30, 30));

        gridLayout_2->addWidget(comma, 4, 2, 1, 1);

        b3 = new QPushButton(verticalLayoutWidget);
        b3->setObjectName(QStringLiteral("b3"));
        sizePolicy.setHeightForWidth(b3->sizePolicy().hasHeightForWidth());
        b3->setSizePolicy(sizePolicy);
        b3->setBaseSize(QSize(30, 30));

        gridLayout_2->addWidget(b3, 3, 2, 1, 1);

        b2 = new QPushButton(verticalLayoutWidget);
        b2->setObjectName(QStringLiteral("b2"));
        sizePolicy.setHeightForWidth(b2->sizePolicy().hasHeightForWidth());
        b2->setSizePolicy(sizePolicy);
        b2->setBaseSize(QSize(30, 30));

        gridLayout_2->addWidget(b2, 3, 1, 1, 1);

        enter = new QPushButton(verticalLayoutWidget);
        enter->setObjectName(QStringLiteral("enter"));
        sizePolicy.setHeightForWidth(enter->sizePolicy().hasHeightForWidth());
        enter->setSizePolicy(sizePolicy);
        enter->setBaseSize(QSize(30, 30));
        enter->setLayoutDirection(Qt::LeftToRight);
        enter->setAutoFillBackground(false);
        enter->setFlat(false);

        gridLayout_2->addWidget(enter, 3, 4, 2, 1);

        eval = new QPushButton(verticalLayoutWidget);
        eval->setObjectName(QStringLiteral("eval"));
        sizePolicy.setHeightForWidth(eval->sizePolicy().hasHeightForWidth());
        eval->setSizePolicy(sizePolicy);
        eval->setBaseSize(QSize(30, 30));

        gridLayout_2->addWidget(eval, 2, 4, 1, 1);

        edit = new QPushButton(verticalLayoutWidget);
        edit->setObjectName(QStringLiteral("edit"));
        sizePolicy.setHeightForWidth(edit->sizePolicy().hasHeightForWidth());
        edit->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(edit, 1, 4, 1, 1);

        clear = new QPushButton(verticalLayoutWidget);
        clear->setObjectName(QStringLiteral("clear"));
        sizePolicy.setHeightForWidth(clear->sizePolicy().hasHeightForWidth());
        clear->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(clear, 0, 4, 1, 1);

        backspace = new QPushButton(verticalLayoutWidget);
        backspace->setObjectName(QStringLiteral("backspace"));
        sizePolicy.setHeightForWidth(backspace->sizePolicy().hasHeightForWidth());
        backspace->setSizePolicy(sizePolicy);
        backspace->setBaseSize(QSize(30, 30));

        gridLayout_2->addWidget(backspace, 0, 0, 1, 3);


        gridLayout_10->addLayout(gridLayout_2, 0, 4, 2, 1);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        arcsin = new QPushButton(verticalLayoutWidget);
        arcsin->setObjectName(QStringLiteral("arcsin"));
        sizePolicy.setHeightForWidth(arcsin->sizePolicy().hasHeightForWidth());
        arcsin->setSizePolicy(sizePolicy);
        arcsin->setBaseSize(QSize(30, 30));

        gridLayout_5->addWidget(arcsin, 1, 1, 1, 1);

        arccos = new QPushButton(verticalLayoutWidget);
        arccos->setObjectName(QStringLiteral("arccos"));
        sizePolicy.setHeightForWidth(arccos->sizePolicy().hasHeightForWidth());
        arccos->setSizePolicy(sizePolicy);
        arccos->setBaseSize(QSize(30, 30));

        gridLayout_5->addWidget(arccos, 0, 1, 1, 1);

        arctan = new QPushButton(verticalLayoutWidget);
        arctan->setObjectName(QStringLiteral("arctan"));
        sizePolicy.setHeightForWidth(arctan->sizePolicy().hasHeightForWidth());
        arctan->setSizePolicy(sizePolicy);
        arctan->setBaseSize(QSize(30, 30));

        gridLayout_5->addWidget(arctan, 2, 1, 1, 1);

        cos = new QPushButton(verticalLayoutWidget);
        cos->setObjectName(QStringLiteral("cos"));
        sizePolicy.setHeightForWidth(cos->sizePolicy().hasHeightForWidth());
        cos->setSizePolicy(sizePolicy);
        cos->setBaseSize(QSize(30, 30));

        gridLayout_5->addWidget(cos, 0, 0, 1, 1);

        sin = new QPushButton(verticalLayoutWidget);
        sin->setObjectName(QStringLiteral("sin"));
        sizePolicy.setHeightForWidth(sin->sizePolicy().hasHeightForWidth());
        sin->setSizePolicy(sizePolicy);
        sin->setBaseSize(QSize(30, 30));

        gridLayout_5->addWidget(sin, 1, 0, 1, 1);

        tan = new QPushButton(verticalLayoutWidget);
        tan->setObjectName(QStringLiteral("tan"));
        sizePolicy.setHeightForWidth(tan->sizePolicy().hasHeightForWidth());
        tan->setSizePolicy(sizePolicy);
        tan->setBaseSize(QSize(30, 30));

        gridLayout_5->addWidget(tan, 2, 0, 1, 1);


        gridLayout_10->addLayout(gridLayout_5, 0, 3, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        im = new QPushButton(verticalLayoutWidget);
        im->setObjectName(QStringLiteral("im"));
        sizePolicy.setHeightForWidth(im->sizePolicy().hasHeightForWidth());
        im->setSizePolicy(sizePolicy);
        im->setBaseSize(QSize(30, 30));

        gridLayout_4->addWidget(im, 2, 0, 1, 1);

        re = new QPushButton(verticalLayoutWidget);
        re->setObjectName(QStringLiteral("re"));
        sizePolicy.setHeightForWidth(re->sizePolicy().hasHeightForWidth());
        re->setSizePolicy(sizePolicy);
        re->setBaseSize(QSize(30, 30));

        gridLayout_4->addWidget(re, 1, 0, 1, 1);

        arg = new QPushButton(verticalLayoutWidget);
        arg->setObjectName(QStringLiteral("arg"));
        sizePolicy.setHeightForWidth(arg->sizePolicy().hasHeightForWidth());
        arg->setSizePolicy(sizePolicy);
        arg->setBaseSize(QSize(30, 30));

        gridLayout_4->addWidget(arg, 1, 1, 1, 1);

        norm = new QPushButton(verticalLayoutWidget);
        norm->setObjectName(QStringLiteral("norm"));
        sizePolicy.setHeightForWidth(norm->sizePolicy().hasHeightForWidth());
        norm->setSizePolicy(sizePolicy);
        norm->setBaseSize(QSize(30, 30));

        gridLayout_4->addWidget(norm, 2, 1, 1, 1);

        dollar = new QPushButton(verticalLayoutWidget);
        dollar->setObjectName(QStringLiteral("dollar"));
        sizePolicy.setHeightForWidth(dollar->sizePolicy().hasHeightForWidth());
        dollar->setSizePolicy(sizePolicy);
        dollar->setBaseSize(QSize(30, 30));

        gridLayout_4->addWidget(dollar, 0, 0, 1, 2);


        gridLayout_10->addLayout(gridLayout_4, 0, 2, 1, 1);


        verticalLayout_2->addLayout(gridLayout_10);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 997, 21));
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
        sqrt->setText(QApplication::translate("MainWindow", "SQRT", 0));
        exp->setText(QApplication::translate("MainWindow", "EXP", 0));
        pow->setText(QApplication::translate("MainWindow", "POW", 0));
        ln->setText(QApplication::translate("MainWindow", "LN", 0));
        mod->setText(QApplication::translate("MainWindow", "MOD", 0));
        div->setText(QApplication::translate("MainWindow", "DIV", 0));
        den->setText(QApplication::translate("MainWindow", "DEN", 0));
        num->setText(QApplication::translate("MainWindow", "NUM", 0));
        lastop->setText(QApplication::translate("MainWindow", "LASTOP", 0));
        swap->setText(QApplication::translate("MainWindow", "SWAP", 0));
        lastargs->setText(QApplication::translate("MainWindow", "LASTARGS", 0));
        drop->setText(QApplication::translate("MainWindow", "DROP", 0));
        dup->setText(QApplication::translate("MainWindow", "DUP", 0));
        undo->setText(QApplication::translate("MainWindow", "UNDO", 0));
        redo->setText(QApplication::translate("MainWindow", "REDO", 0));
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
        pushButton_58->setText(QApplication::translate("MainWindow", "WHILE", 0));
        neg->setText(QApplication::translate("MainWindow", "NEG", 0));
        b0->setText(QApplication::translate("MainWindow", "0", 0));
        b5->setText(QApplication::translate("MainWindow", "5", 0));
        b1->setText(QApplication::translate("MainWindow", "1", 0));
        b4->setText(QApplication::translate("MainWindow", "4", 0));
        b9->setText(QApplication::translate("MainWindow", "9", 0));
        b8->setText(QApplication::translate("MainWindow", "8", 0));
        b7->setText(QApplication::translate("MainWindow", "7", 0));
        b6->setText(QApplication::translate("MainWindow", "6", 0));
        divide->setText(QApplication::translate("MainWindow", "/", 0));
        times->setText(QApplication::translate("MainWindow", "*", 0));
        minus->setText(QApplication::translate("MainWindow", "-", 0));
        plus->setText(QApplication::translate("MainWindow", "+", 0));
        comma->setText(QApplication::translate("MainWindow", ",", 0));
        b3->setText(QApplication::translate("MainWindow", "3", 0));
        b2->setText(QApplication::translate("MainWindow", "2", 0));
        enter->setText(QApplication::translate("MainWindow", "=", 0));
        eval->setText(QApplication::translate("MainWindow", "EVAL", 0));
        edit->setText(QApplication::translate("MainWindow", "EDIT", 0));
        clear->setText(QApplication::translate("MainWindow", "CLEAR", 0));
        backspace->setText(QApplication::translate("MainWindow", "BACKSPACE", 0));
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
