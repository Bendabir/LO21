#include "mainwindow.h"
#include "ui_mainwindow.h"

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
}

MainWindow::~MainWindow()
{
    delete ui;
    delete editProgrammDialog;
}
