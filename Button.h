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

#include "Clickable.h"
#include "AnimatedSprite.h"
#include <SFML/Graphics.hpp>
#include "AnimatedSprite.h"
#include "Clickable.h"
#include <string>

class Button : public AnimatedSprite, public Clickable {
public:
    Button();
    Button(const Button& orig);
    virtual ~Button();
    std::string defaultTexture();
    void clicked(sf::Event &event);
    void released(sf::Event &event);
    void dragged(sf::Event &event);
    void draw(sf::RenderWindow &window);
private:
    sf::IntRect frameBounds;
    sf::Font font;
    sf::Text text;
protected:        
    std::string buttonTexture;
};

#endif /* BUTTON_H */

