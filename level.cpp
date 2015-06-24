#include <SFML/Graphics.hpp>
#include "level.h"
#include <string>
using namespace std;

Level::Level(sf::RenderWindow *window)
{

    this->window = window;
    string levelpath = "/images/level/level.png";
    this->backgrText.loadFromFile(levelpath,sf::IntRect(0,0,window->getSize().x,window->getSize().y));
    this->backgrSprite.setTexture(backgrText);

}
Level::Level(sf::RenderWindow *window,string levelname)
{
    this->window = window;
    string levelpath = "images/level/"+levelname+"/level.png";
    this->backgrText.loadFromFile(levelpath,sf::IntRect(0,0,window->getSize().x,window->getSize().y));
    this->backgrSprite.setTexture(backgrText);
}
void Level::setLevelName(string levelname)
{
    string levelpath;
    levelpath = "/images/level/"+levelname+"level.png";
    this->backgrText.loadFromFile(levelpath,sf::IntRect(0,0,window->getSize().x,window->getSize().y));
    this->backgrSprite.setTexture(backgrText);
}
void Level::draw()
{
    this->window->draw(this->backgrSprite);
}


