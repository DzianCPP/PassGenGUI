#include "recordfinder.h"

RecordFinder::RecordFinder(QObject *parent)
    : QObject{parent}
{

}

std::forward_list<Record>::iterator RecordFinder::getFoundRecord()
{
    return this->toFind;
}

void RecordFinder::slt_findRecord(const QString &keyword_, QString &message_)
{
    QString resource_, login_, password_;
    emit sgn_sendDataOfFoundRecord(resource_, login_, password_, message_, findRecord(resource_, login_, password_, message_, keyword_));
}

bool RecordFinder::findRecord(QString &resource_, QString &login_, QString &password_, QString& message_, const QString &keyword_)
{
    for (; ;)
    {
        if (toFind._M_node != nullptr)
        {
            if (toFind->resource == keyword_ || toFind->login == keyword_)
            {
                resource_ = toFind->resource;
                login_ = toFind->login;
                password_ = toFind->password;
                message_ = "This record suits your request";
                return true;
            }
            ++toFind;
        }

        else
        {
            break;
        }
    }
    message_ = "No records were found";
    return false;
}
