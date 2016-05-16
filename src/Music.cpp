#include "Music.h"

Music::Music()
{
    bgm.loadFromFile("sound/bgm.ogg");
    bgm_sound.setBuffer(bgm);
}

Music::~Music()
{
    //dtor
}
void Music::play()
{
    bgm_sound.play();
}
