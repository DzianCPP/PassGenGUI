#ifndef LOGIC_H
#define LOGIC_H

#include "recordcreator.h"
#include "passwordvalidator.h"

#include <QObject>

class logic : public QObject
{
    Q_OBJECT
public:
    explicit logic(QObject *parent = nullptr);
    recordcreator* getRecordCreator();
    PasswordValidator* getPasswordValidator();

signals:

private:
    recordcreator recordCreator;
    PasswordValidator passwordValidator;


};

#endif // LOGIC_H
