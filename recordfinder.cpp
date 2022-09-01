#include "recordfinder.h"

RecordFinder::RecordFinder(QObject *parent)
    : QObject{parent}
{

}

QList<Record>::iterator RecordFinder::getFoundRecord()
{
    return this->thisToFind;
}

void RecordFinder::slt_findRecord(const QString &keyword_, QString &message_)
{
    QString resource_, login_, password_;
    emit sgn_sendDataOfFoundRecord(resource_, login_, password_, message_, findRecord(resource_, login_, password_, message_, keyword_));
}

bool RecordFinder::findRecord(QString &resource_, QString &login_, QString &password_, QString& message_, const QString &keyword_)
{
    QList<Record>::iterator toFind = _recordList->begin();
    if (_recordList->empty())
    {
        message_ = "No records";
        return false;
    }

    for (auto it = _recordList->begin(); ; )
    {
        ++it;
        if (!(toFind->resource.contains(keyword_)) && !(toFind->login.contains(keyword_)))
        {
            if (it != _recordList->end())
            {
                toFind = it;
            }

            else
            {
                message_ = "No records found";
                return false;
            }
        }

        else
        {
            break;
        }
    }

    resource_ = toFind->resource;
    login_ = toFind->login;
    password_ = toFind->password;
    message_ = "This record suits your request";
    this->thisToFind = toFind;
    return true;
}
