#include "Text.h"
#include "Data.h"
#include <cstdlib>
Text::Text()
{
    font.loadFromFile("fonts/font.ttf");
    score.setFont(font);
    life.setFont(font);
    level.setFont(font);
    score.setCharacterSize(20);
    life.setCharacterSize(20);
    level.setCharacterSize(20);
    sprintf(s,"Your score:%d",Data::score);
    sprintf(l,"\nYour life:%d",Data::life);
    sprintf(lev,"\n\nlevel:%d",Data::level);
    score.setString(s);
    life.setString(l);
    level.setString(lev);
    score.setColor(sf::Color::Red);
    life.setColor(sf::Color::Blue);
    level.setColor(sf::Color::White);
}
Text::~Text()
{
    //dtor
}
void Text::draw()
{
    sprintf(s,"Your score:%d",Data::score);
    sprintf(l,"\nYour life:%d",Data::life);
    sprintf(lev,"\n\nlevel:%d",Data::level);
    score.setString(s);
    life.setString(l);
    level.setString(lev);
    Data::window.draw(score);
    Data::window.draw(life);
    Data::window.draw(level);
    return;
}
