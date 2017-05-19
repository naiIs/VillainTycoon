/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Button.h
 * Author: logan
 *
 * Created on May 19, 2017, 10:47 AM
 */

#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <string>

class Button : public sf::Sprite {
public:
    Button();
    Button(const Button& orig);
    virtual ~Button();
    std::string defaultTexture();
    void clicked();
    void released();
    void draw(sf::RenderWindow &window);
private:
    sf::IntRect frameBounds;
    sf::Font font;
    sf::Text text;
};

#endif /* BUTTON_H */

