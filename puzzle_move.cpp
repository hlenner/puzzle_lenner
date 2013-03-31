#include "puzzle_move.h"

PuzzleMove::PuzzleMove(Board &b)
{
	b_=new Board(b.getTiles(), b.getSize());
	prev_=NULL;
	tileMove_=-1;
	g_=0;
}
PuzzleMove::PuzzleMove(int tile, Board *b, PuzzleMove *parent)
{
	b_=new Board(b->getTiles(), b->getSize());
	tileMove_=tile;
	prev_=parent;
	g_=prev_->g_++;
}
PuzzleMove::~PuzzleMove()
{
	delete [] prev_;
	delete [] b_;
}
// Compare to PuzzleMoves based on f distance (needed for priority queue)
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
bool PuzzleMove::operator==(const PuzzleMove& p) const
{
	if( (g_ + h_) == (p.g_ + p.h_) ){
    return true;
  }
  else {
     return false;
  }
}
