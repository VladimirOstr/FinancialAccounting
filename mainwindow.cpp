#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addDataAction_triggered()
{
    addDataDialog->show();
}

void MainWindow::on_guideAction_triggered()
{
    guideWindow->show();
}

void MainWindow::on_aboutAction_triggered()
{
    aboutWindow->show();
}
