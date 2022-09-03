#include "mainwindow.h"

#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    srand(static_cast<unsigned int>(time(NULL)));
    QFile styleFile(":/style.css");
    styleFile.open(QIODeviceBase::ReadOnly);
    a.setStyleSheet(styleFile.readAll());
    a.setWindowIcon(QIcon("D:\\QtProjects\\PassGenGUI\\ico.png"));
    MainWindow w;
    w.show();
    return a.exec();
}
