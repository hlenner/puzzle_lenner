#include "mainwindow.h"
#include <stdlib.h>
#include <iostream>
#include <vector>


void MainWindow::handleButton(){

}
void MainWindow::newGameClicked(){
	//board->newGame();
}
MainWindow::MainWindow()  {
    //counter=0;
    //We need a scene and a view to do graphics in QT
    scene = new QGraphicsScene();
    cout << "qscene" << endl;
    view = new QGraphicsView( scene );
 
  
    //This sets the size of the window and gives it a title.
    view->setFixedSize( WINDOW_MAX_X*2, WINDOW_MAX_Y*2 );
    view->setWindowTitle( "Graphical 8-Tile Puzzle");

    //This is how we do animation. We use a timer with an interval of 5 milliseconds
    //We connect the signal from the timer - the timeout() function to a function
    //of our own - called handleTimer - which is in this same MainWindow class
    //board = new Board();
    size = new QTextEdit(view);
    size->setText("Enter Size");
    size->setGeometry(25, 50, 100, 40);
    seed = new QTextEdit(view);
    cout << "qview" << endl;
    seed->setText("Enter Seed");
    seed->setGeometry(25, 100, 100, 40);
    moves = new QTextEdit(view);
    moves->setText("Enter Start Moves");
    moves->setGeometry(25, 150, 100, 40);
    quit = new QPushButton(view);
    quit->setText("Quit");
    quit->setGeometry(225, 450, 60, 40);
    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
    button = new QPushButton(view);
    button->setText("Start Game");
    button->setGeometry(225, 400, 100, 40);
     connect(button, SIGNAL(clicked()), this, SLOT(newGameClicked()));
    QRadioButton *heur= new QRadioButton(view);
    QRadioButton *oop = new QRadioButton(view);
    heur->setText("Heuristic search");
    heur->setGeometry(10, 400, 140, 40);
    oop->setText("Out of Place search");
    oop->setGeometry(10, 430, 160, 40);
    
}
void MainWindow::show() {
    //This is only called once by main. Timers don't start working until
    //we call start
    //This is how we get our view displayed.
    view->show();
}
MainWindow::~MainWindow()
{
    //timer->stop();
    //delete timer;
    delete item;
    delete scene;
    delete view;
}
