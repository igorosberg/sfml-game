#ifndef DRAW_H
#define DRAW_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

namespace draw {

    void clear(sf::RenderWindow &window);

    void display(sf::RenderWindow &window);

    void ellipse(sf::RenderWindow &window, int x, int y, float w, float h);

    void rect(sf::RenderWindow &window, int x, int y, float w, float h);

    void line(sf::RenderWindow &window, int x1, int y1, int x2, int y2);

    void noFill();

    void noStroke();

    void fill(int r, int g, int b);

    void stroke(int r, int g, int b);

    void strokeWeight(int weight);

    void background(int r, int g, int b);

    sf::Image loadImage(const char* path);

    void image(sf::RenderWindow &window, sf::Image &image,int x, int y, int w = -1, int h = -1);

    void textSize(int _size);

    void text(sf::RenderWindow &window, const char* text, int x, int y);

    void loadFont(const char* path);

    sf::Sound loadSound(sf::SoundBuffer buffer);


}

#endif
