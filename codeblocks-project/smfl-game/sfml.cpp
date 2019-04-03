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
    _fill_r = _fill_g = _fill_b = _fill_a = 255;
    _stroke_r = _stroke_g = _stroke_b = _stroke_a = 255;
    _background_r = _background_g = _background_b = 0;
    _background_a = 255;
}

void SFML::clear() {
    _color.r = _background_r;
    _color.g = _background_g;
    _color.b = _background_b;
    _color.a = _background_a;
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

    alpha = (_fill) ? _fill_a : 0;

    _color.r = _fill_r;
    _color.g = _fill_g;
    _color.b = _fill_b;
    _color.a = alpha;
    shape.setFillColor(_color);

    alpha = (_stroke) ? _stroke_a : 0;

    _color.r = _stroke_r;
    _color.g = _stroke_g;
    _color.b = _stroke_b;
    _color.a = alpha;

    shape.setOutlineThickness(_stroke_weight);
    shape.setOutlineColor(_color);

    if(angle > 0){
        sf::Transform _transform;
        _bounds = shape.getGlobalBounds();
        _transform.rotate(angle, _bounds.left+_bounds.width/2,_bounds.top+_bounds.height/2);
        _render_texture.draw(shape, _transform);
    } else {
        _render_texture.draw(shape);
    }

}

void SFML::ellipse(int x, int y, float w, float h, float angle) {
    regularPolygon(x,y,w,h,30,angle);
}

void SFML::regularPolygon(int x, int y, float w, float h, int edges, float angle) {
    float r = (w>h) ? w/2 : h/2;

    _ellipse.setRadius(r);
    _ellipse.setPointCount(edges);

    if (w > h) {
        _ellipse.setScale(1, h/w);
    } else {
        _ellipse.setScale(w/h, 1);
    }

    _ellipse.setPosition(x, y);

    drawShape(_ellipse, angle);
}

void SFML::convexPolygon(int x, int y, int points[][2], int n, float angle) {
    sf::ConvexShape convex;

    convex.setPointCount(n);

    for(int i = 0; i < n; ++i) {
        convex.setPoint(i, sf::Vector2f(points[i][0], points[i][1]));
    }

    convex.setPosition(x, y);

    drawShape(convex, angle);
}


void SFML::rect(int x, int y, float w, float h, float angle) {
    _vector2f.x = w;
    _vector2f.y = h;
    _rect.setSize(_vector2f);
    _rect.setPosition(x,y);

    //_rect.setOrigin(w/2,h/2);

    drawShape(_rect, angle);
}

void SFML::line(int x1, int y1, int x2, int y2) {
    _vector2f.x = util::dist(x1,y1,x2,y2);
    _vector2f.y = _stroke_weight;
    _rect.setSize(_vector2f);

    _rect.setPosition(x1,y1);
    _color.r = _stroke_r;
    _color.g = _stroke_g;
    _color.b = _stroke_b;
    _color.a = _stroke_a;
    _rect.setFillColor(_color);

    double angle = util::angleBwPoints(x1,y1,x2,y2);

    _rect.setOrigin(0,0);

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

void SFML::fill(int r, int g, int b, int a) {
    _fill = true;
    _fill_r = r;
    _fill_g = g;
    _fill_b = b;
    _fill_a = a;
}

void SFML::stroke(int r, int g, int b, int a) {
    _stroke = true;
    _stroke_r = r;
    _stroke_g = g;
    _stroke_b = b;
    _stroke_a = a;
}

void SFML::strokeWeight(int weight) {
    _stroke_weight = weight;
}

void SFML::background(int r, int g, int b, int a) {
    _background_r = r;
    _background_g = g;
    _background_b = b;
    _background_a = a;
}

Image SFML::loadImage(const char* path) {
    Image image(path);
    return image;
}

void SFML::image(Image &image,int dx, int dy, int sx, int sy, int sw, int sh, int angle) {
    _texture.loadFromImage(image.image,sf::IntRect(sx,sy,sw,sh));
    _sprite2.setTexture(_texture, true);

    _sprite2.setPosition(dx,dy);

    if(angle > 0){
        sf::Transform _transform;
        _transform.rotate(angle, dx+sw/2,dy+sh/2);
        _render_texture.draw(_sprite2, _transform);
    } else {
        _render_texture.draw(_sprite2);
    }
}

void SFML::image(Image &img,int dx, int dy, int angle) {
    image(img,dx,dy,0,0,img.image.getSize().x,img.image.getSize().y, angle);
}

void SFML::textSize(int _size) {
    _text_size = _size;
}

void SFML::text(const char* str, int x, int y) {
    _text.setString(str);
    _text.setFont(_font);
    _text.setCharacterSize(_text_size);

    _color.r = _fill_r;
    _color.g = _fill_g;
    _color.b = _fill_b;
    _color.a = _fill_a;
    _text.setFillColor(_color);
    _text.setPosition(x,y);

    _render_texture.draw(_text);
}

Sound SFML::loadSound(const char* path) {
    Sound sound(path);
    return sound;
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
