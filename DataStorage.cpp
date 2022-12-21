#include "DataStorage.h"

DataStorage::DataStorage()
{
    _indicatorsMap = new QMap<QDate,FinancialIndicators>();
    //QDate date(2022,1,1);
    //for (int i = 0; i < 365; i++)
    //{
       // _indicatorsMap->insert(date.addDays(i),new FinancialIndicators());

    //}
}

DataStorage::~DataStorage()
{
    delete _indicatorsMap;
}


QDate DataStorage::GetDate()
{
    return _indicatorsMap->firstKey();
}

void DataStorage::SetDate(QDate date)
{
    _indicatorsMap->insert(date,FinancialIndicators());
}

void DataStorage::SetIncome(QDate date, double income)
{
    indicator.SetIncome(income);
    _indicatorsMap->insert(date,indicator);
}

void DataStorage::SetConsumption(QDate date, double consumption)
{
    indicator.SetConsumption(consumption);
    _indicatorsMap->insert(date,indicator);
}

double DataStorage::GetTotal(QDate date)
{
    return _indicatorsMap->value(date).GetTotal();
}
