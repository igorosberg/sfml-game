#ifndef IMAGE_H
#define IMAGE_H

#include <SFML/Graphics.hpp>

class Image {
    friend class SFML;

    private:
        sf::Image image;

    public:
        Image(const char* path);
};

#endif
