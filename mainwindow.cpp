#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    this->setMinimumSize(1050, 400);
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
    m_removeByLine = createLineEdit();

    //labels

    m_rightScreenLabel = createLabel("");
    m_rightScreenLabel->setAlignment(Qt::AlignLeft);
    m_rightScreenLabel->setStyleSheet(" background-color: white; border: 1px solid white; ");
    m_addResourceLabel = createLabel("Resource:");
    m_addLoginLabel = createLabel("Login:");
    m_addPasswordLabel = createLabel("Password:");
    m_editResourceLabel = createLabel("Resource:");
    m_editLoginLabel = createLabel("Login:");
    m_editPasswordLabel = createLabel("Password:");
    m_searchLabel = createLabel("Search:");
    m_messageLabel = createLabel("");
    m_messageLabel->setAlignment(Qt::AlignLeft);
    m_messageLabel->setStyleSheet(" border-width: 1px;"
                             " border-style: solid;"
                             " border-color: black;" );
    m_addLabel = createLabel("Add a new record");
    m_addLabel->setStyleSheet(" background-color: grey; "
                         " border: 1px solid aquamarine; "
                         " border-radius: 5px; "
                         " color: white; ");
    m_addLabel->setAlignment(Qt::AlignCenter);
    m_editLabel = createLabel("Edit a record");
    m_editLabel->setStyleSheet(" background-color: grey; "
                               " border: 1px solid aquamarine; "
                               " border-radius: 5px; "
                               " color: white; ");
    m_editLabel->setAlignment(Qt::AlignCenter);
    m_removeKeywordLabel = createLabel("Keyword:");
    m_findKeywordLabel = createLabel("Keyword:");

    //layouts

    m_mainLayout         = new QGridLayout;
    m_leftLayout         = new QGridLayout;
    m_rightLayout        = new QGridLayout;
    m_addButtonLayout    = new QGridLayout;
    m_smallButtonsLayout = new QGridLayout;
    m_editButtonLayout   = new QGridLayout;
    m_messageLayout      = new QGridLayout;

    //buttons

    m_autoPasswordButton =  createButton("Auto");
    m_checkedAddingButton = createButton("Checked");
    m_saveAddedButton =     createButton("Save");
    m_saveAddedButton->setDisabled(true);
    m_showButton =    createButton("Show all records");
    m_editPasswordAutoButton = createButton("Auto");
    m_checkedEditButton = createButton("Checked");
    m_saveEditButton = createButton("Save");
    m_saveEditButton->setDisabled(true);
    m_findButton = createButton("Find");
    m_quitButton = createButton("Quit");
    m_editByChooseButton = createButton("Choose");
    m_deleteButton = createButton("Delete");
    m_sureButton = createButton("Sure");
    m_cancelButton = createButton("Cancel");

    //scroll bars

    m_rightScreenScrollBar = new QScrollBar;

    //scroll areas

    m_rightScreenScrollArea = new QScrollArea;

    m_rightScreenScrollArea->setWidget(m_rightScreenLabel);
    m_rightScreenScrollArea->setWidgetResizable(true);
    m_rightScreenScrollArea->setStyleSheet(" background-color: white; border: 1px solid white; ");
    m_rightScreenScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    //connections

    connect(this, SIGNAL(sgn_readFromFile()), _logic.getFileReader(), SLOT(slt_readFromFile()));
    connect(_logic.getFileReader(),    SIGNAL(sgn_createNewRecord(QString,QString,QString)),
            _logic.getRecordCreator(), SLOT(slt_createNewRecord(QString,QString,QString)));

    connect(m_checkedAddingButton, SIGNAL(clicked()), this, SLOT(slt_sendPasswordForValidation()));
    connect(this,                          SIGNAL(sgn_sendPasswordForValidation(QString,QString&,QString&)),
            _logic.getPasswordValidator(), SLOT(slt_validatePassword(QString,QString&,QString&)));
    connect(_logic.getPasswordValidator(), SIGNAL(sgn_sendValidationResults(bool)), this, SLOT(slt_getValidationResults(bool)));

    connect(m_saveAddedButton, SIGNAL(clicked()), this, SLOT(m_slt_sendInfoToRecordCreator()));
    connect(this,                      SIGNAL(sgn_sendInfoToRecordCreator(QString,QString,QString)),
            _logic.getRecordCreator(), SLOT(slt_createNewRecord(QString,QString,QString)));

    connect(m_autoPasswordButton, SIGNAL(clicked()), this, SLOT(m_slt_setModAuto()));
    connect(m_autoPasswordButton, SIGNAL(clicked()), this, SLOT(m_slt_setAddOrEditToAdd()));
    connect(m_autoPasswordButton, SIGNAL(clicked()), this, SLOT(slt_generatePasswordAuto()));
    connect(this, SIGNAL(sgn_generateAutoPassword(PasswordValidator*,QString&,QString&)), _logic.getAutoPasswordGenerator(),
                  SLOT(slt_generatePasswordAuto(PasswordValidator*,QString&,QString&)));

    connect(m_saveAddedButton, SIGNAL(clicked()), this, SLOT(slt_writeRecords()));
    connect(this, SIGNAL(sgn_writeOneFile(QString&)), _logic.getFileWriter(), SLOT(slt_writeRecords(QString&)));

    connect(m_saveAddedButton, SIGNAL(clicked()), this, SLOT(slt_getInfoToShowLastAddedRecord()));
    connect(this, SIGNAL(sgn_showLastAddedRecord()), _logic.getRecordShower(), SLOT(slt_sendInfoToShow()));
    connect(_logic.getRecordShower(), SIGNAL(sgn_showNewRecord(QString,QString,QString)),
            this,                     SLOT(slt_showLastAddedRecord(QString,QString,QString)));

    connect(m_saveAddedButton, SIGNAL(clicked()), m_addResourceLine, SLOT(clear()));
    connect(m_saveAddedButton, SIGNAL(clicked()), m_addLoginLine, SLOT(clear()));
    connect(m_saveAddedButton, SIGNAL(clicked()), m_addPasswordLine, SLOT(clear()));

    connect(m_saveAddedButton, SIGNAL(clicked()), m_saveAddedButton, SLOT(m_slt_setEnabledFALSE()));

    connect(m_editByChooseButton, SIGNAL(clicked()), this, SLOT(slt_findRecord()));
    connect(this, SIGNAL(sgn_findRecord(QString,QString&)), _logic.getRecordFinder(), SLOT(slt_findRecord(QString,QString&)));
    connect(_logic.getRecordFinder(), SIGNAL(sgn_sendDataOfFoundRecord(QString&,QString&,QString&,QString&,bool)),
            this,                     SLOT(slt_getDataOfFoundRecord(QString&,QString&,QString&,QString&,bool)));

    connect(m_editPasswordAutoButton, SIGNAL(clicked()), this, SLOT(m_slt_setAddOrEditToEdit()));
    connect(m_editPasswordAutoButton, SIGNAL(clicked()), this, SLOT(m_slt_setModAuto()));
    connect(m_editPasswordAutoButton, SIGNAL(clicked()), this, SLOT(slt_generatePasswordAuto()));
    connect(this, SIGNAL(sgn_generateAutoPassword(PasswordValidator*,QString&,QString&)), _logic.getAutoPasswordGenerator(),
                  SLOT(slt_generatePasswordAuto(PasswordValidator*,QString&,QString&)));
    connect(_logic.getAutoPasswordGenerator(), SIGNAL(sgn_sendAutoPassword(QString*)), this, SLOT(slt_getAutoPassword(QString*)));
    connect(m_checkedEditButton, SIGNAL(clicked()), this, SLOT(slt_sendPasswordForValidation()));

    connect(m_saveEditButton, SIGNAL(clicked()), this, SLOT(slt_editRecord()));
    connect(this,                     SIGNAL(sgn_editRecord(QList<Record>::iterator,QString&,QString&,QString&,QString&)),
            _logic.getRecordEditor(), SLOT(slt_editRecord(QList<Record>::iterator,QString&,QString&,QString&,QString&)));
    connect(_logic.getRecordEditor(), SIGNAL(sgn_sendResultsOfEditing(bool,QString&,QString&,QString&)),
            this, SLOT(slt_getEditedRecord(bool,QString&,QString&,QString&)));
    connect(m_saveEditButton, &myPushButton::clicked, this, &MainWindow::slt_writeRecords);
    connect(this, &MainWindow::sgn_writeOneFile, _logic.getFileWriter(), &FileWriter::slt_writeRecords);
    connect(_logic.getFileWriter(), SIGNAL(sgn_writeRecordsResults(bool)), this, SLOT(slt_getValidationResults(bool)));
    connect(m_saveEditButton, SIGNAL(clicked()), m_editResourceLine, SLOT(clear()));
    connect(m_saveEditButton, SIGNAL(clicked()), m_editLoginLine, SLOT(clear()));
    connect(m_saveEditButton, SIGNAL(clicked()), m_editPasswordLine, SLOT(clear()));
    connect(m_saveEditButton, SIGNAL(clicked()), m_saveEditButton, SLOT(m_slt_setEnabledFALSE()));

    connect(m_showButton, SIGNAL(clicked()), m_rightScreenLabel, SLOT(clear()));
    connect(m_showButton, SIGNAL(clicked()), this, SLOT(slt_askForInfoToShowAllRecords()));
    connect(this, SIGNAL(sgn_askForInfoToShowAllRecords()), _logic.getAllRecordShower(), SLOT(slt_extractInfoToShow()));
    connect(_logic.getAllRecordShower(), SIGNAL(sgn_sendInfoToShow(QString&,QString&,QString&)), this, SLOT(slt_showAllRecords(QString&,QString&,QString&)));

    connect(m_quitButton, SIGNAL(clicked()), this, SLOT(close()));

    //adding widgets

    m_mainLayout->addLayout(m_leftLayout,           0, 0, 11, 9);
    m_mainLayout->addLayout(m_rightLayout,          0, 9, 11, 9);
    m_leftLayout->addLayout(m_addButtonLayout,      0, 0, 5, 5);
    m_leftLayout->addLayout(m_editButtonLayout,     5, 0, 6, 5);
    m_leftLayout->addLayout(m_smallButtonsLayout,   0, 6, 4, 4);
    m_leftLayout->addLayout(m_messageLayout,        4, 6, 7, 4);

    m_addButtonLayout->addWidget(m_addLabel,              0, 0, 1, 5);
    m_addButtonLayout->addWidget(m_addResourceLabel,      1, 0, 1, 2);
    m_addButtonLayout->addWidget(m_addResourceLine,       1, 2, 1, 3);
    m_addButtonLayout->addWidget(m_addLoginLabel,         2, 0, 1, 2);
    m_addButtonLayout->addWidget(m_addLoginLine,          2, 2, 1, 3);
    m_addButtonLayout->addWidget(m_addPasswordLabel,      3, 0, 1, 2);
    m_addButtonLayout->addWidget(m_addPasswordLine,       3, 2, 1, 2);
    m_addButtonLayout->addWidget(m_autoPasswordButton,    3, 4, 1, 1);
    m_addButtonLayout->addWidget(m_checkedAddingButton,   4, 0, 1, 2);
    m_addButtonLayout->addWidget(m_saveAddedButton,       4, 2, 1, 3);

    m_editButtonLayout->addWidget(m_editLabel,                0, 0, 1, 5);
    m_editButtonLayout->addWidget(m_editByLine,               1, 0, 1, 4);
    m_editButtonLayout->addWidget(m_editByChooseButton,       1, 4, 1, 1);
    m_editButtonLayout->addWidget(m_editResourceLabel,        2, 0, 1, 2);
    m_editButtonLayout->addWidget(m_editResourceLine,         2, 2, 1, 3);
    m_editButtonLayout->addWidget(m_editLoginLabel,           3, 0, 1, 2);
    m_editButtonLayout->addWidget(m_editLoginLine,            3, 2, 1, 3);
    m_editButtonLayout->addWidget(m_editPasswordLabel,        4, 0, 1, 2);
    m_editButtonLayout->addWidget(m_editPasswordLine,         4, 2, 1, 2);
    m_editButtonLayout->addWidget(m_editPasswordAutoButton,   4, 4, 1, 1);
    m_editButtonLayout->addWidget(m_checkedEditButton,        5, 0, 1, 2);
    m_editButtonLayout->addWidget(m_saveEditButton,           5, 2, 1, 3);



    m_smallButtonsLayout->addWidget(m_showButton,         0, 0, 1, 4);
    m_smallButtonsLayout->addWidget(m_findKeywordLabel,   1, 0, 1, 1);
    m_smallButtonsLayout->addWidget(m_findLine,           1, 1, 1, 3);
    m_smallButtonsLayout->addWidget(m_findButton,         2, 0, 1, 1);
    m_smallButtonsLayout->addWidget(m_deleteButton,       2, 1, 1, 1);
    m_smallButtonsLayout->addWidget(m_sureButton,         2, 2, 1, 1);
    m_smallButtonsLayout->addWidget(m_cancelButton,       2, 3, 1, 1);
    m_smallButtonsLayout->addWidget(m_quitButton,         3, 0, 1, 4);

    m_messageLayout->addWidget(m_messageLabel,            0, 0, 4, 4);

    //m_rightLayout->addWidget(m_rightScreenLabel,          0, 0, 9, 9);
    m_rightLayout->addWidget(m_rightScreenScrollArea,     0, 0, 9, 9);
    //m_rightLayout->addWidget(m_rightScreenScrollBar,      0, 8, 9, 1);

    //setting layouts

    setLayout(m_mainLayout);
    emit this->sgn_readFromFile();
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
    newLineEdit->setReadOnly(false);
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

