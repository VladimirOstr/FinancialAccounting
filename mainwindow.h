#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "AddDataDialog.h"
#include "GuideWindow.h"
#include "AboutWindow.h"
#include "FinancialIndicators.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void receiveData(QTableWidgetItem data);

private slots:
    void on_addDataAction_triggered();
    void on_guideAction_triggered();
    void on_aboutAction_triggered();

private:
    Ui::MainWindow *ui;
    AddDataDialog *_addDataDialog;
    GuideWindow *_guideWindow;
    AboutWindow *_aboutWindow;
    FinancialIndicators _financialIndicators;
};
#endif // MAINWINDOW_H
