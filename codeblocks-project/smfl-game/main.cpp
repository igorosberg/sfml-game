#include "sfml.h"
#include "util.h"

using namespace util;

int main() {

    SFML sfml(640,480,"Meu jogo!");
    sfml.background(0,0,0);

    float xplayer = 100;
    float yplayer = 100;

    int xenemy = -random(0,640);
    int yenemy = random(0,480);

    float speed = 5;

    while (sfml.windowIsOpen()) {

        sfml.clear();

        bool isColliding = (dist(xplayer,yplayer,xenemy,yenemy) < 25+25) ? true : false;

        if(!isColliding) {
            xenemy += 5;
        } else {
            sfml.text("Colidiu!",10,10);
        }

        if(xenemy > 640) {
            xenemy = -random(0,640);
            yenemy = random(0,480);
        }

        if (sfml.keyIsDown(SFML::Key::Left)) {
            xplayer-=speed;
        } else if (sfml.keyIsDown(SFML::Key::Right)) {
            xplayer+=speed;
        } else if (sfml.keyIsDown(SFML::Key::Up)) {
            yplayer-=speed;
        } else if (sfml.keyIsDown(SFML::Key::Down)) {
            yplayer+=speed;
        }

        sfml.ellipse(xplayer, yplayer, 50, 50);
        sfml.rect(xenemy, yenemy, 50, 50);

        sfml.display();

    }

    return 0;
}
