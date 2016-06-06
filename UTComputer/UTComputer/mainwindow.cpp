#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPalette>
#include <QDebug>
#include <QKeyEvent>

const QString defaultMessage = "Aucun message pour le moment.";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    Calculator(),
    ui(new Ui::MainWindow),
    editProgrammDialog(new EditProgrammDialog(this))
{
    ui->setupUi(this);

    // Paramètres de l'application
    this->setWindowTitle("UTComputer");
    this->setFixedSize(1020, 610);

    // On donne le focus dans la ligne de commandes
    ui->commandInput->setFocus();
    ui->errorInput->setText(defaultMessage);

    // On charge les options
    try{
        this->settings->loadSettingsFromFile(*(this->stack), this->factory);
    }
    catch(const CalculatorException& e){
        setUserMessage(e.what());
    }

    settingsDialog = new SettingsDialog(this->settings ,this); // On ne peut pas le mettre en place avant que les settings soient chargées

    editVariablesDialog = new EditAtomDialog(&(this->factory), this);

    // Mise en place via Qt Designer
    // On connecte tous les slots et les raccourcis

    // Afficher l'édition des programmes/variables, etc.
    QObject::connect(ui->actionQuitter, SIGNAL(triggered(bool)), this, SLOT(close()));
    QObject::connect(ui->actionEdition_des_programmes, SIGNAL(triggered(bool)), editProgrammDialog, SLOT(show()));
    QObject::connect(ui->actionEdition_des_variables, SIGNAL(triggered(bool)), editVariablesDialog, SLOT(improvedShow()));
    QObject::connect(ui->actionOptions, SIGNAL(triggered(bool)), settingsDialog, SLOT(show()));

    // Les bouttons
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
    QObject::connect(ui->dot, SIGNAL(pressed()), this, SLOT(onDotPressed()));
    QObject::connect(ui->backspace, SIGNAL(pressed()), this, SLOT(onBackspacePressed()));
    QObject::connect(ui->clear, SIGNAL(pressed()), this, SLOT(onClearPressed()));
    QObject::connect(ui->dup, SIGNAL(pressed()), this, SLOT(onDupPressed()));
    QObject::connect(ui->swap, SIGNAL(pressed()), this, SLOT(onSwapPressed()));
    QObject::connect(ui->drop, SIGNAL(pressed()), this, SLOT(onDropPressed()));
    QObject::connect(ui->lastop, SIGNAL(pressed()), this, SLOT(onLastopPressed()));
    QObject::connect(ui->lastargs, SIGNAL(pressed()), this, SLOT(onLastargsPressed()));
    QObject::connect(ui->undo, SIGNAL(pressed()), this, SLOT(onUndoPressed()));
    QObject::connect(ui->redo, SIGNAL(pressed()), this, SLOT(onRedoPressed()));
    QObject::connect(ui->whileb, SIGNAL(pressed()), this, SLOT(onWhilePressed()));
    QObject::connect(ui->ift, SIGNAL(pressed()), this, SLOT(onIftPressed()));
    QObject::connect(ui->ifte, SIGNAL(pressed()), this, SLOT(onIftePressed()));
    QObject::connect(ui->leftBracket, SIGNAL(pressed()), this, SLOT(onLeftBracketPressed()));
    QObject::connect(ui->rightBracket, SIGNAL(pressed()), this, SLOT(onRightBracketPressed()));
    QObject::connect(ui->andb, SIGNAL(pressed()), this, SLOT(onAndPressed()));
    QObject::connect(ui->orb, SIGNAL(pressed()), this, SLOT(onOrPressed()));
    QObject::connect(ui->notb, SIGNAL(pressed()), this, SLOT(onNotPressed()));
    QObject::connect(ui->equalb, SIGNAL(pressed()), this, SLOT(onEqualPressed()));
    QObject::connect(ui->notEqual, SIGNAL(pressed()), this, SLOT(onNotEqualPressed()));
    QObject::connect(ui->lt, SIGNAL(pressed()), this, SLOT(onLtPressed()));
    QObject::connect(ui->lte, SIGNAL(pressed()), this, SLOT(onLtePressed()));
    QObject::connect(ui->gt, SIGNAL(pressed()), this, SLOT(onGtPressed()));
    QObject::connect(ui->gte, SIGNAL(pressed()), this, SLOT(onGtePressed()));
    QObject::connect(ui->dollar, SIGNAL(pressed()), this, SLOT(onDollarPressed()));
    QObject::connect(ui->re, SIGNAL(pressed()), this, SLOT(onRePressed()));
    QObject::connect(ui->im, SIGNAL(pressed()), this, SLOT(onImPressed()));
    QObject::connect(ui->arg, SIGNAL(pressed()), this, SLOT(onArgPressed()));
    QObject::connect(ui->norm, SIGNAL(pressed()), this, SLOT(onNormPressed()));
    QObject::connect(ui->num, SIGNAL(pressed()), this, SLOT(onNumPressed()));
    QObject::connect(ui->den, SIGNAL(pressed()), this, SLOT(onDenPressed()));
    QObject::connect(ui->div, SIGNAL(pressed()), this, SLOT(onDivPressed()));
    QObject::connect(ui->mod, SIGNAL(pressed()), this, SLOT(onModPressed()));
    QObject::connect(ui->cos, SIGNAL(pressed()), this, SLOT(onCosPressed()));
    QObject::connect(ui->sin, SIGNAL(pressed()), this, SLOT(onSinPressed()));
    QObject::connect(ui->tan, SIGNAL(pressed()), this, SLOT(onTanPressed()));
    QObject::connect(ui->arccos, SIGNAL(pressed()), this, SLOT(onArccosPressed()));
    QObject::connect(ui->arcsin, SIGNAL(pressed()), this, SLOT(onArcsinPressed()));
    QObject::connect(ui->arctan, SIGNAL(pressed()), this, SLOT(onArctanPressed()));
    QObject::connect(ui->pow, SIGNAL(pressed()), this, SLOT(onPowPressed()));
    QObject::connect(ui->sqrt, SIGNAL(pressed()), this, SLOT(onSqrtPressed()));
    QObject::connect(ui->exp, SIGNAL(pressed()), this, SLOT(onExpPressed()));
    QObject::connect(ui->ln, SIGNAL(pressed()), this, SLOT(onLnPressed()));
    QObject::connect(ui->quote, SIGNAL(pressed()), this, SLOT(onQuotePressed()));
    QObject::connect(ui->neg, SIGNAL(pressed()), this, SLOT(onNegPressed()));
    QObject::connect(ui->edit, SIGNAL(pressed()), this, SLOT(onEditPressed()));
    QObject::connect(ui->eval, SIGNAL(pressed()), this, SLOT(onEvalPressed()));
    QObject::connect(ui->divide, SIGNAL(pressed()), this, SLOT(onDividePressed()));
    QObject::connect(ui->times, SIGNAL(pressed()), this, SLOT(onTimesPressed()));
    QObject::connect(ui->minus, SIGNAL(pressed()), this, SLOT(onMinusPressed()));
    QObject::connect(ui->plus, SIGNAL(pressed()), this, SLOT(onPlusPressed()));
    QObject::connect(ui->enter, SIGNAL(pressed()), this, SLOT(onEnterPressed()));
    QObject::connect(ui->comma, SIGNAL(pressed()), this, SLOT(onCommaPressed()));
    QObject::connect(ui->leftParenthesis, SIGNAL(pressed()), this, SLOT(onLeftParenthesisPressed()));
    QObject::connect(ui->rightParenthesis, SIGNAL(pressed()), this, SLOT(onRightParenthesisPressed()));

    // La gestion du controleur etc.
    QObject::connect(ui->commandInput, SIGNAL(returnPressed()), this, SLOT(execute()));
    QObject::connect(ui->actionSauvegarder, SIGNAL(triggered(bool)), this, SLOT(save()));
    QObject::connect(settingsDialog, SIGNAL(settingsChanged()), this, SLOT(updateSettings()));

    // Raccourcis
    ui->actionQuitter->setShortcut(QKeySequence::Quit);

    ui->actionSauvegarder->setShortcut(QKeySequence::Save);

    ui->tableWidget->horizontalHeader()->setVisible(false);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionMode(QTableWidget::NoSelection);

    updateSettings();

    // Tests
//    undoStack = new QUndoStack(this);
//    undoView = new QUndoView(undoStack);
//    undoView->setWindowTitle("Historique");
//    undoView->show();
//    undoView->setAttribute(Qt::WA_QuitOnClose, false);

//    ui->actionAnnuler = undoStack->createUndoAction(this, "Annuler");
//    ui->actionR_tablir = undoStack->createRedoAction(this, "Rétablir");

    ui->actionAnnuler->setShortcut(QKeySequence::Undo);
    ui->actionR_tablir->setShortcut(QKeySequence::Redo);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete editProgrammDialog;
}

