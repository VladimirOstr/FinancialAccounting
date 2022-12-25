#ifndef ADDDATADIALOG_H
#define ADDDATADIALOG_H

#include <QTableWidget>
#include <QDialog>
#include <QString>
#include <QValidator>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include "DataStorage.h"

namespace Ui {
class AddDataDialog;
}

class AddDataDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddDataDialog(QString date, QString income,
                           QString consumption, QWidget *parent = nullptr);
    ~AddDataDialog();

signals:
    void sendData(QDate currentDate, double currentIncome, double currentConsumption);

private slots:
    void DateEdit();
    void IncomeEdit();
    void ConsumptionEdit();

public slots:
    void on_buttonBox_accepted();
    void on_changed();

private:
    Ui::AddDataDialog *ui;
    QDate currentDate;
    double currentIncome;
    double currentConsumption;
    QValidator *digitValidator;
};

#endif // ADDDATADIALOG_H
