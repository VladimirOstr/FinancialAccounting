#include "FinancialIndicators.h"

FinancialIndicators::FinancialIndicators(QDate date, double income,
                                         double consumption)
{
    _date = date;
    _income = income;
    _consumption = consumption;
    _total = _income - _consumption;
}

FinancialIndicators::FinancialIndicators()
{
    _date = QDate(1970, 1, 1);
    _income = 0;
    _consumption = 0;
    _total = _income - _consumption;
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

void FinancialIndicators::SetIncome(double income)
{
    _income = income;
}

void FinancialIndicators::SetConsumption(double consumption)
{
    _consumption = consumption;
}

double FinancialIndicators::GetTotal()
{
    return _total;
}
