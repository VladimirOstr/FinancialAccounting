#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(DataStorage *data, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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



