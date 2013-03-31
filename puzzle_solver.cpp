#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include "puzzle_solver.h"
#include "pmminlist.h"
#include <vector>

using namespace std;

PuzzleSolver::PuzzleSolver(const Board &b){
	b_=b;
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

int PuzzleSolver::run(PuzzleHeuristic *ph)
{

PuzzleMove *move = new PuzzleMove(b_);
PMMinList openlist;
BoardSet closedlist;
vector<PuzzleMove*> garbage;

BoardSet:: iterator it2 = closedlist.begin();

closedlist.insert(it2, &b_);
openlist.push(move);
cout << "one" << endl;
while(!openlist.empty() && b_.solved()!=true){
move = openlist.top();
cout << "onne" << endl;
move->h_ = ph->compute(move->b_->getTiles(), move->b_->getSize());
openlist.pop();
garbage.push_back(move);
//cout << "two" << endl;
if (move->h_==0){
cout << "Three" << endl;
PuzzleMove * parent = move;
	while (parent->prev_)
	{
		numSolutions++;
		solution.push_back((move->prev_)->tileMove_);
		parent= move->prev_;	
	}
	cout << "Try this sequence: " << endl;
	for (int i=0; i<solution.size(); i++){
		cout << solution[i] << endl;
	}
	//cout << "Expansions: " << endl;
}
else{
//cout << "four" << endl;
map<int, Board*> tempmap = ((move->b_)->potentialMoves());
//cout << "five" << endl;
map<int, Board*>:: iterator it;
//cout << "hello" << endl;
for (it = tempmap.begin(); it!=tempmap.end(); ++it){
cout << "it1" << endl;
	for (it2 = closedlist.begin(); it2!=closedlist.end(); ++it2){
	//cout << "it2" << endl;
		if (!(*it2 == it->second)){
		//cout << "no match" << endl;
			  PuzzleMove *pm = new PuzzleMove(it->first, it->second, move);
			  pm->h_= ph->compute(it->second->getTiles(), it->second->getSize());
			  openlist.push(pm);
			  closedlist.insert(it2, it->second);
			  expansions_++;
			 // cout <<"expansions: "<< expansions_ << endl;
				}
			}
		}
	}
}
while (!garbage.empty()){
	delete garbage.back();
	garbage.pop_back();
}
return numSolutions;
}
