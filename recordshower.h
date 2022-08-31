#ifndef RECORDSHOWER_H
#define RECORDSHOWER_H

#include <QObject>
#include "data.h"

class RecordShower : public QObject
{
    Q_OBJECT
public:
    explicit RecordShower(QObject *parent = nullptr);

signals:
    void sgn_showNewRecord(const QString&, const QString&, const QString&);

public slots:
    void slt_sendInfoToShow();

};

#endif // RECORDSHOWER_H
