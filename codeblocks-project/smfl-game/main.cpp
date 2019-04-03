#include "sfml.h"

int main() {

    //cria a janela com tamanho 640x480 pixels
    SFML sfml(640,480,"Meu jogo!");

    //define a cor de fundo como preto
    sfml.background(0,0,0);

    //início do laço principal do jogo
    while (sfml.windowIsOpen()) {

        //apaga o conteúdo da janela
        sfml.clear();

        //Desenha uma ellipse no centro da tela
        sfml.ellipse(320-50, 240-50, 100, 100);

        //mostra o conteúdo na janela
        sfml.display();

    }

    return 0;
}
