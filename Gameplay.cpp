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
#include <SFML/Graphics.hpp>
#include <iostream>
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
    assetManager->loadTexture("Button.png");
    assetManager->loadTexture("BanditRoom.png");
    assetManager->loadTexture("ImpRoom.png");
    assetManager->loadTexture("OgreRoom.png");
    assetManager->loadTexture("Images/EmptyRoom.png");
    
    // Spawn our dungeon
    dungeon = new Dungeon(*assetManager->getTexture("Images/EmptyRoom.png"));
    
    // Set up our sprite spawn
    spawnNewSprite();
    
    // Spawn our hero and move him into the dungeon
    hero = new Hero;
    hero->setTexture(*assetManager->getTexture("Hero.png"));
    hero->move(dungeon->getEntrance());
    
    nodeID = 9;
    
    // This helps us manage whether the mouse is held down or not
    mouseHeld = false;
    
    // Set the current offset of the mouse from the corner of the currently selected
    // object to 0;
    mouseOffset.x = 0;
    mouseOffset.y = 0;
    
    // Load our button 
    buyRoom.setTexture(*assetManager->getTexture("Button.png"));
    buyRoom.setPosition(25, 225);
    
    // Here we're going to test our new minion sprite
    assetManager->loadTexture(myBandit.getDefaultTexture());
    myBandit.setTexture(*assetManager->getTexture(myBandit.getDefaultTexture()));
    myBandit.setPosition(300, 50);
}

// Here we handle all the user generated events
void Gameplay::handleEvents(sf::Event &event, sf::RenderWindow * window){
    
    // Here is our code for clicking and dragging a new tile from the sprite spawn and
    // placing it in the dungeon
    if (event.type == sf::Event::MouseButtonPressed &&
        spriteSpawn->getGlobalBounds().contains(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y))
    {
        mouseHeld = true;
        mouseOffset.x = spriteSpawn->getPosition().x + sf::Mouse::getPosition(*window).x;
        mouseOffset.y = spriteSpawn->getPosition().y + sf::Mouse::getPosition(*window).y;
    }
    
    // This happens if an event is received while the mouse is pressed
    if (mouseHeld){
        
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

            mouseHeld = false;
        }
    }
    
    // Handle our Buy Room button.
    if (event.type == sf::Event::MouseButtonPressed &&
        buyRoom.getGlobalBounds().contains(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y)){
        buyRoom.clicked();
    }
    
    if (event.type == sf::Event::MouseButtonReleased &&
        buyRoom.getGlobalBounds().contains(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y)){
        buyRoom.released();
        pickNewRoom();
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
    buyRoom.draw(window);
    myBandit.draw(window);
}

void Gameplay::spawnNewSprite(){
    spriteSpawn = new DungeonNode(nodeID);
    spriteSpawn->setTexture(*assetManager->getTexture("Images/EmptyRoom.png"));
    nodeID++;
}

void Gameplay::pickNewRoom(){
    bool picked = false;
    sf::RenderWindow pickRoom(sf::VideoMode(600, 200), "Pick a room", sf::Style::None);
    sf::Event event;
    
    sf::Sprite room1;
    sf::Sprite room2;
    sf::Sprite room3;
    
    room1.setTexture(*assetManager->getTexture("Images/EmptyRoom.png"));
    room2.setTexture(*assetManager->getTexture("Images/EmptyRoom.png"));
    room3.setTexture(*assetManager->getTexture("Images/EmptyRoom.png"));
    
    room2.setPosition(200, 0);
    room3.setPosition(400, 0);
    
    pickRoom.draw(room1);
    pickRoom.draw(room2);
    pickRoom.draw(room3);
    
    pickRoom.display();
                       
    while(!picked){
        if (!pickRoom.hasFocus()){
            picked = true;
        }
        
        while(pickRoom.pollEvent(event)){
            if (event.type == sf::Event::MouseButtonPressed){
                if(sf::Mouse::getPosition(pickRoom).x < 200){
                    spriteSpawn->setTexture(*assetManager->getTexture("Images/EmptyRoom.png"));
                } else if (sf::Mouse::getPosition(pickRoom).x < 400){
                    spriteSpawn->setTexture(*assetManager->getTexture("Images/EmptyRoom.png"));
                } else if (sf::Mouse::getPosition(pickRoom).x < 600){
                    spriteSpawn->setTexture(*assetManager->getTexture("Images/EmptyRoom.png"));
                } 
                
                picked = true;
            }        
        }
    }
}