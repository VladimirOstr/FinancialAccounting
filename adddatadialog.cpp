#include "adddatadialog.h"
#include "ui_adddatadialog.h"

AddDataDialog::AddDataDialog(DataStorage *dataMap, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDataDialog)
{

    ui->setupUi(this);
    ui->dateLineEdit->setPlaceholderText("ДД/ММ/ГГГГ");
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

    //connect(ui->buttonBox, SIGNAL(accept()), this, SLOT(on_buttonBox_accepted(DataStorage*)));
    //[this, &dataMap](){DateEdit(dataMap);}
}

AddDataDialog::~AddDataDialog()
{
    delete ui;
}

void AddDataDialog::on_buttonBox_accepted()
{
    //emit sendData(_stringList);
    emit sendData(currentDate, currentIncome, currentConsumption);
}

void AddDataDialog::DateEdit()
{
    try
    {
        currentDate = QDate::fromString(ui->dateLineEdit->text(), "dd-MM-yyyy");
        //dataMap->SetDate(currentDate);
    }
    catch(std::invalid_argument)
    {
        ui->dateLineEdit->setStyleSheet("background-color: red");
    }
}

void AddDataDialog::IncomeEdit()
{

    try
    {
        currentIncome = ui->incomeLineEdit->text().toDouble();
        //dataMap->SetIncome(currentDate,ui->incomeLineEdit->text().toDouble());
        //emit dataMap->SetIncome(currentDate, ui->incomeLineEdit->text().toDouble());
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
        //dataMap->SetIncome(currentDate,ui->incomeLineEdit->text().toDouble());
        //emit dataMap->SetIncome(currentDate, ui->incomeLineEdit->text().toDouble());
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
