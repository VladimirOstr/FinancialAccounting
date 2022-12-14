#include "FinancialIndicators.h"

FinancialIndicators::FinancialIndicators(QDate date, double income,
                                         double consumption, double total)
{
    date = _date;
    income = _income;
    consumption = _consumption;
    total = _total;
}

FinancialIndicators::FinancialIndicators()
{

}

FinancialIndicators::~FinancialIndicators()
{

}

void FinancialIndicators::SetIncome(double income)
{
    _income = income;
}

void FinancialIndicators::SetDate(QDate date)
{
    _date = date;
}
