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

};

#endif // MYPUSHBUTTON_H
