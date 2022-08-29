#ifndef AUTOPASSWORDGENERATOR_H
#define AUTOPASSWORDGENERATOR_H

#include <QObject>
#include "passwordvalidator.h"

class AutoPasswordGenerator : public QObject
{
    Q_OBJECT
public:
    explicit AutoPasswordGenerator(QObject *parent = nullptr);

signals:
    void sgn_sendAutoPassword(QString* _password);

private:
    QString* generatePasswordAuto(PasswordValidator* _passwordValidator, QString& mod, QString& message);
    int setPasswordSize();

private slots:
    void slt_generatePasswordAuto(PasswordValidator* _passwordValidator, QString& mod, QString& message);

};

#endif // AUTOPASSWORDGENERATOR_H
