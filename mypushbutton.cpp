#include "mypushbutton.h"

myPushButton::myPushButton(const QString buttonText)
{
    this->setText(buttonText);
    this->setStyleSheet(" background-color: aquamarine; ");

}

void myPushButton::setActiveSLOT()
{
    this->setDisabled(false);
}

void myPushButton::setDisabledSLOT()
{
    this->setDisabled(true);
}

void myPushButton::slt_clicked()
{
    emit clicked();
}
