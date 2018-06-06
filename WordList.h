#ifndef WORDLIST_H
#define WORDLIST_H
#include "WordData.h"

using namespace std;

class WordList{
	struct WordNode
	{
		WordData wordData;
		WordNode *next;
		WordNode(char word[], int lineNumber) : wordData(word, lineNumber), next(nullptr) {}; //ctor 1 which sets next to nullptr
		WordNode(char word[], int lineNumber, WordNode *next) : wordData(word, lineNumber), next(next) {}; //ctor 2
	};
	private:
		int size; // size of list
		WordNode *head; // pointer to first node
		WordNode *tail; // pointer to last node
	public:
		WordList(string filename);
		~WordList();
		WordList(const WordList &list);
		void operator=(const WordList &list);
		bool isEmpty();
		int getSize();
		WordNode *getWordNodeWithWord(char word[]);
		void addWord(char wordToStore[], int lineNumber);
		void print(ostream &out)const;
		bool isNumber(const string& s);
};
#endif