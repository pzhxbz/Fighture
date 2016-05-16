#include "Data.h"
#include "Bullet.h"
#include "Music.h"
#include "Enemy.h"
#include "Text.h"
sf::RenderWindow Data::window(sf::VideoMode(WIDTH,HEIGHT),"Wy window");
int Data::score=0;
int Data::life=3;
sf::Texture background;
sf::Sprite background_sprite;
Player Data::a;
Text text;
Enemy* b[100];
Music music;
bool collision(sf::FloatRect enemybound);
int main()
{
    sf::Clock zzz;
    music.play();
    zzz.restart();
    while(Data::window.isOpen())
    {
        sf::Event event;
        while(Data::window.pollEvent(event))
        {
            if(event.type==sf::Event::Closed)
                Data::window.close();
        }
        if(zzz.getElapsedTime().asSeconds()>=9999999||b[0]==NULL)
        {
            for(int i=0;i<100;i++)
            {
                if(b[i]==NULL)
                {
                    b[i]=new Enemy();
                    zzz.restart();
                    break;
                }
            }
        }
        Data::window.clear(sf::Color::Black);
        Data::a.move();
        for(int i=0;i<100;i++)
        {
            if(b[i]==NULL)
            {
                continue;
            }
            if(collision(b[i]->collision())&&!b[i]->isShooted())
            {
                b[i]->boom();
                Data::score++;
            }
            if(b[i]->is_boom()||b[i]->is_over())
            {
                delete(b[i]);
                b[i]=NULL;
                continue;
            }
            b[i]->move();
        }
        text.draw();
        Data::window.display();
    }
    return 0;
}
bool collision(sf::FloatRect enemybound)
{
    for(int i=0;i<10;i++)
    {
        if(Data::a.bullet[i]==NULL)
        {
            continue;
        }
        if(enemybound.intersects(Data::a.bullet[i]->boundingBox))
        {
            Data::a.bullet[i]->destory();
            return true;
        }
    }
    return false;
}


