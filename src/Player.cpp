#include "Player.h"
#include "Data.h"
#include <SFML/Graphics.hpp>
Player::Player()
{
    texture.loadFromFile("picture/player.png");
    bombTexture.loadFromFile("picture/bomb_boom.png");
    effectTexture.loadFromFile("picture/effect.png");
    texture.setSmooth(true);
    bombTexture.setSmooth(true);
    effectTexture.setSmooth(true);
    sprite.setTexture(texture);
    bombsSprite.setTexture(bombTexture);
    effectSprite.setTexture(effectTexture);
    sprite.setPosition(WIDTH/2-16,HEIGHT-46);
    effectSprite.setPosition(WIDTH/2-5,HEIGHT-23-2.5);
    moveSpeed=1;
    fire_speed.restart();
}

Player::~Player()
{
    //dtor
}
void Player::move()
{
    draw();
    for(int i=0;i<PLAYER_BULLET_MAX;i++)
    {
        if(bullet[i].isFire)
        {
            bullet[i].move();
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
    {
        moveSpeed=0.5;
        Data::window.draw(effectSprite);
    }
    else
    {
        moveSpeed=1;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        sprite.move(-moveSpeed,0);
        effectSprite.move(-moveSpeed,0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        sprite.move(moveSpeed,0);
        effectSprite.move(moveSpeed,0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        sprite.move(0,-moveSpeed);
        effectSprite.move(0,-moveSpeed);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        sprite.move(0,moveSpeed);
        effectSprite.move(0,moveSpeed);
    }
    if(sprite.getPosition().x>WIDTH-32)
    {
        sprite.move(-moveSpeed,0);
        effectSprite.move(-moveSpeed,0);
    }
    if(sprite.getPosition().x<0)
    {
        sprite.move(moveSpeed,0);
        effectSprite.move(moveSpeed,0);
    }
    if(sprite.getPosition().y>HEIGHT-46)
    {
        sprite.move(0,-moveSpeed);
        effectSprite.move(0,-moveSpeed);
    }
    if(sprite.getPosition().y<0)
    {
        sprite.move(0,moveSpeed);
        effectSprite.move(0,moveSpeed);
    }
    if(fire_speed.getElapsedTime().asSeconds()>=0.5-Data::power*0.1)
    {
        fire_speed.restart();
        isFire=false;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::X)&&Data::bombNum>0&&!isBomb)
    {
        bombsSprite.setPosition(128,0);
        bombsSprite.setScale(1.0,1.0);
        isBomb=true;
        Data::bombNum--;
        Data::bomb.restart();
    }
    if(Data::bomb.getElapsedTime().asSeconds()>1)
    {
        isBomb=false;
    }
    if(isBomb)
    {
        bombsSprite.scale(1.01,1.01);
        bombsSprite.move(0.7,0.2);
        Data::window.draw(bombsSprite);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        fire();
    }
    bullet_destory();

}
void Player::draw()
{
    Data::window.draw(sprite);
}
void Player::fire()
{
    if(isFire==false)
    {
        for(int i=0;i<PLAYER_BULLET_MAX;i++)
        {
            if(!bullet[i].isFire)
            {
                bullet[i].fire(sprite.getPosition().x+8,sprite.getPosition().y);
                break;
            }
        }
        isFire=true;
    }
}
void Player::bullet_destory()
{
    for(int i=0;i<PLAYER_BULLET_MAX;i++)
    {
        if(bullet[i].is_over())
        {
            bullet[i].isFire=false;
        }
    }
    return;
}
sf::FloatRect Player::bound()
{
    return effectSprite.getGlobalBounds();
}
sf::FloatRect Player::Playerbound()
{
    return sprite.getGlobalBounds();
}
