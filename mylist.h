#ifndef Mylist_H
#define Mylist_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

//template class for mylist
const int DEFAULT_LIST_SIZE=10;

using namespace std;

template <typename T>
class Mylist{

public:
	Mylist();
	~Mylist();
	void push_back(T x);
	int size() const;
	T& at(int loc) const;
	bool remove(T val);
	void print();
	void clearList();
	T& operator[](int lhs);
	//void clear();
private:
	T *items;	
	int _size;
	int capacity;
};

template <typename T>
Mylist<T>::Mylist()
{
	_size=0;
	capacity=DEFAULT_LIST_SIZE;
	items= new T[capacity];
}
template <typename T>
Mylist<T>:: ~Mylist()
{
	//clear();
	delete []items;
}
template <typename T>
void Mylist<T>:: push_back(T x)//this function tests the size of the list and makes sure its big enough before adding the item to the end of it
{
	if (_size==capacity){
		capacity=capacity*2;
		T* moreitems= new T[capacity];
		for (int i = 0; i<_size; i++){
				moreitems[i]=items[i];
			}
			moreitems[_size++] = x;
			delete [] items;
			items=moreitems;
		}
	else{
		items[_size++] = x;	
	}
}
template <typename T>
int Mylist<T>:: size() const//accessor function
{
	return _size;
}
template <typename T>
T& Mylist<T>:: at(int loc) const//returns the item at the location given in parameters 
{
	return items[loc];
}
template <typename T>
bool Mylist<T>::remove(T val)//removes the item in the list matching val if it exists. returns true on success, false on failure
{
	for(int i=0; i<_size; i++)
	{
		if (items[i]==val)
		{
			for(int j=i; j <_size;j++)
			{
				items[j]=items[j+1];//moves all other items up by one index
				}
				_size--;//decrements size
				return true;
		}
	}
	return false;
}
template <typename T>
void Mylist<T>::print()//prints out the lists in the item
{
for (int i=0; i<size(); i++){
	cout << items[i]<< endl;
	}
}
template <typename T>
void Mylist<T>::clearList()
{
	_size=0;
}
/*template <typename T>
void Mylist<T>:: clear()
{
while(items->next!=NULL){
    Item<T> *temp = head_->next;
    delete head_;
    head_ = temp;
  }
}*/
template <typename T>
T& Mylist<T>::operator[](int lhs)
{
	return items[lhs];
}
#endif
