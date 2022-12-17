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
    return QDate::currentDate();
}

void DataStorage::SetDate()
{

}

FinancialIndicators DataStorage::SearchIndicators(QDate date)
{
    return _indicatorsMap->value(date);
}

