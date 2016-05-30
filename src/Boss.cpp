#include "Boss.h"
#include "Data.h"
#include "EnemyBulletOne.h"
#include "EnemyBulletTwo.h"
#include "BossBulletThree.h"
#include "BossBulletOne.h"
#include "BossBulletTwo.h"
#include <random>
Boss::Boss()
{
    texture.loadFromFile("picture/boss.png");
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setPosition(WIDTH/2-202/2,0-206);
    fire.restart();
    hp=Data::level*33;
}
Boss::~Boss()
{
    //dtor
}
void Boss::init()
{
    texture.loadFromFile("picture/boss.png");
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setPosition(WIDTH/2-202/2,0-206);
    hp=Data::level*25;
    fire.restart();
    isinit=true;
    for(int i=0;i<BULLET_MAX;i++)
    {
        if(bullet[i]!=NULL)
        {
            delete(bullet[i]);
            bullet[i]=NULL;
        }
    }
}
void Boss::move()
{
    Data::window.draw(sprite);
    if(sprite.getPosition().y<=20)
    {
        sprite.move(0,0.2);
        return;
    }
    for(int i=0;i<BULLET_MAX;i++)
    {
        if(bullet[i]!=NULL)
        {
            bullet[i]->move();
            if(bullet[i]->is_over())
            {
                delete(bullet[i]);
                bullet[i]=NULL;
            }
        }
    }
    if(fire.getElapsedTime().asSeconds()>0.2)
    {
        shoot();
        fire.restart();
    }
}
void Boss::shoot()
{
    int num=rand()%10+5;
    for(int i=0;i<BULLET_MAX;i++)
    {
        if(bullet[i]==NULL)
        {
            int type=rand()%100;
            if(type<60)
            {
                bullet[i]=new BossBulletOne(((rand()%20)-10)/10+0.2);
                bullet[i]->fire(sprite.getPosition().x+202/2,sprite.getPosition().y+200);
            }
            else if(type<70)
            {
                bullet[i]=new BossBulletThree(((rand()%20)-10)/10+0.2);
                bullet[i]->fire(0,0);
            }
            else if(type<90)
            {
                bullet[i]=new EnemyBulletOne(((rand()%20)-10)/10+0.2);
                bullet[i]->fire(sprite.getPosition().x+21.5,sprite.getPosition().y+60);
            }
            else if(type<99)
            {
                bullet[i]=new EnemyBulletTwo((((rand()%10)-10)/10+0.2)/2);
                bullet[i]->fire(sprite.getPosition().x+21.5+rand()%50-25,sprite.getPosition().y+60+rand()%50-25);
            }
            else if(type==99)
            {
                bullet[i]=new BossBulletTwo(((rand()%20)-10)/10+0.2);
                bullet[i]->fire(sprite.getPosition().x+202/2,sprite.getPosition().y+200);
            }
            num--;
        }
         if(num==0)
        {
            break;
        }
    }
}
sf::FloatRect Boss::collision()
{
    return sprite.getGlobalBounds();
}
void Boss::boom()
{
    Data::score+=5010;
    isinit=false;
    isBomb();
}
bool Boss::is_boom()
{
    return (hp<=0);
}
void Boss::isShoot()
{
    hp-=1;
}
bool Boss::isInit()
{
    return isinit;
}
void Boss::isBomb()
{
    for(int i=0;i<BULLET_MAX;i++)
    {
        if(bullet[i]!=NULL)
        {
            delete(bullet[i]);
            bullet[i]=NULL;
        }
    }
}
