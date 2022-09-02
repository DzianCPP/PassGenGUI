#include "record.h"

Record::Record(const QString& login, const QString& resource, const QString& password)
{
    this->login = login;
    this->resource = resource;
    this->password = password;
}

bool Record::operator==(const Record &other) const
{
    if (this->resource == other.resource && this->login == other.login && this->password == other.login)
    {
        return true;
    }

    return false;
}
