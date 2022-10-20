#ifndef _CONTROLLER_
#define _CONTROLLER_
#include "Data.h"
#include "Utility.h"
#include "Algorithms.h"
//Most of the math operations, randomness, time handling and data types are included here
#include <iostream>
#include <cmath>
#include <random>
#include <time.h>
#include <algorithm>
#include <thread>
#include <iterator>
#include <atomic>


//Object that handles operations over the Sortable vector, includes the multithread executions
class Controller{
    private:
        //Window size and
        int winW, winH;
        //Sleep time between comparisons (milliseconds)
        int sleep = 1; 
        //Thread: useful to stop the program and get order by user
        std::thread sorting;
        std::thread animation;
        //Atomic integer/boolean flag to prevent data races
        std::atomic<int> comparison;
        std::atomic<bool> interrupt;
        //Object that contains sorting methods
        Sorter algo; 

    public:
        Controller(float winW, float winH);
        //Fills the sortable vector with random values and sets the rectangle heights based on the window size
        void populate(int elements, std::vector<Data*>& vector);
        void shuffle(std::vector<Data*>& vector);
        //void randomize(std::vector<Data*>& vector);
        //Starts the sort function in the sorting thread through a lambda definition
        void start(std::vector<Data*>& vector, int& sortType, bool& running); 
        //Actual sorting case switch
        void sort(std::vector <Data*>& vector, bool& running, int& sortType);
        //Stops the sorting and joins the threads
        void stop(bool& running);
        //Prints the ordered vector animations
        void doneAnim(const std::vector <Data*>& vector);
        //Check if the vector is sorted
        bool sorted(const std::vector <Data*>& vector);
        //Return informations about sorting algorithms
        void displayInfo(int& sortType, bool& running, int sortTime, int elements);
        inline void setSleep(int sleep){ this->sleep = sleep; }
};

#endif
