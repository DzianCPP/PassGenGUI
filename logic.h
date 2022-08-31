#ifndef LOGIC_H
#define LOGIC_H

#include "recordcreator.h"
#include "passwordvalidator.h"
#include "autopasswordgenerator.h"
#include "filewriter.h"
#include "filereader.h"
#include "recordshower.h"
#include "recordfinder.h"

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
    FileReader* getFileReader();
    RecordShower* getRecordShower();
    RecordFinder* getRecordFinder();

signals:

private:
    recordcreator recordCreator;
    PasswordValidator passwordValidator;
    AutoPasswordGenerator autoPasswordGenerator;
    FileWriter fileWriter;
    FileReader fileReader;
    RecordShower recordShower;
    RecordFinder recordFinder;


};

#endif // LOGIC_H
