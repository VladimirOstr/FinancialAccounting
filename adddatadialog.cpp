#include "adddatadialog.h"
#include "ui_adddatadialog.h"

AddDataDialog::AddDataDialog(DataStorage *dataMap, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDataDialog)
{
    ui->setupUi(this);

    connect(ui->dateLineEdit, SIGNAL(textEdited()),
            this, SLOT(DateEdit(DataStorage*,QString)));
    connect(ui->incomeLineEdit, SIGNAL(textEdited()),
            this, SLOT(DataEdit(Qstring)));
    connect(ui->consumptionLineEdit, SIGNAL(textEdited()),
            this, SLOT(DataEdit(Qstring)));
    connect(ui->buttonBox, SIGNAL(accept()), this, SLOT(on_buttonBox_accepted(DataStorage*)));

}

AddDataDialog::~AddDataDialog()
{
    delete ui;
}

void AddDataDialog::on_buttonBox_accepted(DataStorage *dataMap)
{

    emit sendData(_stringList);
}

void AddDataDialog::DataEdit(DataStorage *dataMap, QString string)
{
    QDate date = QDate::fromString(string, "dd, mm, yyyy");
    FinancialIndicators data = *dataMap->SearchIndicators(date);
    if(data.GetDate() == QDate(1970, 1, 1))
    {
        _stringList->append(string);
        return;
    }
    _stringList->append(string);
}



