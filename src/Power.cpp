#include "Power.h"
#include "Data.h"
Power::Power(sf::Vector2f position)
{
    texture.loadFromFile("picture/power.png");
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setPosition(position);
    boundingbox=sprite.getGlobalBounds();
}

Power::~Power()
{
    //dtor
}
void Power::move()
{
    sprite.move(0,MOVE_SPEED);
    boundingbox=sprite.getGlobalBounds();
    Data::window.draw(sprite);
    bound();
}
void Power::bound()
{
    if(boundingbox.intersects(Data::player.Playerbound()))
    {
        float powerNum=(float)(rand()%5)/100+0.02;
        Data::power+=powerNum;
        isDestory=true;
    }
}
bool Power::isAdd()
{
    return isDestory;
}
bool Power::isOver()
{
    float y=sprite.getPosition().y;
    return y>HEIGHT;
}
