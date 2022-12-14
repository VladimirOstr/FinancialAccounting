#ifndef PROJECT_H
#define PROJECT_H

#include <QMap>
#include "FinancialIndicators.h"

class Project
{
public:
    Project();
    ~Project();
    void AddIndicatorsToMap(FinancialIndicators indicators);


private:
    QMap<QDate,FinancialIndicators> *_indicatorsMap = new QMap<QDate,FinancialIndicators>();

};

#endif // PROJECT_H
