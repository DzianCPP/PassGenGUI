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
#include <string>
#include "mainwindow.h"

using namespace std;



class records : public QObject
{
    Q_OBJECT
public:
    explicit records(QObject *parent = nullptr);

signals:

private slots:
    void m_slt_createNewRecord(const MainWindow& mainwin);

private:
    class Record {
    public:
        Record* next_record_;
        QString login{};
        QString resource{};
        QChar password[17]{};

        Record(QString login, QString resource, QChar* password, Record* next_record_ = nullptr) {
            this->login = login;
            this->resource = resource;
            for (int i = 0; i < std::strlen((const char*) password); i++) {
                this->password[i] = password[i];
            }
            this->next_record_ = next_record_;
        }
    };

public:
    ~records();
    records();

    int getRecordsAmount();
    void push_back(QString login, QString resource, QChar* password);
    void push_front(QString login, QString resource, char* password);
    void clear();
    void pop_front();
    void pop_back();
    bool edit_record(QString login, QString resource, char* password, Record& record, QString mod);
    bool remove(int index);
    bool saveToFileAll(QString filename);
    void saveToFileOne(QString filename);
    void findRecords(QString keyword);

private:

    int records_amount_;
    Record* first_record_p_;

};

#endif // RECORDS_H
