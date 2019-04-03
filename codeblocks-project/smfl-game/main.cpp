#include "sfml.h"

int main() {

    SFML sfml(640,480,"Meu jogo!");
    sfml.background(0,0,0);

    float x = 100;
    float y = 100;

    float speed = 5;

    while (sfml.windowIsOpen()) {

        sfml.clear();

        if (sfml.keyIsDown(SFML::Key::Left)) {
            x-=speed;
        } else if (sfml.keyIsDown(SFML::Key::Right)) {
            x+=speed;
        } else if (sfml.keyIsDown(SFML::Key::Up)) {
            y-=speed;
        } else if (sfml.keyIsDown(SFML::Key::Down)) {
            y+=speed;
        }

        sfml.ellipse(x, y, 50, 50);

        sfml.display();

    }

    return 0;
}
