#include "passwordvalidator.h"

PasswordValidator::PasswordValidator(QObject *parent)
    : QObject{parent}
{

}

bool PasswordValidator::validatePassword(const QString &password_, QString& mod, QString& message)
{
    std::string _password = password_.toStdString();
    char* _pass = new char[_password.length() + 1];
    for (int i = 0; i < _password.length(); i++)
    {
        _pass[i] = _password.at(i);
    }
    _pass[_password.length()] = '\0';
    if (std::strlen(_pass) < 8 || std::strlen(_pass) > 16)
    {
        if (mod == "manual")
        {
            message = "This password is invalid:\nit must be 8-16 symbols!";
        }
        delete[] _pass;
        return false;
    }

    int upperCount = 0;
    for (int i = 0; _pass[i] != '\0'; i++)
    {
        if (std::isupper(_pass[i]))
        {
            upperCount++;
        }
    }

    if (!upperCount)
    {
        if (mod == "manual")
        {
            message = "This password is invalid:\nit must contain at least 1 upper case letter!";
        }
        delete[] _pass;
        return false;
    }

    int lowerCount = 0;

    for (int i = 0; _pass[i] != '\0'; i++)
    {
        if (std::islower(_pass[i]))
        {
            lowerCount++;
        }
    }

    if (!lowerCount)
    {
        if (mod == "manual")
        {
            message = "This password is invalid:\nit must contain at least 1 lower case letter!";
        }

        delete[] _pass;
        return false;
    }

    int numCount = 0;
    for (int i = 0; _pass[i] != '\0'; i++)
    {
        if (std::isdigit(_pass[i]))
        {
            numCount++;
        }
    }
    if (!numCount)
    {
        if (mod == "manual")
        {
            message = "This password is invalid:\nit must contain at least one digit!";
        }
        delete[] _pass;
        return false;
    }

    int specialCount = 0;
    for (int i = 0; _pass[i] != '\0'; i++)
    {
        if (_pass[i] == 33
            || _pass[i] == 35 || _pass[i] == 36
            || _pass[i] == 37 || _pass[i] == 38
            || _pass[i] == 40 || _pass[i] == 41
            || _pass[i] == 42 || _pass[i] == 43
            || _pass[i] == 45 || _pass[i] == 61
            || _pass[i] == 64 || _pass[i] == 94 || _pass[i] == 95)
        {
            specialCount++;
        }
        if (mod == "auto")
        {
            if (_pass[i] == 34 || _pass[i] == 39
                || _pass[i] == 40 || _pass[i] == 41
                || _pass[i] == 44 || _pass[i] == 46
                || _pass[i] == 47 || _pass[i] == 58
                || _pass[i] == 59 || _pass[i] == 60
                || _pass[i] == 62 || _pass[i] == 63
                || _pass[i] == 91 || _pass[i] == 92
                || _pass[i] == 93 || _pass[i] == 96)
            {
                _pass[i] = rand() % 89 + 33;
                i--;
            }
        }
    }

    if (!specialCount)
    {
        if (mod == "manual")
        {
            message = "This password is invalid!\nIt must contain at least on special character:\n!, @, #, $, %, ^, &, *, (, ), _, +, -, = ";
        }
        delete[] _pass;
        return false;
    }

    delete[] _pass;
    message = "This password is ok";
    return true;
}

void PasswordValidator::slt_validatePassword(const QString &password_, QString &mod, QString &message)
{
    emit sgn_sendValidationResults(validatePassword(password_, mod, message));
}
