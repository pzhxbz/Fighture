#include "EnemyBulletOne.h"
#include <SFML/Graphics.hpp>
EnemyBulletOne::EnemyBulletOne(float speed)
{
    texture.loadFromFile("picture/enemy_bullet1.png");
    texture.setSmooth(true);
    sprite.setTexture(texture);
    boundingBox=sprite.getGlobalBounds();
    this->speed=speed;
    k=(rand()%200000)*PI/100000;
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
    sprite.move(speed*cos(k),speed*sin(k));
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
    int x=sprite.getPosition().x;
    return (y>HEIGHT)||(x>WIDTH)||(y<0)||(x<0);
}
void EnemyBulletOne::destory()
{
    sprite.setPosition(0,HEIGHT+100);
}
void EnemyBulletOne::collision()
{
    if(boundingBox.intersects(Data::player.bound()))
    {
        Data::life--;
        destory();
    }
}
