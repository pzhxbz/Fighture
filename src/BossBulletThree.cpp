#include "BossBulletThree.h"
#include "Data.h"
BossBulletThree::BossBulletThree(float speed)
{
    texture.loadFromFile("picture/bossBullet3.png");
    texture.setSmooth(true);
    sprite.setTexture(texture);
    boundingBox=sprite.getGlobalBounds();
    this->speed=speed*sqrt(sqrt(Data::level));
}
BossBulletThree::~BossBulletThree()
{
    //dtor
}
void BossBulletThree::fire(float x,float y)
{
    sprite.setPosition(rand()%800,0);
    move();
}
void BossBulletThree::move()
{
    sprite.move(0,speed);
    boundingBox=sprite.getGlobalBounds();
    draw();
    collision();
}
void BossBulletThree::destory()
{
    sprite.setPosition(0,HEIGHT+100);
}
void BossBulletThree::draw()
{
    Data::window.draw(sprite);
}
bool BossBulletThree::is_over()
{
    int y=sprite.getPosition().y;
    int x=sprite.getPosition().x;
    return (y>HEIGHT)||(x>WIDTH)||(y<0)||(x<0);
}
void BossBulletThree::collision()
{
    if(Data::bomb.getElapsedTime().asSeconds()>0.5&&boundingBox.intersects(Data::player.bound()))
    {
        Data::life--;
        destory();
    }
}
