#include "sfml.h"
#include "util.h"

using namespace util;

int main() {

    SFML sfml(640,480,"Meu jogo!");
    sfml.background(0,0,0);

    Image image1("zelda.png");
    Image image2("zelda.png");

    while (sfml.windowIsOpen()) {

        sfml.clear();

        sfml.image(image1,125,125);

        sfml.noFill();
        sfml.stroke(255,255,255);
        sfml.rect(125,125,125,125);

        sfml.image(image2,300,300,63,63,125,125);

        sfml.display();

    }

    return 0;
}
