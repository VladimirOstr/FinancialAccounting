#include "adddatadialog.h"
#include "ui_adddatadialog.h"

AddDataDialog::AddDataDialog(DataStorage *dataMap, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDataDialog)
{
    ui->setupUi(this);

    connect(ui->dateLineEdit, SIGNAL(textEdited()),
            dataMap, SLOT(DataEdit(Qstring)));
    connect(ui->incomeLineEdit, SIGNAL(textEdited()),
            this, SLOT(DataEdit(Qstring)));
    connect(ui->consumptionLineEdit, SIGNAL(textEdited()),
            this, SLOT(DataEdit(Qstring)));
    connect(ui->buttonBox, SIGNAL(accept()), this, SLOT(on_buttonBox_accepted()));

}

AddDataDialog::~AddDataDialog()
{
    delete ui;
}

void AddDataDialog::on_buttonBox_accepted()
{
    emit sendData(_stringList);
}

void AddDataDialog::DataEdit(QString string)
{
    _stringList->append(string);
}



