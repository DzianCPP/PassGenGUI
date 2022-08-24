#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    this->setMinimumSize(850, 650);
    this->setStyleSheet("background-color: white; ");

    //tables

    m_rightScreen = new QTableView;
    m_rightScreen->setAutoScroll(true);
    m_rightScreen->setStyleSheet("background-color: white; "
                                 "border-width: 1px; "
                                 "border-style: solid;"
                                 "border-color: black; ");

    //line_edits

    m_addResourceLine = createLineEdit();
    m_addLoginLine = createLineEdit();
    m_addPasswordLine = createLineEdit();
    m_addPasswordLine->setReadOnly(false);

    //labels

    m_addResource = createLabel("Resource:");
    m_addLogin = createLabel("Login:");
    m_addPassword = createLabel("Password:");

    //layouts

    m_mainLayout = new QGridLayout;
    m_leftLayout = new QGridLayout;
    m_rightLayout = new QGridLayout;
    m_addButtonLayout = new QGridLayout;
    m_smallButtonsLayout = new QGridLayout;
    m_editButtonLayout = new QGridLayout;

    //buttons

    m_addButton =     createButton("Add a record");
    m_autoPassword =  createButton("Auto");
    m_checkedAdding = createButton("Checked");
    m_saveAdded =     createButton("Save");
    m_saveAdded->     setDisabled(true);
    m_showButton =    createButton("Show");
    m_editButton = createButton("Edit a record");

    //connections

    connect(m_checkedAdding, SIGNAL(clicked()), m_saveAdded, SLOT(setActiveSLOT()));

    //adding widgets

    m_mainLayout->addLayout(m_leftLayout,           0, 0, 14, 9);
    m_mainLayout->addLayout(m_rightLayout,          0, 9, 14, 9);
    m_leftLayout->addLayout(m_addButtonLayout,      0, 0, 5, 5);
    m_leftLayout->addLayout(m_smallButtonsLayout,   0, 6, 14, 4);
    m_leftLayout->addLayout(m_editButtonLayout,     6, 0, 6, 5);

    m_addButtonLayout->addWidget(m_addButton,       0, 0, 1, 5);
    m_addButtonLayout->addWidget(m_addResource,     1, 0, 1, 2);
    m_addButtonLayout->addWidget(m_addResourceLine, 1, 2, 1, 3);
    m_addButtonLayout->addWidget(m_addLogin,        2, 0, 1, 2);
    m_addButtonLayout->addWidget(m_addLoginLine,    2, 2, 1, 3);
    m_addButtonLayout->addWidget(m_addPassword,     3, 0, 1, 2);
    m_addButtonLayout->addWidget(m_addPasswordLine, 3, 2, 1, 2);
    m_addButtonLayout->addWidget(m_autoPassword,    3, 4, 1, 1);
    m_addButtonLayout->addWidget(m_checkedAdding,   4, 0, 1, 2);
    m_addButtonLayout->addWidget(m_saveAdded,       4, 2, 1, 3);

    m_editButtonLayout->addWidget(m_editButton,     0, 0, 1, 5);

    m_smallButtonsLayout->addWidget(m_showButton,   0, 1, 1, 2);

    //setting layouts

    setLayout(m_mainLayout);
}

MainWindow::~MainWindow()
{
}

QLabel *MainWindow::createLabel(const QString labelText)
{
    QLabel* newLabel = new QLabel(labelText);
    newLabel->setAlignment(Qt::AlignLeft);
    return newLabel;
}

QLineEdit *MainWindow::createLineEdit()
{
    QLineEdit* newLineEdit = new QLineEdit();
    newLineEdit->setReadOnly(true);
    return newLineEdit;
}

myPushButton *MainWindow::createButton(const QString buttonText)
{
    myPushButton* newButton = new myPushButton(buttonText);
    return newButton;
}

