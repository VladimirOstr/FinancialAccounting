#include "adddatadialog.h"
#include "ui_adddatadialog.h"

AddDataDialog::AddDataDialog(DataStorage *dataMap, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDataDialog)
{
    ui->setupUi(this);
    ui->dateLineEdit->setPlaceholderText("ДД/ММ/ГГГГ");
    connect(ui->dateLineEdit, SIGNAL(textChanged(QString)),
            this, SLOT(DateEdit(QString)));
    connect(ui->incomeLineEdit, SIGNAL(textChanged(QString)),
            this, SLOT(IncomeEdit(Qstring, DataStorage*)));
    connect(ui->consumptionLineEdit, SIGNAL(textChanged()),
            this, SLOT(IndicatorsEdit(Qstring, DataStorage*)));
    connect(ui->incomeLineEdit, SIGNAL(textChanged(QString)),
            this, SLOT(on_changed()));
    connect(ui->consumptionLineEdit, SIGNAL(textChanged(QString)),
            this, SLOT(on_changed()));
    //if (ui->incomeLineEdit->text() != "" && ui->consumptionLineEdit->text() != "")
    //{
        //ui->totalLineEdit->setText(QString::number(dataMap->GetTotal(currentDate)));
    //}
    //connect();
    connect(ui->buttonBox, SIGNAL(accept()), this, SLOT(on_buttonBox_accepted(DataStorage*)));

}

AddDataDialog::~AddDataDialog()
{
    delete ui;
}

void AddDataDialog::on_buttonBox_accepted(DataStorage *dataMap)
{
    //emit sendData(_stringList);
}

void AddDataDialog::DateEdit(QString string)
{
    try
    {
        currentDate = QDate::fromString(string, "dd, mm, yyyy");
        //dataMap->SetDate(currentDate);
    }
    catch(std::invalid_argument)
    {
        ui->dateLineEdit->setStyleSheet("QLineEdit { background: rgb(0, 255, 255);"
                                        " selection-background-color: rgb(100, 25, 25); }");
    }
}

void AddDataDialog::IncomeEdit(QString string, DataStorage *dataMap)
{
    try
    {
        dataMap->SetIncome(currentDate,string.toDouble());
    }
    catch(std::invalid_argument)
    {
        //ui->dateLineEdit->setStyle();
    }
}

void AddDataDialog::ConsumptionEdit(QString string, DataStorage *dataMap)
{
    try
    {
        dataMap->SetConsumption(currentDate,string.toDouble());
    }
    catch(std::invalid_argument)
    {
        //ui->dateLineEdit->setStyle();
    }
}

void AddDataDialog::on_changed()
{
    double result;
    result = ui->incomeLineEdit->text().toDouble() - ui->consumptionLineEdit->text().toDouble();
    ui->totalLineEdit->setText(QString::number(result));
}
