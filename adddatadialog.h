#ifndef ADDDATADIALOG_H
#define ADDDATADIALOG_H

#include <QTableWidget>
#include <QDialog>
#include <QString>

namespace Ui {
class AddDataDialog;
}

class AddDataDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddDataDialog(QWidget *parent = nullptr);
    ~AddDataDialog();

signals:
    void sendData(QTableWidgetItem *data);

private slots:
    void on_ButtonSend();

private:
    Ui::AddDataDialog *ui;
};

#endif // ADDDATADIALOG_H
