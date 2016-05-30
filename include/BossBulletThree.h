#ifndef BOSSBULLETTHREE_H
#define BOSSBULLETTHREE_H
#include "Bullet.h"

class BossBulletThree:public Bullet
{
    public:
        BossBulletThree(float speed);
        virtual ~BossBulletThree();
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
};

#endif // BOSSBULLETTHREE_H
