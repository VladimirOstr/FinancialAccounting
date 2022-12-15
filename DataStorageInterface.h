#ifndef DATASTORAGEINTERFACE_H
#define DATASTORAGEINTERFACE_H

#include <QDate>

class DataStorageInterface
{
public:
    DataStorageInterface();
    virtual void SetData() = 0;
    virtual QDate GetDate() = 0;
};

#endif // DATASTORAGEINTERFACE_H
