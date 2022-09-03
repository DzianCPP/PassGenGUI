#include "recordcreator.h"

recordcreator::recordcreator()
{

}

void recordcreator::createNewRecord(const QString& login_, const QString& resource_, const QString& password_)
{
    Record* newRecord = new Record(login_, resource_, password_);
    this->recordList_->push_back(*newRecord);
}

bool recordcreator::slt_createNewRecord(const QString &login_, const QString &resource_, const QString &password_)
{
    if (resource_.isEmpty() || login_.isEmpty())
    {
        return false;
    }
    this->createNewRecord(login_, resource_, password_);
    return true;
}
