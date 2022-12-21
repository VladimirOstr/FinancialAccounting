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
    void DateEdit(QString string);
    void IncomeEdit(QString string,DataStorage *dataMap);
    void ConsumptionEdit(QString string, DataStorage *dataMap);

public slots:
    void on_buttonBox_accepted(DataStorage *dataMap);
    void on_changed();

private:
    Ui::AddDataDialog *ui;
    QDate currentDate;
    QColor errorColor = QColor("Red");
};

#endif // ADDDATADIALOG_H
