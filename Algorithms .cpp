#include "Algorithms.h"

Sorter::Sorter(std::atomic<int>& comparison) : comparison(comparison){}

void Sorter::swap(std::vector<Data*>& vector, float sleep, Data* d1, Data* d2){
	d1->setColor(d1->rgb(255,0,0));
	d2->setColor(d2->rgb(255,0,0));
	//Simple swap of pointed data 
	Data temp = *d1;
	*d1 = *d2;
	*d2 = temp;
	sf::sleep(sf::milliseconds(sleep));
	d1->setColor(d1->rgb(255,255,255));
	d2->setColor(d2->rgb(255,255,255));
}

/* Utils for quickSort
int Sorter::quickSortHelper(std::vector<Data*>& parent, std::vector<Data*>::iterator begin, std::vector<Data*>::iterator end, int sleep, std::atomic<bool>& interrupt){
	if(interrupt || end-begin < 2) return 0;  //base case
	std::vector<Data*>::iterator pivot;
	std::tie(pivot, comparison) = quickSortPartition(parent, begin, end, interrupt);
	return comparison + quickSortHelper(parent, begin, pivot, sleep, interrupt) + quickSortHelper(parent, begin, pivot+1, sleep, interrupt);
}

std::tuple<std::vector<Data*>::iterator, int> quickSortPartition(std::vector<Data*> parent, std::vector<Data*>::iterator begin, std::vector<Data*>::iterator end, int sleep, std::atomic<bool>& interrupt){
	auto pivot = end-1;
	int tempcomparison = 0;
	//left-hand-side / right-hand-side
	auto lhs = begin;
	for(auto rhs = lhs; rhs != pivot; rhs++){
		if(interrupt) return std::make_tuple(lhs, tempcomparison);
		tempcomparison++;
		if(parent.at(rhs)->getValue() <= pivot->getValue()){
			swap(parent, sleep, *lhs, *rhs);
			lhs++;
		}
	} swap(parent, sleep, *lhs, *rhs);
	return std::tuple<std::vector<Data*>::iterator, int>(lhs, tempcomparison);
} 
*/

void Sorter::bubbleSort(std::vector<Data*>& vector, float sleep, std::atomic<bool>& interrupt){
	for(int i=0; i<vector.size()-1; i++){
		if(interrupt) return;
		if(vector[i]->getValue()>vector[i+1]->getValue()) swap(vector, sleep, vector[i], vector[i+1]);
		comparison++; 		//essendo una &, comparison si incrementa nel playground
	}
	return;
}

void Sorter::selectionSort(std::vector<Data*>& vector, float sleep, std::atomic<bool>& interrupt){
	for(int i=0; i<vector.size(); i++){
		for(int j=i; j<vector.size(); j++){
			if(interrupt) return;
			if(vector[i]->getValue()>vector[j]->getValue()) swap(vector, sleep, vector[i], vector[j]);
			comparison++; 	
		}	
	}
	return;
}

void Sorter::inserctionSort(std::vector<Data*>& vector, float sleep, std::atomic<bool>& interrupt){
	for(int i=1; i<vector.size(); i++){
		auto temp = vector[i];
		int j=i-1;
		while(temp->getValue()<=vector[j]->getValue() && j>=0){ 
			if(interrupt) return;
			vector[j]->setColor(sf::Color::Red);
			vector[j+1] = vector[j];
			sf::sleep(sf::milliseconds(sleep));
			vector[j+1]->setColor(sf::Color::White);
			j = j-1;
			comparison++; 		
		}
		vector[j+1] = temp;
		comparison++;
	}
	return;
}

void Sorter::cocktailSort(std::vector<Data*>& vector, float sleep, std::atomic<bool>& interrupt){
	bool swapped = true;
	int start = 0;
	int end = vector.size() -1;
	while(swapped){
		swapped = false;
		for(int i=0 + start; i<end; i++){
			if(vector[i]->getValue()>vector[i+1]->getValue()){
				swap(vector, sleep, vector[i], vector[i+1]);
				swapped = true;
			}
			comparison++;
			swapped = false;
			end -= 1;
			for(int i=0 + end; i>start; i--){
				if(interrupt) return;
				if(vector[i]->getValue()>vector[i+1]->getValue()){
					swap(vector, sleep, vector[i], vector[i+1]);
					swapped = true;
				}
				comparison++;

				start += 1;
			}
		}
	}
}

void Sorter::bogoSort(std::vector<Data*>& vector, float sleep, std::atomic<bool>& interrupt){
	//random_shuffle -> deprecated
	sf::sleep(sf::milliseconds(sleep));
	std::random_shuffle(std::begin(vector), std::end(vector));
	comparison++;
	return;
}

/*void Sorter::quickSort(std::vector<Data*>& vector, float sleep, std::atomic<bool>& interrupt){
	
	return;
}*/
