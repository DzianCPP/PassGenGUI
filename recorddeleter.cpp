#include "recorddeleter.h"

RecordDeleter::RecordDeleter(QObject *parent)
    : QObject{parent}
{

}

void RecordDeleter::slt_deleteRecord(QList<Record>::iterator toDelete, QString& message_)
{
    this->deleteRecord(toDelete, message_);
    emit sgn_deleteRecordResults();
}

bool RecordDeleter::deleteRecord(QList<Record>::iterator& toDelete, QString& message_)
{
    if (_recordList->isEmpty())
    {
        message_ = "Error! No records were made yet";
        return false;
    }

    if (toDelete == _recordList->end())
    {
        message_ = "Error! Couldn't delete the record";
        return false;
    }

    _recordList->erase(toDelete, toDelete+1);
    message_ = "Successfully deleted";
    for (auto it : *_recordList)
    {
        qInfo() << it.resource << "\n";
    }
    return true;
}
