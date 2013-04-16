#include <QtGui/QApplication>
#include "mainwindow.h"
#include "iostream"
/** @mainpage CSCI 102 PA4 
@section qtpuzzle building from PA3, use qt to implement a GUI for the puzzle game
@section requirements move tiles to locations, 
*/

int main(int argc, char *argv[])
{
    
    QApplication a(argc, argv);/**creating qt application*/
    MainWindow w;/**creates main window */
    w.show();/**shows the main window */
    return a.exec();/**@returns when the application quits*/
}
