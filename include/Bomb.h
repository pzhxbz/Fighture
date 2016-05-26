#ifndef BOMB_H
#define BOMB_H
#include "Item.h"

class Bomb:public Item
{
    public:
        Bomb(sf::Vector2f position);
        virtual ~Bomb();
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

#endif // BOMB_H
