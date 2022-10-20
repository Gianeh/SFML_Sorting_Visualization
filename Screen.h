#ifndef _SCREEN_
#define _SCREEN_
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>

//Just a single class to initialize an sf::RenderWindow in an easier way
//RenderWindow è un oggetto che gestisce le funzioni applicabili ad una finestra
class Screen : public sf::RenderWindow{
    public:
        Screen(int W, int H, std::string name, int framerate);
};


#endif