#include "Data.h"

Data::Data(float W, float H, float value){
    this->W = W;
    this->H = H;
    this->value = value;
}

sf::Color Data::rgb(int r, int g, int b){
    if(!(r<256 && r>=0 && g<256 && g>=0 && b<256 && b>=0)){ 
        return sf::Color(255,255,255);     
    } 
    return sf::Color(r,g,b);
}

sf::RectangleShape Data::shape(){
    return sf::RectangleShape(sf::Vector2f(W,H));
}