void MainWindow::m_slt_sendInfoToRecordCreator()
{
    QString resource_ = this->m_addResourceLine->text();
    QString login_ = this->m_addLoginLine->text();
    QString password_ = this->m_addPasswordLine->text();

    emit this->sgn_sendInfoToRecordCreator(login_, resource_, password_);
}

void MainWindow::slt_sendPasswordForValidation()
{
    m_messageLabel->clear();
    if (add_or_edit == "add")
    {
        emit sgn_sendPasswordForValidation(this->m_addPasswordLine->text(), this->mod, this->message);
    }

    else
    {
        emit sgn_sendPasswordForValidation(this->m_editPasswordLine->text(), this->mod, this->message);
    }
}

void MainWindow::slt_getValidationResults(bool result_)
{
    if (add_or_edit == "add")
    {
        if (result_ == true)
        {
             m_saveAddedButton->setEnabled(true);
             m_messageLabel->setText(message);
              return;
        }

         m_saveAddedButton->setDisabled(true);
         m_messageLabel->setText(message);
         return;
    }

    else
    {
        if (result_ == true)
        {
            m_saveEditButton->setEnabled(true);
            m_messageLabel->setText(message);
            return;
        }

        m_saveEditButton->setDisabled(true);
        m_messageLabel->setText(message);
        return;
    }
}

