#include "Music.h"

Music::Music()
{
    bgm.loadFromFile("sound/bgm.ogg");
}

Music::~Music()
{

}
void Music::replay()
{
    bgm_sound.setBuffer(bgm);
    bgm_sound.setLoop(true);
    bgm_sound.play();
}
