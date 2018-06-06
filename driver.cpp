#include <iostream>
#include <fstream>
#include "WordList.h"
using namespace std;

int main(){
	WordList w1("input.txt"); // Initialize wordlist object and pass input file to read as a string
	ofstream out("result.txt"); // create an object of ofstream class to write on the file
 	w1.print(out); // print wordlist to file
 	w1.print(cout); // print wordlist to console
	return 0;
}
