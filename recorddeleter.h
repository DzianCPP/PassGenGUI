#ifndef RECORDDELETER_H
#define RECORDDELETER_H

#include <QObject>
#include <QDebug>
#include "data.h"

class RecordDeleter : public QObject
{
    Q_OBJECT
public:
    explicit RecordDeleter(QObject *parent = nullptr);

signals:
    void sgn_deleteRecordResults();
public slots:
    void slt_deleteRecord(QList<Record>::iterator toDelete, QString& message_);

private:
    bool deleteRecord(QList<Record>::iterator& toDelete, QString &message_);

};

#endif // RECORDDELETER_H
