#include "Screen.h"


                                                                //Default inizialization of RenderWindow
Screen::Screen(int W, int H, std::string name, int framerate) : sf::RenderWindow(sf::VideoMode(W,H), name, sf::Style::Close | sf::Style::Titlebar){
    sf::RenderWindow::setFramerateLimit(framerate);
}


