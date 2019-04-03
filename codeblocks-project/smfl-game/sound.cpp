#include "sound.h"

Sound::Sound(const char* path) {
    buffer.loadFromFile(path);
    sound.setBuffer(buffer);
}

void Sound::play() {
    sound.play();
}

void Sound::stop() {
    sound.stop();
}

void Sound::setLoop(bool loop) {
    sound.setLoop(loop);
}



