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
    sprite.setPosition(Random(WIDTH-43),-52);
    boundingBox=sprite.getGlobalBounds();
    fireInterval=Random(3);
    hp=Random(3)+Data::level*2;
    score=hp*10;
    fire.restart();
}
Enemy::~Enemy()
{
    for(int i=0;i<BULLET_MAX_NUM;i++)
    {
        if(bullet[i]!=NULL)
        {
            delete(bullet[i]);
            bullet[i]=NULL;
        }
    }
}
void Enemy::move()
{
    for(int i=0;i<BULLET_MAX_NUM;i++)
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
    if(sprite.getPosition().y>HEIGHT)
    {
        return;
    }
    draw();
    if(isDestory)
    {
        float t=boom_time.getElapsedTime().asSeconds();
        sprite.setScale(t*2.2,t*2.2);
        return;
    }
    if(fire.getElapsedTime().asSeconds()>fireInterval)
    {
        isFire=false;
        fireInterval=Random(60)/10-Data::level;
        fire.restart();
    }
    shoot();
    if(!isDestory)
    {
        sprite.move(0,0.1);
    }

    boundingBox=sprite.getGlobalBounds();
}
void Enemy::draw()
{
    Data::window.draw(sprite);
}
void Enemy::shoot()
{
    if(!isFire&&!isDestory)
    {
        for(int i=0;i<BULLET_MAX_NUM;i++)
        {
            if(bullet[i]==NULL)
            {
                int type=rand()%3;
                if(type==1||type==0)
                {
                    bullet[i]=new EnemyBulletOne(((rand()%20)-10)/10+0.2);
                    bullet[i]->fire(sprite.getPosition().x+21.5,sprite.getPosition().y+60);
                }
                else if(type==2)
                {
                    bullet[i]=new EnemyBulletTwo((((rand()%10)-10)/10+0.2)/2);
                    bullet[i]->fire(sprite.getPosition().x+21.5+rand()%50-25,sprite.getPosition().y+60+rand()%50-25);
                }
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
    if(hp>0)
    {
        hp--;
        return;
    }
    image.loadFromFile("picture/enemy_boom.png");
    texture.loadFromImage(image);
    texture.setSmooth(true);
    sprite.setTexture(texture);
    boom_buffer.loadFromFile("sound/boom.ogg");
    boom_music.setBuffer(boom_buffer);
    boom_music.play();
    if(!isDestory)
    {
        boom_time.restart();
    }
    isDestory=true;
    sprite.move(0,20);
    Data::score+=score;
}
bool Enemy::isShooted()
{
    return isDestory;
}
bool Enemy::is_boom()
{
    return (boom_time.getElapsedTime().asSeconds()>0.5&&isDestory);
}
bool Enemy::is_over()
{
    int x=sprite.getPosition().x;
    int y=sprite.getPosition().y;
    for(int i=0;i<BULLET_MAX_NUM;i++)
    {
        if(bullet[i]==NULL)
        {
            continue;
        }
        if(!bullet[i]->is_over())
        {
            return false;
        }
    }
    return ((y>=HEIGHT)||(x<=0));
}
sf::Vector2f Enemy::position()
{
    return sprite.getPosition();
}
