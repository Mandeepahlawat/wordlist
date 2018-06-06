#ifndef NUMLIST_H
#define NUMLIST_H
class NumList{
	private:
		int *store; // dynamic array structure to store data
		int capacity; // total capacity of the store
		int size; // number of occupied elemenets in store

		void doubleCapacity();
	public:
		NumList(int length = 1); // ctor
		~NumList(); // dtor
		NumList(const NumList &prevNumList); // copy constructor

		void add(int lineNumber);
		bool isEmpty();
		bool isPresent(int number);
		int get(int position);
		void set(int element, int position);
		int getSize();
		int getCapacity();

		void operator=(const NumList &store1);

		friend std::ostream& operator<<(std::ostream &out, const NumList &list);

};

#endif