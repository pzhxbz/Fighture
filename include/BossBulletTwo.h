#ifndef BOSSBULLETTWO_H
#define BOSSBULLETTWO_H

#include "Bullet.h"
class BossBulletTwo:public Bullet
{
    public:
        BossBulletTwo(float speed);
        virtual ~BossBulletTwo();
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
        float aim_x,aim_y;
};

#endif // BOSSBULLETTWO_H
