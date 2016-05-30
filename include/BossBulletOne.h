#ifndef BOSSBULLETONE_H
#define BOSSBULLETONE_H

#include "Bullet.h"
class BossBulletOne:public Bullet
{
    public:
        BossBulletOne(float speed);
        virtual ~BossBulletOne();
        void fire(float x,float y);
        void move();
        void destory();
        void draw();
        sf::FloatRect boundingBox;
        bool is_over();
        void collision();
    protected:
    private:
        sf::Sprite sprite;
        sf::Texture texture;
        float speed;
        float k;
};

#endif // BOSSBULLETONE_H
