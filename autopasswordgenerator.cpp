#include "autopasswordgenerator.h"

AutoPasswordGenerator::AutoPasswordGenerator(QObject *parent)
    : QObject{parent}
{

}

QString *AutoPasswordGenerator::generatePasswordAuto(PasswordValidator* _passwordValidator, QString& mod, QString& message)
{
    int pass_size = setPasswordSize();
    char* password = new char[pass_size];

    for (int i = 0; i < pass_size; i++)
    {
        password[i] = rand() % 89 + 33;
    }
    password[pass_size] = '\0';


    QString* _pass = new QString(password);

    if (_passwordValidator->validatePassword(*_pass, mod, message))
    {
        return _pass;
    }

    else
    {
        return generatePasswordAuto(_passwordValidator, mod, message);
    }
}

int AutoPasswordGenerator::setPasswordSize()
{
    int pass_size = rand() % 16 + 1;

    if (pass_size < 9 || pass_size > 17) {
        return setPasswordSize();
    }

    else {
        return pass_size;
    }
}

void AutoPasswordGenerator::slt_generatePasswordAuto(PasswordValidator* _passwordValidator, QString &mod, QString &message)
{
    emit sgn_sendAutoPassword(generatePasswordAuto(_passwordValidator, mod, message));
}
