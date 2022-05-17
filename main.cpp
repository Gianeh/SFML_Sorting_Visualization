#include <iostream>
#include "Dataset.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main(){
    float width = 1700, height = 1000;
    sf::RenderWindow screen(sf::VideoMode(width, height), "Sorting playground", sf::Style::Close | sf::Style::Titlebar);
    //SECOND SCREEN THAT RUNS OTHER SORTING FOR COMPARISON
    //sf::RenderWindow prova(sf::VideoMode(width, height), "Sorting playground", sf::Style::Close | sf::Style::Titlebar);
    sf::Event e;
    Dataset D(1000);
    //Dataset B(1000);
    D.randinit(1000);
    //B.randinit(1000);
    screen.clear(sf::Color::White);
    //prova.clear(sf::Color::White);
    D.setScreen(&screen);
    //B.setScreen(&prova);
    screen.display();
    //prova.display();

    
    //screen.setFramerateLimit(2);
    while(screen.isOpen()){
        while(screen.pollEvent(e)){
            if(e.type == e.Closed){ screen.close(); /*prova.close();*/ }
        }
        D.selectionsort();
        D.shuffle(1000);
        //B.bubblesort();
        
    }

    return 0;
}