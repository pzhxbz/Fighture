#include "Life.h"
#include "Data.h"
Life::Life(sf::Vector2f position)
{
    texture.loadFromFile("picture/life.png");
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setPosition(position);
    boundingbox=sprite.getGlobalBounds();
}

Life::~Life()
{
    //dtor
}
void Life::move()
{
    sprite.move(0,MOVE_SPEED);
    boundingbox=sprite.getGlobalBounds();
    Data::window.draw(sprite);
    bound();
}
void Life::bound()
{
    if(boundingbox.intersects(Data::player.Playerbound()))
    {
        Data::life+=1;
        isDestory=true;
    }
}
bool Life::isAdd()
{
    return isDestory;
}
bool Life::isOver()
{
    float y=sprite.getPosition().y;
    return y>HEIGHT;
}
