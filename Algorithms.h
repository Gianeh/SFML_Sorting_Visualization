#ifndef _ALGO_
#define _ALGO_
#include "Data.h"
#include <atomic>	
//#include <tuple>

class Sorter{
	private:
		//Reference to number of comparisons in PlayGround
		//atomic data type prevents data races over the variable (not necessary but safe)
		//race = concorrenza su una parte di memoria contemporaneamente di due thread
		std::atomic<int>& comparison;
	public:
		Sorter(std::atomic<int>& comparison);
		
		//Utils
		void swap(std::vector<Data*>& vector, float sleep, Data* d1, Data* d2);
		//int Sorter::quickSortHelper(std::vector<Data*>& parent, std::vector<Data*>::iterator begin, std::vector<Data*>::iterator end, int sleep, std::atomic<bool>& interrupt);
		//std::tuple<std::vector<Data*>::iterator, int> quickSortPartition(std::vector<Data*> parent, std::vector<Data*>::iterator begin, std::vector<Data*>::iterator end, int sleep, std::atomic<bool>& interrupt);

		//Sorting algorithms
		//easiest sorting algorithm, complexity: n^2
		void bubbleSort(std::vector<Data*>& vector, float sleep, std::atomic<bool>& interrupt);
		void selectionSort(std::vector<Data*>& vector, float sleep, std::atomic<bool>& interrupt);
		void inserctionSort(std::vector<Data*>& vector, float sleep, std::atomic<bool>& interrupt);
		void cocktailSort(std::vector<Data*>& vector, float sleep, std::atomic<bool>& interrupt);
		//random shuffle until ordering occurs
		void bogoSort(std::vector<Data*>& vector, float sleep, std::atomic<bool>& interrupt);
		//void quickSort(std::vector<Data*>& vector, float sleep, std::atomic<bool>& interrupt);
};

#endif


