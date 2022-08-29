#include "record.h"

Record::Record(const QString& login, const QString& resource, const QString& password)
{
    this->login = login;
    this->resource = resource;
    this->password = password;
}
