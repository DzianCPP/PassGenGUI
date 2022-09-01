#include "filewriter.h"

FileWriter::FileWriter(QObject *parent)
    : QObject{parent}
{

}

void FileWriter::slt_writeRecords(QString& message)
{
    emit sgn_writeRecordsResults(writeRecords(message));
}

bool FileWriter::writeRecords(QString &message)
{
    QFile file(filename);
    if (!file.open(QIODeviceBase::ReadWrite))
    {
        message = "Error! Could not save the record!";
        return false;
    }

    if (_recordList->empty())
    {
        message = "Error! No records were created!";
        return false;
    }

    QList<Record>::iterator toWrite = _recordList->begin();
    QTextStream fout(&file);
    while(toWrite != _recordList->end())
    {
        fout << toWrite->resource + "\n" + toWrite->login + "\n" + toWrite->password + "\n";
        ++toWrite;
    }
    file.close();
    return true;
}
