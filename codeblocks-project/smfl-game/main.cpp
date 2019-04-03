#include "sfml.h"
#include "util.h"
#include <cstring>

using namespace util;

int main() {

    SFML sfml(640,480,"Meu jogo!");
    sfml.background(200,200,200);
    sfml.fill(0,0,0);

    sfml.textSize(18);

    int x1 = 10;
    int y1 = 90;
    char frase[100];

    while (sfml.windowIsOpen()) {

        sfml.clear();

        int x2 = sfml.mouseX();
        int y2 = sfml.mouseY();

        sfml.line(x1, y1, x2, y2);
        sfml.ellipse(x1, y1, 7, 7);
        sfml.ellipse(x2, y2, 7, 7);

        //calcula a distância entre os pontos (x1,y1) e (x2,y2)
        int d = dist(x1, y1, x2, y2);

        sprintf(frase,"A distância entre os pontos é %d pixels.",d);

        sfml.text(frase, 80, 400);

        sfml.display();
    }

    return 0;
}
