#ifndef ITEM_H
#define ITEM_H
#include <SFML/Graphics.hpp>
#define MOVE_SPEED 0.3
class Item
{
    public:
        Item();
        Item(sf::Vector2f position);
        virtual ~Item();
        virtual void move(){};
        virtual void bound(){};
        virtual bool isAdd(){return false;};
        virtual bool isOver(){return false;}
    protected:
    private:
        sf::Sprite sprite;
        sf::Texture texture;
        sf::FloatRect boundingbox;
        bool isDestory=false;
};

#endif // ITEM_H
