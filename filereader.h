#ifndef FILEREADER_H
#define FILEREADER_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include "data.h"

class FileReader : public QObject
{
    Q_OBJECT
public:
    explicit FileReader(QObject *parent = nullptr);

signals:
    void sgn_createNewRecord(QString, QString, QString);

public slots:
    void slt_readFromFile();

private:
    bool readFromFile(QString& resource_, QString& login_, QString& password_);

};

#endif // FILEREADER_H
