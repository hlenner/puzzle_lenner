#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#include "board.h"
using namespace std;


/** Init a board of given size and scramble it with numInitMoves 
 * by moving the space tile with a randomly chosen direction N, W, S, E
 * some of which may be invalid, in which case we skip that move 
 * 
 *  @param size Number of tiles for the game.  \
 *      Should be a perfect square (4, 16, 25)
 *  @param numInitMoves Number of tile moves to attempt to scramble the board
 *  @param seed Use to seed the random number generator (srand) 
 */
Board::Board(int size, int numInitMoves, int seed)
{
  size_ = size;
  tiles_ = new int[size_];
  int dim = static_cast<int>(sqrt(size_));
  srand(seed);
  for(int i=0; i < size_; i++){
    tiles_[i] = i;
  }
  int blankLoc = 0;
  for(int i=0; i < numInitMoves; i++){
    int r = rand()%4;
    int randNeighbor = -1;
    if(r == 0){
      int n = blankLoc - dim;
      if(n >= 0){
	randNeighbor = n;
      }
    }
    else if(r == 1){
      int w = blankLoc - 1;
      if(blankLoc % dim != 0){
	randNeighbor = w;
      }
    }
    else if(r == 2){
      int s = blankLoc + dim;
      if(s  < size_){
	randNeighbor = s;
      }
    }
    else {
      int e = blankLoc + 1;
      if(blankLoc % dim != dim-1){
	randNeighbor = e;
      }
    }
    if(randNeighbor > -1){
      tiles_[blankLoc] = tiles_[randNeighbor];
      tiles_[randNeighbor] = 0;
      blankLoc = randNeighbor;
    }
  }
}


/** Default constructor. provide documentation here */
Board::Board()
{
  size_=9;
  tiles_ = new int[size_];
  int dim = static_cast<int>(sqrt(size_));
  srand(100);
  for(int i=0; i < size_; i++){
    tiles_[i] = i;
  }
  int blankLoc = 0;
  for(int i=0; i < 100; i++){
    int r = rand()%4;
    int randNeighbor = -1;
    if(r == 0){
      int n = blankLoc - dim;
      if(n >= 0){
	randNeighbor = n;
      }
    }
    else if(r == 1){
      int w = blankLoc - 1;
      if(blankLoc % dim != 0){
	randNeighbor = w;
      }
    }
    else if(r == 2){
      int s = blankLoc + dim;
      if(s  < size_){
	randNeighbor = s;
      }
    }
    else {
      int e = blankLoc + 1;
      if(blankLoc % dim != dim-1){
	randNeighbor = e;
      }
    }
    if(randNeighbor > -1){
      tiles_[blankLoc] = tiles_[randNeighbor];
      tiles_[randNeighbor] = 0;
      blankLoc = randNeighbor;
    }
  }
}
Board::Board(const Board &b)
{
	size_= b.size_;
	tiles_=b.tiles_;
}
Board::Board(int *tiles, int size)
{
	size_ =size;
	tiles_ = new int[size];
	//cout << "Size " << size << endl;
	for (int i=0; i<size; i++){
		tiles_[i]=tiles[i];
	}	
}
/** Default destructor. provide documentation here */
Board::~Board()
{

  /*
   * IMPLEMENT ME
  */
}

bool Board::operator<(const Board& rhs) const
{
  if(size_ < rhs.size_){
    return true;
  }

  for(int i=0; i < size_; i++){
    if(tiles_[i] < rhs.tiles_[i]){
       //val = true;
       //break;
  
     }
     else if(tiles_[i] > rhs.tiles_[i]){
       //break;
       return false;
     }
  }
  return true;
}
std::ostream& operator<<(std::ostream &os, const Board &b){	
	
	int x=b.size_;
	int y=sqrt(x);
	//os << "Size: " << x << endl;
	//os << "Columns: " << y << endl;
	os << setw(3) << b.tiles_[0] ;
	for (int i=1; i<b.size_; i++){
		os << setw(3) <<b.tiles_[i] ;
		if ((i+1)%y==0){
			os << endl;
			}
	}
	return os;
}
bool Board::operator!=(const Board& rhs) const{
	{
  if(size_ < rhs.size_){
    return true;
  }
  bool val = true;
  for(int i=0; i < size_; i++){
    if(tiles_[i] == rhs.tiles_[i]){
       //val = true;
       //break;
       val= false;
     }
     else{
     	val=true;
     	break;
     }
  }
  return val;
}
}

bool Board:: operator==(const Board& rhs) const{
	{
  if(size_ < rhs.size_){
    return false;
  }
  bool val = true;
  for(int i=0; i < size_; i++){
    if(tiles_[i] == rhs.tiles_[i]){
       //val = true;
       //break;
     }
     else{
     	val=false;
     	break;
     }
  }
  return val;
}
}
bool Board::solved(){
	for(int i=0; i<size_; i++){
		if (tiles_[i]==i){
		}
	else{
		return false;
		}
	}
	cout << "You win!" << endl;
	return true;
}
int* Board::getTiles(){
	return tiles_;
}
int Board::getSize(){

	return size_;
}
void Board::move(int tile)
{
int index;
int cols=sqrt(size_);
  for (int i=0;i<size_; i++){
  	if (tiles_[i]==tile){
  		index = i;
  		//cout << "index= " <<index << endl;
  		break;
  	}
  } 
  if ((index-cols)>=0 && tiles_[index-cols]==0 ){
  		tiles_[index-cols]=tile;
  		tiles_[index]=0;
  }
 if (index % cols != 0 && tiles_[index-1] ==0){
  		tiles_[index-1]=tile;
  		tiles_[index]=0;
  }
  if((index+cols)<=(cols*cols-1) && tiles_[index+cols]==0){

  		tiles_[index+cols]=tile;
  		tiles_[index]=0;

  }
  if ((index+1) % cols !=0 && tiles_[index+1] ==0){

  		tiles_[index+1]=tile;
  		tiles_[index]=0;
  		}
  
}
std::map<int, Board*> Board:: potentialMoves()
{
    map<int, Board*> mymap;
    int dim = sqrt(size_);
    int blankLoc;
    
    for (int i=0; i<size_; i++){
    	if (tiles_[i]==0){
    		blankLoc =i;
    	}
    }
    if (blankLoc-dim >= 0)//north
    {
    	Board *board = new Board(tiles_, size_);
    	board->move(blankLoc-dim);
    	mymap[tiles_[blankLoc-dim]]=board;
    }
    if (blankLoc+dim < size_)//south
    {
    	Board *board = new Board(tiles_, size_);
    	board->move(blankLoc+dim);
    	mymap[tiles_[blankLoc+dim]]=board;
    }
    if (blankLoc % dim != 0)//east
    {
    	Board *board = new Board(tiles_, size_);
    	board->move(blankLoc-1);
    	mymap[tiles_[blankLoc-1]]=board;
    }
    if (blankLoc % dim != dim-1 )//west
    {
    	Board *board = new Board(tiles_, size_);
    	board->move(blankLoc+1);
    	mymap[tiles_[blankLoc+1]]=board;
    }
 return mymap;
}
