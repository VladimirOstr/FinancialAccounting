#ifndef DATASTORAGEINTERFACE_H
#define DATASTORAGEINTERFACE_H

#include <QTableWidget>
#include <QDate>
#include "FinancialIndicators.h"

class DataStorageInterface
{
public:
    DataStorageInterface();


public slots:
    //void EditStorage();
    //void ReceiveData();

signals:
    void SetIncome(QDate date, double income);

};

#endif // DATASTORAGEINTERFACE_H
