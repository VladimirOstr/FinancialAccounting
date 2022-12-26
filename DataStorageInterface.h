#ifndef DATASTORAGEINTERFACE_H
#define DATASTORAGEINTERFACE_H

#include <QTableWidget>
#include <QDate>

class DataStorageInterface
{
public:
    DataStorageInterface();
    virtual void SetIndicator(QDate date, double income, double consumption) = 0;


};

#endif // DATASTORAGEINTERFACE_H
