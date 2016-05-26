#include "Bomb.h"
#include "Data.h"
Bomb::Bomb(sf::Vector2f position)
{
    texture.loadFromFile("picture/bomb.png");
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setPosition(position);
    boundingbox=sprite.getGlobalBounds();
}
Bomb::~Bomb()
{
    //dtor
}
void Bomb::move()
{
    sprite.move(0,MOVE_SPEED);
    boundingbox=sprite.getGlobalBounds();
    Data::window.draw(sprite);
    bound();
}
void Bomb::bound()
{
    if(boundingbox.intersects(Data::player.Playerbound()))
    {
        Data::bombNum++;
        isDestory=true;
    }
}
bool Bomb::isAdd()
{
    return isDestory;
}
bool Bomb::isOver()
{
    float y=sprite.getPosition().y;
    return y>HEIGHT;
}
