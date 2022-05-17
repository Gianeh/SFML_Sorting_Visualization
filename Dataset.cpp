#include "Dataset.h"
#define PI 3.14159265359

//pre-Run constructor for Array Data,heights (alternative to Array::reAllocate)
Dataset::Dataset(int len) : Data(len), heights(len){
    screen = nullptr;
    sorted = false;
    //Data.reAllocate(len);
    //heights.reAllocate(len);
    rect.setFillColor(sf::Color::Black);
    rect.setOutlineColor(sf::Color::Red);
    rect.setOutlineThickness(-0.5);
}

void Dataset::setScreen(sf::RenderWindow *s){
    screen = s;
    if(screen == nullptr){ std::cout << "screen not initialized" << std::endl; return; }
    W = screen->getSize().x;
    H = screen->getSize().y;
    size = W / Data.length();

    for(int i = 0; i < Data.length(); i++){
        heights.set(H * 2 * atan(Data.get(i)) / PI, i);
        rect.setSize(sf::Vector2f(size, heights.get(i)));
        rect.setPosition(sf::Vector2f(i * size, H - heights.get(i)));
        screen->draw(rect);
    }
}

void Dataset::update(){
    if(screen == nullptr){ std::cout << "screen not initialized" << std::endl; return; }
    screen->clear(sf::Color::White);
    for(int i = 0; i < Data.length(); i++){
        rect.setSize(sf::Vector2f(size, heights.get(i)));
        rect.setPosition(sf::Vector2f(i * size, H - heights.get(i)));
        screen->draw(rect);
    }
    screen->display();
}

void Dataset::randinit(int max){
    srand(time(0));
    for(int i = 0; i < Data.length(); i++){
        Data.set(std::remainder(float(rand())/rand(), max), i);
    }
}

void Dataset::shuffle(int max){
    if(!sorted) return;
    srand(time(0));
    for(int i = 0; i < Data.length(); i++){
        Data.set(std::remainder(float(rand())/rand(), max), i);
        heights.set(H * 2 * atan(Data.get(i)) / PI, i);
        update();
    }
    sorted = false;
}