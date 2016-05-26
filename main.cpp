#include "Data.h"
#include "Bullet.h"
#include "Music.h"
#include "Enemy.h"
#include "Text.h"
#include "Item.h"
#include "Score.h"
#include "Life.h"
#include "Power.h"
#include "Bomb.h"
#define ENEMY_MAX_NUM 8
sf::RenderWindow Data::window(sf::VideoMode(WIDTH,HEIGHT),"Wy window");
int Data::score=14999;
int Data::life=3;
int Data::level=1;
int Data::bombNum=3;
float Data::power=1.0;
sf::Clock Data::bomb;
Player Data::player;
Text text;
Enemy* enemy[ENEMY_MAX_NUM];
sf::Clock enemyInit;
float enemyInterval=rand()%3+0.5;
bool isRestart=false;
Item* item[ENEMY_MAX_NUM*5];
Music music;
bool collision(sf::FloatRect enemybound);
void init();
void enemy_action();
void item_action();
void text_print();
void init_enemy();
void init_item(sf::Vector2f position);
int main()
{
    bool isClose=false;
    Data::window.setFramerateLimit(240);
    for(;!isClose;)
    {
        init();
        while(Data::window.isOpen())
        {
            sf::Event event;
            while(Data::window.pollEvent(event))
            {
                if(event.type==sf::Event::Closed)
                {
                    isClose=true;
                    Data::window.close();
                    break;
                }
            }
            Data::window.clear(sf::Color::Black);
            init_enemy();
            if(Data::life<0)
            {
                text.endText();
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
                {
                    break;
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::F1))
                {
                    isRestart=true;
                    break;
                }
            }
            else
            {
                Data::player.move();
            }
            enemy_action();
            item_action();
            text_print();

        }
    }
    Data::window.close();
    return 0;
}
void init()
{
    Data::player.resetPosition();
    Data::life=3;
    Data::bombNum=3;
    if(isRestart)
    {
        isRestart=false;
        Data::bomb.restart();
        return;
    }
    music.replay();
    Data::score=0;
    Data::level=1;
    Data::power=1.0;
    for(int i=0;i<ENEMY_MAX_NUM;i++)
    {
        if(enemy[i]!=NULL)
        {
            delete(enemy[i]);
            enemy[i]=NULL;
        }
    }
    for(int i=0;i<ENEMY_MAX_NUM*5;i++)
    {
        if(item[i]!=NULL)
        {
            delete(item[i]);
            item[i]=NULL;
        }
    }
}
void init_enemy()
{
    if(enemyInit.getElapsedTime().asSeconds()>enemyInterval)
    {
        for(int i=0;i<ENEMY_MAX_NUM;i++)
        {
            if(enemy[i]==NULL)
            {
                enemy[i]=new Enemy();
                enemyInterval=(rand()%43-Data::level*3)/10;
                enemyInit.restart();
                break;
            }
        }
    }
}
bool collision(sf::FloatRect enemybound)
{
    if(Data::bomb.getElapsedTime().asSeconds()<0.5)
    {
        return true;
    }
    for(int i=0;i<PLAYER_BULLET_MAX;i++)
    {
        if(!Data::player.bullet[i].isFire)
        {
            continue;
        }
        if(enemybound.intersects(Data::player.bullet[i].boundingBox))
        {
            Data::player.bullet[i].destory();
            return true;
        }
    }
    return false;
}
void enemy_action()
{
    for(int i=0;i<ENEMY_MAX_NUM;i++)
    {
        if(enemy[i]==NULL)
        {
            continue;
        }
        if(!enemy[i]->isShooted())
        {
            if(collision(enemy[i]->collision()))
            {
                enemy[i]->boom();
            }
        }
        if(enemy[i]->is_boom()||enemy[i]->is_over())
        {
            if(enemy[i]->is_boom())
            {
                init_item(enemy[i]->position());
            }
            delete(enemy[i]);
            enemy[i]=NULL;
            continue;
        }
        enemy[i]->move();
    }
}
void item_action()
{
    for(int i=0;i<ENEMY_MAX_NUM*5;i++)
    {
        if(item[i]==NULL)
        {
            continue;
        }
        item[i]->move();
        if(item[i]->isAdd()||item[i]->isOver())
        {
            delete(item[i]);
            item[i]=NULL;
        }
    }
}
void init_item(sf::Vector2f position)
{
    int num=rand()%5+1;
    for(int i=0;i<ENEMY_MAX_NUM*5;i++)
    {
        if(item[i]==NULL)
        {
            int type=rand()%100;
            sf::Vector2f initPosition=position;
            initPosition.x+=10*num-30;
            initPosition.y+=10*num-30;
            if(type<3)
            {
                item[i]=new Life(initPosition);
            }
            else if(type<8)
            {
                item[i]=new Bomb(initPosition);
            }
            else if(type<30)
            {
                item[i]=new Score(initPosition);
            }
            else if(type<55)
            {
                item[i]=new Power(initPosition);
            }
            num--;
            if(num==0)
            {
                break;
            }
        }
    }
}
void text_print()
{
    Data::level=Data::score/5000+1;
    text.draw();
    Data::window.display();
}
