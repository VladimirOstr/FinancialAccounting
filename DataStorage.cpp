#include "DataStorage.h"

DataStorage::DataStorage()
{
    _indicatorsMap = new QMap<QDate,FinancialIndicators*>();
    QDate date(2022,1,1);
    for (int i = 0; i < 365; i++)
    {
        _indicatorsMap->insert(date.addDays(i),new FinancialIndicators());

    }
}

DataStorage::~DataStorage()
{
    delete _indicatorsMap;
}

void DataStorage::AddIndicatorsToMap(FinancialIndicators *indicators)
{
    _indicatorsMap->insert(indicators->GetDate(),indicators);
}

QDate DataStorage::GetDate()
{
    return _indicatorsMap->firstKey();
}

void DataStorage::SetDate()
{

}

FinancialIndicators* DataStorage::SearchIndicators(QDate date)
{
    return _indicatorsMap->value(date);
}

