#ifndef BOSS_H
#define BOSS_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Bullet.h"
#define BULLET_MAX 150
class Boss
{
    public:
        Boss();
        virtual ~Boss();
        void move();
        void shoot();
        void isShoot();
        sf::FloatRect collision();
        void boom();
        void init();
        bool is_boom();
        bool isInit();
        void isBomb();
        sf::Vector2f position();
    protected:
    private:
        sf::Texture texture;
        sf::Sprite sprite;
        Bullet* bullet[BULLET_MAX]={NULL};
        sf::Sound boom_music;
        sf::SoundBuffer boom_buffer;
        bool isDestory=false;
        bool isinit=false;
        sf::Clock fire;
        sf::Clock boom_time;
        float fireInterval=0.5;
        int hp;
};

#endif // BOSS_H
