#include "recordshower.h"

RecordShower::RecordShower(QObject *parent)
    : QObject{parent}
{

}

void RecordShower::slt_sendInfoToShow()
{
    auto toShow = _recordList->cbegin();
    if (toShow._M_node != nullptr)
    {
        emit sgn_showNewRecord(toShow->resource, toShow->login, toShow->password);
    }
}
