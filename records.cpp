#include "records.h"


Records::Records(QObject *parent)
{
    records_amount_ = 0;
    first_record_p_ = nullptr;
}

Records::~Records()
{
    this->clear();
}


void Records::m_slt_addRecord(QString& resource, QString& login, QString& password)
{
    this->push_back(resource, login, password);
}

void Records::m_slt_pop_front()
{
    this->pop_front();
}

void Records::m_slt_saveToFileAll(QString& filename, QLabel* m_messageLabel)
{
    this->saveToFileAll(filename, m_messageLabel);
}

void Records::m_slt_showRecords(QString all, QLabel *m_rightScreen)
{
    this->showRecords(all, m_rightScreen);
}

int Records::getRecordsAmount()
{
    return records_amount_;
}

void Records::push_back(QString& login, QString& resource, QString& password)
{
    if (first_record_p_ == nullptr) {
        first_record_p_ = new Record(login, resource, password);
    }

    else if (first_record_p_ != nullptr) {
        Record* this_record = this->first_record_p_;
        while (this_record->next_record_ != nullptr) {
            this_record = this_record->next_record_;
        }
        this_record->next_record_ = new Record(login, resource, password);
    }

    records_amount_++;
}

void Records::clear()
{
    while (records_amount_) {
        pop_front();
    }
}

void Records::pop_front()
{
    Record* temp = this->first_record_p_;
    if (temp == nullptr) { return; }

    if (first_record_p_->next_record_ != nullptr) {
        this->first_record_p_ = first_record_p_->next_record_;
    }
    temp->next_record_ = nullptr;
    delete temp;
    records_amount_--;
    if (records_amount_ == 0) {
        temp = NULL;
        this->first_record_p_ = NULL;
    }
}

bool Records::saveToFileAll(QString filename, QLabel* m_messageLabel)
{
    QFile file(filename);
    if (!file.open(QIODeviceBase::OpenModeFlag::WriteOnly | QIODeviceBase::Append))
    {
        m_messageLabel->setText("Error! No file!");
    }

    else
    {
        Record* toPrint = this->first_record_p_;
        if (toPrint == nullptr)
        {
            return false;
        }

        else
        {
            for (; ;)
            {
                QByteArray _resource = toPrint->resource.toLocal8Bit();
                QByteArray _login = toPrint->login.toLocal8Bit();
                file.write(_resource + '\n' + _login + '\n');
                file.write((const char*) toPrint->password);
                file.write("\n\n");

                if (toPrint->next_record_ != nullptr)
                {
                    toPrint = toPrint->next_record_;
                }

                else
                {
                    break;
                }
            }
        }
    }

    m_messageLabel->setText("All records were saved");
    file.close();
    return true;
}

bool Records::showRecords(QString all, QLabel *m_rightScreen)
{
    Record* toPrint = this->first_record_p_;
    if (toPrint == nullptr) {
        return false;
    }

    else {
        int count = { 1 };
        for (; ; count++) {
            m_rightScreen->setText("Resource: " + toPrint->resource + "\n"
                                    + "Login: " + toPrint->login + "\n"
                                   + "Password: " + QtPrivate::convertToQString(toPrint->password) + "\n");

            toPrint = toPrint->next_record_;
            if (toPrint == nullptr) {
                break;
            }
        }
    }

    return true;
}

