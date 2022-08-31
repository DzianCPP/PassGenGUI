#ifndef RECORDEDITOR_H
#define RECORDEDITOR_H

#include <QObject>
#include <forward_list>
#include "data.h"

class RecordEditor : public QObject
{
    Q_OBJECT
public:
    explicit RecordEditor(QObject *parent = nullptr);

signals:

public slots:
    bool editRecord(std::forward_list<Record>::iterator& toEdit);

};

#endif // RECORDEDITOR_H
