#include <iostream>
#include "init.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

void Setup();
void Map();

int main()
{
    Setup();
    sf::Window window(sf::VideoMode(800,800), "float");

    while(window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }
    }
    //Map();

}
void Setup()
{
    gameOn = true;
    cordX = width/2;
    cordY = height/2;
    appleX = 2;
    appleY = 2;
}
void Map()
{
    }
