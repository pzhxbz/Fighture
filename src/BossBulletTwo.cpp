#include "BossBulletTwo.h"
#include "Data.h"
BossBulletTwo::BossBulletTwo(float speed)
{
    texture.loadFromFile("picture/bossBullet2.png");
    texture.setSmooth(true);
    sprite.setTexture(texture);
    boundingBox=sprite.getGlobalBounds();
    this->speed=speed*sqrt(sqrt(Data::level));
}

BossBulletTwo::~BossBulletTwo()
{
    //dtor
}
void BossBulletTwo::fire(float x,float y)
{
    sprite.setPosition(x,y);
    sf::Vector2f aim=Data::player.getPosition();
    aim_x=aim.x-x;
    aim_y=aim.y-y;
    move();
}
void BossBulletTwo::move()
{
    sprite.move(aim_x*speed/150,aim_y*speed/150);
    boundingBox=sprite.getGlobalBounds();
    draw();
    collision();
}
void BossBulletTwo::destory()
{
    sprite.setPosition(0,HEIGHT+100);
}
void BossBulletTwo::draw()
{
    Data::window.draw(sprite);
}
bool BossBulletTwo::is_over()
{
    int y=sprite.getPosition().y;
    int x=sprite.getPosition().x;
    return (y>HEIGHT)||(x>WIDTH)||(y<0)||(x<0);
}
void BossBulletTwo::collision()
{
    if(Data::bomb.getElapsedTime().asSeconds()>0.5&&boundingBox.intersects(Data::player.bound()))
    {
        Data::life--;
        destory();
    }
}
