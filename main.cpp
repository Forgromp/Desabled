#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "level.h"
#include "characters.h"
using namespace std;
const sf::Vector2f res(640,480);


int main()
{
    sf::RenderWindow window(sf::VideoMode(res.x,res.y),"THE DISABLED");
    Level def(&window,"default");
    Player player(&window,"default");
    player.setHP();
    window.setVerticalSyncEnabled(true);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed
                ||(event.type == sf::Event::KeyPressed&&event.key.code == sf::Keyboard::Escape))
                    window.close();
            if ((event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space))
            {
               player.hitSet();
            }
        }
        window.clear();
        def.draw();
        player.draw();
        window.display();
    }



    }
