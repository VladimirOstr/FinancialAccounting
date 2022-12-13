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
    void sendData(QStringList data);

private slots:
    void TableChanged(QStringList data);

public slots:
    void on_buttonBox_accepted();

private:
    Ui::AddDataDialog *ui;
    QStringList data;
};

#endif // ADDDATADIALOG_H
