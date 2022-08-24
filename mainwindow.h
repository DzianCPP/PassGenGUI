#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QGridLayout>
#include <QTableView>
#include <QLabel>
#include "mypushbutton.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QLabel* createLabel(const QString labelText);
    QLineEdit* createLineEdit();
    myPushButton* createButton(const QString buttonText);

private:
    QTableView* m_rightScreen;

    QGridLayout* m_mainLayout;
    QGridLayout* m_leftLayout;
    QGridLayout* m_rightLayout;
    QGridLayout* m_smallButtonsLayout;
    QGridLayout* m_addButtonLayout;
    QGridLayout* m_editButtonLayout;

    myPushButton* m_addButton;
    myPushButton* m_autoPassword;
    myPushButton* m_checkedAdding;
    myPushButton* m_saveAdded;
    myPushButton* m_showButton;
    myPushButton* m_editButton;


    QLabel* m_addResource;
    QLabel* m_addLogin;
    QLabel* m_addPassword;

    QLineEdit* m_addResourceLine;
    QLineEdit* m_addLoginLine;
    QLineEdit* m_addPasswordLine;
};
#endif // MAINWINDOW_H
