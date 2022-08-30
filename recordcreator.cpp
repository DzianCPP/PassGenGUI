#include "recordcreator.h"

recordcreator::recordcreator()
{

}

void recordcreator::createNewRecord(const QString& login_, const QString& resource_, const QString& password_)
{
    Record* newRecord = new Record(login_, resource_, password_);
    this->recordList_->push_front(*newRecord);
}

void recordcreator::slt_createNewRecord(const QString &login_, const QString &resource_, const QString &password_)
{
    this->createNewRecord(login_, resource_, password_);
}
