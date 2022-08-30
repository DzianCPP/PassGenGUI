#ifndef PASSWORDVALIDATOR_H
#define PASSWORDVALIDATOR_H

#include <QObject>

class PasswordValidator : public QObject
{
    Q_OBJECT
public:
    explicit PasswordValidator(QObject *parent = nullptr);
    bool validatePassword(const QString& password_, QString& mod, QString& message);

signals:
    void sgn_sendValidationResults(bool result);

public slots:
    void slt_validatePassword(const QString& password_, QString& mod, QString& message);

};

#endif // PASSWORDVALIDATOR_H
