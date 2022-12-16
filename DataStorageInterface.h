#ifndef DATASTORAGEINTERFACE_H
#define DATASTORAGEINTERFACE_H

#include <QTableWidget>
#include <QDate>

class DataStorageInterface
{
public:
    DataStorageInterface();
    virtual void SetDate() = 0;
    virtual QDate GetDate() = 0;

public slots:
    void EditStorage();
    void ReceiveData();
};

#endif // DATASTORAGEINTERFACE_H
