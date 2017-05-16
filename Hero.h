/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Hero.h
 * Author: logan
 *
 * Created on May 12, 2017, 11:00 AM
 */

#include "DungeonNode.h"

#ifndef HERO_H
#define HERO_H

class Hero : public sf::Sprite{
public:
    Hero();
    Hero(const Hero& orig);
    virtual ~Hero();
    void draw(sf::RenderWindow &window);
    void move(DungeonNode * node);
    DungeonNode * getLocation();
private:
    DungeonNode * location;
    int offset;
};

#endif /* HERO_H */

