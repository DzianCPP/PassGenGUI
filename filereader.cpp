#include "filereader.h"

FileReader::FileReader(QObject *parent)
    : QObject{parent}
{

}

void FileReader::slt_readFromFile()
{
    QString resource_, login_, password_;
    this->readFromFile(resource_, login_, password_);
}

bool FileReader::readFromFile(QString &resource_, QString &login_, QString &password_)
{
    QFile file(filename);
    if (!file.open(QFile::ReadOnly))
    {
        return false;
    }

    QTextStream fin(&file);
    while(!fin.atEnd())
    {
        login_ = fin.readLine();
        resource_ = fin.readLine();
        password_ = fin.readLine();
        emit sgn_createNewRecord(resource_, login_, password_);
    }
    file.close();
    return true;
}
