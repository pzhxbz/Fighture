#ifndef BULLET_H
#define BULLET_H
#include <SFML/Graphics.hpp>
class Bullet
{
    public:
        Bullet(){};
        Bullet(float a){};
        virtual ~Bullet(){};
        virtual void fire(float x,float y){};
        virtual void move(){};
        virtual void destory(){};
        virtual void draw(){};
        sf::FloatRect boundingBox;
        virtual bool is_over(){return true;};
        virtual void collision(){};
    protected:
    private:
        sf::Sprite sprite;
        sf::Texture texture;
        float speed;
};

#endif // BULLET_H
