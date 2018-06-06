#include <iostream>
#include "WordData.h"

using namespace std;

char WordData::getFirstChar(){
	return word[0];
}

int WordData::getCharArraySize(char word[]) const {
	int i = 0;
	while (word[i] != '\0'){
		i++;
	}
	return i;
}

WordData::WordData(char wordToStore[], int lineNumber){
	int size = getCharArraySize(wordToStore);
	word = new char[size+1];

	for (int i = 0; i < size+1; ++i){
		word[i] = tolower(wordToStore[i]);
	}
	frequency = 1;
	lineNumberList.add(lineNumber);
}

int WordData::compare(char wordToCompare[]){
	// check each character in wordToCompare and compare ascii values with word to see if
	// wordToCompare and word are equal, wordToCompare should come before or after the word and return
	// 0, -1, 1 respectively
	int i;
	for (i = 0; wordToCompare[i] != '\0'; ++i){
		if (int(word[i]) > int(tolower(wordToCompare[i]))){
			return -1;
		}
		else if (int(word[i]) < int(tolower(wordToCompare[i]))){
			return 1;
		}
	}
	if(getCharArraySize(word) == getCharArraySize(wordToCompare)){
		return 0;
	}
	else{
		return -1;
	}
}

WordData::~WordData(){
	delete[] word;
}

WordData::WordData(const WordData &prevWord){
	frequency = prevWord.frequency;
	word = new char[getCharArraySize(prevWord.word)];
	lineNumberList = prevWord.lineNumberList;

	for (int i = 0; i < getCharArraySize(prevWord.word); ++i){
		word[i] = prevWord.word[i];
	}
}

void WordData::operator=(const WordData &prevWord){
	if (this == &prevWord) return;
	WordData::~WordData();
	frequency = prevWord.frequency;
	word = new char[getCharArraySize(prevWord.word)];
	for (int i = 0; i < getCharArraySize(prevWord.word); ++i){
		word[i] = prevWord.word[i];
	}
	lineNumberList = prevWord.lineNumberList;
}

bool WordData::isLineNumberPresent(int lineNumber) {
	return lineNumberList.isPresent(lineNumber);
}

void WordData::appendLineNumber(int lineNumber){
	lineNumberList.add(lineNumber);
	++frequency;
}

int WordData::getFrequency(){
	return frequency;
}

const char *WordData::getWord(){
	return word;
}

const NumList &WordData::getNumList(){
	return lineNumberList;
}

int WordData::getWordSize() const {
	return getCharArraySize(word);
}

// print elements
ostream& operator<<(ostream &out, const WordData &wordData){
	out.width(15); out << right << wordData.word;
	out << "\t";
	out << "(" << wordData.frequency << ")";
	out << wordData.lineNumberList << endl;
	return out;
}