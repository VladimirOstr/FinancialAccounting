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
    connect(ui->guideAction, SIGNAL(triggered()),
            _guideWindow, SLOT(show()));
    connect(ui->aboutAction, SIGNAL(triggered()),
            _aboutWindow, SLOT(show()));

    connect(_addDataDialog, SIGNAL(sendData(QStringList)),
            this, SLOT(recieveData(QStringList)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::receiveData(QStringList data)
{
    for (int i = 0; i < ui->tableWidget->rowCount(); i++)
    {
        ui->tableWidget->item(i,1)->setText(data.at(i));
    }
}
