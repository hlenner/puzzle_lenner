#include <QtGui/QApplication>
#include "mainwindow.h"
#include "iostream"

int main(int argc, char *argv[])
{
    cout << "hi" << endl;
    QApplication a(argc, argv);
    cout << "1" << endl;
    MainWindow w;
    cout << "2" << endl;
    w.show();
    cout << "3" << endl;
    return a.exec();
}
