#include "puzzle_heur.h"
#include <cmath>
#include <iostream>


int ManhattanHeuristic:: compute(int *tiles, int size)
{
 	int h_ = 0;
 	int index;
 	int dim=sqrt(size);
  for (int i=0; i<size; i++){
  	for (int j=0; j<size; j++){
  		if (tiles[i]==0){
  			
  		}
  		else if (tiles[i]==j){
  			index=j;
  			int currentx=index%dim;
  			int currenty=index/dim;
  			int targetx=i%dim;
  			int targety=i/dim;
  			h_=h_+ abs(currentx-targetx)+ abs(currenty-targety);
  			}
  		}
  	}
  	return h_;
} 
int OutOfPlaceHeuristic:: compute(int *tiles, int size){
  	int number=0;
	for (int i=0; i<size; i++){
	 if (tiles[i]!=i && tiles[i] !=0){
	
	 	number++;
	 }
	}
	return number;
}
 
