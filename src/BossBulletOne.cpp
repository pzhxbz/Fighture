#include "BossBulletOne.h"
#include "Data.h"
BossBulletOne::BossBulletOne(float speed)
{
    texture.loadFromFile("picture/bossBullet1.png");
    texture.setSmooth(true);
    sprite.setTexture(texture);
    boundingBox=sprite.getGlobalBounds();
    this->speed=speed*sqrt(sqrt(Data::level));
    k=(rand()%200000-100000)*PI/100000;
}

BossBulletOne::~BossBulletOne()
{
    //dtor
}
void BossBulletOne::fire(float x,float y)
{
    sprite.setPosition(x,y);
    move();
}
void BossBulletOne::move()
{
    sprite.move(4*speed*cos(k),4*speed*sin(k));
    boundingBox=sprite.getGlobalBounds();
    draw();
    collision();
}
void BossBulletOne::destory()
{
    sprite.setPosition(0,HEIGHT+100);
}
void BossBulletOne::draw()
{
    Data::window.draw(sprite);
}
bool BossBulletOne::is_over()
{
    int y=sprite.getPosition().y;
    int x=sprite.getPosition().x;
    return (y>HEIGHT)||(x>WIDTH)||(y<0)||(x<0);
}
void BossBulletOne::collision()
{
    if(Data::bomb.getElapsedTime().asSeconds()>0.5&&boundingBox.intersects(Data::player.bound()))
    {
        Data::life--;
        destory();
    }
}
