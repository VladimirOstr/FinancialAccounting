#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "AddDataDialog.h"
#include "GuideWindow.h"
#include "AboutWindow.h"
#include "Project.h"

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
    void receiveData(QStringList *data);

private:
    Ui::MainWindow *ui;
    AddDataDialog *_addDataDialog;
    GuideWindow *_guideWindow;
    AboutWindow *_aboutWindow;
    Project *_indicatorsProject;
};
#endif // MAINWINDOW_H
