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
    void sendData(QStringList *data);

private slots:
    void TextChanged(QTableWidgetItem *item);

public slots:
    void on_buttonBox_accepted();

private:
    Ui::AddDataDialog *ui;
    QStringList *_indicatorsStringList = new QStringList();
};

#endif // ADDDATADIALOG_H
