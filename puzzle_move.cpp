#include "puzzle_move.h"
/**Constructor to create the Board
* with the reference of the Board,
* prev_ is null when it is the first Board
* the tileMove is 0 depth(g_) is 0 when
it's the original state of the Board*/
PuzzleMove::PuzzleMove(Board &b)
{
b_=new Board(b.getTiles(), b.getSize());
prev_=NULL;
tileMove_=0;
g_=0;
}
/**
* Constructor to create the Board
* with the given tile and Board,
* tileMove is set to the tile,
* the prev_ is set to parent
* g_ calculated from parent+1, gives the depth
* @param tile being moved, board pointer, and previous board*/
PuzzleMove::PuzzleMove(int tile, Board *b, PuzzleMove *parent)
{
b_=new Board(b->getTiles(), b->getSize());
tileMove_=tile;
prev_=parent;
g_=(parent->g_)+1;
}
/**Destructor to delete the Board
* once it is no longer needed,
* frees the memory */
PuzzleMove::~PuzzleMove()
{
delete b_;
}
/**
* Overloads the < operator so it can
* be used to compare puzzle moves
* @param PuzzleMove& p that is being compared
* @return bool, false if &p depth and heuristic(g+h)
* score is greater or equal to the created instance,
* false if &p depth and heuristic(g+h) score is less than
* the created instance*/
bool PuzzleMove::operator<(const PuzzleMove& p) const
{
  if((g_ + h_) < (p.g_ + p.h_)){
    return true;
  }
  else if((g_ + h_ == p.g_ + p.h_) && (g_ > p.g_)){
    return true;
  }
  else {
    return false;
  }
}
/**
* Overloads the > operator so it can
* be used to compare puzzle moves
* @param PuzzleMove& p that is being compared
* @return bool, true if &p depth and heuristic(g+h) score is greater,
* false if &p depth and heuristic(g+h) score is equal or less than
the created instance*/
bool PuzzleMove::operator>(const PuzzleMove& p) const
{
  if( (g_ + h_) > (p.g_ + p.h_) ){
    return true;
  }
  else if((g_ + h_ == p.g_ + p.h_) && (g_ < p.g_) ){
    return true;
  }
  else {
     return false;
  }
  
}
/**
* Overloads the == operator so it can
* be used to compare puzzle moves
* @param PuzzleMove& p that is being compared
* @return bool, true if they are equal PuzzleMoves,
*(g and h combined values are the same)
*false if they are not equal PuzzleMoves,
*(g and h combined values are not the same)
*/
bool PuzzleMove::operator==(const PuzzleMove& p) const
{
if( (g_ + h_) == (p.g_ + p.h_) ){
    return true;
  }
  else {
     return false;
  }
}
