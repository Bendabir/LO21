#ifndef EDIT_ATOM_DIALOG_H
#define EDIT_ATOM_DIALOG_H

#include <QDialog>

class LiteralFactory;

namespace Ui {
class EditAtomDialog;
}

class EditAtomDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditAtomDialog(LiteralFactory* f, QWidget *parent = 0);
    ~EditAtomDialog();

private:
    Ui::EditAtomDialog *ui;
    LiteralFactory* factory;

private slots:
    void showAtomContent();
};

#endif // EDIT_ATOM_DIALOG_H
