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
#include "logic.h"

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

signals:
    void sgn_sendInfoToRecordCreator(const QString& login_, const QString& resource_, const QString& password_);
    void sgn_sendPasswordForValidation(const QString& password_, QString& mod, QString& message);
    void sgn_generatePasswordAuto();
    void sgn_generateAutoPassword(PasswordValidator*, QString&, QString&);
    void sgn_writeOneFile(QString&);

private slots:
    void m_slt_sendInfoToRecordCreator();
    void slt_sendPasswordForValidation();
    void slt_getValidationResults(bool result_);
    void m_slt_setModAuto();
    void slt_generatePasswordAuto();
    void slt_getAutoPassword(QString* _password);
    void slt_writeOneRecord();

private:
    QString mod = {"manual"};
    QString message = {};

    QGridLayout* m_mainLayout;
    QGridLayout* m_leftLayout;
    QGridLayout* m_rightLayout;
    QGridLayout* m_smallButtonsLayout;
    QGridLayout* m_addButtonLayout;
    QGridLayout* m_editButtonLayout;
    QGridLayout* m_messageLayout;

    myPushButton* m_autoPasswordButton;
    myPushButton* m_checkedAddingButton;
    myPushButton* m_saveAddedButton;
    myPushButton* m_showButton;
    myPushButton* m_findButton;
    myPushButton* m_editPasswordAutoButton;
    myPushButton* m_checkedEditButton;
    myPushButton* m_saveEditButton;
    myPushButton* m_quitButton;
    myPushButton* m_editByChooseButton;
    myPushButton* m_deleteButton;
    myPushButton* m_sureButton;
    myPushButton* m_cancelButton;

    QComboBox* m_editByComboBox;

    QLabel* m_rightScreenLabel;
    QLabel* m_addResourceLabel;
    QLabel* m_addLoginLabel;
    QLabel* m_addPasswordLabel;
    QLabel* m_editResourceLabel;
    QLabel* m_editLoginLabel;
    QLabel* m_editPasswordLabel;
    QLabel* m_searchLabel;
    QLabel* m_messageLabel;
    QLabel* m_addLabel;
    QLabel* m_editLabel;
    QLabel* m_removeKeywordLabel;
    QLabel* m_findKeywordLabel;

    QLineEdit* m_addResourceLine;
    QLineEdit* m_addLoginLine;
    QLineEdit* m_addPasswordLine;
    QLineEdit* m_editByLine;
    QLineEdit* m_editResourceLine;
    QLineEdit* m_editLoginLine;
    QLineEdit* m_editPasswordLine;
    QLineEdit* m_findLine;
    QLineEdit* m_removeByLine;

    QScrollBar* m_rightScreenScrollBar;

    logic _logic;
};
#endif // MAINWINDOW_H
