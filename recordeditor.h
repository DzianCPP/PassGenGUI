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
    void sgn_sendResultsOfEditing(bool value, QString& newResource_, QString& newLogin_, QString& newPassword_);

public slots:
    void slt_editRecord(QList<Record>::iterator toEdit, QString& newResource_, QString& newLogin_, QString& newPassword_, QString& message_);

private:
    bool editRecord(QList<Record>::iterator& toEdit, QString& newResource_, QString& newLogin_, QString& newPassword_, QString& message_);
};

#endif // RECORDEDITOR_H
