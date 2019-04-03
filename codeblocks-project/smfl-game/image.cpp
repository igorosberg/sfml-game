#include "image.h"

Image::Image(const char* path) {
    image.loadFromFile(path);
}



