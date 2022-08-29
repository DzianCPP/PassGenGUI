#include "mainwindow.h"

#include <QApplication>
#include <QList>
#include "record.h"
#include "recordcreator.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QList<Record> recordList;
    srand(static_cast<unsigned int>(time(NULL)));
    MainWindow w;
    w.show();
    return a.exec();
}
