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
        sf::FloatRect Playerbound();
        void bullet_destory();
        PlayerBullet bullet[PLAYER_BULLET_MAX];
        void resetPosition();
        sf::Vector2f getPosition();
    protected:
    private:
        sf::Texture texture;
        sf::Sprite sprite;
        sf::Texture bombTexture;
        sf::Sprite bombsSprite;
        sf::Texture effectTexture;
        sf::Sprite effectSprite;
        sf::Clock fire_speed;
        bool isFire=false;
        float moveSpeed;
        bool isBomb=false;
};
#endif // PLAYER_H
