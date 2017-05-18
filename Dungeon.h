/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Dungeon.h
 * Author: logan
 *
 * Created on May 4, 2017, 9:41 AM
 */

#ifndef DUNGEON_H
#define DUNGEON_H

#include "DungeonNode.h"

class Dungeon {
public:
    Dungeon(sf::Texture &texture);
    Dungeon(const Dungeon& orig);
    virtual ~Dungeon();
    void draw(sf::RenderWindow &window);
    bool add(DungeonNode * node);    
    DungeonNode * getEntrance();
    void soundOff();
private:
    // Here we'll create our room data structure, a series of linked DungeonNode
    // pointers stored in a 2d array
    int dungeonHeight;
    int dungeonWidth;
    DungeonNode * dungeon[3][3];
    sf::Vector2i location;
    sf::Vector2i tileSize;
    int snapRange;
    DungeonNode * replace(DungeonNode * node, DungeonNode * oldNode);
};

#endif /* DUNGEON_H */