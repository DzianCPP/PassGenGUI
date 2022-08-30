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
    void sgn_writeOneRecordResults(bool value);

public slots:
    void slt_writeOneRecord(QString& message);

private:
    bool writeOneRecord(QString& message);

};

#endif // FILEWRITER_H
