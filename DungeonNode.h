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
#include "Minion.h"
#include "AnimatedSprite.h"
#include "Clickable.h"

enum direction { u, d, l, r };

class DungeonNode : public AnimatedSprite, public Clickable{
public:
    DungeonNode(int nID);
    DungeonNode(DungeonNode& orig);
    virtual ~DungeonNode();
    void linkNode(DungeonNode * link, direction direction);
    DungeonNode * unLinkNode(direction direction);
    DungeonNode * getLink(direction direction);
    int getID(); 
    void clicked(sf::Event &event);
    void released(sf::Event &event);
    void dragged(sf::Event &event);
private:
    DungeonNode * up;
    DungeonNode * down;
    DungeonNode * left;
    DungeonNode * right;
    int nodeID;
};

#endif /* DUNGEONNODE_H */

