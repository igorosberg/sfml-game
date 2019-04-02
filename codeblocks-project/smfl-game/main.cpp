#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "draw.h"
#include "util.h"

using namespace draw;
using namespace sf;
using namespace util;

int main() {

    //cria a janela
    init(640,480,"Meu jogo!");

    //define a cor de fundo
    background(255,255,255);

    stroke(0,0,0);

    clear();

    //início do laço principal do jogo
    while (windowIsOpen()) {
        Event event = lastEvent();

        if (event.type == Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                line(random(0,640),random(0,480),random(0,640),random(0,480));
                display();
            }
        }
    }

    return 0;
}
