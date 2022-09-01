#ifndef FILEWRITER_H
#define FILEWRITER_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include "data.h"

class FileWriter : public QObject
{
    Q_OBJECT
public:
    explicit FileWriter(QObject *parent = nullptr);

signals:
    void sgn_writeRecordsResults(bool value);

public slots:
    void slt_writeRecords(QString& message);

private:
    bool writeRecords(QString& message);

};

#endif // FILEWRITER_H
