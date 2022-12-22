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
    FinancialIndicators indicator(date, income, consumption);
    _indicatorsMap->insert(date,indicator);
    QMap <QDate,FinancialIndicators>::iterator it = _indicatorsMap->begin();
    for (it; it != _indicatorsMap->end(); it++)
    {
        it.value(date).SetTotal(it.value(date.addDays(-1)).GetIncome(),
                                it.value(date.addDays(-1)).GetConsumption());
    }
}

