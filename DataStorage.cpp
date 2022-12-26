#include "DataStorage.h"

DataStorage::DataStorage()
{
    _indicatorsMap = new QMap<QDate,FinancialIndicators*>();
    FinancialIndicators *indicator = new FinancialIndicators();
    _indicatorsMap->insert(indicator->GetDate(),indicator);

}

DataStorage::~DataStorage()
{
    delete _indicatorsMap;
}

void DataStorage::SetIndicator(QDate date, double income, double consumption)
{
    FinancialIndicators *indicator = new FinancialIndicators(date, income, consumption);
    _indicatorsMap->insert(date,indicator);
    /*QMap <QDate,FinancialIndicators>::iterator it = _indicatorsMap->begin();
    double currentTotal = 0;
    for (it; it != _indicatorsMap->end(); it++)
    {
        it.value().SetTotal(currentTotal);
        currentTotal = it.value().GetTotal();
    }*/
    QMap <QDate,FinancialIndicators*>::iterator it = _indicatorsMap->begin();
    double currentTotal = 0;
    for (it; it != _indicatorsMap->find(date); it++)
    {
        currentTotal = it.value()->GetTotal();
    }
    _indicatorsMap->value(date)->SetTotal(currentTotal);
    currentTotal = 0;
    for (it = _indicatorsMap->find(date); it != _indicatorsMap->end()++; it++)
    {
        it.value()->SetTotal(currentTotal);
        currentTotal = it.value()->GetIncome() - it.value()->GetConsumption();
    }
}


double DataStorage::GetIncome(QDate date)
{
    return (_indicatorsMap->contains(date))? _indicatorsMap->value(date)->GetIncome(): 0;
}

double DataStorage::GetConsumption(QDate date)
{
    return (_indicatorsMap->contains(date))? _indicatorsMap->value(date)->GetConsumption(): 0;
}

double DataStorage::GetTotal(QDate date)
{
    return (_indicatorsMap->contains(date))?
                _indicatorsMap->value(date)->GetTotal(): 0;
}

bool DataStorage::Contains(QDate date)
{
    return _indicatorsMap->contains(date);
}
