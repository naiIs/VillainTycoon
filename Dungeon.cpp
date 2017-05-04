/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Dungeon.cpp
 * Author: logan
 * 
 * Created on May 4, 2017, 9:41 AM
 */

#include "Dungeon.h"

Dungeon::Dungeon() {
    
    // Here we initialize our array size
    dungeonHeight = 3;
    dungeonWidth = 3;
    //dungeon = new DungeonNode[dungeonHeight][dungeonWidth];
    
    // This for loop initializes the elements in our dungeon to nodes
    for (int i = 0; i < dungeonHeight; i++) {
        for (int j = 0; j < dungeonWidth; j++){
            
            // This line creates a new node object which the element in the array points to
            dungeon[i][j] = new DungeonNode;
            
            //This line sets the location of each element in the array
        }
    }
    
    // Here we link each node to its neighbors. Since the code for nodes includes
    // a link back to the linking node we only have to make two links per node. EG:
    // if I link a node to the node above it and to the right of it, then those nodes
    // won't have to be manually linked back to this node.
    
    // This first loop links every cell except the far left and bottom cells, it links
    // each cell to the cell to the left and the cell to the bottom. It doesn't try 
    // to link the left and bottom rows since, at the edge of the array, they wouldn't
    // have anything to link to.
    for (int i = 0; i < dungeonHeight - 1; i++){
        for (int j = 0; j < dungeonHeight -1; j++){
            dungeon[i][j]->linkNode(dungeon[i+1][j], l);
            dungeon[i][j]->linkNode(dungeon[i][j+1], d);
        }
    }
    
    // These two loops link the bottom and far left rows
    for (int i = 0; i < dungeonHeight - 1; i++){
        dungeon[i][dungeonHeight - 1]->linkNode(dungeon[i + 1][dungeonHeight - 1], l);
    }
    
    for (int i = 0; i < dungeonWidth - 1; i++){
        dungeon[dungeonWidth - 1][i]->linkNode(dungeon[dungeonWidth - 1][i + 1], d);
    }
}

Dungeon::Dungeon(const Dungeon& orig) {
}

Dungeon::~Dungeon() {
}