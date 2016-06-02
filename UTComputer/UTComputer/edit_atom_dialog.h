#ifndef EDIT_ATOM_DIALOG_H
#define EDIT_ATOM_DIALOG_H

#include <QDialog>

namespace Ui {
class EditAtomDialog;
}

class EditAtomDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditAtomDialog(QWidget *parent = 0);
    ~EditAtomDialog();

private:
    Ui::EditAtomDialog *ui;
};

#endif // EDIT_ATOM_DIALOG_H
