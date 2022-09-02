#ifndef LOGIC_H
#define LOGIC_H

#include "recordcreator.h"
#include "passwordvalidator.h"
#include "autopasswordgenerator.h"
#include "filewriter.h"
#include "filereader.h"
#include "recordshower.h"
#include "recordfinder.h"
#include "recordeditor.h"
#include "allrecordshower.h"
#include "recorddeleter.h"

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
    RecordEditor* getRecordEditor();
    AllRecordShower* getAllRecordShower();
    RecordDeleter* getRecordDeleter();

signals:

private:
    recordcreator recordCreator;
    PasswordValidator passwordValidator;
    AutoPasswordGenerator autoPasswordGenerator;
    FileWriter fileWriter;
    FileReader fileReader;
    RecordShower recordShower;
    RecordFinder recordFinder;
    RecordEditor recordEditor;
    AllRecordShower allRecordShower;
    RecordDeleter recordDeleter;


};

#endif // LOGIC_H
