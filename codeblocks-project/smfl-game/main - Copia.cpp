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

    //carrega uma fonte
    loadFont("Calibri.ttf");

    //carrega uma imagem
    Image img = loadImage("zelda.png");

    //carrega um som
    SoundBuffer buffer;
    buffer.loadFromFile("deny.wav");
    Sound sound;
    sound.setBuffer(buffer);

    //variavel posicao usada para mover o quadrado
    float x = 200;

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

        //desenha uma ellipse sem preenchimento e com borda
        noFill();
        stroke(0,0,255);
        ellipse(window,200,100,120,60);

        //desenha um retangulo sem borda que se move
        noStroke();
        fill(255, 0, 0);
        rect(window,x,200,80,80);
        x += 0.1;
        if(x > 800) {
            sound.play();
            x = 0;
        }

        //desenha uma linha
        stroke(60, 150, 60);
        strokeWeight(3);
        line(window,100,300,400,400);

        //desenha uma imagem
        image(window,img, 100, 350, 100, 100);

        //desenha uma texto
        textSize(30);
        text(window, "Score", 10, 10);

        display(window);

    }

    return 0;
}

