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
    void SetIndicator(QDate date, double income, double consumption) override;
    double GetIncome(QDate date);
    double GetConsumption(QDate date);
    double GetTotal(QDate date);
    bool Contains(QDate date);

private:
    QMap<QDate,FinancialIndicators*> *_indicatorsMap;

};

#endif // DATASTORAGE_H
