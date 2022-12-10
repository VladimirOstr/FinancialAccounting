#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _addDataDialog = new AddDataDialog(this);
    _guideWindow = new GuideWindow();
    _aboutWindow = new AboutWindow();
    connect(ui->addDataAction, SIGNAL(triggered()),
            _addDataDialog, SLOT(show()));
    connect(this, SIGNAL(sendData(QTableWidgetItem)),
            _addDataDialog, SLOT(recieveData(QTableWidgetItem)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addDataAction_triggered()
{
    _addDataDialog->show();
}

void MainWindow::on_guideAction_triggered()
{
    _guideWindow->show();
}

void MainWindow::on_aboutAction_triggered()
{
    _aboutWindow->show();
}

void MainWindow::receiveData(QTableWidgetItem data)
{
   _financialIndicators.SetIncome(data.text().toDouble());
}
