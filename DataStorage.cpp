#include "DataStorage.h"

DataStorage::DataStorage()
{
    _indicatorsMap = new QMap<QDate,FinancialIndicators>();
    FinancialIndicators indicator;
    _indicatorsMap->insert(indicator.GetDate(),indicator);

}

DataStorage::~DataStorage()
{
    delete _indicatorsMap;
}

void DataStorage::AddIndicator(QDate date, double income, double consumption)
{
    FinancialIndicators *indicator = new FinancialIndicators(date, income, consumption);
    _indicatorsMap->insert(date,*indicator);
    QMap <QDate,FinancialIndicators>::iterator it = _indicatorsMap->begin();
    double currentTotal = 0;
    for (it; it != _indicatorsMap->end(); it++)
    {
        it.value().SetTotal(currentTotal);
        currentTotal = it.value().GetTotal();
    }

}

void DataStorage::CalculateTotal()
{
    QMap <QDate,FinancialIndicators>::iterator it = _indicatorsMap->begin();
    double currentTotal = 0;
    /*for (it; it != _indicatorsMap->end(); it++)
    {
        it.value().SetTotal(currentTotal);
        currentTotal = it.value().GetTotal();
    }*/
}

double DataStorage::GetIncome(QDate date)
{
    return (_indicatorsMap->contains(date))? _indicatorsMap->value(date).GetIncome(): 0;
}

double DataStorage::GetConsumption(QDate date)
{
    return (_indicatorsMap->contains(date))? _indicatorsMap->value(date).GetConsumption(): 0;
}

double DataStorage::GetTotal(QDate date)
{
    return (_indicatorsMap->contains(date))?
                _indicatorsMap->value(date).GetTotal(): 0;
}

bool DataStorage::Contains(QDate date)
{
    return _indicatorsMap->contains(date);
}
