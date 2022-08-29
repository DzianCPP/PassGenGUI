#ifndef LOGIC_H
#define LOGIC_H

#include "recordcreator.h"
#include "passwordvalidator.h"
#include "autopasswordgenerator.h"

#include <QObject>

class logic : public QObject
{
    Q_OBJECT
public:
    explicit logic(QObject *parent = nullptr);
    recordcreator* getRecordCreator();
    PasswordValidator* getPasswordValidator();
    AutoPasswordGenerator* getAutoPasswordGenerator();

signals:

private:
    recordcreator recordCreator;
    PasswordValidator passwordValidator;
    AutoPasswordGenerator autoPasswordGenerator;


};

#endif // LOGIC_H
