#include "DataStorage.h"

DataStorage::DataStorage()
{
    _indicatorsMap = new QMap<QDate,FinancialIndicators>();

}

DataStorage::~DataStorage()
{
    delete _indicatorsMap;
}

void DataStorage::AddIndicator(QDate date, double income, double consumption)
{
    FinancialIndicators *indicator = new FinancialIndicators(date, income, consumption);
    _indicatorsMap->insert(date,*indicator);
    QMap <QDate,FinancialIndicators>::iterator it = _indicatorsMap->find(date);
    if (_indicatorsMap->contains(date.addDays(-1)))
    {
        QMap <QDate,FinancialIndicators>::iterator itPrev = _indicatorsMap->find(date.addDays(-1));
        for (it; it != _indicatorsMap->end(); it++)
        {
            it.value().SetTotal(itPrev->GetIncome(),
                                    itPrev->GetConsumption());
            itPrev++;
        }
    }

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
    return (_indicatorsMap->contains(date))? _indicatorsMap->value(date).GetTotal(): 0;
}
