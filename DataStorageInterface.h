#ifndef DATASTORAGEINTERFACE_H
#define DATASTORAGEINTERFACE_H

#include <QTableWidget>
#include <QDate>

class DataStorageInterface
{
public:
    DataStorageInterface();
    virtual void SetDate(QDate date) = 0;
    virtual QDate GetDate() = 0;
    virtual void SetIncome(QDate date, double income) = 0;
    virtual void SetConsumption(QDate date, double consumption) = 0;
    virtual double GetTotal(QDate date) = 0;

public slots:
    void EditStorage();
    void ReceiveData();
};

#endif // DATASTORAGEINTERFACE_H