void MainWindow::m_slt_setModAuto()
{
    this->mod = "auto";
}

void MainWindow::m_slt_setAddOrEditToAdd()
{
    this->add_or_edit = "add";
}

void MainWindow::m_slt_setAddOrEditToEdit()
{
    this->add_or_edit = "edit";
}

void MainWindow::slt_generatePasswordAuto()
{
    emit sgn_generateAutoPassword(_logic.getPasswordValidator(), this->mod, this->message);
}

void MainWindow::slt_getAutoPassword(QString* _password)
{
    if (add_or_edit == "add")
    {
        m_addPasswordLine->setText(*_password);
    }

    else
    {
        m_editPasswordLine->setText(*_password);
    }
}

void MainWindow::slt_writeRecords()
{
    emit sgn_writeOneFile(this->message);
}

void MainWindow::slt_showLastAddedRecord(const QString &resource_, const QString &login_, const QString &password_)
{
    this->m_rightScreenLabel->setText("Resource: " + resource_ + "\nLogin: " + login_ + "\nPassword: " + password_);
}

void MainWindow::slt_getInfoToShowLastAddedRecord()
{
    emit sgn_showLastAddedRecord();
}

void MainWindow::slt_findRecord()
{
    emit sgn_findRecord(this->m_editByLine->text(), this->message);
}

