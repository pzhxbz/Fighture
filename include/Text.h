#ifndef TEXT_H
#define TEXT_H
#include <SFML/Graphics.hpp>

class Text
{
    public:
        Text();
        virtual ~Text();
        void draw();
    protected:
    private:
        sf::Font font;
        sf::Text score;
        sf::Text life;
        sf::Text level;
        sf::Text bomb;
        sf::Text power;
        char s[20];
        char l[20];
        char lev[20];
        char b[20];
        char p[20];
};

#endif // TEXT_H
