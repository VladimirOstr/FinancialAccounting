#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _addDataDialog = new AddDataDialog(this);
    _addDataDialog->setModal(true);
    _guideWindow = new GuideWindow();
    _aboutWindow = new AboutWindow();

    connect(ui->addDataAction, SIGNAL(triggered()),
            _addDataDialog, SLOT(show()));
    connect(_addDataDialog, SIGNAL(sendData(QString)),
            this, SLOT(recieveData(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::receiveData(QString data)
{
    //QDate date(2022,12,10);
    //FinancialIndicators financialIndicators(date,data.toDouble(),22,15);
    //_indicators.SetIndicator(date,financialIndicators);
    ui->tableWidget->item(0,1)->text() = data;
}
