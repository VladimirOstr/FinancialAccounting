#ifndef PROJECT_H
#define PROJECT_H

#include <QMap>
#include "FinancialIndicators.h"

class Project
{
public:
    Project();
    ~Project();
    void SetIndicator(QDate date,FinancialIndicators indicator);


private:
    QMap<QDate,FinancialIndicators> *_indicators = new QMap<QDate,FinancialIndicators>();

};

#endif // PROJECT_H
