#ifndef MUSIC_H
#define MUSIC_H
#include <SFML/Audio.hpp>
class Music
{
    public:
        Music();
        virtual ~Music();
        void play();
    protected:
    private:
        sf::SoundBuffer bgm;
        sf::Sound bgm_sound;
};

#endif // MUSIC_H
