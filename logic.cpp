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
