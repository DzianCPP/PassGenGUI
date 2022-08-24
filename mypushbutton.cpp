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
