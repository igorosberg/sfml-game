#ifndef SFML_H
#define SFML_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class SFML {
    public:
        enum Key {
            Unknown = -1, A = 0, B, C,
            D, E, F, G,
            H, I, J, K,
            L, M, N, O,
            P, Q, R, S,
            T, U, V, W,
            X, Y, Z, Num0,
            Num1, Num2, Num3, Num4,
            Num5, Num6, Num7, Num8,
            Num9, Escape, LControl, LShift,
            LAlt, LSystem, RControl, RShift,
            RAlt, RSystem, Menu, LBracket,
            RBracket, Semicolon, Comma, Period,
            Quote, Slash, Backslash, Tilde,
            Equal, Hyphen, Space, Enter,
            Backspace, Tab, PageUp, PageDown,
            End, Home, Insert, Delete,
            Add, Subtract, Multiply, Divide,
            Left, Right, Up, Down,
            Numpad0, Numpad1, Numpad2, Numpad3,
            Numpad4, Numpad5, Numpad6, Numpad7,
            Numpad8, Numpad9, F1, F2,
            F3, F4, F5, F6,
            F7, F8, F9, F10,
            F11, F12, F13, F14,
            F15, Pause, KeyCount, Dash = Hyphen,
            BackSpace = Backspace, BackSlash = Backslash, SemiColon = Semicolon, Return = Enter
        };

    private:

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
        sf::Clock _clock;

        double distance(double x1, double y1, double x2, double y2);

        double angleBwPoints(int x1, int y1, int x2, int y2);

        void processEvents();

        bool mouseButtonIsPressed(sf::Mouse::Button button);

        void drawShape(sf::Shape &shape, float angle);

    public:

        SFML(int w, int h, const char* title);

        void clear();

        void display();

        void ellipse(int x, int y, float w, float h, float angle = 0);

        void rect(int x, int y, float w, float h, float angle = 0);

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

        bool windowIsOpen();

        sf::Sound loadSound(sf::SoundBuffer buffer);

        bool mouseLeftButtonIsPressed();

        bool mouseRightButtonIsPressed();

        int mouseX();

        int mouseY();

        bool keyIsDown(Key key);

        int getElapsedTime();


};

#endif
