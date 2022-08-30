#ifndef RECORD_H
#define RECORD_H
#pragma once

#include <QString>
#include <QChar>
const size_t MAXPASSLENGTH = { 17 };


class Record
{    
public:
    QString login{};
    QString resource{};
    QString password{};

    Record(const QString& login, const QString& resource, const QString& password);

private:

};

#endif // RECORD_H
