#include "sfml.h"
#include "util.h"

using namespace util;

int main() {

    SFML sfml(640,480,"Meu jogo!");
    sfml.background(0,0,0);

    int xo = -random(0,640);
    int yo = random(0,480);

    int angle = 0;

    while (sfml.windowIsOpen()) {

        sfml.clear();

        xo += 3;

        if(xo > 640) {
            xo = -random(0,640);
            yo = random(0,480);
        }

        sfml.rect(xo,yo,40,40, angle);

        angle = (angle+2)%360;

        sfml.display();
    }

    return 0;
}
