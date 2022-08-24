#include "records.h"
#pragma once

records::records(QObject *parent)
    : QObject{parent}
{
    records_amount_ = 0;
    first_record_p_ = nullptr;
}

void records::m_slt_createNewRecord(MainWindow& mainwin)
{
    this->push_back(mainwin.getAddLoginLineText(), mainwin.getAddResourceLineText(), mainwin.getAddPasswordLineText());
}

int records::getRecordsAmount()
{
    return records_amount_;
}

void records::push_back(QString login, QString resource, char* password)
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
        this_record = this_record->next_record_;
    }

    records_amount_++;
}

void records::push_front(QString login, QString resource, char *password)
{
    Record* new_record = new Record(login, resource, password);
    new_record->next_record_ = first_record_p_;
    first_record_p_ = new_record;
    records_amount_++;
}

void records::clear()
{
    while (records_amount_) {
        pop_front();
    }
}

void records::pop_front()
{
    Record* temp = this->first_record_p_;
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

void records::pop_back()
{
    Record* this_record = this->first_record_p_;
    while (this_record->next_record_ != nullptr) {
        this_record = this_record->next_record_;
    }

    delete this_record;
    records_amount_--;
}

bool records::edit_record(QString login, QString resource, char *password, Record &record, QString mod)
{
    return true;
}

bool records::remove(int index)
{
    return true;

}

bool records::saveToFileAll(QString filename)
{
    return true;

}

void records::saveToFileOne(QString filename)
{

}

void records::findRecords(QString keyword)
{

}
