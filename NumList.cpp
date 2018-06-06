#include <iostream>
#include <cassert>
#include "NumList.h"
using namespace std;

// constructor
NumList::NumList(int length){
	store = new int[length];
	capacity = length;
	size = 0;
}

// copy constructor
NumList::NumList(const NumList &list){
	capacity = list.capacity;
	size = list.size;
	store = new int[capacity];
	for(int i = 0; i < capacity; ++i){
		store[i] = list.store[i];
	}
}

// destructor
NumList::~NumList(){
	delete [] store;
}

//copy assignment
void NumList::operator=(const NumList &list){
	if(this == &list) return;
	NumList::~NumList();
	capacity = list.capacity;
	size = list.size;
	store = new int[capacity];
	for(int i = 0; i < capacity; ++i){
		store[i] = list.store[i];
	}
}

void NumList::add(int lineNumber){
	// if a line number is already present then retun out of the function
	// and don't add a new word
	if(isPresent(lineNumber)) return;
	if(size < capacity){
		store[size] = lineNumber;
		++size;
	}
	else{
		int *temp = new int[size];
		for(int i = 0; i < size; ++i){
			temp[i] = store[i];
		}
		NumList::~NumList();
		capacity = capacity * 2;
		store = new int[capacity];
		for(int i = 0; i < size; ++i){
			NumList::set(temp[i], i);
		}
		store[size] = lineNumber;
		++size;
	}
}

int NumList::get(int position){
	assert (position >= 0 && position < capacity);
	return store[position];
}

void NumList::set(int element, int position){
	assert (position >= 0 && position < capacity);
	store[position] = element;
}

// check if store is empty
bool NumList::isEmpty(){
	if(size == 0)
		return false;
	else
		return true;
}

// check if a line number is already present
bool NumList::isPresent(int lineNumber){
	for(int k = 0; k < size; ++k){
		if(store[k] == lineNumber)
			return true;
	}
	return false;
}

int NumList::getSize(){
	return size;
}

int NumList::getCapacity(){
	return capacity;
}

// print elements
ostream& operator<<(ostream &out, const NumList &list){
	for(int i = 0; i < list.size; ++i){
		// seperate first line number from frequency by a tab and then successive line numbers by a space
		if(i==0){
			out << '\t';
		}
		else{
			out << ' ';
		}
		out << list.store[i];
	}
	return out;
}