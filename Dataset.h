#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <math.h>
#include <time.h>
#include <random>
#include "Array.h"

class Dataset{
    private:
        Array Data;
        Array heights;
        float W, H, size;
        sf::RectangleShape rect;
        sf::RenderWindow *screen;
        bool sorted;

    public:
        Dataset(int len);

        void setScreen(sf::RenderWindow *s);

        void update();

        void randinit(int max = 10000);

        void shuffle(int max = 10000);

        //SORTING ALGORITHMS

        void bubblesort();
        void selectionsort();
};