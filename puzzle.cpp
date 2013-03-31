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

  //**** Implement the gameplay here
  int y;
 
  while (b.solved()==false){
  //ManhattanHeuristic *Manhattan = new ManhattanHeuristic();
  //OutOfPlaceHeuristic *Place = new OutOfPlaceHeuristic();
  
  //cout << "Manhattan: " << Manhattan->compute(b.getTiles(), b.getSize()) << endl;
  //cout << "Out Of Place: " << Place->compute(b.getTiles(), b.getSize()) << endl;
  
  cout << "Enter tile number to move or -1 for a cheat:  " << endl;
  cin >> y;
    if (y == -1){
 
  }
  else{
  b.move(y);
  }
cout << b;
}

  return 0;
}
