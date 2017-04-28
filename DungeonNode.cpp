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

//#define nullptr nullptr

DungeonNode::DungeonNode() {
    up = 0;
    down = 0;
    left = 0;
    right = 0;
    location.x = 0;
    location.y = 0;
}

DungeonNode::DungeonNode(const DungeonNode& orig) {
}

DungeonNode::~DungeonNode() {
}

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