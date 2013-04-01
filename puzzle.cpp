#include <iostream>
#include <cstdlib>
#include <deque>
#include "board.h"
#include "puzzle_heur.h"
#include "puzzle_solver.h"
#include <math.h>

using namespace std;

int main(int argc, char *argv[])
{
  if(argc < 3){
    cerr << "Usage: ./puzzle size initMoves seed" << endl;
    return 1;
  }
  
  int size, initMoves, seed;

  size = atoi(argv[1]);
  initMoves = atoi(argv[2]);
  seed = atoi(argv[3]);

  Board b(size,initMoves,seed);
  cout << b;

  int y;

  ManhattanHeuristic *Manhattan = new ManhattanHeuristic();
  OutOfPlaceHeuristic *Place = new OutOfPlaceHeuristic();
  
  cout << "Manhattan: " << Manhattan->compute(b.getTiles(), b.getSize()) << endl;
  cout << "Out Of Place: " << Place->compute(b.getTiles(), b.getSize()) << endl;
  while (!b.solved()){
  cout << "Enter tile number to move or -1 for a cheat:  " << endl;
  cin >> y;
  int x;
    if (y == -1){
    
    cout << "type 1 for Manhattan, 2 for Out-of-Place Heuristic" << endl;
    cin >> x;
    }
    if (x==1){
    	PuzzleHeuristic *heur = new ManhattanHeuristic();
    	PuzzleSolver p(b);
    	p.run(heur);
    	cout << "Manhattan: " << heur->compute(b.getTiles(), b.getSize()) << endl;
    }
    else if (x==2){
        PuzzleHeuristic *oop = new OutOfPlaceHeuristic();
        PuzzleSolver p(b);
    	p.run(oop);
    	cout << "OutOfPlace: " << oop->compute(b.getTiles(), b.getSize()) << endl;
    }
  
  else{
  b.move(y);
   }
  }
   return 0;
}
