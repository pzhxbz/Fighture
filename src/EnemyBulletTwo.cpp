#include "EnemyBulletTwo.h"
#include <SFML/Graphics.hpp>
#include <cmath>
EnemyBulletTwo::EnemyBulletTwo(float speed)
{
    texture.loadFromFile("picture/enemy_bullet2.png");
    texture.setSmooth(true);
    sprite.setTexture(texture);
    boundingBox=sprite.getGlobalBounds();
    this->speed=speed*sqrt(Data::level);
    t.restart();
}
EnemyBulletTwo::~EnemyBulletTwo()
{

}
void EnemyBulletTwo::fire(float x,float y)
{
    sprite.setPosition(x,y);
    move();
}
void EnemyBulletTwo::move()
{
    float x=PI*t.getElapsedTime().asSeconds();
    sprite.move(speed*(cos(x)-x*sin(x)),speed*(sin(x)+x*cos(x)));
    boundingBox=sprite.getGlobalBounds();
    draw();
    collision();
}
void EnemyBulletTwo::draw()
{
    Data::window.draw(sprite);
}
bool EnemyBulletTwo::is_over()
{
    int y=sprite.getPosition().y;
    int x=sprite.getPosition().x;
    return (y>HEIGHT+100)||(x>WIDTH+100)||(y<-100)||(x<-100);
}
void EnemyBulletTwo::destory()
{
    sprite.setPosition(0,HEIGHT+100);
}
void EnemyBulletTwo::collision()
{
    if(Data::bomb.getElapsedTime().asSeconds()>0.5&&boundingBox.intersects(Data::player.bound()))
    {
        Data::life--;
        destory();
    }
}
