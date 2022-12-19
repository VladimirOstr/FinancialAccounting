#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(DataStorage *data, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    FillTableWidgets(data);
    ui->tableWidget->setItem(0,0, new QTableWidgetItem(data->GetDate().toString()));

    AddDataDialog *addDataDialog = new AddDataDialog(data);
    addDataDialog->setModal(true);
    _guideWindow = new GuideWindow();
    _guideWindow->setModal(true);
    _aboutWindow = new AboutWindow();
    _aboutWindow->setModal(true);

    connect(ui->addDataAction, SIGNAL(triggered()),
            addDataDialog, SLOT(show()));
    connect(ui->guideAction, SIGNAL(triggered()),
            _guideWindow, SLOT(show()));
    connect(ui->aboutAction, SIGNAL(triggered()),
            _aboutWindow, SLOT(show()));

    connect(addDataDialog, SIGNAL(sendData(QStringList*)),
            this, SLOT(recieveData(QStringList*)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::receiveData(QStringList *data)
{
    for (int i = 0; i < ui->tableWidget->rowCount(); i++)
    {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(data->at(i)));
    }
    //FinancialIndicators indicators = FinancialIndicators::ToFinancialIndicators(data);
    //_indicatorsProject->AddIndicatorsToMap(indicators);
}

void MainWindow::FillTableWidgets(DataStorage* data)
{
    ui->tableWidget->setItem(0,0, new QTableWidgetItem(data->GetDate().toString()));
    ui->tableWidget_2->setItem(0,0, new QTableWidgetItem(data->GetDate().toString()));
    ui->tableWidget_3->setItem(0,0, new QTableWidgetItem(data->GetDate().toString()));
    ui->tableWidget_4->setItem(0,0, new QTableWidgetItem(data->GetDate().toString()));
    ui->tableWidget_5->setItem(0,0, new QTableWidgetItem(data->GetDate().toString()));
    ui->tableWidget_6->setItem(0,0, new QTableWidgetItem(data->GetDate().toString()));
    ui->tableWidget_7->setItem(0,0, new QTableWidgetItem(data->GetDate().toString()));
    ui->tableWidget_8->setItem(0,0, new QTableWidgetItem(data->GetDate().toString()));
    ui->tableWidget_9->setItem(0,0, new QTableWidgetItem(data->GetDate().toString()));
    ui->tableWidget_10->setItem(0,0, new QTableWidgetItem(data->GetDate().toString()));
    ui->tableWidget_11->setItem(0,0, new QTableWidgetItem(data->GetDate().toString()));
    ui->tableWidget_12->setItem(0,0, new QTableWidgetItem(data->GetDate().toString()));
    ui->tableWidget_13->setItem(0,0, new QTableWidgetItem(data->GetDate().toString()));
    ui->tableWidget_14->setItem(0,0, new QTableWidgetItem(data->GetDate().toString()));
    ui->tableWidget_15->setItem(0,0, new QTableWidgetItem(data->GetDate().toString()));
    ui->tableWidget_16->setItem(0,0, new QTableWidgetItem(data->GetDate().toString()));
    ui->tableWidget_17->setItem(0,0, new QTableWidgetItem(data->GetDate().toString()));
    ui->tableWidget_18->setItem(0,0, new QTableWidgetItem(data->GetDate().toString()));
    ui->tableWidget_19->setItem(0,0, new QTableWidgetItem(data->GetDate().toString()));
    ui->tableWidget_20->setItem(0,0, new QTableWidgetItem(data->GetDate().toString()));
    ui->tableWidget_21->setItem(0,0, new QTableWidgetItem(data->GetDate().toString()));
    ui->tableWidget_22->setItem(0,0, new QTableWidgetItem(data->GetDate().toString()));
    ui->tableWidget_23->setItem(0,0, new QTableWidgetItem(data->GetDate().toString()));
    ui->tableWidget_24->setItem(0,0, new QTableWidgetItem(data->GetDate().toString()));
    ui->tableWidget_25->setItem(0,0, new QTableWidgetItem(data->GetDate().toString()));
    ui->tableWidget_26->setItem(0,0, new QTableWidgetItem(data->GetDate().toString()));
    ui->tableWidget_27->setItem(0,0, new QTableWidgetItem(data->GetDate().toString()));
    ui->tableWidget_28->setItem(0,0, new QTableWidgetItem(data->GetDate().toString()));
    ui->tableWidget_29->setItem(0,0, new QTableWidgetItem(data->GetDate().toString()));
    ui->tableWidget_30->setItem(0,0, new QTableWidgetItem(data->GetDate().toString()));
}

