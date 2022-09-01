#ifndef RECORDFINDER_H
#define RECORDFINDER_H

#include <QObject>
#include "data.h"
#include <QDebug>

class RecordFinder : public QObject
{
    Q_OBJECT
public:
    explicit RecordFinder(QObject *parent = nullptr);
    QList<Record>::iterator getFoundRecord();

signals:
    void sgn_sendDataOfFoundRecord(QString&, QString&, QString&, QString& message_, bool searchResults);

public slots:
    void slt_findRecord(const QString& keyword_, QString& message_);

private:
    bool findRecord(QString& resource_, QString& login_, QString& password_, QString& message_, const QString& keyword_);
    QList<Record>::iterator thisToFind = _recordList->begin();

};
#endif // RECORDFINDER_H
