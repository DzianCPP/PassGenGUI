#include "mypushbutton.h"

myPushButton::myPushButton(const QString buttonText)
{
    this->setText(buttonText);
    this->setStyleSheet(" background-color: aquamarine; ");

}

void myPushButton::m_slt_setEnabledTRUE()
{
    this->setEnabled(true);
}

void myPushButton::m_slt_setEnabledFALSE()
{
    this->setDisabled(true);
}
