#include "recordshower.h"

RecordShower::RecordShower(QObject *parent)
    : QObject{parent}
{

}

void RecordShower::slt_sendInfoToShow()
{
    auto toShow = _recordList->end();
    --toShow;
    emit sgn_showNewRecord(toShow->resource, toShow->login, toShow->password);
}
