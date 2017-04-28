/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DungeonNode.h
 * Author: logan
 *
 * Created on April 26, 2017, 11:57 AM
 */

#ifndef DUNGEONNODE_H
#define DUNGEONNODE_H

#include <SFML/System.hpp>
#include "Tile.h"

enum direction { u, d, l, r };

class DungeonNode {
public:
    DungeonNode();
    DungeonNode(const DungeonNode& orig);
    virtual ~DungeonNode();
    void linkNode(DungeonNode * link, direction direction);
private:
    DungeonNode * up;
    DungeonNode * down;
    DungeonNode * left;
    DungeonNode * right;
    sf::Vector2i location;
    Tile * tile;
};

#endif /* DUNGEONNODE_H */

