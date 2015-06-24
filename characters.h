#ifndef CHARACTERS_H_INCLUDED
#define CHARACTERS_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

class Player
{
    private:
        sf::RenderWindow *window;
        //int amount_static_animation;
        //int amount_hit_animation;
        static const int hitSpeed = 10;
        static const int animationSpeed = 10;
        int hit;
        int sAnimation;
        int hp;
        sf::Texture *staticTexture;
        sf::Texture *hitTexture;
        sf::Texture hpTexture;
        sf::Sprite *staticSprite;
        sf::Sprite *hitSprite;
        sf::Sprite *hpSprite;
    public:
        Player(sf::RenderWindow *window, string skinName);
        Player(sf::RenderWindow *window);
        //~Player();
        void setSkin(string skinName);
        bool hitSet();
        void setHP();
        void drawHP();
        void draw();




};


#endif // CHARACTERS_H_INCLUDED
