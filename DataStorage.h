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
    QDate GetDate() override;
    void SetDate(QDate date) override;
    void SetIncome(QDate date, double income) override;
    void SetConsumption(QDate date, double consumption) override;
    double GetTotal(QDate date) override;
    void AddIndicatorsToMap(FinancialIndicators *indicators);
    FinancialIndicators *SearchIndicators(QDate date);


private:
    QMap<QDate,FinancialIndicators> *_indicatorsMap;
    FinancialIndicators indicator;

};

#endif // DATASTORAGE_H
