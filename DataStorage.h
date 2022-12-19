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
    void SetDate() override;
    void AddIndicatorsToMap(FinancialIndicators *indicators);
    FinancialIndicators *SearchIndicators(QDate date);


private:
    QMap<QDate,FinancialIndicators*> *_indicatorsMap;

};

#endif // DATASTORAGE_H
