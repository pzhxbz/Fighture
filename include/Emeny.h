#ifndef EMENY_H
#define EMENY_H
#include <SFML/Graphics.hpp>
#include "Bullet.h"
class Emeny
{
    public:
        Emeny();
        virtual ~Emeny();
        void move();
        void shoot();
        sf::Sprite draw();
        sf::Sprite draw_bullet();
    protected:
    private:
        sf::Texture texture;
        sf::Sprite sprite;
        Bullet *bullet;
        float x,y;
};
#endif // EMENY_H
