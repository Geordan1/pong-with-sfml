// Pong by Geordan Sfetsos with SFML
#include <SFML/Graphics.hpp>
#include <iostream>
//libarys
int main() {
    sf::RenderWindow window(sf::VideoMode(1000,600), "test", sf::Style::Close | sf::Style::None);
    window.setFramerateLimit(30);
    //setup
    int p1y = 0;
    int p2y = 0;
    int ball_x = 70;
    int ball_y = 0;
    int ball_x_speed = 10;
    int ball_y_speed = 10;
    //vars
    while (window.isOpen()) {
        sf::Event evnt;
        while (window.pollEvent(evnt)) {
            if (evnt.type == sf::Event::Closed) {
                window.close();
            }
        }
        //check if close
        if (ball_y > 550) {
            ball_y_speed = 0-ball_y_speed;
        }
        if (ball_y < 0) {
            ball_y_speed = 0-ball_y_speed;
        }
        //ball bounce
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            p1y -= 10;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            p1y += 10;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            p2y -= 10;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            p2y += 10;
        }
        //key input
        if (p1y >= 500) {
            p1y = 500;
        }
        if (p1y <= 0) {
            p1y = 0;
        }
        if (p2y >= 500) {
            p2y = 500;
        }
        if (p2y <= 0) {
            p2y = 0;
        }
        //padlle stoper
        if (ball_x < 20) {
            window.close();
        }
        if (ball_x+50 > 980) {
            window.close();
        }
        //ball pass player detect
        if (ball_x > 910 && ball_y < p2y+100 && ball_y+50 > p2y) {
            ball_x_speed = 0-ball_x_speed;
        } else if (ball_x < 40 && ball_y < p1y+100 && ball_y+50 > p1y) {
            ball_x_speed = 0-ball_x_speed;
        }
        //detect ball padlle
        ball_x += ball_x_speed;
        ball_y += ball_y_speed;
        //add speed
        window.clear(sf::Color(0,0,0));
        sf::RectangleShape shape(sf::Vector2f(20, 100));
        shape.setPosition(sf::Vector2f(20, p1y));
        shape.setFillColor(sf::Color(255,255,255));
        window.draw(shape);
        sf::RectangleShape shape2(sf::Vector2f(20, 100));
        shape2.setPosition(sf::Vector2f(960, p2y));
        shape2.setFillColor(sf::Color(255,255,255));
        window.draw(shape2);
        sf::CircleShape shape3(25);
        shape3.setPosition(sf::Vector2f(ball_x, ball_y));
        shape3.setFillColor(sf::Color(255,255,255));
        window.draw(shape3);
        window.display();
        //render
    }
    return 0;
}