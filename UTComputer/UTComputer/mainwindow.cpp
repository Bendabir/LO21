#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPalette>

#define STACK_SIZE 5

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    Calculator(),
    ui(new Ui::MainWindow),
    editProgrammDialog(new QDialog(this)),
    editVariablesDialog(new EditAtomDialog(this))
{
    ui->setupUi(this);

    editProgrammDialog->setWindowTitle("UTComputer - Edition des programmes");
    editProgrammDialog->setFixedSize(640, 480);

    // Mise en place via Qt Designer
    // On connecte tous les slots et les raccourcis

    // Quitte l'application
    QObject::connect(ui->actionQuitter, SIGNAL(triggered(bool)), this, SLOT(close()));

    // Afficher l'édition des programmes/variables
    QObject::connect(ui->actionEdition_des_programmes, SIGNAL(triggered(bool)), editProgrammDialog, SLOT(show()));
    QObject::connect(ui->actionEdition_des_variables, SIGNAL(triggered(bool)), editVariablesDialog, SLOT(show()));
//    QObject::connect(ui->b0, SIGNAL(toggled(bool)), ui->commandInput, SLOT(setText(QString)));
    QObject::connect(ui->b0, SIGNAL(pressed()), this, SLOT(on0Pressed()));
    QObject::connect(ui->b1, SIGNAL(pressed()), this, SLOT(on1Pressed()));
    QObject::connect(ui->b2, SIGNAL(pressed()), this, SLOT(on2Pressed()));
    QObject::connect(ui->b3, SIGNAL(pressed()), this, SLOT(on3Pressed()));
    QObject::connect(ui->b4, SIGNAL(pressed()), this, SLOT(on4Pressed()));
    QObject::connect(ui->b5, SIGNAL(pressed()), this, SLOT(on5Pressed()));
    QObject::connect(ui->b6, SIGNAL(pressed()), this, SLOT(on6Pressed()));
    QObject::connect(ui->b7, SIGNAL(pressed()), this, SLOT(on7Pressed()));
    QObject::connect(ui->b8, SIGNAL(pressed()), this, SLOT(on8Pressed()));
    QObject::connect(ui->b9, SIGNAL(pressed()), this, SLOT(on9Pressed()));
    QObject::connect(ui->comma, SIGNAL(pressed()), this, SLOT(onCommaPressed()));
    QObject::connect(ui->backspace, SIGNAL(pressed()), this, SLOT(onBackspacePressed()));

    // On donne le focus dans la ligne de commandes
    ui->commandInput->setFocus();

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

// Permet de changer le texte de la ligne de commande
void MainWindow::addTextToCommand(const QString& exp){
    QString text = ui->commandInput->text() + exp;

    // Si on ne traite pas un point, on ajoute un espace, sinon on le remplace par un point
    // Cela permet de créer des nombres à virgule
    if(exp != ".")
        text += " ";
    else
        text = text.left(text.length() - 2) + exp;

    // On prépare le texte
    ui->commandInput->setText(text);
}

// On va faire d'une manière dégueu mais pas le temps de coder l'interface comme des vrais cowboys
void MainWindow::on0Pressed(){
    addTextToCommand("0");
}
void MainWindow::on1Pressed(){
    addTextToCommand("1");
}
void MainWindow::on2Pressed(){
    addTextToCommand("2");
}
void MainWindow::on3Pressed(){
    addTextToCommand("3");
}
void MainWindow::on4Pressed(){
    addTextToCommand("4");
}
void MainWindow::on5Pressed(){
    addTextToCommand("5");
}
void MainWindow::on6Pressed(){
    addTextToCommand("6");
}
void MainWindow::on7Pressed(){
    addTextToCommand("7");
}
void MainWindow::on8Pressed(){
    addTextToCommand("8");
}
void MainWindow::on9Pressed(){
    addTextToCommand("9");
}
void MainWindow::onCommaPressed(){
    addTextToCommand(".");
}

void MainWindow::onBackspacePressed(){
    ui->commandInput->backspace();
}
