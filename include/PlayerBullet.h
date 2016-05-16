#ifndef PLAYERBULLET_H
#define PLAYERBULLET_H
#include "Bullet.h"
class PlayerBullet:public Bullet
{
    public:
        PlayerBullet();
        virtual ~PlayerBullet();
        void fire(float x,float y);
        void move();
        void destory();
        void draw();
        sf::FloatRect boundingBox;
        bool is_over();
    protected:
    private:
        sf::Sprite sprite;
        sf::Texture texture;
        float speed;
};

#endif // PLAYERBULLET_H
