#include "PlayerBullet.h"
#include <SFML/Graphics.hpp>
#include "Data.h"
PlayerBullet::PlayerBullet()
{
    texture.loadFromFile("picture/fire.png");
    texture.setSmooth(true);
    sprite.setTexture(texture);
    boundingBox=sprite.getGlobalBounds();
    speed=-5;
}
PlayerBullet::~PlayerBullet()
{
}
void PlayerBullet::fire(float x,float y)
{
    sprite.setPosition(x,y);
    move();
}
void PlayerBullet::move()
{
    sprite.move(0,speed);
    boundingBox=sprite.getGlobalBounds();
    draw();
}
void PlayerBullet::draw()
{
    Data::window.draw(sprite);
}
bool PlayerBullet::is_over()
{
    int y=sprite.getPosition().y;
    return (y<0);
}
void PlayerBullet::destory()
{
    sprite.setPosition(0,-100);
}

