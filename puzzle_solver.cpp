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
expansions_=0;
//PuzzleMove *start = new PuzzleMove(b_);
PMMinList openlist;
BoardSet closedlist;
vector<PuzzleMove*> garbage;

closedlist.insert(new Board(b_));
openlist.push(new PuzzleMove(b_));
cout << "one" << endl;
//PuzzleMove *move = start;
//move->h_ = ph->compute(move->b_->getTiles(), move->b_->getSize());
PuzzleMove *move;
while(!openlist.empty()){
//cout << "Starting open list" << endl;
move = openlist.top();
move->h_ = ph->compute(move->b_->getTiles(), move->b_->getSize());

cout << "Size after popping: " << openlist.size() << endl;
garbage.push_back(move);
closedlist.insert(move->b_);
openlist.pop();
if (move->b_->solved()){
	cout << "Three" << endl;
	cout << "Expansions" << expansions_ << endl;
	PuzzleMove * parent = move;
	while (parent->prev_)
	{
		//numSolutions++;
		//cout <<"hihi" << endl;
		solution.push_back((move->prev_)->tileMove_);
		parent= move->prev_;	
	}
	cout << "Try this sequence: " << endl;
	for (int i=0; i<solution.size(); i++){
		cout << solution[i] << endl;
	}
	return numSolutions;
	//cout << "Expansions: " << endl;
}
else{
cout << "in else statement" << endl;
map<int, Board*> tempmap= move->b_->potentialMoves();
//cout << "map size: " <<pMoves.size() << endl;
for(map<int, Board*>::iterator it = tempmap.begin(); it != tempmap.end(); ++it){
	cout << "it1: "<<endl;
	cout << *(it->second) << endl;
	//cout << "it1" << endl;
	bool check=true;
		for (std::set<Board*, BoardLessThan>::iterator it2 = closedlist.begin(); it2!=closedlist.end(); ++it2){
		cout << "it2: " << endl;
		cout <<**it2 << endl;
		
		if ((**it2 == *(it->second))){
			cout << "hi" << endl;
			check = false;
			//break;
			}
		if (check != false){
			cout << "false:" << endl;
			PuzzleMove *pm = new PuzzleMove(it->first, it->second, move);
			pm->h_= ph->compute(it->second->getTiles(), it->second->getSize());
			openlist.push(pm);
			closedlist.insert(it2, it->second);
			expansions_++;
		}
// cout <<"expansions: "<< expansions_ << endl;
}
}

	/*if (closedlist.find(it->second) == closedlist.end()){
		PuzzleMove *s = new PuzzleMove(it->first, it->second, move);
		s->h_ = ph->compute(it->second->getTiles(), it->second->getSize());
		cout << "s->h: "<< s->h_ << endl;
		closedlist.insert(s->b_);
		openlist.push(s);
		
		//cout <<"Open list size: " << openlist.size() << endl;
		expansions_++;
		}
	}*/
   }
   }

	garbage.clear();
	cout << solution.size() << endl;
	return solution.size();
}