void MainWindow::slt_getDataOfFoundRecord(QString &resource_, QString &login_, QString &password_, QString &message_, bool searchResults)
{
    if (searchResults)
    {
        this->m_editResourceLine->setText(resource_);
        this->m_editLoginLine->setText(login_);
        this->m_editPasswordLine->setText(password_);
        this->m_messageLabel->setText(message_);
    }

    else
    {
        this->m_editResourceLine->clear();
        this->m_editLoginLine->clear();
        this->m_editPasswordLine->clear();
        this->m_messageLabel->setText(message_);
    }
}

void MainWindow::slt_editRecord()
{
    QString thisResource = m_editResourceLine->text();
    QString thisLogin = m_editLoginLine->text();
    QString thisPassword = m_editPasswordLine->text();
    emit sgn_editRecord(_logic.getRecordFinder()->getFoundRecord(), thisResource,
                                            thisLogin, thisPassword, this->message);
}

void MainWindow::slt_getEditedRecord(bool result, QString &resource_, QString &login_, QString &password_)
{
    m_messageLabel->setText(message);
    if (!result)
    {
        m_editResourceLine->clear();
        m_editLoginLine->clear();
        m_editPasswordLine->clear();
        return;
    }

    m_rightScreenLabel->setText("Resource: " + resource_ + "\nLogin: " + login_ + "\nPassword: " + password_);
    return;
}

void MainWindow::slt_askForInfoToShowAllRecords()
{
    emit sgn_askForInfoToShowAllRecords();
}

void MainWindow::slt_showAllRecords(QString &resource_, QString &login_, QString &password_)
{
    QString temp = m_rightScreenLabel->text();
    temp.append("Resource: " + resource_ + "\nLogin: " + login_ + "\nPassword: " + password_ + "\n\n");
    m_rightScreenLabel->setText(temp);
}
