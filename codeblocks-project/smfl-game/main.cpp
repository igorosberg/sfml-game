#include "sfml.h"
#include "util.h"

using namespace util;

int main() {

    //cria a janela
    SFML sfml(640,480,"Meu jogo!");

    //define a cor de fundo
    sfml.background(255,255,255);

    sfml.stroke(0,0,0);

    sfml.clear();

    //início do laço principal do jogo
    while (sfml.windowIsOpen()) {

        if(sfml.mouseLeftButtonIsPressed()) {
            sfml.line(random(0,640),random(0,480),random(0,640),random(0,480));
            sfml.display();
        }

    }

    return 0;
}
