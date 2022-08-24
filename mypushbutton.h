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
    void setActive(bool value);
    void sgn_saveAdded();

private slots:
    void setActiveSLOT();
    void setDisabledSLOT();

};

#endif // MYPUSHBUTTON_H
