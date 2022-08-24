#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>

class myPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit myPushButton(const QString buttonText);

signals:
    void setActive(bool value);

private slots:
    void setActiveSLOT();

};

#endif // MYPUSHBUTTON_H
