#include "sfml.h"

int main() {

    SFML sfml(640,480,"Meu jogo!");
    sfml.background(0,0,0);

    Image image("zelda.png");

    while (sfml.windowIsOpen()) {

        sfml.clear();

        sfml.image(image,320,240);

        sfml.display();

    }

    return 0;
}
