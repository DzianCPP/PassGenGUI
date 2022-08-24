#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//#pragma once
#include <QWidget>
#include <QLineEdit>
#include <QGridLayout>
#include <QTableView>
#include <QLabel>
#include <QComboBox>
#include <QScrollBar>
#include "mypushbutton.h"
#include "records.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QLabel* createLabel(const QString labelText);
    QLineEdit* createLineEdit();
    myPushButton* createButton(const QString buttonText);
    QComboBox* createComboBox(const QString itemText, const QString itemText2);

    QString getAddResourceLineText();
    QString getAddLoginLineText();
    QString getAddPasswordLineText();

signals:
    void m_sgn_saveAddedRecord(QString& resource, QString& login, QString& password);
    void m_sgn_deleteButtonClicked();

private slots:
    void m_slt_saveAddedButtonCLicked();
    void m_slt_deleteButtonClicked();

private:
    QString filename = "records.dat";
    static const int MAXPASSLENGTH = 17;
    Records* records;
    QString resource{};
    QString login{};
    QString keyword{};
    int id{};
    char password[MAXPASSLENGTH]{};

    QGridLayout* m_mainLayout;
    QGridLayout* m_leftLayout;
    QGridLayout* m_rightLayout;
    QGridLayout* m_smallButtonsLayout;
    QGridLayout* m_addButtonLayout;
    QGridLayout* m_editButtonLayout;
    QGridLayout* m_messageLayout;

    myPushButton* m_autoPassword;
    myPushButton* m_checkedAdding;
    myPushButton* m_saveAdded;
    myPushButton* m_showButton;
    myPushButton* m_findButton;
    myPushButton* m_editButton;
    myPushButton* m_editPasswordAuto;
    myPushButton* m_checkedEdit;
    myPushButton* m_saveEdit;
    myPushButton* m_quitButton;
    myPushButton* m_editByChoose;
    myPushButton* m_deleteButton;

    QComboBox* m_editBy;
    QComboBox* m_findBy;


    QLabel* m_rightScreen;
    QLabel* m_addResource;
    QLabel* m_addLogin;
    QLabel* m_addPassword;
    QLabel* m_editResource;
    QLabel* m_editLogin;
    QLabel* m_editPassword;
    QLabel* m_search;
    QLabel* m_message;
    QLabel* m_add;

    QLineEdit* m_addResourceLine;
    QLineEdit* m_addLoginLine;
    QLineEdit* m_addPasswordLine;
    QLineEdit* m_editByLine;
    QLineEdit* m_editResourceLine;
    QLineEdit* m_editLoginLine;
    QLineEdit* m_editPasswordLine;
    QLineEdit* m_findLine;

    QScrollBar* m_rightScreenScrollBar;

    friend Records;
};
#endif // MAINWINDOW_H
