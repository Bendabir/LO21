#include "mainwindow.h"
#include "ui_mainwindow.h"

#define STACK_SIZE 5

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    editProgrammDialog(new QDialog(this)),
    editVariablesDialog(new QDialog(this))
{
    ui->setupUi(this);

    editProgrammDialog->setWindowTitle("UTComputer - Edition des programmes");
    editProgrammDialog->setFixedSize(640, 480);
    editVariablesDialog->setWindowTitle("UTComputer - Edition des programmes");
    editVariablesDialog->setFixedSize(640, 480);

    // Mise en place via Qt Designer
    // On connecte tous les slots et les raccourcis

    // Quitte l'application
    QObject::connect(ui->actionQuitter, SIGNAL(triggered(bool)), this, SLOT(close()));

    // Afficher l'édition des programmes/variables
    QObject::connect(ui->actionEdition_des_programmes, SIGNAL(triggered(bool)), editProgrammDialog, SLOT(show()));
    QObject::connect(ui->actionEdition_des_variables, SIGNAL(triggered(bool)), editVariablesDialog, SLOT(show()));

    // Raccourcis
    ui->actionQuitter->setShortcut(QKeySequence::Quit);
    ui->actionAnnuler->setShortcut(QKeySequence::Undo);
    ui->actionR_tablir->setShortcut(QKeySequence::Redo);

    // Paramètres de l'application
    this->setWindowTitle("UTComputer");
    this->setWindowIcon(QIcon(QCoreApplication::applicationDirPath() + "/icon.png"));

    ui->tableWidget->horizontalHeader()->setVisible(false);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // Petit test des chaumières pour l'affichage
    for(unsigned int i = 0; i < STACK_SIZE; i++)
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(STACK_SIZE - i)));

    // On va bricoler les labels
   QStringList labels;
   for(unsigned int i = STACK_SIZE; i > 0; i--){
       QString label = QString::number(i);
       label += " :";
       labels << label;
   }
   ui->tableWidget->setVerticalHeaderLabels(labels);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete editProgrammDialog;
}
