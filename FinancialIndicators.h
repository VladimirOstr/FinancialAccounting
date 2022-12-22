#ifndef FINANCIALINDICATORS_H
#define FINANCIALINDICATORS_H

#include <QDate>

class FinancialIndicators
{
public:
    FinancialIndicators(QDate date, double income,
                        double consumption);
    FinancialIndicators();
    ~FinancialIndicators();
    void SetIncome(double income);
    void SetConsumption(double consumption);
    void SetTotal(double income, double consumption);
    QDate GetDate();
    double GetIncome();
    double GetConsumption();
    double GetTotal();

private:
    QDate _date;
    double _income = 0;
    double _consumption = 0;
    double _total = 0;

};

#endif // FINANCIALINDICATORS_H
