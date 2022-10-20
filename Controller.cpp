#include "Controller.h"
//Needed in the threshold population of vector (atan()*2/PI)
#define PI 3.14159265359

Controller::Controller(float winW, float winH) : algo(comparison){  
    this->winW = winW;
    this->winH = winH;
    srand(time(0));
}                     

void Controller::populate(int elements, std::vector<Data*>& vector){
    //Deletes current dynamic object before new filling
    for(int i=0; i<vector.size(); i++){
        delete vector[i];
    }
    vector.clear();
    for(int i = 0; i < elements; i++){
        //Value and heights assignments
        float value = std::remainder(float(rand())/rand(), 1000);
        vector.push_back(new Data(winW / (float)elements, winH * (2/PI * atan(value)), value));
    }
}

void Controller::shuffle(std::vector<Data*>& vector){
    std::random_shuffle(std::begin(vector), std::end(vector));
} 

//Not deprecated alternative form (random_shuffle is deprecated)
/*void Controller::shuffle(std::vector<Data*>& vector){
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(vector.begin(), vector.end(), g);
}*/

//Useless with our populate funcion -- (same result)
/*void Cotroller::randomize(std::vector<Data*>& vector){
    for(int i = 0; i < vector.size(); i++){
        float value = rand();
        vector[i] = new Data(winW / (float)vector.size(), winH * (2/PI * atan(std::remainder(value/rand(),RAND_MAX))),value);
    }
}*/

bool Controller::sorted(const std::vector <Data*>& vector){ 
    for(int i=0; i<vector.size()-1; i++){
        if(vector[i]->getValue() > vector[i+1]->getValue()) return false;
    }
    return true;
}

void Controller::start(std::vector<Data*>& vector, int& sortType, bool& running){
    //Joins the thread in case it's running
    if(sorting.joinable()) sorting.join();

    interrupt = false;
    running = true;
    //sorting = std::thread(&Controller::sort, std::ref(controller), sortElements, interrupt, running, sortType);
    //sorting = std::thread([controller,sortElements,interrupt,running,sortType](){controller.sort(&sortElements, &interrupt, &running, &sortType);});
    //Lambda notation, [&] --> default reference arguments
    sorting = std::thread([&](){this->sort(vector, running, sortType);});
}

//Launched on std::thread sorting, doesn't produce any result until joinded (stopped)
void Controller::sort(std::vector <Data*>& vector, /*std::atomic<bool>& interrupt,*/ bool& running, int& sortType){
    comparison = 0;
    //Keeps track of milliseconds from start
    sf::Clock sortTime;
    //displayInfo should return "Sorting name: Sorting..."
    displayInfo(sortType, running, sortTime.getElapsedTime().asMilliseconds(), vector.size());

    while(!sorted(vector) && !interrupt){

        switch(sortType){
            case 0:
                algo.bubbleSort(vector, sleep, interrupt);
            break;

            case 1:
                algo.selectionSort(vector, sleep, interrupt);
            break;

            case 2:
                algo.inserctionSort(vector, sleep, interrupt);
            break;

            case 3:
                algo.cocktailSort(vector, sleep, interrupt);
            break;

            case 4:
                algo.bogoSort(vector, sleep, interrupt);
            break;

            /*case 5:
                algo.quickSort(vector, sleep, interrupt);
            break;*/

            default : 
                break;
        }
    }

    running = false;

    if(interrupt){
        int elements = vector.size();
        populate(elements, vector); 
    }

    //displayInfo should return algo details
    displayInfo(sortType, running, sortTime.getElapsedTime().asMilliseconds(), vector.size());
    //Launched asynchronous animation of sorted elements
    animation = std::thread([&](){this->doneAnim(vector);});
    animation.detach();     
}

void Controller::stop(bool& running){
    if(!sorting.joinable()){
        //only if already stopped
        return;
    }
    interrupt = true;
    sorting.join();
    running = false;
}

void Controller::doneAnim(const std::vector <Data*>& vector){
    for(int i=0; i<vector.size(); i++){
        vector[i]->setColor(sf::Color::Green);
        sf::sleep(sf::milliseconds(1));
    }
}


void Controller::displayInfo(int& sortType, bool& running, int sortTime, int elements){
    system("clear");

    std::cout << "Sort type: " << Utility::getSortName(sortType) << std::endl << std::endl;

    if(running){
        std::cout << "\nSorting ... " << std::endl;
    } else {
        std::cout << "Sort time : " << sortTime << "ms ||" <<(double)sortTime/1000 << "s" << std::endl;
        std::cout << "Number of elements : " << elements << std::endl;
        std::cout << "Time between comparison : " << sleep << "ms" << std::endl;
        std::cout << "Number of comparison : " << comparison << std::endl;
    }
}

