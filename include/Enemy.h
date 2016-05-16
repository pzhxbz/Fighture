#ifndef EMENY_H
#define EMENY_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Bullet.h"
#include "EnemyBulletOne.h"
class Enemy
{
    public:
        Enemy();
        virtual ~Enemy();
        void move();
        void shoot();
        void draw();
        void draw_bullet();
        sf::FloatRect collision();
        void boom();
        bool isShooted();
        bool is_boom();
        bool is_over();
    protected:
    private:
        sf::Texture texture;
        sf::Texture boom_texture;
        sf::Sprite sprite;
        Bullet* bullet[100]={NULL};
        float x,y;
        sf::FloatRect boundingBox;
        sf::Sound boom_music;
        sf::SoundBuffer boom_buffer;
        sf::Image boom_image;
        sf::Image image;
        bool isDestory=false;
        bool isFire=false;
        sf::Clock fire;
        sf::Clock boom_time;
};
#endif // EMENY_H
