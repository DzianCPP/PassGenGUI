#include "allrecordshower.h"

AllRecordShower::AllRecordShower(QObject *parent)
    : QObject{parent}
{

}

void AllRecordShower::slt_extractInfoToShow()
{
    QList<Record>::iterator toShow = _recordList->begin();
    while (toShow != _recordList->end())
    {
        emit this->sgn_sendInfoToShow(toShow->resource, toShow->login, toShow->password);
        ++toShow;
    }
}
