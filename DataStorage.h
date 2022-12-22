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

public slots:
    //void ReceiveData(QDate date, double income, double consumption);
private:
    QMap<QDate,FinancialIndicators> *_indicatorsMap;
    //FinancialIndicators _indicator;

};

#endif // DATASTORAGE_H
