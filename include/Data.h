#ifndef DATA_H
#define DATA_H
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#define WIDTH 800
#define HEIGHT 600
class Data
{
    public:
        Data();
        virtual ~Data();
        static int score;
        static int life;
        static sf::RenderWindow window;
        static Player a;
    protected:
    private:
};
#endif // DATA_H
