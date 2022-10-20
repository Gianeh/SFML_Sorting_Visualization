#ifndef _PLAYGROUND_
#define _PLAYGROUND_

#include "Screen.h"
#include "Controller.h"
#include <SFML/System.hpp>
#include <vector>
#include <iostream>

//Object that handles most of the interaction and the main loop (play())
class PlayGround{
    private:
        Screen screen;
        Controller controller;
        //sfml object that polls(sonda) the events
        sf::Event E;
        //number of elements
        int elements;
        //an integer to represent the sort algorithm
        int sortType = 0;
        bool running = false;
        //Actual sortable objects vector
        //pointers are needed for dinamic allocation
        std::vector<Data*> sortElements;
        
    public:
        //Initializes the Screen and Controller objects
        PlayGround(int W, int H, std::string name, int elements = 100, int framerate = 60);
        //Destroy the Sortables at the end
        ~PlayGround();
        //Main loop
        void play();
        //Refresh of the current rectangles position
        void draw();
        inline std::vector<Data*>& vector(){ return sortElements; }

};

#endif
