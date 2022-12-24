#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "AddDataDialog.h"
#include "GuideWindow.h"
#include "AboutWindow.h"
#include "DataStorage.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(DataStorage *data, QWidget *parent = nullptr);
    ~MainWindow();
    void InitializeTableWidgets();

public slots:
    void SelectMonth(QAction *action, DataStorage *data);
    void FillTableWidgets(DataStorage *data);
    void ReceiveData(QDate date, double income, double consumption, DataStorage *data);

private:
    Ui::MainWindow *ui;
    GuideWindow *_guideWindow;
    AboutWindow *_aboutWindow;
    QStringList months{"Январь",
                "Февраль",
                "Март",
                "Апрель",
                "Май",
                "Июнь",
                "Июль",
                "Август",
                "Сентябрь",
                "Октябрь",
                "Ноябрь",
                "Декабрь"};
    QList <QTableWidget*> *tableWidgets = new QList<QTableWidget*>();
    QDate baseDate;
};
#endif // MAINWINDOW_H
