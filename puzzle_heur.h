#ifndef PUZZLE_HEUR_H
#define PUZZLE_HEUR_H
#include <cmath>

using namespace std;
class PuzzleHeuristic
{
 public:
  virtual int compute(int *tiles, int size) = 0;
};


// Define Heuristic Classes here
class ManhattanHeuristic: public PuzzleHeuristic
{
 public:
 int compute(int *tiles, int size);
 	
};
class OutOfPlaceHeuristic: public PuzzleHeuristic
{
 public:
 int compute(int *tiles, int size);
};
#endif
