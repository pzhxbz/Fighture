#include "Text.h"
#include "Data.h"
#include <cstdlib>
Text::Text()
{
    font.loadFromFile("fonts/font.ttf");
    score.setFont(font);
    life.setFont(font);
    score.setCharacterSize(20);
    life.setCharacterSize(20);
    sprintf(s,"Your score:%d",Data::score);
    sprintf(l,"\nYour life:%d",Data::life);
    score.setString(s);
    life.setString(l);
    score.setColor(sf::Color::Red);
    life.setColor(sf::Color::Blue);
}
Text::~Text()
{
    //dtor
}
void Text::draw()
{
    sprintf(s,"Your score:%d",Data::score);
    sprintf(l,"\nYour life:%d",Data::life);
    score.setString(s);
    life.setString(l);
    Data::window.draw(score);
    Data::window.draw(life);
    return;
}
