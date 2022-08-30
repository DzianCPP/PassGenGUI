#ifndef LOGIC_H
#define LOGIC_H

#include "recordcreator.h"
#include "passwordvalidator.h"
#include "autopasswordgenerator.h"
#include "filewriter.h"

#include <QObject>

class logic : public QObject
{
    Q_OBJECT
public:
    explicit logic(QObject *parent = nullptr);
    recordcreator* getRecordCreator();
    PasswordValidator* getPasswordValidator();
    AutoPasswordGenerator* getAutoPasswordGenerator();
    FileWriter* getFileWriter();

signals:

private:
    recordcreator recordCreator;
    PasswordValidator passwordValidator;
    AutoPasswordGenerator autoPasswordGenerator;
    FileWriter fileWriter;


};

#endif // LOGIC_H
