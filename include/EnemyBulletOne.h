#ifndef ENEMYBULLETONE_H
#define ENEMYBULLETONE_H
#include "Data.h"
#include "Bullet.h"
class EnemyBulletOne:public Bullet
{
    public:
        EnemyBulletOne(float speed);
        virtual ~EnemyBulletOne();
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

#endif // ENEMYBULLETONE_H
