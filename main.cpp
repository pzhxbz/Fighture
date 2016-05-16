#include "Data.h"
#include "Bullet.h"
#include "Music.h"
#include "Enemy.h"
#include "Text.h"
#define ENEMY_MAX_NUM 7
sf::RenderWindow Data::window(sf::VideoMode(WIDTH,HEIGHT),"Wy window");
int Data::score=0;
int Data::life=3;
int Data::level=3;
sf::Texture background;
sf::Sprite background_sprite;
Player Data::player;
Text text;
Enemy* enemy[ENEMY_MAX_NUM];
Music music;
bool collision(sf::FloatRect enemybound);
int main()
{
    sf::Clock enemyInit;
    enemyInit.restart();
    float enemyInterval=rand()%3;
    while(Data::window.isOpen())
    {
        sf::Event event;
        while(Data::window.pollEvent(event))
        {
            if(event.type==sf::Event::Closed)
                Data::window.close();
        }
        if(enemyInit.getElapsedTime().asSeconds()>enemyInterval)
        {
            for(int i=0;i<ENEMY_MAX_NUM;i++)
            {
                if(enemy[i]==NULL)
                {
                    enemy[i]=new Enemy();
                    enemyInterval=(rand()%33-Data::level*3)/10;
                    enemyInit.restart();
                    break;
                }
            }
        }
        Data::window.clear(sf::Color::Black);
        Data::player.move();
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
                delete(enemy[i]);
                enemy[i]=NULL;
                continue;
            }
            enemy[i]->move();
        }
        Data::level=Data::score/400+1;
        text.draw();
        Data::window.display();
        if(Data::level>3)
        {
            Data::level=1;
        }
    }
    return 0;
}
bool collision(sf::FloatRect enemybound)
{
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


