#include "adddatadialog.h"
#include "ui_adddatadialog.h"

AddDataDialog::AddDataDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDataDialog)
{
    ui->setupUi(this);
    connect(ui->buttonBox, SIGNAL(accept()), this, SLOT(on_buttonBox_accepted()));
}

AddDataDialog::~AddDataDialog()
{
    delete ui;
}

void AddDataDialog::on_buttonBox_accepted()
{
    QStringList data;

    for (int i = 0; i < ui->addDataTableWidget->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->addDataTableWidget->item(i,1);
        if (item != NULL)
            data.append(ui->addDataTableWidget->item(i,1)->text());
        delete item;
    }
    emit sendData(data);
}
