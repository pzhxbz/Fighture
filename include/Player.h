#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include "PlayerBullet.h"
#define PLAYER_BULLET_MAX 3
class Player
{
    public:
        Player();
        virtual ~Player();
        void move();
        void fire();
        void draw();
        sf::FloatRect bound();
        void bullet_destory();
        void bullet_shotted();
        PlayerBullet bullet[PLAYER_BULLET_MAX];
    protected:
    private:
        sf::Texture texture;
        sf::Sprite sprite;
        sf::Clock fire_speed;
        bool isFire=false;
        sf::FloatRect boundingBox;
        float moveSpeed;
};
#endif // PLAYER_H
