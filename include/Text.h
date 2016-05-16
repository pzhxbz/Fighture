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
        char s[12];
        char l[12];

};

#endif // TEXT_H
