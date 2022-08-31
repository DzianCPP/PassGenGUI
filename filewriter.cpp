#include "filewriter.h"

FileWriter::FileWriter(QObject *parent)
    : QObject{parent}
{

}

void FileWriter::slt_writeOneRecord(QString& message)
{
    emit sgn_writeOneRecordResults(writeOneRecord(message));
}

bool FileWriter::writeOneRecord(QString &message)
{
    QFile file(filename);
    if (!file.open(QFile::WriteOnly | QFile::Append))
    {
        message = "Error! Could not save the record!";
        return false;
    }

    if (_recordList->empty())
    {
        message = "Error! No records were created!";
        return false;
    }

    auto toWrite = _recordList->cbegin();

    QTextStream fout(&file);
    fout << toWrite->resource + "\n" + toWrite->login + "\n" + toWrite->password + "\n";
    file.close();
    return true;
}
