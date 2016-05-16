#include "Enemy.h"
#include "Data.h"
#include <random>
#define Random(a) (rand()%a)
Enemy::Enemy()
{
    image.loadFromFile("picture/enemy.png");
    texture.loadFromImage(image);
    texture.setSmooth(true);
    sprite.setTexture(texture);
    this->x=Random(WIDTH-43);
    this->y=-52;
    sprite.setPosition(x,y);
    boundingBox=sprite.getGlobalBounds();
    fire.restart();
}
Enemy::~Enemy()
{

}
void Enemy::move()
{
    if(fire.getElapsedTime().asSeconds()>1.5)
    {
        isFire=false;
        fire.restart();
    }
    shoot();
    if(!isDestory)
    {
        sprite.move(0,0.1);
    }
    for(int i=0;i<100;i++)
    {
        if(bullet[i]==NULL)
        {
            continue;
        }
        bullet[i]->move();
        if(bullet[i]->is_over())
        {
            delete(bullet[i]);
            bullet[i]=NULL;
        }
    }
    boundingBox=sprite.getGlobalBounds();
    draw();
}
void Enemy::draw()
{
    Data::window.draw(sprite);
}
void Enemy::draw_bullet()
{

}
void Enemy::shoot()
{
    if(!isFire&&!isDestory)
    {
        for(int i=0;i<100;i++)
        {
            if(bullet[i]==NULL)
            {
                bullet[i]=new EnemyBulletOne(1);
                bullet[i]->fire(sprite.getPosition().x+21.5,sprite.getPosition().y+60);
                isFire=true;
                fire.restart();
                break;
            }
        }
    }
    return;
}
sf::FloatRect Enemy::collision()
{
    return boundingBox;
}
void Enemy::boom()
{
    boom_image.loadFromFile("picture/enemy_boom.gif");
    boom_texture.loadFromImage(boom_image);
    boom_texture.setSmooth(true);
    sprite.setTexture(boom_texture);
    boom_buffer.loadFromFile("sound/boom.ogg");
    boom_music.setBuffer(boom_buffer);
    boom_music.play();
    if(!isDestory)
    {
        boom_time.restart();
    }
    isDestory=true;
}
bool Enemy::isShooted()
{
    return isDestory;
}
bool Enemy::is_boom()
{
    return (boom_time.getElapsedTime().asSeconds()>1.0&&isDestory);
}
bool Enemy::is_over()
{
    int x=sprite.getPosition().x;
    int y=sprite.getPosition().y;
    return ((y>=HEIGHT)||(x>WIDTH)||(x<=0));
}
