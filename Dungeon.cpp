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
#include <iostream>

// We're passing the texture into the constructor instead of loading it here so that
// the texture won't go out of scope for the duration of the program run.
Dungeon::Dungeon(sf::Texture &texture) {
    
    // Here we initialize our array size. This is the height and width of the dungeon
    // in rooms.
    dungeonHeight = 3;
    dungeonWidth = 3;
    
    // This tells us the size of each tile (in pixels) that will be managed by the dungeon
    tileSize.x = 200;
    tileSize.y = 200;
    
    // This is the location of the dungeon on screen. More accurately, it's the location
    // of the upper left corner of the upper left node.
    location.x = 200;
    location.y = 0;
    
    // This tells us how close a new node has to be to a potential drop location to
    // qualify to drop inside of it.
    snapRange = 50;
    
    int id = 0;
    
    // This for loop initializes the elements in our dungeon to nodes
    for (int i = 0; i < dungeonHeight; i++) {
        for (int j = 0; j < dungeonWidth; j++){
            
            // This line creates a new node object which the element in the array points to
            dungeon[i][j] = new DungeonNode(id);
            
            // This sets the texture of that node to our default 'empty node' texture
            dungeon[i][j]->setTexture(texture);
            
            //This line sets the on-screen location of each element in the array
            dungeon[i][j]->setPosition((location.x + (tileSize.x * i)), 
                                        location.y + (tileSize.y * j));
            
            id++;
        }
    }
    
    // Here's some test code to make sure our nodes are in the right spot.
    /*for (int i = 0; i < dungeonHeight; i++){
        for (int j = 0; j < dungeonWidth; j++){
            std::cout << dungeon[i][j]->getLocation().x << " " << dungeon[i][j]->getLocation().y << std::endl;
        }
    }*/
    
    // Here we link each node to its neighbors. Since the code for nodes includes
    // a link back to the linking node we only have to make two links per node. EG:
    // if I link a node to the node above it and to the right of it, then those nodes
    // won't have to be manually linked back to this node.
    
    // This first loop links every cell except the far left and bottom cells, it links
    // each cell to the cell to the left and the cell to the bottom. It doesn't try 
    // to link the right and bottom rows since, at the edge of the array, they wouldn't
    // have anything to link to.
    for (int i = 0; i < dungeonHeight - 1; i++){
        for (int j = 0; j < dungeonHeight -1; j++){
            dungeon[i][j]->linkNode(dungeon[i+1][j], l);
            dungeon[i][j]->linkNode(dungeon[i][j+1], d);
        }
    }
    
    // These two loops link the bottom and far right rows to the nodes above and to the 
    // left of them, respectively.
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
    // Since the destructor for each node already un-links it from its surrounding nodes
    // we don't have to worry about managing links, we just delete all the nodes in the dungeon
    for (int i = 0; i < dungeonHeight; i++){
        for (int j = 0; j < dungeonWidth; j++){
            delete dungeon[i][j];
        }
    }
}

/*bool Dungeon::add(Tile * tile){
    
    // Here we iterate through our array until we find a node that's within the snapping
    // range of the sprite that we're dropping in. We set the pointer of the node to
    // the tile and the location of the tile to the node.
    for(int i = 0; i < dungeonHeight; i++){
        for(int j = 0; j < dungeonWidth; j++){
            if (tile->getPosition().x > dungeon[i][j]->getPosition().x - snapRange &&
                    tile->getPosition().x < dungeon[i][j]->getPosition().x + snapRange &&
                    tile->getPosition().y > dungeon[i][j]->getLocation().y - snapRange &&
                    tile->getPosition().y < dungeon[i][j]->getLocation().y + snapRange)
            {
                dungeon[i][j]->setTile(tile);
                tile->setPosition(dungeon[i][j]->getLocation().x, dungeon[i][j]->getLocation().y);
                return true;               
            }
        }
    }
    
    return false;
    
    while (looking && i < dungeonHeight){
        while (looking && j < dungeonWidth){
            
            // Here we check to see if the location of the tile we're adding is within
            // the snapping range of the node we want to link it to. This means that
            // we don't have to drop the new tile in the pixel perfect location that
            // the node is set to.
            if (tile->getPosition().x > dungeon[i][j]->getLocation().x - snapRange &&
                    tile->getPosition().x < dungeon[i][j]->getLocation().x + snapRange &&
                    tile->getPosition().y > dungeon[i][j]->getLocation().y - snapRange &&
                    tile->getPosition().y < dungeon[i][j]->getLocation().y + snapRange)
                {
                    looking = false;
                    dungeon[i][j]->setTile(tile);
                    return true;               
                }
            
            j++;
        }    
        
        i++;
    }
}*/

