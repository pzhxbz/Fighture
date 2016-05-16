#include "EnemyBulletOne.h"
#include <SFML/Graphics.hpp>
EnemyBulletOne::EnemyBulletOne(float speed)
{
    texture.loadFromFile("picture/enemy_bullet1.png");
    texture.setSmooth(true);
    sprite.setTexture(texture);
    boundingBox=sprite.getGlobalBounds();
    this->speed=speed;
}
EnemyBulletOne::~EnemyBulletOne()
{

}
void EnemyBulletOne::fire(float x,float y)
{
    sprite.setPosition(x,y);
    move();
}
void EnemyBulletOne::move()
{
    sprite.move(0,speed);
    boundingBox=sprite.getGlobalBounds();
    draw();
    collision();
}
void EnemyBulletOne::draw()
{
    Data::window.draw(sprite);
}
bool EnemyBulletOne::is_over()
{
    int y=sprite.getPosition().y;
    return (y>HEIGHT);
}
void EnemyBulletOne::destory()
{
    sprite.setPosition(0,HEIGHT+100);
}
void EnemyBulletOne::collision()
{
    if(boundingBox.intersects(Data::a.bound()))
    {
        Data::life--;
        destory();
    }
}
