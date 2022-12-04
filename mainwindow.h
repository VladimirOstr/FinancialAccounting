#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "AddDataDialog.h"
#include "GuideWindow.h"
#include "AboutWindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addDataAction_triggered();
    void on_guideAction_triggered();
    void on_aboutAction_triggered();

private:
    Ui::MainWindow *ui;
    AddDataDialog *addDataDialog = new AddDataDialog(this);
    GuideWindow *guideWindow = new GuideWindow();
    AboutWindow *aboutWindow = new AboutWindow();
};
#endif // MAINWINDOW_H
