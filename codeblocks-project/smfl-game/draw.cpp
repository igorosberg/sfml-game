#include "draw.h"
#include <cmath>
#include<iostream>

# define PI 3.14159265358979323846

namespace draw {
    namespace {
        bool _fill = true;
        bool _stroke = true;
        int _text_size = 30;
        int _stroke_weight = 1;
        int _fill_r = 255, _fill_g = 255, _fill_b = 255;
        int _stroke_r = 255, _stroke_g = 255, _stroke_b = 255;
        int _background_r = 0, _background_g = 0, _background_b = 0;
        sf::Font _font;
        sf::RenderTexture _render_texture;

        sf::RenderWindow _window;


        double distance(double x1, double y1, double x2, double y2){
            return sqrt(pow(x2-x1,2)+pow(y2-y1,2));
        }

        double angleBwPoints(int x1, int y1, int x2, int y2) {
            double dy = y2-y1;
            double dx = x2-x1;
            double theta = atan2(dy,dx);
            theta *= 180/PI;
            if(theta < 0) theta = 360 + theta;
            return theta;
        }

    };

    void init(int w, int h, const char* title) {
        sf::ContextSettings settings;
        settings.antialiasingLevel = 8;
        _window.create(sf::VideoMode(w, h), title, sf::Style::Default, settings);
        _render_texture.create(w,h);
    }

    void clear() {
        _render_texture.clear(sf::Color(_background_r,_background_g,_background_b));
    }

    void display() {
        _render_texture.display();
        _window.clear();
        sf::Sprite sprite(_render_texture.getTexture());
        _window.draw(sprite);
        _window.display();
    }

    void ellipse(int x, int y, float w, float h) {
        float r = (w>h) ? w/2 : h/2;

        sf::CircleShape ellipse(r);

        if (w > h) {
            ellipse.setScale(1, h/w);
            ellipse.setPosition(x-r,y-h/w*r);
        } else {
            ellipse.setScale(w/h, 1);
            ellipse.setPosition(x-w/h*r, y-r);
        }

        double alpha = (_fill) ? 255 : 0;
        ellipse.setFillColor(sf::Color(_fill_r,_fill_g,_fill_b,alpha));

        if(_stroke) {
            ellipse.setOutlineThickness(_stroke_weight);
            ellipse.setOutlineColor(sf::Color(_stroke_r, _stroke_g, _stroke_b));
        }

        _render_texture.draw(ellipse);
    }

    void rect(int x, int y, float w, float h) {
        sf::RectangleShape rect(sf::Vector2f(w,h));
        rect.setPosition(x,y);

        double alpha = (_fill) ? 255 : 0;
        rect.setFillColor(sf::Color(_fill_r,_fill_g,_fill_b, alpha));

        if(_stroke) {
            rect.setOutlineThickness(_stroke_weight);
            rect.setOutlineColor(sf::Color(_stroke_r, _stroke_g, _stroke_b));
        }

        _render_texture.draw(rect);
    }

    void line(int x1, int y1, int x2, int y2) {
        sf::RectangleShape rect(sf::Vector2f(distance(x1,y1,x2,y2),_stroke_weight));
        rect.setPosition(x1,y1);
        rect.setFillColor(sf::Color(_stroke_r,_stroke_g,_stroke_b));

        double angle = angleBwPoints(x1,y1,x2,y2);

        rect.rotate(angle);
        _render_texture.draw(rect);
    }

    void noFill() {
        _fill = false;
    }

    void noStroke() {
        _stroke = false;
    }

    void fill(int r, int g, int b) {
        _fill = true;
        _fill_r = r;
        _fill_g = g;
        _fill_b = b;
    }

    void stroke(int r, int g, int b) {
        _stroke = true;
        _stroke_r = r;
        _stroke_g = g;
        _stroke_b = b;
    }

    void strokeWeight(int weight) {
        _stroke_weight = weight;
    }

    void background(int r, int g, int b) {
        _background_r = r;
        _background_g = g;
        _background_b = b;
    }

    sf::Image loadImage(const char* path) {
        sf::Image image;
        image.loadFromFile(path);
        return image;
    }

    void image(sf::Image &image,int x, int y, int w, int h) {
        sf::Texture texture;
        texture.loadFromImage(image);

        sf::Sprite sprite;
        sprite.setTexture(texture);

        float xscale = (w!=-1) ? (float)w/texture.getSize().x : 1;
        float yscale = (h!=-1) ? (float)h/texture.getSize().y : 1;

        sprite.setScale(xscale,yscale);

        sprite.setPosition(x,y);

        _render_texture.draw(sprite);
    }

    void textSize(int _size) {
        _text_size = _size;
    }

    void text(const char* _text, int x, int y) {
        sf::Text text(_text, _font, _text_size);
        text.setCharacterSize(_text_size);
        text.setFillColor(sf::Color(_fill_r,_fill_g,_fill_b));
        text.setPosition(x,y);
        _render_texture.draw(text);
    }

    void loadFont(const char* path) {
        _font.loadFromFile(path);
    }

    sf::Sound loadSound(sf::SoundBuffer buffer) {
        sf::Sound s;
        s.setBuffer(buffer);
        s.setVolume(50.f);
        return s;
    }

    bool windowIsOpen() {
        return _window.isOpen();
    }

    sf::Event lastEvent() {
        sf::Event event;
        while (_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                _window.close();
        }
        return event;
    }


}
