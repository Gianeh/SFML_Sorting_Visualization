#include "PlayGround.h"

PlayGround::PlayGround(int W, int H, std::string name, int elements, int framerate) : screen(W,H,name,framerate), controller(W,H){
    this->elements = elements;
}

PlayGround::~PlayGround(){
    system("clear");
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "Thanks for using our sorting visualizer!" << std::endl;
    std::cout << "Deliting memory..." << std::endl;
    for(int i=0; i<sortElements.size(); i++){
        delete[] sortElements[i];
    }
    std::cout << "Done." << std::endl;
}

void PlayGround::play(){
    controller.populate(elements, sortElements);
    screen.clear(sf::Color::Black);
    draw();
    screen.display();
    while(screen.isOpen()){
        while(screen.pollEvent(E)){
            if(E.type == sf::Event::KeyPressed){
                switch(E.key.code){

                case(sf::Keyboard::Space):
                    if(!running){
                        controller.populate(elements, sortElements);
                        controller.start(sortElements, sortType, running);
                        //controller.doneAnim(sortElements);
                    }
                break;

                case(sf::Keyboard::Backspace):
                    if(running){
                        system("clear");
                        std::cout << "Sorting stopped!" << std::endl;
                        controller.stop(running);
                    }else{
                        controller.populate(elements, sortElements);
                    }
                break;

                case(sf::Keyboard::H):
                    system("clear");
                    std::cout << "Use the following commands to change settings:\n" << std::endl;
                    std::cout << "[Space]: Start sort" << std::endl;
                    std::cout << "[Backspace]: Stop sort" << std::endl;                    
                    std::cout << "[Up/Down Arrows]: Change sort type" << std::endl;
                    std::cout << "[F1]: Change number of elements" << std::endl;
                    std::cout << "[F2]: Change time between comparisons" << std::endl;
                break;

                case(sf::Keyboard::Up):
                    if(sortType>=0 && Utility::hasNext(sortType)){
                        sortType++;
                        system("clear");
                        std::cout << "Sort changed to: " << Utility::getSortName(sortType) << std::endl;
                    }
                break;

                case(sf::Keyboard::Down):
                    if(sortType>0){
                        sortType--;
                        system("clear");
                        std::cout << "Sort changed to: " << Utility::getSortName(sortType) << std::endl;
                    }
                break;

                //Change number of elements
                case(sf::Keyboard::F1):
                    if(!running){
                        system("clear");
                        std::cout << "New number of elements : ";
                        std::cin >> elements;
                        printf("\n");

                        controller.populate(elements, sortElements);
                    }
                break;

                //Change time of comparison
                case(sf::Keyboard::F2):
                    if(!running){
                        system("clear");
                        std::cout << "New time between comparisons (milliseconds) : ";
                        int sleep;
                        std::cin >> sleep;
                        controller.setSleep(sleep);
                    }
                break;

                case(sf::Keyboard::Q):
                    controller.stop(running);
                    screen.close();
                break;

                default:
                    std::cout << "Undefined command!" << std::endl;
                break;
                }
            
            }

            if(E.type == sf::Event::Closed){ 
                controller.stop(running);
                screen.close();
            }
        }


        // Background refresh
        screen.clear(sf::Color::Black);
        // Updates the drawing
        draw();
        //Shows the buffer
        screen.display();

    }
}


void PlayGround::draw(){
    for(int i=0; i<sortElements.size(); i++){
        sf::RectangleShape rect = sortElements[i]->shape();
        rect.setFillColor(sortElements[i]->getColor());
        rect.setPosition(sf::Vector2f(sortElements[i]->size().x * i, screen.getSize().y - sortElements[i]->size().y));
        rect.setOutlineThickness(-1);
        rect.setOutlineColor(sf::Color::Red);
        screen.draw(rect);
    }
}
