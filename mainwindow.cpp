#include "mainwindow.h"
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <QFormLayout>
#include "puzzle_heur.h"
#include "puzzle_solver.h"

void MainWindow::handleTimer(){
counter++;
    if (timer->isActive()==true){
    	
    	timer->stop();
    	//button->setText("Start");
    }
    else{
    	
    }
}
void MainWindow::MainWindowmoveTile(int number, GUITile *tile){

	int s = size->text().toInt();
	
	tile->moveTile(b, number,s);
	cout <<"number: " <<number << endl;
}
void MainWindow:: AStar(){
	if (heur->isChecked()){
		error->setText(" ");
		PuzzleHeuristic *heurs = new ManhattanHeuristic();
     		PuzzleSolver p(*b);
     		p.run(heurs);
     		Mylist<int> *temp=p.getSolutions();
     		sequence->setModel(hint);
     		for (int i=temp->size()-1; i>=0; i--){
     		//cout << "temp: "<<temp->at(i)<<endl;
     		QString setnum;
     		setnum.setNum(temp->at(i));
     		QStandardItem *q = new QStandardItem(setnum);
     		hint->appendRow(q);
     		}
	}	
	if (oop->isChecked()){
		error->setText(" ");
		PuzzleHeuristic *oops = new OutOfPlaceHeuristic();
     		PuzzleSolver p(*b);
     		p.run(oops);
     		Mylist<int> *temp=p.getSolutions();
     		sequence->setModel(hint);
     		for (int i=temp->size()-1; i>=0; i--){
     		//cout << "temp: "<<temp->at(i)<<endl;
     		QString setnum;
     		setnum.setNum(temp->at(i));
     		QStandardItem *q = new QStandardItem(setnum);
     		hint->appendRow(q);
		}
	}
	else{
		//error->setText("Please select a heuristic");
		error->show();
	}
}
void MainWindow:: newGameClicked(){
	//bool good;
	
	int x = size->text().toInt();
	if (x!= 9 && x!=16){
		error->setText("Please enter a valid size");
	}
	else{
	error->setText("");
	int y = moves->text().toInt();
	int z = seed->text().toInt();
	b = new Board(x,y,z);
	if (heur->isChecked()){
		PuzzleHeuristic *heurs = new ManhattanHeuristic();
     		PuzzleSolver p(*b);
     		p.run(heurs);
	}	
	else if (oop->isChecked()){
		error->clear();
		PuzzleHeuristic *oops = new OutOfPlaceHeuristic();
     		PuzzleSolver p(*b);
     		p.run(oops);
	}
	else{
		error->setText("Please select a heuristic if you want to cheat");
	}
	int dim = sqrt(x);
	int *f = b->getTiles();
	tiles = new Mylist<GUITile*>();
	for (int i=0; i<x; i++){
	if (f[i]!=0){
    		GUITile *tile = new GUITile((50*(i%dim)),(50*(i/dim)),50,50,f[i],this, scene);
    		scene->addItem(tile);
    		tiles->push_back(tile);
    		
    		}
    	else{
    	GUITile *tile = new GUITile((50*(i%dim)),(50*(i/dim)),50,50,f[i],this, scene);
    		
    		tiles->push_back(tile);	
    	}
    	}
    }
}
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
    moves = new QLineEdit(view);  
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
    formlayout->addRow(tr("Error"), error);
  
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
    delete scene;
    delete view;
}
