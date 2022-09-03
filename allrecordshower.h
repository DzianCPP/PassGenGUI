#ifndef ALLRECORDSHOWER_H
#define ALLRECORDSHOWER_H

#include <QObject>
#include "data.h"

class AllRecordShower : public QObject
{
    Q_OBJECT
public:
    explicit AllRecordShower(QObject *parent = nullptr);

signals:
    void sgn_sendInfoToShow(QString& resource_, QString& login_, QString& password);

public slots:
    void slt_extractInfoToShow(QString &message_);

private:

};

#endif // ALLRECORDSHOWER_H
