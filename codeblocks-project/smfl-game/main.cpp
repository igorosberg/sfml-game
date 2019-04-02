#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "draw.h"

using namespace draw;
using namespace sf;

int main() {

    //cria a janela
    ContextSettings settings;
    settings.antialiasingLevel = 8;
    RenderWindow window(sf::VideoMode(800, 600), "Meu jogo!", Style::Default, settings);

    //define a cor de fundo
    background(0,0,0);

    //início do laço principal do jogo
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        clear(window);

        //desenha uma ellipse com preenchimento vermelho
        fill(255, 0, 0);
        ellipse(window,200,100,120,60);

        display(window);
    }

    return 0;
}

