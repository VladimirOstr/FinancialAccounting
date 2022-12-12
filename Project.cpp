#include "Project.h"

Project::Project()
{

}

Project::~Project()
{

}

void Project::SetIndicator(QDate date,FinancialIndicators indicator)
{
    _indicators->insert(date,indicator);

}
