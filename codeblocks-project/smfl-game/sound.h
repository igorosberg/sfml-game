#ifndef SOUND_H
#define SOUND_H

#include <SFML/Audio.hpp>

class Sound {
    friend class SFML;

    private:
        sf::SoundBuffer buffer;
        sf::Sound sound;

    public:
        Sound(const char* path);

        void play();
        void stop();
        void setLoop(bool loop);
};

#endif

