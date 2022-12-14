#include "adddatadialog.h"
#include "ui_adddatadialog.h"

AddDataDialog::AddDataDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDataDialog)
{
    ui->setupUi(this);
    connect(ui->addDataTableWidget, SIGNAL(itemChanged(QTableWidgetItem*)),
            this, SLOT(TextChanged(QTableWidgetItem*)));
    connect(ui->buttonBox, SIGNAL(accept()), this, SLOT(on_buttonBox_accepted()));

}

AddDataDialog::~AddDataDialog()
{
    delete ui;
}

void AddDataDialog::on_buttonBox_accepted()
{
    for (int i = 0; i < ui->addDataTableWidget->rowCount();i++)
    {
        ui->addDataTableWidget->setItem(i,0, new QTableWidgetItem(""));
    }
    emit sendData(_indicatorsStringList);
}

void AddDataDialog::TextChanged(QTableWidgetItem* item)
{
    if (item != NULL)
    {
        _indicatorsStringList->append(item->text());
    }
}



