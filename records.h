#ifndef RECORDS_H
#define RECORDS_H
#pragma once


#define PAUSE std::system("pause");
#define CLS std::system("cls");

#include <QObject>
#include <iostream>
#include <cstring>
#include <cctype>
#include <ctime>
#include <fstream>

using namespace std;



class Records : public QObject
{
    Q_OBJECT

private:
    class Record;
public:
    explicit Records(QObject *parent = nullptr);
    ~Records();

    int getRecordsAmount();
    void push_back(QString& login, QString& resource, QString& password);
    void clear();
    void pop_front();
    bool edit_record(QString& login, QString& resource, QString& password, Record& record, QString mod);

signals:

public slots:
    void m_slt_addRecord(QString& resource, QString& login, QString& password);
    void m_slt_pop_front();
    void m_slt_edit_record(QString& login, QString& resource, QString& password, Record& record, QString mod);

private:
    class Record {
    public:
        Record* next_record_;
        QString login{};
        QString resource{};
        QChar password[17]{};

        Record(QString login, QString resource, QString& password, Record* next_record_ = nullptr) {
            this->login = login;
            this->resource = resource;
            for (int i = 0; i < password.length(); i++) {
                this->password[i] = password[i];
            }
            this->next_record_ = next_record_;
        }
    };

    int records_amount_;
    Record* first_record_p_;
};

#endif // RECORDS_H
