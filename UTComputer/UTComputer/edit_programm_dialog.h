#ifndef EDIT_PROGRAMM_DIALOG_H
#define EDIT_PROGRAMM_DIALOG_H

#include <QDialog>

namespace Ui {
class EditProgrammDialog;
}

class EditProgrammDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditProgrammDialog(QWidget *parent = 0);
    ~EditProgrammDialog();

private:
    Ui::EditProgrammDialog *ui;
};

#endif // EDIT_PROGRAMM_DIALOG_H