void Dungeon::draw(sf::RenderWindow &window){
    
    for (int i = 0; i < dungeonHeight; i++){
        for (int j = 0; j < dungeonWidth; j++){
            dungeon[i][j]->draw(window);
        }
    }
}

bool Dungeon::add(DungeonNode * node){
    
    
    std::cout << "Sprite spawn position when released: " << node->getPosition().x << " , " << node->getPosition().y << std::endl;
    // This loop iterates through our dungeon checking each existing node. If the node
    // to be added is within snapRange of a target node that node is replaced with the
    // new node.
    for(int i = 0; i < dungeonHeight; i++){
        for(int j = 0; j < dungeonWidth; j++){
            
            std::cout << "You tried to add that to row " << i << " column" << j << std::endl;
                
            std::cout << "The position of the dungeon room in that location is " << dungeon[i][j]->getPosition().x << " , " << dungeon[i][j]->getPosition().y << std::endl;
                
            if (node->getPosition().x > dungeon[i][j]->getPosition().x - snapRange &&
                    node->getPosition().x < dungeon[i][j]->getPosition().x + snapRange &&
                    node->getPosition().y > dungeon[i][j]->getPosition().y - snapRange &&
                    node->getPosition().y < dungeon[i][j]->getPosition().y + snapRange)
            {
                
                // Replace the old node with the new node that we're adding to the dungeon
                ///dungeon[i][j] = replace(node, dungeon[i][j]);
                std::cout << "THE NEW SPRITE IS INSIDE THIS NODE!" << std::endl;
                
                node->setPosition(dungeon[i][j]->getPosition());
                
                if (dungeon[i][j]->getLink(u)){
                    node->linkNode(dungeon[i][j]->getLink(u), u);
                }
                
                if (dungeon[i][j]->getLink(d)){
                    node->linkNode(dungeon[i][j]->getLink(d), d);
                }
                
                if (dungeon[i][j]->getLink(l)){
                    node->linkNode(dungeon[i][j]->getLink(l), l);
                }
                
                if (dungeon[i][j]->getLink(r)){
                    node->linkNode(dungeon[i][j]->getLink(r), r);
                }
                
                // These next three lines are the old node switcheroo. The current dungeon
                // node goes into a temp pointer new goes to old, temp gets deleted.
                DungeonNode * temp = dungeon[i][j];
                
                dungeon[i][j] = node;
                
                delete temp;
               
                // This return breaks us out of the loop, so if a new node is succesfully
                // added replacing an old node the code will stop searching for a space
                // to add the new node.
                return true;               
            }
        }
    }
    
    return false;
}

// This method replaces an old node with a new node and then deletes the old node
/*DungeonNode * Dungeon::replace(DungeonNode * node, DungeonNode * oldNode){
    
    // This sets the new node to the on-screen position of the old node
    node->setPosition(oldNode->getPosition());
    
    // This sets the links of the node to the links of the old node, and liks the nodes
    // that the old node was linked to to the new node instead. It sets the links of the
    // old node to null.
    node->linkNode(oldNode->getLink(u), u);
    node->linkNode(oldNode->getLink(d), d);
    node->linkNode(oldNode->getLink(l), l);
    node->linkNode(oldNode->getLink(r), r);
    
    // Because the links of the old node have been set to null we can delete the old node
    // without it un-linking any of the nodes it was previously linked to
    delete oldNode;
    
    // Finally we return the newly modified new node so that we can put it in the
    // array.
    return node;
}*/

DungeonNode * Dungeon::getEntrance(){
    return dungeon[0][0];
}

void Dungeon::soundOff(){
    for (int i = 0; i < dungeonHeight; i++){
        for(int j = 0; j < dungeonWidth; j++){
            std::cout << "I am node " << dungeon[i][j]->getID() << std::endl;
            std::cout << "Above me is ";
            if (dungeon[i][j]->getLink(u)){
                std::cout << "node # " << dungeon[i][j]->getLink(u)->getID() << std::endl;
            } else {
                std::cout << "nothing." << std::endl;
            }
        }
    }
}