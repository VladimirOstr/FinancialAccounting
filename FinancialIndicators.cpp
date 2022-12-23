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
    //delete this;
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

void FinancialIndicators::SetTotal(double income, double consumption)
{
    _total += income - consumption;
}

double FinancialIndicators::GetIncome()
{
    return _income;
}

double FinancialIndicators::GetConsumption()
{
    return _consumption;
}
