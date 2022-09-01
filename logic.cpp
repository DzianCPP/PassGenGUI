#include "logic.h"

logic::logic(QObject *parent)
    : QObject{parent}
{

}

recordcreator *logic::getRecordCreator()
{
    recordcreator* thisRecordCreator = &recordCreator;
    return thisRecordCreator;
}

PasswordValidator *logic::getPasswordValidator()
{
    PasswordValidator* thisPasswordValidator = &passwordValidator;
    return thisPasswordValidator;
}

AutoPasswordGenerator *logic::getAutoPasswordGenerator()
{
    AutoPasswordGenerator* thisAutoPasswordGenerator = &autoPasswordGenerator;
    return thisAutoPasswordGenerator;
}

FileWriter *logic::getFileWriter()
{
    FileWriter* thisFileWriter = &fileWriter;
    return thisFileWriter;
}

FileReader *logic::getFileReader()
{
    FileReader* thisFileReader = &fileReader;
    return thisFileReader;
}

RecordShower* logic::getRecordShower()
{
    RecordShower* thisRecordShower = &this->recordShower;
    return thisRecordShower;
}

RecordFinder *logic::getRecordFinder()
{
    RecordFinder* thisRecordFinder = &this->recordFinder;
    return thisRecordFinder;
}

RecordEditor *logic::getRecordEditor()
{
    RecordEditor* thisRecordEditor = &this->recordEditor;
    return thisRecordEditor;
}

AllRecordShower *logic::getAllRecordShower()
{
    AllRecordShower* thisAllRecordShower = &this->allRecordShower;
    return thisAllRecordShower;
}
