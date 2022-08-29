#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H
#pragma once

#include <QPushButton>

class myPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit myPushButton(const QString buttonText);

signals:

private slots:
    void m_slt_setEnabledTRUE();
    void m_slt_setEnabledFALSE();

};

#endif // MYPUSHBUTTON_H
