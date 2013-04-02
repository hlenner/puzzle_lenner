#include <iostream>
#include <cstdlib>
#include <deque>
#include "board.h"
#include "puzzle_heur.h"
#include "puzzle_solver.h"
#include <math.h>
/**
@mainpage Puzzle Implementation

*/
using namespace std;

int main(int argc, char *argv[])
{
/**
tests the number of arguments
*/
  if(argc < 3){
    cerr << "Usage: ./puzzle size initMoves seed" << endl;
    return 1;
  }
  
  int size, initMoves, seed;

  size = atoi(argv[1]);
  initMoves = atoi(argv[2]);
  seed = atoi(argv[3]);

  Board b(size,initMoves,seed);


  int y;

  //ManhattanHeuristic *Manhattan = new ManhattanHeuristic();
  //OutOfPlaceHeuristic *Place = new OutOfPlaceHeuristic();
  
  //cout << "Manhattan: " << Manhattan->compute(b.getTiles(), b.getSize()) << endl;
 // cout << "Out Of Place: " << Place->compute(b.getTiles(), b.getSize()) << endl;
  while (!b.solved()){
  cout << b;
  cout << endl;
  cout << " Enter tile number to move or -1 for a cheat:  " ;

  cin >> y;
cout << endl;
    if (y == -1){
    	/*PuzzleHeuristic *heur = new ManhattanHeuristic();
    	PuzzleSolver p(b);
    	p.run(heur);
    	//cout << "Manhattan: " << heur->compute(b.getTiles(), b.getSize()) << endl;*/
    	PuzzleHeuristic *oop = new OutOfPlaceHeuristic();
    	PuzzleSolver p(b);
    	p.run(oop);
    }
  
  else{
 	 b.move(y);
   }
   }
   cout << b;
   cout << "you win!" << endl;

   return 0;
}
