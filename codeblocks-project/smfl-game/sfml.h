#ifndef SFML_H
#define SFML_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class SFML {
    public:
        bool _fill;
        bool _stroke;
        int _text_size;
        int _stroke_weight = 1;
        int _fill_r, _fill_g, _fill_b;
        int _stroke_r, _stroke_g, _stroke_b;
        int _background_r, _background_g, _background_b;
        sf::Font _font;
        sf::RenderTexture _render_texture;
        sf::RenderWindow _window;
        sf::Event _event;

        double distance(double x1, double y1, double x2, double y2);

        double angleBwPoints(int x1, int y1, int x2, int y2);

        void processEvents();

        bool mouseButtonIsPressed(sf::Mouse::Button button);

    public:

        SFML(int w, int h, const char* title);

        void clear();

        void display();

        void ellipse(int x, int y, float w, float h);

        void rect(int x, int y, float w, float h);

        void line(int x1, int y1, int x2, int y2);

        void noFill();

        void noStroke();

        void fill(int r, int g, int b);

        void stroke(int r, int g, int b);

        void strokeWeight(int weight);

        void background(int r, int g, int b);

        sf::Image loadImage(const char* path);

        void image(sf::Image &image,int x, int y, int w = -1, int h = -1);

        void textSize(int _size);

        void text(const char* text, int x, int y);

        void loadFont(const char* path);

        bool windowIsOpen();

        sf::Sound loadSound(sf::SoundBuffer buffer);

        bool mouseLeftButtonIsPressed();

        bool mouseRightButtonIsPressed();


};

#endif
