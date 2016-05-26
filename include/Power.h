#ifndef POWER_H
#define POWER_H
#include <SFML/Graphics.hpp>
#include "Item.h"
class Power:public Item
{
    public:
        Power(sf::Vector2f position);
        virtual ~Power();
        void move();
        void bound();
        bool isAdd();
        bool isOver();
    protected:
    private:
        sf::Sprite sprite;
        sf::Texture texture;
        sf::FloatRect boundingbox;
        bool isDestory=false;
};

#endif // POWER_H
