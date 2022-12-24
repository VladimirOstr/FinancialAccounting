#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(DataStorage *data, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tableWidgets->append(ui->tableWidget);
    tableWidgets->append(ui->tableWidget_2);
    tableWidgets->append(ui->tableWidget_3);
    tableWidgets->append(ui->tableWidget_4);
    tableWidgets->append(ui->tableWidget_5);
    tableWidgets->append(ui->tableWidget_6);
    tableWidgets->append(ui->tableWidget_7);
    tableWidgets->append(ui->tableWidget_8);
    tableWidgets->append(ui->tableWidget_9);
    tableWidgets->append(ui->tableWidget_10);
    tableWidgets->append(ui->tableWidget_11);
    tableWidgets->append(ui->tableWidget_12);
    tableWidgets->append(ui->tableWidget_13);
    tableWidgets->append(ui->tableWidget_14);
    tableWidgets->append(ui->tableWidget_15);
    tableWidgets->append(ui->tableWidget_16);
    tableWidgets->append(ui->tableWidget_17);
    tableWidgets->append(ui->tableWidget_18);
    tableWidgets->append(ui->tableWidget_19);
    tableWidgets->append(ui->tableWidget_20);
    tableWidgets->append(ui->tableWidget_21);
    tableWidgets->append(ui->tableWidget_22);
    tableWidgets->append(ui->tableWidget_23);
    tableWidgets->append(ui->tableWidget_24);
    tableWidgets->append(ui->tableWidget_25);
    tableWidgets->append(ui->tableWidget_26);
    tableWidgets->append(ui->tableWidget_27);
    tableWidgets->append(ui->tableWidget_28);
    tableWidgets->append(ui->tableWidget_29);
    tableWidgets->append(ui->tableWidget_30);
    tableWidgets->append(ui->tableWidget_31);
    baseDate.setDate(2022,1,1);
    FillTableWidgets(data);

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
    connect(ui->toolButton, &QToolButton::triggered, monthMenu, &QMenu::show);
    connect(monthMenu, &QMenu::triggered, this, [this, &data]
            (QAction *action)
            {SelectMonth(action,data);});

    AddDataDialog *addDataDialog = new AddDataDialog(data);
    //addDataDialog->setModal(true);
    _guideWindow = new GuideWindow();
    _guideWindow->setModal(true);
    _aboutWindow = new AboutWindow();
    _aboutWindow->setModal(true);

    connect(ui->addDataAction, SIGNAL(triggered()),
            addDataDialog, SLOT(exec()));
    connect(ui->tableWidget, SIGNAL(cellDoubleClicked(int,int)),
            addDataDialog, SLOT(exec()));
    connect(ui->guideAction, SIGNAL(triggered()),
            _guideWindow, SLOT(show()));
    connect(ui->aboutAction, SIGNAL(triggered()),
            _aboutWindow, SLOT(show()));

    connect(addDataDialog, &AddDataDialog::sendData,
            this, [this, &data]
            (QDate date, double income, double consumption)
            {ReceiveData(date,income,consumption,data);});


    //connect(addDataDialog, SIGNAL(sendData(QStringList*)),
            //this, SLOT(recieveData(QStringList*)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::SelectMonth(QAction *action, DataStorage* data)
{
    switch(months.indexOf(action->text()))
    {
        case 0:
        {
            baseDate.setDate(2022,1,1);
            FillTableWidgets(data);

            break;
        }

        case 1:
        {
            baseDate.setDate(2022,2,1);
            FillTableWidgets(data);
            break;
        }

        case 2:
        {
            baseDate.setDate(2022,3,1);
            FillTableWidgets(data);
            break;
        }

        case 3:
        {
            baseDate.setDate(2022,4,1);
            FillTableWidgets(data);
            break;
        }

        case 4:
        {
            baseDate.setDate(2022,5,1);
            FillTableWidgets(data);
            break;
        }

        case 5:
        {
            baseDate.setDate(2022,6,1);
            FillTableWidgets(data);
            break;
        }

        case 6:
        {
            baseDate.setDate(2022,7,1);
            FillTableWidgets(data);
            break;
        }

        case 7:
        {
            baseDate.setDate(2022,8,1);
            FillTableWidgets(data);
            break;
        }

        case 8:
        {
            baseDate.setDate(2022,9,1);
            FillTableWidgets(data);
            break;
        }

        case 9:
        {
            baseDate.setDate(2022,10,1);
            FillTableWidgets(data);
            break;
        }

        case 10:
        {
            baseDate.setDate(2022,11,1);
            FillTableWidgets(data);
            break;
        }

        case 11:
        {
            baseDate.setDate(2022,12,1);
            FillTableWidgets(data);
            break;
        }
    }
}

void MainWindow::FillTableWidgets(DataStorage *data)
{
    for (int i = 0; i < tableWidgets->count(); i++)
    {
        tableWidgets->at(i)->setItem(0,0, new QTableWidgetItem(baseDate.addDays(i).toString()));


        /*if(tableWidgets->at(i)->item(0,0)->text() == date.toString())
        {
            tableWidgets->at(i)->setItem(0,1, new QTableWidgetItem(QString::number(data->GetIncome(date))));
            tableWidgets->at(i)->setItem(0,2, new QTableWidgetItem(QString::number(data->GetConsumption(date))));
            tableWidgets->at(i)->setItem(0,3, new QTableWidgetItem(QString::number(data->GetTotal(date))));
            for (int j = i; j < tableWidgets->count(); j++)
            {
                tableWidgets->at(j)->setItem(0,3, new QTableWidgetItem(QString::number(data->GetTotal(date))));
            }
        }*/
        if (data->Contains(QDate::fromString(tableWidgets->at(i)->item(0,0)->text())))
        {
            QDate tableDate = QDate::fromString(tableWidgets->at(i)->item(0,0)->text());
            tableWidgets->at(i)->setItem(0,1, new QTableWidgetItem(QString::number(data->GetIncome(tableDate))));
            tableWidgets->at(i)->setItem(0,2, new QTableWidgetItem(QString::number(data->GetConsumption(tableDate))));
            tableWidgets->at(i)->setItem(0,3, new QTableWidgetItem(QString::number(data->GetTotal(tableDate))));
            for (int j = i; j < tableWidgets->count(); j++)
            {
                tableWidgets->at(j)->setItem(0,3, new QTableWidgetItem(QString::number(data->GetTotal(tableDate))));
            }
        }
    }

}

void MainWindow::ReceiveData(QDate date, double income, double consumption, DataStorage* data)
{
    data->AddIndicator(date,income,consumption);
    FillTableWidgets(data);
}
