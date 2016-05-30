#include "Text.h"
#include "Data.h"
#include <cstdlib>
Text::Text()
{
    font.loadFromFile("fonts/font.ttf");
    score.setFont(font);
    life.setFont(font);
    level.setFont(font);
    bomb.setFont(font);
    power.setFont(font);
    score.setCharacterSize(20);
    life.setCharacterSize(20);
    level.setCharacterSize(20);
    bomb.setCharacterSize(20);
    power.setCharacterSize(20);
    score.setColor(sf::Color::Red);
    life.setColor(sf::Color::Blue);
    level.setColor(sf::Color::Red);
    bomb.setColor(sf::Color::Green);
    power.setColor(sf::Color::Black);
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
    sprintf(b,"\n\n\nbomb:%d",Data::bombNum);
    if(Data::power>4)
    {
        Data::power=4;
    }
    sprintf(p,"\n\n\n\npower:%.2f/4.00",Data::power);
    score.setString(s);
    life.setString(l);
    level.setString(lev);
    bomb.setString(b);
    power.setString(p);
    Data::window.draw(score);
    Data::window.draw(life);
    Data::window.draw(level);
    Data::window.draw(bomb);
    Data::window.draw(power);
    return;
}
void Text::endText()
{
    endGame.setFont(font);
    endGame.setCharacterSize(30);
    endGame.setColor(sf::Color::Red);
    sprintf(end,"Congratualtions!\nYour score:%d\nPlease Press R to restart this game\nPress F1 to continue game",Data::score);
    endGame.setString(end);
    endGame.setPosition(WIDTH/2-200,HEIGHT/2-100);
    Data::window.draw(endGame);
}

