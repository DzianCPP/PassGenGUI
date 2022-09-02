#include "recordeditor.h"

RecordEditor::RecordEditor(QObject *parent)
    : QObject{parent}
{

}

void RecordEditor::slt_editRecord(QList<Record>::iterator toEdit, QString &newResource_, QString &newLogin_, QString &newPassword_, QString &message_)
{
    emit sgn_sendResultsOfEditing(this->editRecord(toEdit, newResource_, newLogin_, newPassword_, message_),
                                                                     newResource_, newLogin_, newPassword_);
}

bool RecordEditor::editRecord(QList<Record>::iterator &toEdit, QString &newResource_, QString &newLogin_,
                                                                QString &newPassword_, QString &message_)
{
    if (newResource_ == "" || newLogin_ == "")
    {
        message_ = "Error! No resource or login were entered";
        return false;
    }

    if (_recordList->empty())
    {
        message_ = "No records made yet";
        return false;
    }

    if (toEdit == _recordList->end())
    {
        message_ = "Error: invalid link to the record";
        return false;
    }
    toEdit->resource = newResource_;
    toEdit->login = newLogin_;
    toEdit->password = newPassword_;
    message_ = "Record was edited and saved";
    return true;
}
