#include "GuideWindow.h"
#include "ui_GuideWindow.h"

GuideWindow::GuideWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GuideWindow)
{
    ui->setupUi(this);
}

GuideWindow::~GuideWindow()
{
    delete ui;
}
