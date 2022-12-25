#include "adddatadialog.h"
#include "ui_adddatadialog.h"

AddDataDialog::AddDataDialog(QString date, QString income,
                             QString consumption, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDataDialog)
{
    QRegularExpression digitRegExp;
    digitRegExp.setPattern("^(?:0|[1-9]/d*)(?:[.,]/d+)?$)");
    digitValidator = new QRegularExpressionValidator(digitRegExp);


    ui->setupUi(this);
    ui->dateLineEdit->text() = date;
    ui->incomeLineEdit->text() = income;
    ui->consumptionLineEdit->text() = consumption;
    ui->dateLineEdit->setPlaceholderText("ДД-ММ-ГГГГ");
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
    emit sendData(currentDate, currentIncome, currentConsumption);
}

void AddDataDialog::DateEdit()
{
    try
    {
        currentDate = QDate::fromString(ui->dateLineEdit->text(), "dd-MM-yyyy");
    }
    catch(std::invalid_argument)
    {
        ui->dateLineEdit->setStyleSheet("background-color: red");
    }
}

void AddDataDialog::IncomeEdit()
{
    ui->totalLineEdit->setValidator(digitValidator);
    try
    {
        currentIncome = ui->incomeLineEdit->text().toDouble();
    }
    catch(std::invalid_argument)
    {
        ui->incomeLineEdit->setStyleSheet("background-color: red");
    }
}

void AddDataDialog::ConsumptionEdit()
{
    try
    {
        currentConsumption = ui->consumptionLineEdit->text().toDouble();
    }
    catch(std::invalid_argument)
    {
        ui->consumptionLineEdit->setStyleSheet("background-color: red");
    }

}

void AddDataDialog::on_changed()
{
    double result;
    result = ui->incomeLineEdit->text().toDouble() - ui->consumptionLineEdit->text().toDouble();
    ui->totalLineEdit->setText(QString::number(result));
}
