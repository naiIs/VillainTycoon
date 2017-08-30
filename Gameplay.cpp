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
    
    // Spawn our dungeon. To do this we'll tell the AssetManager to load the dungeon's
    // default sprite and then load the dungeon using that sprite.
    assetManager->loadTexture("Images/EmptyRoom.png");
    dungeon = new Dungeon(*assetManager->getTexture("Images/EmptyRoom.png"));
    
    // Spawn our buttons, every button that will appear on screen. Right now we have
    // one button, Buy Room
    buttonsCount = 1;
    buttons = new Button*[buttonsCount];
    buttons[0] = new BuyButton();
    assetManager->loadTexture(buttons[0]->defaultTexture()); // The BuyButton class knows what the texture for that button should be, so we load it into our asset manager
    buttons[0]->setTexture(*assetManager->getTexture(buttons[0]->defaultTexture())); // Now that the asset manager has loaded the texture we map it tot he button itself
    buttons[0]->setPosition(0, 200);
    
    // Create a list of clickables, everything that the user will be able to click on.
    // Right now we have one, the Buy Room button.
    clickablesCount = buttonsCount;
    clickables = new Clickable*[clickablesCount];
    
    // Here we map our button list to our clickable list (the reason that they're separate is
    // because we may have some clickables that are not buttons)
    for (int i = 0; i < clickablesCount; i++){
        clickables[0] = buttons[0];
    }
    
    // This helps us manage whether the mouse is held down or not
    mouseHeld = false;
}

// Here we handle all the user generated events
void Gameplay::handleEvents(sf::Event &event, sf::RenderWindow * window){
    
    // Here is our code for managing mouse clicks
    if (event.type == sf::Event::MouseButtonPressed)
    {
        // Set the mouseHeld to 'true' to let us know that we're currently holding
        // down the mouse
        mouseHeld = true;
        
        // Pass the click event into each of our clickables. They'll check things like the
        // mouse's position and take appropriate actions
        for (int i = 0; i < clickablesCount; i++){
            clickables[i]->clicked(event);
        }  
    }
    
    // This happens if an event is received while the mouse is pressed
    if (mouseHeld){
        
        // If we're holding the sprite and we move the mouse pass the event to the
        // clickable array's dragged method.
        if (event.type == sf::Event::MouseMoved){
            for (int i = 0; i < clickablesCount; i++){
                clickables[i]->dragged(event);
            }
        }
    
        // If the mouse is inside the sprite and currently held down, then released,
        // try to drop the currently held sprite into the appropriate array slot
        if (event.type == sf::Event::MouseButtonReleased)
        {
            for(int i = 0; i < clickablesCount; i++){
                clickables[i]->released(event);
            }

            
            mouseHeld = false;
        }
    }
}

void Gameplay::pickNewRoom(){
    // grey out everything else and make them un-clickable
    
    // show a list of buildable rooms on screen
}

void Gameplay::update(){
    
}

void Gameplay::draw(sf::RenderWindow &window){
    
    // Draw our dungeon
    dungeon->draw(window);
    
    // Draw our buttons
    for(int i = 0; i < buttonsCount; i++){
        buttons[i]->draw(window);
    }
}
