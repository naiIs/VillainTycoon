/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Hero.cpp
 * Author: logan
 * 
 * Created on May 12, 2017, 11:00 AM
 */

#include "Hero.h"
#include "Dungeon.h"
#include <SFML/Graphics.hpp>

Hero::Hero() {
    offset = 50;
    location = 0;
}

Hero::Hero(const Hero& orig) {
}

Hero::~Hero() {
}

void Hero::draw(sf::RenderWindow &window){
        
    window.draw(*this);
}

void Hero::move(DungeonNode * node){
    location = node;
    this->setPosition(location->getPosition().x + offset, location->getPosition().y + offset);
}

DungeonNode * Hero::getLocation(){
    return location;
}