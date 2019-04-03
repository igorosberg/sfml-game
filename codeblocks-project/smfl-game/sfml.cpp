#include "sfml.h"
#include "util.h"

# define PI 3.14159265358979323846

double SFML::distance(double x1, double y1, double x2, double y2){
    return sqrt(pow(x2-x1,2)+pow(y2-y1,2));
}

double SFML::angleBwPoints(int x1, int y1, int x2, int y2) {
    double dy = y2-y1;
    double dx = x2-x1;
    double theta = atan2(dy,dx);
    theta *= 180/PI;
    if(theta < 0) theta = 360 + theta;
    return theta;
}

void SFML::processEvents() {
    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed)
            _window.close();
    }
}

SFML::SFML(int w, int h, const char* title) {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    _window.create(sf::VideoMode(w, h), title, sf::Style::Default, settings);
    _window.setFramerateLimit(120);
    _render_texture.create(w,h);
    _font.loadFromFile("Calibri.ttf");

    _fill = true;
    _stroke = false;
    _text_size = 16;
    _stroke_weight = 1;
    _fill_r = _fill_g = _fill_b = 255;
    _stroke_r = _stroke_g = _stroke_b = 255;
    _background_r = _background_g = _background_b = 0;
}

void SFML::clear() {
    _render_texture.clear(sf::Color(_background_r,_background_g,_background_b));
}

void SFML::display() {
    _render_texture.display();
    _window.clear();
    sf::Sprite sprite(_render_texture.getTexture());
    _window.draw(sprite);
    _window.display();
}

void SFML::drawShape(sf::Shape &shape, float angle) {
    double alpha = (_fill) ? 255 : 0;
    shape.setFillColor(sf::Color(_fill_r,_fill_g,_fill_b,alpha));

    alpha = (_stroke) ? 255 : 0;
    shape.setOutlineThickness(_stroke_weight);
    shape.setOutlineColor(sf::Color(_stroke_r, _stroke_g, _stroke_b, alpha));
    shape.rotate(angle);

    _render_texture.draw(shape);
}

void SFML::ellipse(int x, int y, float w, float h, float angle) {
    float r = (w>h) ? w/2 : h/2;

    sf::CircleShape ellipse(r);

    if (w > h) {
        ellipse.setScale(1, h/w);
        ellipse.setPosition(x-r,y-h/w*r);
    } else {
        ellipse.setScale(w/h, 1);
        ellipse.setPosition(x-w/h*r, y-r);
    }

    drawShape(ellipse, angle);
}

void SFML::rect(int x, int y, float w, float h, float angle) {
    sf::RectangleShape rect(sf::Vector2f(w,h));
    rect.setPosition(x,y);
    rect.setOrigin(w/2,h/2);

    drawShape(rect, angle);
}

void SFML::line(int x1, int y1, int x2, int y2) {
    sf::RectangleShape rect(sf::Vector2f(distance(x1,y1,x2,y2),_stroke_weight));
    rect.setPosition(x1,y1);
    rect.setFillColor(sf::Color(_stroke_r,_stroke_g,_stroke_b));

    double angle = angleBwPoints(x1,y1,x2,y2);

    rect.rotate(angle);

    _render_texture.draw(rect);
}

void SFML::noFill() {
    _fill = false;
}

void SFML::noStroke() {
    _stroke = false;
}

void SFML::fill(int r, int g, int b) {
    _fill = true;
    _fill_r = r;
    _fill_g = g;
    _fill_b = b;
}

void SFML::stroke(int r, int g, int b) {
    _stroke = true;
    _stroke_r = r;
    _stroke_g = g;
    _stroke_b = b;
}

void SFML::strokeWeight(int weight) {
    _stroke_weight = weight;
}

void SFML::background(int r, int g, int b) {
    _background_r = r;
    _background_g = g;
    _background_b = b;
}

sf::Image SFML::loadImage(const char* path) {
    sf::Image image;
    image.loadFromFile(path);
    return image;
}

void SFML::image(sf::Image &image,int x, int y, int w, int h) {
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

void SFML::textSize(int _size) {
    _text_size = _size;
}

void SFML::text(const char* _text, int x, int y) {
    sf::Text text(_text, _font, _text_size);
    text.setCharacterSize(_text_size);
    text.setFillColor(sf::Color(_fill_r,_fill_g,_fill_b));
    text.setPosition(x,y);
    _render_texture.draw(text);
}

sf::Sound SFML::loadSound(sf::SoundBuffer buffer) {
    sf::Sound s;
    s.setBuffer(buffer);
    s.setVolume(50.f);
    return s;
}

bool SFML::windowIsOpen() {
    processEvents();
    return _window.isOpen();
}

bool SFML::mouseButtonIsPressed(sf::Mouse::Button button){
    if (sf::Mouse::isButtonPressed(button)) {
        return true;
    }
    return false;
}

bool SFML::mouseLeftButtonIsPressed() {
    return mouseButtonIsPressed(sf::Mouse::Left);
}

bool SFML::mouseRightButtonIsPressed() {
    return mouseButtonIsPressed(sf::Mouse::Right);
}

int SFML::mouseX() {
    return sf::Mouse::getPosition(_window).x;
}

int SFML::mouseY() {
    return sf::Mouse::getPosition(_window).y;
}

bool SFML::keyIsDown(Key key){
    return sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(key));
}

int SFML::getElapsedTime() {
    return _clock.restart().asMilliseconds();
}
