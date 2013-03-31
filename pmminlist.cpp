#include "puzzle_move.h"
#include "pmminlist.h"

/**
 * Default Constructor
 */
PMMinList::PMMinList() : slist_()
{

}

/**
 * Destructor
 */
PMMinList::~PMMinList()
{

}

/**
 * Adds the value val to the internal list in sorted
 * order from smallest to largest (if 
 * @param val Value to add to the sorted PuzzleMove list
 * @return nothing
 */
void PMMinList::push(PuzzleMove* pm)
{
  bool isFound = false;
  std::list<PuzzleMove*>::iterator it = slist_.begin();
  if (slist_.empty()){
  	cout << "empty closed list" << endl;
  	slist_.insert(it, pm);
  }
  else{
  for (it = slist_.begin();it!=slist_.end(); ++it){
  if ((((*it)->g_) + ((*it)->h_)) > (pm->g_ + pm->h_)){
  	slist_.insert(it, pm);
 	}
  }
  if ((((*it)->g_) + ((*it)->h_)) == (pm->g_ + pm->h_)){
  	++it;
  	slist_.insert(it, pm);
  }
  if (!isFound){
  	slist_.insert(slist_.end(), pm);
        }
  }
  //---- Add your implementation to iterate through the list
  //---- to find the correct location to insert pm and then
  //---- use the insert() method of std::List to insert it
  //---- See http://www.cplusplus.com/reference/list/list/insert/
}

/**
 * Adds the value val to the internal list in sorted
 * order from smallest to largest
 * @param val Value to add to the sorted PuzzleMove list
 * @return nothing
 */
void PMMinList::pop()
{
  slist_.pop_front();
}

/**
 * Adds the value val to the internal list in sorted
 * order from smallest to largest
 * @param val Value to add to the sorted PuzzleMove list
 * @return reference to the minimum-scored PuzzleMove*
 */
PuzzleMove* PMMinList::top()
{
  return slist_.front();
}

