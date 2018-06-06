#ifndef WORD_DATA_H
#define WORD_DATA_H
#include "NumList.h"
class WordData{
	private:
		char *word;
		int frequency;
		NumList lineNumberList;
	public:
		WordData(char word[], int lineNumber);
		~WordData();
		WordData(const WordData &word);
		void operator=(const WordData &word);
		bool isLineNumberPresent(int lineNumber);
		void appendLineNumber(int lineNumber);
		int getFrequency();
		const char *getWord(); // return read only pointer to word
		const NumList &getNumList(); // return read only reference to word
		int compare(char wordToCompare[]); // returns -1, 0, 1 depending on if new word is before, equal or after
		friend std::ostream &operator<<(std::ostream &out, const WordData &wordData);

		int getCharArraySize(char[]) const; // ##TODO make this a static memeber function

		int getWordSize() const;

		char getFirstChar();
};
#endif