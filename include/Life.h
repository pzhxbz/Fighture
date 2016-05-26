#ifndef LIFE_H
#define LIFE_H

#include "Item.h"
class Life:public Item
{
    public:
        Life(sf::Vector2f position);
        virtual ~Life();
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

#endif // LIFE_H
