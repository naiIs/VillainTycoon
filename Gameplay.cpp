/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Gameplay.cpp
 * Author: logan
 * 
 * Created on May 17, 2017, 12:12 PM
 */

#include "Gameplay.h"
#include <string>

Gameplay::Gameplay() {
}

Gameplay::Gameplay(const Gameplay& orig) {
}

Gameplay::~Gameplay() {
}

void Gameplay::init(){
    
    // Spawn our asset manager and load our assets
    assetManager = new AssetManager;
    
    assetManager->init();
    
    assetManager->loadTexture("DefaultTile.png");
    assetManager->loadTexture("DungeonTile.png");
    assetManager->loadTexture("Hero.png");
    
    // Spawn our dungeon
    dungeon = new Dungeon(*assetManager->getTexture("DefaultTile.png"));
    
    // Set up our sprite spawn
    spawnNewSprite();
    
    // Spawn our hero and move him into the dungeon
    hero = new Hero;
    hero->setTexture(*assetManager->getTexture("Hero.png"));
    hero->move(dungeon->getEntrance());
    
    nodeID = 9;
    
    held = false;
    
    mouseOffset.x = 0;
    mouseOffset.y = 0;
}

// Here we handle all the user generated events
void Gameplay::handleEvents(sf::Event &event, sf::RenderWindow * window){
    
    // Here is our code for clicking and dragging a new tile from the sprite spawn and
    // placing it in the dungeon
    if (event.type == sf::Event::MouseButtonPressed &&
        spriteSpawn->getGlobalBounds().contains(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y))
    {
        held = true;
        mouseOffset.x = spriteSpawn->getPosition().x + sf::Mouse::getPosition(*window).x;
        mouseOffset.y = spriteSpawn->getPosition().y + sf::Mouse::getPosition(*window).y;
    }
    
    // This happens if an event is received while the mouse is pressed
    if (held){
        
        // If we're holding the sprite and we move the mouse, move the position of the sprite
        // to the mouse's new position
        if (event.type == sf::Event::MouseMoved){
            spriteSpawn->setPosition(sf::Mouse::getPosition(*window).x - mouseOffset.x, 
                    sf::Mouse::getPosition(*window).y - mouseOffset.y);
        }
    
        // If the mouse is inside the sprite and currently held down, then released,
        // try to drop the currently held sprite into the appropriate array slot
        if (event.type == sf::Event::MouseButtonReleased)
        {

            // If we succesfully add our sprite to the dungeon then spawn a new one                       
            if(dungeon->add(spriteSpawn))
            {
                spawnNewSprite();
            } 

            // Irregardless if this is a new node (because the old node was dropped
            // into the dungeon sucessfully) or not (because the old node didn't drop in) we put
            // the sprite back up into the corner.
            spriteSpawn->setPosition(0,0);

            held = false;
        }
    }
    
    // This event manages our keyboard input. This is mainlly to test some of the hero
    // stuff.
    
    // First we check to see if a key was pressed
    if(event.type == sf::Event::KeyPressed){

        // Then we check to see WHICH key was pressed when the KeyPressed event was fired
        if(event.key.code == sf::Keyboard::Up){

            // We check to see if there's actually a node in the desired direction
            if(hero->getLocation()->getLink(u)){

                // And if there is we move the hero to that node.
                hero->move(hero->getLocation()->getLink(u));
            }
        }

        if(event.key.code == sf::Keyboard::Down){
            if(hero->getLocation()->getLink(d)){
                hero->move(hero->getLocation()->getLink(d));
            }
        }

        if(event.key.code == sf::Keyboard::Left){
            if(hero->getLocation()->getLink(r)){
                hero->move(hero->getLocation()->getLink(r));
            }
        }

        if(event.key.code == sf::Keyboard::Right){
            if(hero->getLocation()->getLink(l)){
               hero->move(hero->getLocation()->getLink(l));
            }
        }
    }
}

void Gameplay::update(){
    
}

void Gameplay::draw(sf::RenderWindow &window){
    dungeon->draw(window);
    spriteSpawn->draw(window);
    hero->draw(window);
}

void Gameplay::spawnNewSprite(){
    spriteSpawn = new DungeonNode(nodeID);
    spriteSpawn->setTexture(*assetManager->getTexture("DungeonTile.png"));
    nodeID++;
}