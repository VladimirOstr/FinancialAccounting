#ifndef PROJECT_H
#define PROJECT_H

#include <QMap>
#include "FinancialIndicators.h"
#include "DataStorageInterface.h"

class DataStorage:public DataStorageInterface
{
public:
    DataStorage();
    ~DataStorage();
    QDate GetDate() override;
    void AddIndicatorsToMap(FinancialIndicators indicators);


private:
    QMap<QDate,FinancialIndicators> *_indicatorsMap;

};

#endif // PROJECT_H
