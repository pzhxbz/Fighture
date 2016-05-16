#include "Player.h"
#include "Data.h"
#include <SFML/Graphics.hpp>
Player::Player()
{
    texture.loadFromFile("picture/player.png");
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setPosition(WIDTH/2-16,HEIGHT-46);
    fire_speed.restart();
}

Player::~Player()
{
    //dtor
}
void Player::move()
{
    for(int i=0;i<10;i++)
    {
        if(bullet[i]!=NULL)
        {
            bullet[i]->move();
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        sprite.move(-0.2,0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        sprite.move(0.2,0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        sprite.move(0,-0.2);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        sprite.move(0,0.2);
    }
    if(sprite.getPosition().x>WIDTH-32)
    {
        sprite.move(-0.2,0);
    }
    if(sprite.getPosition().x<0)
    {
        sprite.move(0.2,0);
    }
    if(sprite.getPosition().y>HEIGHT-46)
    {
        sprite.move(0,-0.2);
    }
    if(sprite.getPosition().y<0)
    {
        sprite.move(0,0.2);
    }
    if(fire_speed.getElapsedTime().asSeconds()>=0.08)
    {
        fire_speed.restart();
        isFire=false;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        fire();
    }
    bullet_destory();
    draw();
    boundingBox=sprite.getGlobalBounds();
}
void Player::draw()
{
    Data::window.draw(sprite);
}
void Player::fire()
{
    if(isFire==false)
    {
        for(int i=0;i<10;i++)
        {
            if(bullet[i]==NULL)
            {
                bullet[i]=new PlayerBullet();
                bullet[i]->fire(sprite.getPosition().x+8,sprite.getPosition().y);
                break;
            }
        }
        isFire=true;
    }
}
void Player::bullet_destory()
{
    for(int i=0;i<10;i++)
    {
        if(bullet[i]==NULL)
        {
            continue;
        }
        if(bullet[i]->is_over())
        {
            delete(bullet[i]);
            bullet[i]=NULL;
        }
    }
    return;
}
sf::FloatRect Player::bound()
{
    return boundingBox;
}
void Player::bullet_shotted()
{

}
