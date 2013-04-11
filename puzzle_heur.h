#ifndef PUZZLE_HEUR_H
#define PUZZLE_HEUR_H
#include <cmath>

using namespace std;
/**
*Class to calculate the Manhattan and
Out Of Place heuristic scores of the boards*/

class PuzzleHeuristic
{
 public:
  virtual int compute(int *tiles, int size) = 0;/**virtual function, inherited by Manhattan and Out Of Place Heuristic classes*/
};


// Define Heuristic Classes here
class ManhattanHeuristic: public PuzzleHeuristic/**Manhattan class inheriting from PuzzleHeuristic*/
{
 public:
 int compute(int *tiles, int size);/**compute Manhattan Heuristic of Boards*/
 
};
class OutOfPlaceHeuristic: public PuzzleHeuristic/**Out of Place class inheriting from PuzzleHeuristic*/
{
 public:
 int compute(int *tiles, int size);/**compute Out Of Place Heuristic of Boards*/
};
#endif
