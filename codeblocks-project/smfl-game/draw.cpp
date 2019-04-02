#include "draw.h"
#include <cmath>
#include<iostream>

# define PI 3.14159265358979323846

namespace draw {
    namespace {
        bool _fill = true;
        bool _stroke = false;
        int _text_size = 30;
        int _stroke_weight = 3;
        int _fill_r = 255, _fill_g = 255, _fill_b = 255;
        int _stroke_r = 255, _stroke_g = 255, _stroke_b = 255;
        int _background_r = 0, _background_g = 0, _background_b = 0;
        sf::Font _font;


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

    void clear(sf::RenderWindow &window) {
        window.clear(sf::Color(_background_r,_background_g,_background_b));
    }

    void display(sf::RenderWindow &window) {
        window.display();
    }

    void ellipse(sf::RenderWindow &window, int x, int y, float w, float h) {
        float r = (w>h) ? w/2 : h/2;

        sf::CircleShape ellipse(r);

        if (w > h) {
            ellipse.setScale(1, h/w);
            ellipse.setPosition(x-r,y-h/w*r);
        } else {
            ellipse.setScale(w/h, 1);
            ellipse.setPosition(x-w/h*r, y-r);
        }

        if(_fill) {
            ellipse.setFillColor(sf::Color(_fill_r,_fill_g,_fill_b));
        } else {
            ellipse.setFillColor(sf::Color(_background_r,_background_g,_background_b));
        }

        if(_stroke) {
            ellipse.setOutlineThickness(_stroke_weight);
            ellipse.setOutlineColor(sf::Color(_stroke_r, _stroke_g, _stroke_b));
        }

        window.draw(ellipse);
    }

    void rect(sf::RenderWindow &window, int x, int y, float w, float h) {
        sf::RectangleShape rect(sf::Vector2f(w,h));
        rect.setPosition(x,y);

        if(_fill) {
            rect.setFillColor(sf::Color(_fill_r,_fill_g,_fill_b));
        } else {
            rect.setFillColor(sf::Color(_background_r,_background_g,_background_b));
        }

        if(_stroke) {
            rect.setOutlineThickness(_stroke_weight);
            rect.setOutlineColor(sf::Color(_stroke_r, _stroke_g, _stroke_b));
        }

        window.draw(rect);
    }

    void line(sf::RenderWindow &window, int x1, int y1, int x2, int y2) {
        sf::RectangleShape rect(sf::Vector2f(distance(x1,y1,x2,y2),_stroke_weight));
        rect.setPosition(x1,y1);
        rect.setFillColor(sf::Color(_stroke_r,_stroke_g,_stroke_b));

        double angle = angleBwPoints(x1,y1,x2,y2);

        rect.rotate(angle);
        window.draw(rect);
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

    void image(sf::RenderWindow &window, sf::Image &image,int x, int y, int w, int h) {
        sf::Texture texture;
        texture.loadFromImage(image);

        sf::Sprite sprite;
        sprite.setTexture(texture);

        float xscale = (w!=-1) ? (float)w/texture.getSize().x : 1;
        float yscale = (h!=-1) ? (float)h/texture.getSize().y : 1;

        sprite.setScale(xscale,yscale);

        sprite.setPosition(x,y);

        window.draw(sprite);
    }

    void textSize(int _size) {
        _text_size = _size;
    }

    void text(sf::RenderWindow &window, const char* _text, int x, int y) {
        sf::Text text(_text, _font, _text_size);
        text.setCharacterSize(_text_size);
        text.setFillColor(sf::Color(_fill_r,_fill_g,_fill_b));
        text.setPosition(x,y);
        window.draw(text);
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


}