// Permet de changer le texte de la ligne de commande
void MainWindow::addTextToCommand(const QString& exp){
    if(exp.isEmpty())
        return;

    QString text = ui->commandInput->text();

    // Si on ne traite pas un point, on ajoute un espace, sinon on le remplace par un point
    // Cela permet de créer des nombres à virgule

    if(exp != "." && exp != "," && exp != "(" && exp != "." && exp != ")")
        text += exp + " ";
    else
        text = text.left(text.length() - 1) + exp;

    // On prépare le texte
    ui->commandInput->setText(text);
}

void MainWindow::executeOperator(const QString& op){
    if(op.isEmpty())
        return;

    addTextToCommand(op);

    QString text = ui->commandInput->text().trimmed();

    // On tente l'exécution
    execute();
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
void MainWindow::onDotPressed(){
    addTextToCommand(".");
}

void MainWindow::onBackspacePressed(){
    ui->commandInput->backspace();
}

void MainWindow::onClearPressed(){
    executeOperator("CLEAR");
}

void MainWindow::onDupPressed(){
    executeOperator("DUP");
}
void MainWindow::onSwapPressed(){
    executeOperator("SWAP");
}
void MainWindow::onDropPressed(){
    executeOperator("DROP");
}
void MainWindow::onLastopPressed(){
    executeOperator("LASTOP");
}
void MainWindow::onLastargsPressed(){
    executeOperator("LASTARGS");
}
void MainWindow::onUndoPressed(){
    executeOperator("UNDO");
}
void MainWindow::onRedoPressed(){
    executeOperator("REDO");
}
void MainWindow::onWhilePressed(){
    executeOperator("WHILE");
}
void MainWindow::onIftPressed(){
    executeOperator("IFT");
}
void MainWindow::onIftePressed(){
    executeOperator("IFTE");
}
void MainWindow::onLeftBracketPressed(){
    addTextToCommand("[");
}
void MainWindow::onRightBracketPressed(){
    addTextToCommand("]");
}
void MainWindow::onAndPressed(){
    executeOperator("AND");
}
void MainWindow::onOrPressed(){
    executeOperator("OR");
}
void MainWindow::onNotPressed(){
    executeOperator("NOT");
}
void MainWindow::onEqualPressed(){
    executeOperator("=");
}
void MainWindow::onNotEqualPressed(){
    executeOperator("!=");
}
void MainWindow::onLtPressed(){
    executeOperator("<");
}
void MainWindow::onLtePressed(){
    executeOperator("<=");
}
void MainWindow::onGtPressed(){
    executeOperator(">");
}
void MainWindow::onGtePressed(){
    executeOperator(">=");
}
void MainWindow::onDollarPressed(){
    executeOperator("$");
}
void MainWindow::onRePressed(){
    executeOperator("RE");
}
void MainWindow::onImPressed(){
    executeOperator("IM");
}
void MainWindow::onArgPressed(){
    executeOperator("ARG");
}
void MainWindow::onNormPressed(){
    executeOperator("NORM");
}
void MainWindow::onNumPressed(){
    executeOperator("NUM");
}
void MainWindow::onDenPressed(){
    executeOperator("DEN");
}
void MainWindow::onDivPressed(){
    executeOperator("DIV");
}
void MainWindow::onModPressed(){
    executeOperator("MOD");
}
void MainWindow::onCosPressed(){
    executeOperator("COS");
}
void MainWindow::onSinPressed(){
    executeOperator("SIN");
}
void MainWindow::onTanPressed(){
    executeOperator("TAN");
}
void MainWindow::onArccosPressed(){
    executeOperator("ARCCOS");
}
void MainWindow::onArcsinPressed(){
    executeOperator("ARCSIN");
}
void MainWindow::onArctanPressed(){
    executeOperator("ARCTAN");
}
void MainWindow::onPowPressed(){
    executeOperator("POW");
}
void MainWindow::onSqrtPressed(){
    executeOperator("SQRT");
}
void MainWindow::onExpPressed(){
    executeOperator("EXP");
}
void MainWindow::onLnPressed(){
    executeOperator("LN");
}
void MainWindow::onQuotePressed(){
    addTextToCommand("'");
}
void MainWindow::onNegPressed(){
    executeOperator("NEG");
}
void MainWindow::onEditPressed(){
    editProgrammDialog->show();
}
void MainWindow::onEvalPressed(){
    executeOperator("EVAL");
}
void MainWindow::onDividePressed(){
    executeOperator("/");
}
void MainWindow::onTimesPressed(){
    executeOperator("*");
}
void MainWindow::onMinusPressed(){
    executeOperator("-");
}
void MainWindow::onPlusPressed(){
    executeOperator("+");
}
void MainWindow::onEnterPressed(){
    // Execution de la commande
    execute();
}
void MainWindow::onCommaPressed(){
    addTextToCommand(",");
}
void MainWindow::onLeftParenthesisPressed(){
    addTextToCommand("(");
}
void MainWindow::onRightParenthesisPressed(){
    addTextToCommand(")");
}
void MainWindow::onStoPressed(){
    executeOperator("STO");
}
void MainWindow::onForgetPressed(){
    executeOperator("FORGET");
}

void MainWindow::execute(){
    QString text = ui->commandInput->text().trimmed();

    // On tente l'exécution
    try{
        this->commandTest(text);
        setUserMessage(defaultMessage);
    }
    catch(const CalculatorException& e){
        setUserMessage(e.what());
    }

    refreshListView();

    ui->commandInput->clear();

    for(int i = 0; i < this->factory.size(); i++)
        if((this->factory)[i].isAtom())
            qDebug() << (this->factory)[i].toString() << " : " << (this->factory)[i].eval();

    qDebug() << endl;

    qDebug() << this->factory.existsAtom("Y2") << endl;
}

void MainWindow::updateSettings(){
    // On met à jour les options dès que la fenêtre d'options nous envoie un signal de mise à jour
    ui->widgetPad->setVisible(this->settings->getDisplayKeyboard());

    // On met à jour la vue de la pile
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setRowCount(this->settings->getNbLiteralsOnStack());

    QStringList labels;
    for(int i = 0; i < ui->tableWidget->rowCount(); i++){
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(""));
        QString label = QString::number(ui->tableWidget->rowCount() - i);
        labels << label;
    }
    ui->tableWidget->setVerticalHeaderLabels(labels);

    refreshListView();
}

void MainWindow::setUserMessage(const QString& message){
    if(this->settings->getPlaySound() && message != defaultMessage)
        QApplication::beep();

    ui->errorInput->setText(message);
}

void MainWindow::save(){
    try{
        this->settings->saveSettingsToFile(*(this->stack), this->factory);
        setUserMessage("INFO : Les paramètres, la pile, les programmes et les variables ont été sauvegardés.");
    }
    catch(const CalculatorException& e){
        setUserMessage(e.what());
    }
}

void MainWindow::refreshListView(){
    // On efface puis on réécrit
    for(int i = 0; i < ui->tableWidget->rowCount(); i++)
        ui->tableWidget->item(i, 0)->setText("");

    int i = ui->tableWidget->rowCount() - 1;
    for(Stack::reverse_iterator literal = this->stack->rbegin(); literal != this->stack->rend(); ++literal, i--)
        if(i >= 0)
            ui->tableWidget->item(i, 0)->setText((*literal).toString());
        else
            break;
}
