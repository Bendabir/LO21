#ifndef EDIT_PROGRAMM_DIALOG_H
#define EDIT_PROGRAMM_DIALOG_H

#include <QDialog>

class LiteralFactory;

namespace Ui {
class EditProgrammDialog;
}

class EditProgrammDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditProgrammDialog(LiteralFactory* f, QWidget *parent = 0);
    ~EditProgrammDialog();

private:
    Ui::EditProgrammDialog *ui;
    LiteralFactory* factory;

private slots:
    void showAtomContent();
    void updateVariablesList();
    void improvedShow();
    void editVariable();
    void enableApply();

signals:
    void isShown();
};

#endif // EDIT_PROGRAMM_DIALOG_H
