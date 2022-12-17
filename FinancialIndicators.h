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
    static FinancialIndicators ToFinancialIndicators(QStringList *indicatorsStringList);
    QDate GetDate();

private:
    QDate _date;
    double _income = 0;
    double _consumption = 0;
    double _total;

};

#endif // FINANCIALINDICATORS_H
