#ifndef ADDDATADIALOG_H
#define ADDDATADIALOG_H

#include <QDialog>

namespace Ui {
class AddDataDialog;
}

class AddDataDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddDataDialog(QWidget *parent = nullptr);
    ~AddDataDialog();

private:
    Ui::AddDataDialog *ui;
};

#endif // ADDDATADIALOG_H
