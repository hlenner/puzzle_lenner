#include "mainwindow.h"
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <QFormLayout>
#include "puzzle_heur.h"
#include "puzzle_solver.h"
#include <QIntValidator>

/** A mainwindow class to implement qt for the PA4 puzzle game
creates formlayouts, buttons, lines used for implementation, 
performs heuristics, a* algorithm

@author Haley Lenner
*/

/**method for getting the board, number, and size to perform moveTile.

@pre MousePressEvent refers to it
@post
@param number on the tile, the pointer to that tile
@return none
*/
void MainWindow::MainWindowmoveTile(int number, GUITile *tile) {

    int s = size->text().toInt();
	tile->moveTile(b, number,s);
    //cout <<"number: " <<number << endl;
}
/**method for performing the AStar search algorithm.

@pre out of place or heuristic radio button must be selected, and cheat must be clicked
@post computes and prints out sequence of tiles to move in order to win
@param none
@return none
*/

void MainWindow:: AStar() {
    if (heur->isChecked()) {
        error->setText(" ");
        PuzzleHeuristic *heurs = new ManhattanHeuristic();
        PuzzleSolver p(*b);
        p.run(heurs);
        Mylist<int> *temp=p.getSolutions();
        sequence->setModel(hint);
        for (int i=temp->size()-1; i>=0; i--) {
            //cout << "temp: "<<temp->at(i)<<endl;
            QString setnum;
            setnum.setNum(temp->at(i));
            QStandardItem *q = new QStandardItem(setnum);
            hint->appendRow(q);
        }
    }
    if (oop->isChecked()) {
        error->setText(" ");
        PuzzleHeuristic *oops = new OutOfPlaceHeuristic();
        PuzzleSolver p(*b);
        p.run(oops);
        Mylist<int> *temp=p.getSolutions();
        sequence->setModel(hint);
        for (int i=temp->size()-1; i>=0; i--) {
            QString setnum;
            setnum.setNum(temp->at(i));
            QStandardItem *q = new QStandardItem(setnum);
            hint->appendRow(q);
        }
    }
    else {
        error->show();
    }
}
/**method for getting the board, number, and size to perform moveTile.

@pre start button must be clicked because it is connected to the start button in constructor
@post takes in user input to set up board and gives relevant errors if there are any
@param none
@return none
*/
void MainWindow:: newGameClicked() {
scene->clear();
    int x = size->text().toInt();
    if (x!= 9 && x!=16) {
        error->setText("Please enter a valid size");
    }
    else {
        error->setText("");
        int y = moves->text().toInt();
        int z = seed->text().toInt();
        if (z>=0) {
            if (y>=0) {
                b = new Board(x,y,z);
                if (heur->isChecked()) {
                    PuzzleHeuristic *heurs = new ManhattanHeuristic();
                    PuzzleSolver p(*b);
                    p.run(heurs);
                }
                else if (oop->isChecked()) {
                    error->clear();
                    PuzzleHeuristic *oops = new OutOfPlaceHeuristic();
                    PuzzleSolver p(*b);
                    p.run(oops);
                }
                else {
                    error->setText("Please select a heuristic type if you want to cheat");
                }
                int dim = sqrt(x);
                int *f = b->getTiles();
                tiles = new Mylist<GUITile*>();
                for (int i=0; i<x; i++) {
                    if (f[i]!=0) {
                        GUITile *tile = new GUITile((50*(i%dim)),(50*(i/dim)),50,50,f[i],this, scene);
                        scene->addItem(tile);
                        tiles->push_back(tile);

                    }
                    else {
                        GUITile *tile = new GUITile((50*(i%dim)),(50*(i/dim)),50,50,f[i],this, scene);

                        tiles->push_back(tile);
                    }
                }
            }
            else {
                error->setText("Please enter a valid number of initial moves");
            }
        }
        else {
            error->setText("Please enter a valid seed");
        }
        }
    
}
/**constructor for creating necessary objects going in the view of the GUI.

@pre must have a main class creating mainwindow object to perform all actions
@post creates buttons, timer, layouts, lineedits, and sets the geometry/texts
@param none
@return none
*/
MainWindow::MainWindow() {
    counter=0;
    //We need a scene and a view to do graphics in QT
    scene = new QGraphicsScene();
    //cout << "qscene" << endl;
    view = new QGraphicsView(scene);
    //This sets the size of the window and gives it a title.
    view->setFixedSize( WINDOW_MAX_X*2.5, WINDOW_MAX_Y*2.5 );
    view->setWindowTitle( "Graphical 8-Tile Puzzle");

    //This is how we do animation. We use a timer with an interval of 5 milliseconds
    //We connect the signal from the timer - the timeout() function to a function
    //of our own - called handleTimer - which is in this same MainWindow class
    timer = new QTimer(this);
    timer->setInterval(5);
    connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));
    cheat = new QPushButton(view);
    cheat->setText("Cheat");
    cheat->setGeometry(10, 450, 75, 30);
    connect(cheat, SIGNAL(clicked()), this, SLOT(AStar()));

    size = new QLineEdit(view);
    seed = new QLineEdit(view);
    seed->setValidator(new QIntValidator(0, 10000, this));
    moves = new QLineEdit(view);
    moves->setValidator(new QIntValidator(0, 10000, this));
    error = new QLineEdit(view);
    quit = new QPushButton(view);
    sequence = new QListView(view);
    sequence->setGeometry(100, 450, 200, 50);
    quit->setText("Quit");
    quit->setGeometry(425, 140, 60, 30);
    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
    button = new QPushButton(view);
    button->setText("Start Game");
    button->setGeometry(325, 140, 90, 30);
    connect(button, SIGNAL(clicked()), this, SLOT(newGameClicked()));
    heur= new QRadioButton(view);
    hint = new QStandardItemModel();
    oop = new QRadioButton(view);
    heur->setText("Heuristic search");
    heur->setGeometry(10, 140, 140, 40);
    oop->setText("Out of Place search");
    oop->setGeometry(160, 140, 160, 40);
    QRect rect(0, 0, 0, 0);
    QFormLayout *formlayout = new QFormLayout(view);
    formlayout->setGeometry(rect);
    formlayout->addRow(tr("Enter size: "), size);
    formlayout->addRow(tr("Enter seed: "), seed);
    formlayout->addRow(tr("Enter initial moves: "), moves);
    formlayout->addRow(tr("Console"), error);
    QMessageBox *win = new QMessageBox();

}
/**method for showing everything within the view.

@pre none
@post displays everything in GUI
@param none
@return none
*/
void MainWindow::show() {
    //This is only called once by main. Timers don't start working until
    //we call start
    //This is how we get our view displayed.
    view->show();
}
/**destructor to delete appropriate values

@pre none, internally called
@post scene and view memory freed
@param none
@return none
*/
MainWindow::~MainWindow()
{
    //timer->stop();
    //delete timer;
    delete scene;
    delete view;
}
