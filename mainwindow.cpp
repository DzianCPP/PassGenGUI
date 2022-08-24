#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    this->setMinimumSize(850, 350);
    this->setStyleSheet("background-color: white; ");

    //line_edits

    m_addResourceLine = createLineEdit();
    m_addLoginLine = createLineEdit();
    m_addPasswordLine = createLineEdit();
    m_addPasswordLine->setReadOnly(false);
    m_editByLine = createLineEdit();
    m_editResourceLine = createLineEdit();
    m_editLoginLine = createLineEdit();
    m_editPasswordLine = createLineEdit();
    m_findLine = createLineEdit();

    //labels


    m_rightScreen = new QLabel;
    m_rightScreen->setStyleSheet(" background-color: white; border: 1px solid black; ");
    m_addResource = createLabel("Resource:");
    m_addLogin = createLabel("Login:");
    m_addPassword = createLabel("Password:");
    m_editResource = createLabel("Resource:");
    m_editLogin = createLabel("Login:");
    m_editPassword = createLabel("Password:");
    m_search = createLabel("Search:");
    m_message = createLabel("Message");
    m_message->setAlignment(Qt::AlignLeft);
    m_message->setStyleSheet(" border-width: 1px;"
                             " border-style: solid;"
                             " border-color: black;" );

    //layouts

    m_mainLayout = new QGridLayout;
    m_leftLayout = new QGridLayout;
    m_rightLayout = new QGridLayout;
    m_addButtonLayout = new QGridLayout;
    m_smallButtonsLayout = new QGridLayout;
    m_editButtonLayout = new QGridLayout;
    m_messageLayout = new QGridLayout;

    //buttons

    m_addButton =     createButton("Add a record");
    m_autoPassword =  createButton("Auto");
    m_checkedAdding = createButton("Checked");
    m_saveAdded =     createButton("Save");
    m_saveAdded->     setDisabled(true);
    m_showButton =    createButton("Show all records");
    m_editButton = createButton("Edit a record");
    m_editPasswordAuto = createButton("Auto");
    m_checkedEdit = createButton("Checked");
    m_saveEdit = createButton("Save");
    m_saveEdit->setDisabled(true);
    m_findButton = createButton("Find");
    m_quitButton = createButton("Quit");
    m_editByChoose = createButton("Choose");

    //combo box

    m_editBy = createComboBox("Resource:", "Login:");
    m_findBy = createComboBox("Resource:", "Login:");

    //scroll bars

    m_rightScreenScrollBar = new QScrollBar;

    //connections

    connect(m_checkedAdding, SIGNAL(clicked()), m_saveAdded, SLOT(setActiveSLOT()));
    connect(m_saveAdded, SIGNAL(clicked()), m_saveAdded, SLOT(setDisabledSLOT()));
    connect(m_checkedEdit, SIGNAL(clicked()), m_saveEdit, SLOT(setActiveSLOT()));
    connect(m_saveEdit, SIGNAL(clicked()), m_saveEdit, SLOT(setDisabledSLOT()));

    //adding widgets

    m_mainLayout->addLayout(m_leftLayout,           0, 0, 11, 9);
    m_mainLayout->addLayout(m_rightLayout,          0, 9, 11, 9);
    m_leftLayout->addLayout(m_addButtonLayout,      0, 0, 5, 5);
    m_leftLayout->addLayout(m_editButtonLayout,     5, 0, 6, 5);
    m_leftLayout->addLayout(m_smallButtonsLayout,   0, 6, 5, 4);
    m_leftLayout->addLayout(m_messageLayout,        5, 6, 6, 4);

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

    m_editButtonLayout->addWidget(m_editButton,         0, 0, 1, 5);
    m_editButtonLayout->addWidget(m_editBy,             1, 0, 1, 2);
    m_editButtonLayout->addWidget(m_editByLine,         1, 2, 1, 2);
    m_editButtonLayout->addWidget(m_editByChoose,       1, 4, 1, 1);
    m_editButtonLayout->addWidget(m_editResource,       2, 0, 1, 2);
    m_editButtonLayout->addWidget(m_editResourceLine,   2, 2, 1, 3);
    m_editButtonLayout->addWidget(m_editLogin,          3, 0, 1, 2);
    m_editButtonLayout->addWidget(m_editLoginLine,      3, 2, 1, 3);
    m_editButtonLayout->addWidget(m_editPassword,       4, 0, 1, 2);
    m_editButtonLayout->addWidget(m_editPasswordLine,   4, 2, 1, 2);
    m_editButtonLayout->addWidget(m_editPasswordAuto,   4, 4, 1, 1);
    m_editButtonLayout->addWidget(m_checkedEdit,        5, 0, 1, 2);
    m_editButtonLayout->addWidget(m_saveEdit,           5, 2, 1, 3);



    m_smallButtonsLayout->addWidget(m_showButton,   0, 0, 1, 4);
    m_smallButtonsLayout->addWidget(m_search,       1, 0, 1, 4);
    m_smallButtonsLayout->addWidget(m_findBy,       2, 0, 1, 1);
    m_smallButtonsLayout->addWidget(m_findLine,     2, 1, 1, 3);
    m_smallButtonsLayout->addWidget(m_findButton,   3, 0, 1, 4);
    m_smallButtonsLayout->addWidget(m_quitButton,   4, 0, 1, 4);

    m_messageLayout->addWidget(m_message,           0, 0, 5, 4);

    m_rightLayout->addWidget(m_rightScreen,          0, 0, 9, 8);
    m_rightLayout->addWidget(m_rightScreenScrollBar, 0, 8, 9, 1);

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
    newLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    return newLabel;
}

QLineEdit *MainWindow::createLineEdit()
{
    QLineEdit* newLineEdit = new QLineEdit();
    newLineEdit->setReadOnly(true);
    newLineEdit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    return newLineEdit;
}

myPushButton *MainWindow::createButton(const QString buttonText)
{
    myPushButton* newButton = new myPushButton(buttonText);
    newButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    return newButton;
}

QComboBox *MainWindow::createComboBox(const QString itemText, const QString itemText2)
{
    QComboBox* newComboBox = new QComboBox;
    newComboBox->addItem(itemText);
    newComboBox->addItem(itemText2);
    newComboBox->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    return newComboBox;
}

