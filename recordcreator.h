#ifndef RECORDCREATOR_H
#define RECORDCREATOR_H

#include <QObject>
#include <QList>
#include "record.h"
#include "data.h"

class recordcreator : public QObject
{
    Q_OBJECT
public:
    recordcreator();

    void createNewRecord(const QString& login_, const QString& resource_, const QString& password_);

public slots:
    bool slt_createNewRecord(const QString& login_, const QString& resource_, const QString& password_);

private:
    QList<Record>* recordList_ = _recordList;
};

#endif // RECORDCREATOR_H
