#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(DataStorage *data, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //InitializeTableWidgets();
    QMenu *monthMenu = new QMenu("Месяц");
    monthMenu->addAction(months[0]);
    monthMenu->addAction(months[1]);
    monthMenu->addAction(months[2]);
    monthMenu->addAction(months[3]);
    monthMenu->addAction(months[4]);
    monthMenu->addAction(months[5]);
    monthMenu->addAction(months[6]);
    monthMenu->addAction(months[7]);
    monthMenu->addAction(months[8]);
    monthMenu->addAction(months[9]);
    monthMenu->addAction(months[10]);
    monthMenu->addAction(months[11]);
    ui->toolButton->setMenu(monthMenu);
    connect(ui->toolButton, SIGNAL(triggered()), monthMenu, SLOT(show()));
    connect(monthMenu, SIGNAL(triggered(QAction*)), this, SLOT(SelectMonth(QAction*)));

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

void MainWindow::SelectMonth(QAction *action)
{
    switch(months.indexOf(action->text()))
    {
        case 0:
            ui->tableWidget->setItem(0,0, new QTableWidgetItem(action->text()));

        break;

        case 1:
            ui->tableWidget->setItem(0,0, new QTableWidgetItem(action->text()));

        break;

        case 2:

        break;

        case 3:

        break;

        case 4:

        break;

        case 5:

        break;

        case 6:

        break;

        case 7:

        break;

        case 8:

        break;

        case 9:

        break;

        case 10:

        break;

        case 11:

        break;
    }
}

