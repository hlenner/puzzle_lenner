#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include "puzzle_solver.h"
#include "pmminlist.h"
#include <vector>

using namespace std;

PuzzleSolver::PuzzleSolver(const Board &b) : b_(b) {
//    b_=b;
    expansions_=0;
    numSolutions=-1;
}
PuzzleSolver::~PuzzleSolver()
{

}
int PuzzleSolver::getNumExpansions()
{
    return expansions_;
}

void PuzzleSolver::printClosedSet(BoardSet &cl)
{
  cout << "Closed list: " << endl;
  for(BoardSet::iterator it=cl.begin(); it!=cl.end(); ++it){
    cout << **it << endl;
  }
}
int PuzzleSolver::run(PuzzleHeuristic *ph)
{
    expansions_=0;
//PuzzleMove *start = new PuzzleMove(b_);
    PMMinList openlist;
    BoardSet closedlist;
    vector<PuzzleMove*> garbage;

    Board *myb = new Board(b_);
    closedlist.insert(myb);

    //printClosedSet(closedlist);
    openlist.push(new PuzzleMove(b_));
    //cout << "one" << endl;
//PuzzleMove *move = start;
//move->h_ = ph->compute(move->b_->getTiles(), move->b_->getSize());
    PuzzleMove *move;
    while(!openlist.empty()) {
        move = openlist.top();
        move->h_ = ph->compute(move->b_->getTiles(), move->b_->getSize());

        garbage.push_back(move);
        closedlist.insert(move->b_);
        openlist.pop();
        if (move->b_->solved()) {
          
            PuzzleMove * parent = move;
            while (parent->prev_)
            {	
                solution.push_back(parent->tileMove_);
                parent= parent->prev_;
            }
            cout << "Try this sequence: " ;
            for (int i=solution.size()-1; i>=0; i--) {
                cout << solution[i] << " ";
            }
            cout << "" <<endl;
            cout << "(Expansions  = " << expansions_ << " )" << endl;
            numSolutions= solution.size()-1;
            return numSolutions;
          
        }
        else {
            map<int, Board*> tempmap= move->b_->potentialMoves();
            for(map<int, Board*>::iterator it = tempmap.begin(); it != tempmap.end(); ++it) {
                if (closedlist.find(it->second) == closedlist.end()) {
                    PuzzleMove *s = new PuzzleMove(it->first, it->second, move);
                    s->h_ = ph->compute(it->second->getTiles(), it->second->getSize());
                    closedlist.insert(s->b_);
                    openlist.push(s);
                    expansions_++;
                }   
            }
        }  
    }
    garbage.clear();
    cout << solution.size() << endl;
    return solution.size();
}
