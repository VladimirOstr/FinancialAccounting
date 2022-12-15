#include "DataStorage.h"

DataStorage::DataStorage()
{
    _indicatorsMap = new QMap<QDate,FinancialIndicators>;
}

DataStorage::~DataStorage()
{

}

void DataStorage::AddIndicatorsToMap(FinancialIndicators indicators)
{
    _indicatorsMap->insert(indicators.GetDate(),indicators);
}

QDate DataStorage::GetDate()
{

}
