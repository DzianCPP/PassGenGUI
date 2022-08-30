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
    if (!file.open(QFile::WriteOnly))
    {
        message = "Error! Could not save the record!";
        return false;
    }

    if (_recordList->empty())
    {
        message = "Error! No records were created!";
        return false;
    }

    std::_Fwd_list_iterator<Record> toWrite = _recordList->begin();
    for (; toWrite._M_next() != _recordList->end(); )
    {
        toWrite = toWrite._M_next();
    }

    QTextStream fout(&file);
    fout << toWrite->resource + "\n" + toWrite->login + "\n" + toWrite->password + "\n\n";
    message = "Record successfully saved";
    file.close();
    return true;
}
