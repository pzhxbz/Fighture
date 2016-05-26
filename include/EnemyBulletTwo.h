#ifndef ENEMYBULLETTWO_H
#define ENEMYBULLETTWO_H
#include "Data.h"
class EnemyBulletTwo:public Bullet
{
    public:
        EnemyBulletTwo(float speed);
        virtual ~EnemyBulletTwo();
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
        sf::Clock t;
        float speed;
};

#endif // ENEMYBULLETTWO_H
