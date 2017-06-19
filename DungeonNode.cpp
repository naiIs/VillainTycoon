/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DungeonNode.cpp
 * Author: logan
 * 
 * Created on April 26, 2017, 11:57 AM
 */


#include "DungeonNode.h"
#include "Dungeon.h"

// The constructor sets each adjacent node pointer to null and the location to
// the top left corner of the screen
DungeonNode::DungeonNode(int nID) : AnimatedSprite(3, 150, 150, 2){
    nodeID = nID;
    up = 0;
    down = 0;
    left = 0;
    right = 0;
}

DungeonNode::DungeonNode(DungeonNode& orig) {
}

// The de-constructor unlinks this node from each adjacent node
DungeonNode::~DungeonNode() {
    
    // This code is commented out for now, when a node in the dungeon is deleted we don't want
    // the node that's about to be deleted to mess with things.
    /*if (up){
        up->unLinkNode(d);
    }
    
    if (down){
        down->unLinkNode(u);
    }
    
    if (left){
        left->unLinkNode(r);
    }
    
    if (right){
        right->unLinkNode(l);
    }*/
}

// The linkNode method links this node to another node adjacent to it
// and also links that nodes's corresponding pointer to this node
void DungeonNode::linkNode(DungeonNode * link, direction direction){
    switch (direction){
        
        case u:
            up = link;
            link->down = this;
            break;
        case d:
            down = link;
            link->up = this;
            break;
        case l:
            left = link;
            link->right = this;
            break;
        case r:
            right = link;
            link->left = this;
            break;
    }
}

// The unlink node method sets to pointer to another node to null
DungeonNode * DungeonNode::unLinkNode(direction direction){
    
    DungeonNode * temp;
    
    switch(direction){
        
        case u:
            temp = up;
            up = 0;
            return temp;
            break;
        case d:
            temp = down;
            down = 0;
            return temp;
            break;
        case l:
            temp = left;
            left = 0;
            return temp;
            break;
        case r:
            temp = right;
            right = 0;
            return temp;
            break;
    }
}

DungeonNode * DungeonNode::getLink(direction direction){  
    
    switch(direction){        
        case u:
            return up;
            break;
        case d:
            return down;
            break;
        case l:
            return left;
            break;
        case r:
            return right;
            break;
    }
}

int DungeonNode::getID(){ 
    return nodeID; 
}