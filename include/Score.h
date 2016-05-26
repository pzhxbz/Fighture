#ifndef SCORE_H
#define SCORE_H
#include <SFML/Graphics.hpp>
#include "Item.h"
class Score:public Item
{
    public:
        Score(sf::Vector2f position);
        virtual ~Score();
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

#endif // SCORE_H
