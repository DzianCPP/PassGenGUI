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
#include <QFile>
#include <QLabel>
#include <QDir>

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
    bool edit_record(QString& login, QString& resource, QString& password, Records::Record& record, QString mod);
    bool saveToFileAll(QString filename, QLabel* m_messageLabel);
    bool showRecords(QString all, QLabel* m_rightScreen);

signals:

public slots:
    void m_slt_addRecord(QString& resource, QString& login, QString& password);
    void m_slt_pop_front();
    void m_slt_saveToFileAll(QString& filename, QLabel* m_messageLabel);
    void m_slt_showRecords(QString all, QLabel *m_rightScreen);

private:
    class Record {
    public:
        Record* next_record_;
        QString login{};
        QString resource{};
        unsigned char password[17]{};

        Record(QString login, QString resource, QString& password, Record* next_record_ = nullptr) {
            this->login = login;
            this->resource = resource;
            unsigned char _password[17];
            memcpy(_password, password.toStdString().c_str(), password.size());
            _password[password.toStdString().size()] = '\0';
            for (int i = 0; i < 17; i++) {
                if (_password[i] != '\0')
                {
                    this->password[i] = _password[i];
                }

                else
                {
                    break;
                }
            }
            this->next_record_ = next_record_;
        }
    };

    int records_amount_;
    Record* first_record_p_;
};

#endif // RECORDS_H
