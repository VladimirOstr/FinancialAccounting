#ifndef ADDDATADIALOG_H
#define ADDDATADIALOG_H

#include <QTableWidget>
#include <QDialog>
#include <QString>
#include "DataStorage.h"

namespace Ui {
class AddDataDialog;
}

class AddDataDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddDataDialog(DataStorage *dataMap, QWidget *parent = nullptr);
    ~AddDataDialog();

signals:
    void sendData(QStringList *data);

private slots:
    void DataEdit(DataStorage *dataMap, QString string);

public slots:
    void on_buttonBox_accepted(DataStorage *dataMap);

private:
    Ui::AddDataDialog *ui;
    QStringList *_stringList = new QStringList();
};

#endif // ADDDATADIALOG_H
