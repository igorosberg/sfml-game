#include "sfml.h"

int main() {

    SFML sfml(640,480,"Meu jogo!");
    sfml.background(0,0,0);

    Image image("background.png");

    int x = 0;

    while (sfml.windowIsOpen()) {

        sfml.clear();

        sfml.image(image,0,0,x,0,640,480);
        x = (x+1)%1280;

        sfml.display();

    }

    return 0;
}
