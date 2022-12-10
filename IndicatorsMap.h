#ifndef INDICATORSMAP_H
#define INDICATORSMAP_H

#include <QMap>
#include "FinancialIndicators.h"

class IndicatorsMap
{
public:
    IndicatorsMap();

private:
    QMap<QDate,FinancialIndicators> _indicators;
};

#endif // INDICATORSMAP_H
