#include "Score.h"
#include "Data.h"
Score::Score(sf::Vector2f position)
{
    texture.loadFromFile("picture/score.png");
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setPosition(position);
    boundingbox=sprite.getGlobalBounds();
}

Score::~Score()
{
    //dtor
}
void Score::move()
{
    sprite.move(0,MOVE_SPEED);
    boundingbox=sprite.getGlobalBounds();
    Data::window.draw(sprite);
    bound();
}
void Score::bound()
{
    if(boundingbox.intersects(Data::player.Playerbound()))
    {
        Data::score+=100;
        isDestory=true;
    }
}
bool Score::isAdd()
{
    return isDestory;
}
bool Score::isOver()
{
    float y=sprite.getPosition().y;
    return y>HEIGHT;
}
