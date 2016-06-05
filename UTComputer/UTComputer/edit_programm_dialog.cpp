#include "edit_programm_dialog.h"
#include "ui_edit_programm_dialog.h"

EditProgrammDialog::EditProgrammDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditProgrammDialog)
{
    ui->setupUi(this);

    this->setWindowTitle("UTComputer - Edition des programmes");
    ui->errorLine->setText("Aucun message pour le moment.");

    // On connecte les slots
    QObject::connect(ui->close, SIGNAL(pressed()), this, SLOT(close()));

    // Juste pour du test
    QStringList programms;
    programms << "Programme 1" << "Programme 2" << "Modulo" << "LO21";
    ui->comboBox->addItems(programms);

    QString abs = "[ DUP 0 < [ NEG ] IFT ]";
    abs.replace(" ", "\n");

    int parenthesisCount = 0;
    for(int i = 0; i < abs.size(); i++){
        if(abs[i] == '[')
            parenthesisCount++;

        if(abs[i] == ']')
            parenthesisCount--;

        if(abs[i] == '\n')
            abs.insert(i+1, QString(" ").repeated(4 * parenthesisCount));
    }
    ui->plainTextEdit->document()->setPlainText(abs);
    ui->plainTextEdit->setFont(QFont("serif"));
}

EditProgrammDialog::~EditProgrammDialog()
{
    delete ui;
}
