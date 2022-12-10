#ifndef FINANCIALINDICATORS_H
#define FINANCIALINDICATORS_H

#include <QDate>

class FinancialIndicators
{
public:
    FinancialIndicators(QDate date, double income,
                        double consumption, double total);
    FinancialIndicators();
    ~FinancialIndicators();
    void SetIncome(double income);

private:
    QDate _date;
    double _income;
    double _consumption;
    double _total;

};

#endif // FINANCIALINDICATORS_H
