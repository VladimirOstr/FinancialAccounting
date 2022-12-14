#include "FinancialIndicators.h"

FinancialIndicators::FinancialIndicators(QDate date, double income,
                                         double consumption)
{
    date = _date;
    income = _income;
    consumption = _consumption;
    _total = _income - _consumption;
}

FinancialIndicators::FinancialIndicators()
{

}

FinancialIndicators::~FinancialIndicators()
{

}

FinancialIndicators ToFinancialIndicators(QStringList *indicatorsStringList)
{
    QDate date = QDate::fromString(indicatorsStringList->at(0), "dd/mm/yyyy");
    double income = indicatorsStringList->at(1).toDouble();
    double consumption = indicatorsStringList->at(2).toDouble();
    FinancialIndicators *indicators = new FinancialIndicators(date,income,consumption);
    return *indicators;
}

QDate FinancialIndicators::GetDate()
{
    return _date;
}
