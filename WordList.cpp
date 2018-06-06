#include <iostream>
#include <cassert>
#include <string>
#include <fstream>
#include <sstream>
#include "WordList.h"
using namespace std;

WordList::WordList(string filename) : head(nullptr), tail(nullptr), size(0) {
	ifstream fin(filename);
	if(!fin){
		cout << "could not open input file: " << filename << endl;
		exit(1);
	}
	int linenum = 0;
	string line;
	getline(fin, line); // attempt to read a line
	while(fin){
		++linenum;
		istringstream sin(line); // convert the line  just read into an input stream
		string word;
		while(sin >> word){
			// check if the word is a valid word, a valid word should have some alphabets
			if(!isNumber(word)){
				// remove elements from the start of the word if they are not alphabets 
				while((word[0] < 'a' || word[0] > 'z') && (word[0] < 'A' || word[0] > 'Z')){
					word.erase(0,1);
				}

				char lastCharacter = word[word.length()-1];
				// remove elements from the end of the word if they are not alphabets
				while((lastCharacter < 'a' || lastCharacter > 'z') && (lastCharacter < 'A' || lastCharacter > 'Z')){
					word.erase(word.length()-1,1);
					lastCharacter = word[word.length()-1];
				}

			  char *charArrayWord = new char[word.length() + 1];
			  strcpy(charArrayWord, word.c_str());

			  addWord(charArrayWord, linenum);

			  delete[] charArrayWord;
			}
		}
		getline(fin, line);
	}
	fin.close();
};

WordList::~WordList(){
	head = nullptr;
	tail = nullptr;
}

bool WordList::isNumber(const string& s){
	string::const_iterator it = s.begin();
  while (it != s.end() && (isdigit(*it) || ispunct(*it))) ++it;
  return !s.empty() && it == s.end();
}

int WordList::getSize() {
	return size;
};

bool WordList::isEmpty(){
	return head == nullptr;
}

WordList::WordNode *WordList::getWordNodeWithWord(char inputWord[]){
	if (isEmpty()){
		return nullptr;
	}
	else{
		WordNode *temp = head;
		// iterate over the list till tail whose next node points to nullptr
		// return nullptr if no node with the word is found;
		while (temp != nullptr){
			if (temp->wordData.compare(inputWord) == 0){
				return temp;
			}
			temp = temp->next;
		}
		return nullptr;
	}
}

void WordList::addWord(char wordToStore[], int lineNumber){
	WordNode *tempWordNode = getWordNodeWithWord(wordToStore);
	if (tempWordNode != nullptr){
		// word already present in the list
		tempWordNode->wordData.appendLineNumber(lineNumber);
	}
	else{
		WordNode *newWordNode = new WordNode(wordToStore, lineNumber);

		if (head == nullptr){
			// list is empty
			head = newWordNode;
			tail = newWordNode;
			newWordNode->next = nullptr;
		}
		else{
			int i = 0;
			WordNode *temp = head;
			WordNode *prevTemp = nullptr;

			// find the correct position to enter the new node. 2 temp pointers contain previous and next
			// nodes
			while (temp != nullptr && temp->wordData.compare(wordToStore) == 1){
				prevTemp = temp;
				temp = temp->next;
				++i;
			}

			if (i == 0){
				// if new word to be add is at the start
				newWordNode->next = head;
				head = newWordNode;
			}
			else if (i == size){
				// if new word to be add is at the end
				tail->next = newWordNode;
				tail = newWordNode;
			}
			else{
				// if new word to be add is in between start and end
				prevTemp->next = newWordNode;
				newWordNode->next = temp;
			}
		}
		++size;
	}
}

//copy assignment
void WordList::operator=(const WordList &list){
	if (this == &list) return;
	WordList::~WordList();
	size = list.size;
	head = list.head;
	tail = list.tail;
}

// copy ctr
WordList::WordList(const WordList &list){
	size = list.size;
	head = list.head;
	tail = list.tail;
}

void WordList::print(ostream &out)const{
	out << "WordList Source File: input.txt" << endl;
	out << "============================" << endl;
	char c;
	for (c = 'A'; c <= 'Z'; ++c){
		out << "<" << c << ">" << endl;

		WordNode *temp = head;

		// print all the words till temp points to tail
		while (temp != nullptr){
			char tempWord = temp->wordData.getWord()[0];
			if(toupper(tempWord) == c){
				out << temp->wordData;
			}
			temp = temp->next;
		}
	}
	out << "============================";
}