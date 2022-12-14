#include "Project.h"

Project::Project()
{

}

Project::~Project()
{

}

void Project::AddIndicatorsToMap(FinancialIndicators indicators)
{
    _indicatorsMap->insert(indicators.GetDate(),indicators);
}
