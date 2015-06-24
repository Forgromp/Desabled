#include "characters.h"
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;

Player::Player(sf::RenderWindow *window)
{
    this->window = window;
    this->staticTexture = NULL;
    this->hitTexture = NULL;
    this->staticSprite = NULL;
    this->hitSprite = NULL;
    this->hit = -1;
    sAnimation = 0;
}
Player::Player(sf::RenderWindow *window, string skinName)
{
    this->window = window;
    this->staticTexture = new sf::Texture[3];
    string textureName = "images/character/player/"+skinName+"/Dis_";
    staticTexture[0].loadFromFile(textureName+"01.png",sf::IntRect(0,0,32,32));
    staticTexture[1].loadFromFile(textureName+"02.png",sf::IntRect(0,0,32,32));
    staticTexture[2].loadFromFile(textureName+"03.png",sf::IntRect(0,0,32,32));
    this->hitTexture = new sf::Texture[3];
    hitTexture[0].loadFromFile(textureName+"01_hit.png",sf::IntRect(0,0,32,32));
    hitTexture[1].loadFromFile(textureName+"02_hit.png",sf::IntRect(0,0,32,32));
    hitTexture[2].loadFromFile(textureName+"03_hit.png",sf::IntRect(0,0,32,32));
    staticSprite = new sf::Sprite[3];
    hitSprite = new sf::Sprite[3];
    for (int i = 0;i<3;i++)
    {
        staticSprite[i].setTexture(staticTexture[i]);
        hitSprite[i].setTexture(hitTexture[i]);
        hitSprite[i].setPosition(288,430);
        staticSprite[i].setPosition(288,430);
    }
    this->hit = -1;

}
void Player::setSkin(string skinName)
{
    this->staticTexture = new sf::Texture[3];
    string textureName = "images/character/player/"+skinName+"/Dis_";
    staticTexture[0].loadFromFile(textureName+"01.png",sf::IntRect(0,0,32,32));
    staticTexture[1].loadFromFile(textureName+"02.png",sf::IntRect(0,0,32,32));
    staticTexture[2].loadFromFile(textureName+"03.png",sf::IntRect(0,0,32,32));
    this->hitTexture = new sf::Texture[3];
    hitTexture[0].loadFromFile(textureName+"01_hit.png",sf::IntRect(0,0,32,32));
    hitTexture[1].loadFromFile(textureName+"02_hit.png",sf::IntRect(0,0,32,32));
    hitTexture[2].loadFromFile(textureName+"03_hit.png",sf::IntRect(0,0,32,32));
    staticSprite = new sf::Sprite[3];
    hitSprite = new sf::Sprite[3];
    for (int i = 0;i<3;i++)
    {
        staticSprite[i].setTexture(staticTexture[i]);
        hitSprite[i].setTexture(hitTexture[i]);
        staticSprite[i].setPosition(288,430);
        hitSprite[i].setPosition(288,430);
    }

}
bool Player::hitSet()
{
    if (this->hit >=0)
        return 0;
    else
    {
        this->hit = 0;
    return 1;
    }

}
void Player::draw()
{
    switch (this->hit)
{

case -1:
        if (sAnimation < animationSpeed)
            this->window->draw(this->staticSprite[0]);
        else if (sAnimation >= animationSpeed&&sAnimation<animationSpeed*2)
            this->window->draw(this->staticSprite[1]);
        else if (sAnimation >=animationSpeed*2&&sAnimation <= animationSpeed*3)
            this->window->draw(this->staticSprite[2]);
            break;
default:
        if (sAnimation < animationSpeed)
            this->window->draw(this->hitSprite[0]);
        else if (sAnimation >= animationSpeed&&sAnimation<animationSpeed*2)
            this->window->draw(this->hitSprite[1]);
        else if (sAnimation >=animationSpeed*2&&sAnimation <= animationSpeed*3)
            this->window->draw(this->hitSprite[2]);
        if (hit == hitSpeed)
            hit = -1;
        else
            hit++;
}
    if(sAnimation == animationSpeed*3)
            sAnimation = 0;
    else
        sAnimation++;
        drawHP();
}

void Player::setHP()
{
    int hpY=20, hpX=20;
    this->hp=5;
    hpSprite = new sf::Sprite[hp];
    this->hpTexture.loadFromFile("images/character/player/hp/heart.png",sf::IntRect(0,0,32,32));
    for(int i = 0; i < hp; i++)
    {
    hpSprite[i].setTexture(hpTexture);
    hpSprite[i].setPosition(hpX,hpY);
    hpX=hpX+32;
    }
}

void Player::drawHP()
{
    for (int i =0;i < hp;i++)
    {
        this->window->draw(this->hpSprite[i]);
    }
}
