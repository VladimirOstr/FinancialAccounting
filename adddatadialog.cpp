#include "adddatadialog.h"
#include "ui_adddatadialog.h"

AddDataDialog::AddDataDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDataDialog)
{
    ui->setupUi(this);
    connect(ui->buttonBox, SIGNAL(clicked()), this, SLOT(onButtonSend()));
}

AddDataDialog::~AddDataDialog()
{
    delete ui;
}

void AddDataDialog::on_ButtonSend()
{
    //QTableWidgetItem *tmp[ui->addDataTableWidget->rowCount()];
    //for (int i = 0; i <
      //   ui->addDataTableWidget->rowCount(); i++)
        //tmp[i] = ui->addDataTableWidget->item(i,1);
    emit sendData(ui->addDataTableWidget->item(0,1));
}
