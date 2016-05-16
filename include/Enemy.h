#ifndef EMENY_H
#define EMENY_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Bullet.h"
#include "EnemyBulletOne.h"
#define BULLET_MAX_NUM 15
class Enemy
{
    public:
        Enemy();
        virtual ~Enemy();
        void move();
        void shoot();
        void draw();
        sf::FloatRect collision();
        void boom();
        bool isShooted();
        bool is_boom();
        bool is_over();
    protected:
    private:
        sf::Texture texture;
        sf::Sprite sprite;
        Bullet* bullet[BULLET_MAX_NUM]={NULL};
        sf::FloatRect boundingBox;
        sf::Sound boom_music;
        sf::SoundBuffer boom_buffer;
        sf::Image image;
        bool isDestory=false;
        bool isFire=false;
        sf::Clock fire;
        sf::Clock boom_time;
        float fireInterval;
        int hp;
        int score;
};
#endif // EMENY_H
