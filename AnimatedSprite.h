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

#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H

#include <SFML/Graphics.hpp>

class AnimatedSprite : public sf::Sprite {
public:
    AnimatedSprite(int maxF, int fWidth, int fHeight);
    AnimatedSprite(const AnimatedSprite& orig);
    virtual ~AnimatedSprite();
    void nextFrame();
    void draw(sf::RenderWindow &window);
private:
    int maxFrames;
    int currentFrame;
    sf::IntRect frameBounds;
};

#endif /* ANIMATEDSPRITE_H */

