/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AnimatedSprite.cpp
 * Author: logan
 * 
 * Created on May 16, 2017, 10:19 AM
 */

#include "AnimatedSprite.h"

AnimatedSprite::AnimatedSprite(int maxF, int fWidth, int fHeight) {
    maxFrames = maxF;
    currentFrame = 1;
    frameBounds.left = 0;
    frameBounds.top = 0;
    frameBounds.height = fHeight;
    frameBounds.width = fWidth;
}

AnimatedSprite::AnimatedSprite(const AnimatedSprite& orig) {
}

AnimatedSprite::~AnimatedSprite() {
}

void AnimatedSprite::nextFrame(){
    
    if (currentFrame < maxFrames){
        currentFrame++;
        frameBounds.left += frameBounds.width;
    } else {
        currentFrame = 1;
        frameBounds.left = 0;
    }
}

void AnimatedSprite::draw(sf::RenderWindow &window){
    nextFrame();
    setTextureRect(frameBounds);
    window.draw(*this);
}