#include <SFML/Graphics.hpp>
#include <string>
#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED
using namespace std;

class Level
{
private:
    sf::RenderWindow* window;
    sf::Texture backgrText;
    sf::Sprite backgrSprite;
public:
    Level(sf::RenderWindow *window);
    Level(sf::RenderWindow *window,string levelname);
    void setLevelName(string levelname);
    void draw();

};





#endif // LEVEL_H_INCLUDED
