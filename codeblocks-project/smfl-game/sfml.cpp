#include "sfml.h"
#include "util.h"

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
    _color.r = _background_r;
    _color.g = _background_g;
    _color.b = _background_b;
    _color.a = 255;
    _render_texture.clear(_color);
}

void SFML::display() {
    _render_texture.display();
    _window.clear();
    _sprite.setTexture(_render_texture.getTexture());
    _window.draw(_sprite);
    _window.display();
}

void SFML::drawShape(sf::Shape &shape, float angle) {
    double alpha;

    alpha = (_fill) ? 255 : 0;

    _color.r = _fill_r;
    _color.g = _fill_g;
    _color.b = _fill_b;
    _color.a = alpha;
    shape.setFillColor(_color);

    alpha = (_stroke) ? 255 : 0;

    _color.r = _stroke_r;
    _color.g = _stroke_g;
    _color.b = _stroke_b;
    _color.a = alpha;

    shape.setOutlineThickness(_stroke_weight);
    shape.setOutlineColor(_color);

    shape.rotate(angle);
    _render_texture.draw(shape);
    shape.rotate(-angle);
}

void SFML::ellipse(int x, int y, float w, float h, float angle) {
    float r = (w>h) ? w/2 : h/2;

    _ellipse.setRadius(r);

    if (w > h) {
        _ellipse.setScale(1, h/w);
        _ellipse.setPosition(x,y);
    } else {
        _ellipse.setScale(w/h, 1);
        _ellipse.setPosition(x, y);
    }

    _ellipse.setOrigin(r,r);
    drawShape(_ellipse, angle);
    _ellipse.setOrigin(0,0);
}

void SFML::rect(int x, int y, float w, float h, float angle) {
    _vector2f.x = w;
    _vector2f.y = h;
    _rect.setSize(_vector2f);
    _rect.setPosition(x,y);

    _rect.setOrigin(w/2,h/2);
    drawShape(_rect, angle);
    _rect.setOrigin(0,0);
}

void SFML::line(int x1, int y1, int x2, int y2) {
    _vector2f.x = util::dist(x1,y1,x2,y2);
    _vector2f.y = _stroke_weight;
    _rect.setSize(_vector2f);

    _rect.setPosition(x1,y1);
    _color.r = _stroke_r;
    _color.g = _stroke_g;
    _color.b = _stroke_b;
    _color.a = 255;
    _rect.setFillColor(_color);

    double angle = util::angleBwPoints(x1,y1,x2,y2);

    _rect.rotate(angle);
    _render_texture.draw(_rect);
    _rect.rotate(-angle);
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

void SFML::text(const char* str, int x, int y) {
    _text.setString(str);
    _text.setFont(_font);
    _text.setCharacterSize(_text_size);

    _text.setFillColor(sf::Color(_fill_r,_fill_g,_fill_b));
    _text.setPosition(x,y);

    _render_texture.draw(_text);
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
