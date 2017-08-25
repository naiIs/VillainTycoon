/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AnimatedSprite.h
 * Author: logan
 *
 * Created on May 16, 2017, 10:19 AM
 */

// This is our Animated Sprite class, the class that most game objects will inheret
// from. It inherits from the Sprite class and adds a framework for an animated
// sprite sheet
#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H

#include <SFML/Graphics.hpp>
#include <string>

class AnimatedSprite : public sf::Sprite {
public:
    AnimatedSprite(int maxF, int fWidth, int fHeight, int fDelay);
    AnimatedSprite();
    AnimatedSprite(const AnimatedSprite& orig);
    virtual ~AnimatedSprite();
    void nextFrame();
    void draw(sf::RenderWindow &window);
private:
    int maxFrames; // The number of frames the animation will cycle through
    int currentFrame; // The frame that we're currently drawing
    int frameDelay; // The amount of time to wait before updating the frame
    int currentDelay;
    sf::IntRect frameBounds;
    std::string defaultSprite;
};

#endif /* ANIMATEDSPRITE_H */

