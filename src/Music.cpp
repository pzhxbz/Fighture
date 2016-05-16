#include "Music.h"

Music::Music()
{
    bgm.loadFromFile("sound/bgm.ogg");
    bgm_sound.setBuffer(bgm);
    bgm_sound.play();
}

Music::~Music()
{

}
void Music::play()
{

}
