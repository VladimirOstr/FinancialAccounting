#ifndef DATASTORAGE_H
#define DATASTORAGE_H

#include <QMap>
#include "FinancialIndicators.h"
#include "DataStorageInterface.h"

class DataStorage:public DataStorageInterface
{
public:
    DataStorage();
    ~DataStorage();
    void AddIndicator(QDate date, double income, double consumption);
    FinancialIndicators *SearchIndicators(QDate date);
    double GetIncome(QDate date);
    double GetConsumption(QDate date);
    double GetTotal(QDate date);


private:
    QMap<QDate,FinancialIndicators> *_indicatorsMap;

};

#endif // DATASTORAGE_H
