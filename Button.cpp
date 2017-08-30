/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Button.cpp
 * Author: logan
 * 
 * Created on May 19, 2017, 10:47 AM
 */

#include "Button.h"
#include "AnimatedSprite.h"

Button::Button(){
    frameBounds.width = 150;
    frameBounds.height = 50;
    frameBounds.top = 0;
    frameBounds.left = 0;
    buttonTexture = "Images/Button.png";
}

Button::Button(const Button& orig) {
}

Button::~Button() {
}

std::string Button::defaultTexture(){
    return buttonTexture;
}

void Button::clicked(sf::Event &event){
    frameBounds.left = 150;
    setTextureRect(frameBounds);
}

void Button::released(sf::Event &event){
    frameBounds.left = 0;
    setTextureRect(frameBounds);
}

void Button::dragged(sf::Event &event){
    
}

void Button::draw(sf::RenderWindow &window){
    window.draw(*this);
}
