#include "sfml.h"

int main() {

    SFML sfml(640,480,"Meu jogo!");
    sfml.background(0,0,0);

    Image image("explosion-sprite.png");

    bool animating = false;
    int i = 0;
    int x, y;
    int w = 100; //largura do objeto no sprite
    int h = 100; //altura do objeto no sprite


    while (sfml.windowIsOpen()) {

        sfml.clear();

        if(sfml.mouseLeftButtonIsPressed() && !animating) {
            animating = true;
            x = sfml.mouseX();
            y = sfml.mouseY();
        }

        if(animating) {
            sfml.image(image,x-w/2,y-h/2,(i%9)*w,(i/9)*h,w,h);
            i++;
            if(i == 81) {
                animating = false;
                i = 0;
            }
        }

        sfml.display();

    }

    return 0;
}
