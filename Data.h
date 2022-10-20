#ifndef _DATA_
#define _DATA_
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

//A sortable object for our algorithms
class Data /*: public RectangleShape*/{
    private:
        float W,H;
        float value;
        sf::Color color = sf::Color::White;
    public:
        Data(float W, float H, float value);

        //Useful to generate sf::Color from rgb values
        sf::Color rgb(int r, int g, int b);
        //Returns a drawble rectangle
        sf::RectangleShape shape();

        inline sf::Vector2f size(){
            return sf::Vector2f(W,H);
        }
        inline float getValue(){
            return value;
        }
        inline sf::Color getColor(){
            return color;
        }
        inline void setColor(sf::Color color){
            this->color = color;
        }
        
};

#endif