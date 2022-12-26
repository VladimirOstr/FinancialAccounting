#include "adddatadialog.h"
#include "ui_adddatadialog.h"

AddDataDialog::AddDataDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDataDialog)
{

    ui->setupUi(this);
    ui->dateLineEdit->setPlaceholderText("ДД-ММ-ГГГГ");
    ui->incomeLineEdit->setPlaceholderText("Только цифры. Разделять точкой");
    ui->consumptionLineEdit->setPlaceholderText("Только цифры. Разделять точкой");
    ui->totalLineEdit->setPlaceholderText("Итог. Только для чтения");
    connect(ui->dateLineEdit, &QLineEdit::editingFinished,
            this, &AddDataDialog::DateEdit);
    connect(ui->incomeLineEdit, &QLineEdit::editingFinished,
            this,&AddDataDialog::IncomeEdit);
    connect(ui->consumptionLineEdit, &QLineEdit::editingFinished,
            this, &AddDataDialog::ConsumptionEdit);
    connect(ui->incomeLineEdit, &QLineEdit::textChanged,
            this, &AddDataDialog::on_changed);
    connect(ui->consumptionLineEdit, &QLineEdit::textChanged,
            this, &AddDataDialog::on_changed);

}

AddDataDialog::~AddDataDialog()
{
    delete ui;
}

void AddDataDialog::on_buttonBox_accepted()
{
    ui->dateLineEdit->clear();
    ui->incomeLineEdit->clear();
    ui->consumptionLineEdit->clear();
    ui->totalLineEdit->clear();
    emit sendData(_currentDate, _currentIncome, _currentConsumption);
}

void AddDataDialog::on_buttonBox_rejected()
{
    ui->dateLineEdit->clear();
    ui->dateLineEdit->setStyleSheet("background-color: white");
    ui->incomeLineEdit->clear();
    ui->incomeLineEdit->setStyleSheet("background-color: white");
    ui->consumptionLineEdit->clear();
    ui->consumptionLineEdit->setStyleSheet("background-color: white");
    ui->totalLineEdit->clear();
}

void AddDataDialog::DateEdit()
{
    if (QDate::fromString(ui->dateLineEdit->text(), "dd-MM-yyyy").isValid())
    {
        _currentDate = QDate::fromString(ui->dateLineEdit->text(), "dd-MM-yyyy");
        ui->dateLineEdit->setStyleSheet("background-color: white");
        ui->buttonBox->setDisabled(false);
        return;
    }
    ui->dateLineEdit->setStyleSheet("background-color: rgb(255,64,64)");
    ui->buttonBox->setDisabled(true);
}

void AddDataDialog::IncomeEdit()
{
    QString string = ui->incomeLineEdit->text();
    if (string.contains(QRegularExpression("^\\d+|\\w(.)\\d+$")))
    {
        _currentIncome = ui->incomeLineEdit->text().toDouble();
        ui->incomeLineEdit->setStyleSheet("background-color: white");
        ui->buttonBox->setDisabled(false);
        return;
    }
    ui->incomeLineEdit->setStyleSheet("background-color: rgb(255,64,64)");
    ui->buttonBox->setDisabled(true);
}

void AddDataDialog::ConsumptionEdit()
{
    QString string = ui->consumptionLineEdit->text();
    if (string.contains(QRegularExpression("^\\d+|\\w(.)\\d+$")))
    {
        _currentConsumption = ui->consumptionLineEdit->text().toDouble();
        ui->consumptionLineEdit->setStyleSheet("background-color: white");
        ui->buttonBox->setDisabled(false);
        return;
    }
    ui->consumptionLineEdit->setStyleSheet("background-color: rgb(255,64,64)");
    ui->buttonBox->setDisabled(true);
}

void AddDataDialog::on_changed()
{
    double result;
    result = ui->incomeLineEdit->text().toDouble() - ui->consumptionLineEdit->text().toDouble();
    ui->totalLineEdit->setText(QString::number(result));
}
