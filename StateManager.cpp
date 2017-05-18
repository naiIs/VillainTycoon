/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StateManager.cpp
 * Author: logan
 * 
 * Created on May 17, 2017, 11:41 AM
 */

#include "StateManager.h"
#include "AnimatedSprite.h"

StateManager::StateManager() {
    gameState = NULL;
}

StateManager::StateManager(const StateManager& orig) {
}

StateManager::~StateManager() {
}

// Initialize our state manager
void StateManager::init(){
    
}

// Return true if we're running an active game state
bool StateManager::running(){
    if(gameState){
        return true;
    }
    
    return false;
}

void StateManager::handleEvents(sf::Event &event, sf::RenderWindow * window){
    
    // We're managing the Window Close event here because it's a functionality that's
    // common to all gamestates
    if (event.type == sf::Event::Closed){
        cleanup();     
    }    
    
    if (gameState){
        gameState->handleEvents(event, window);
    }
}

void StateManager::update(){
    if (gameState){
        gameState->update();
    }
}

void StateManager::draw(sf::RenderWindow &window){
    if (gameState){
        gameState->draw(window);
    }
}

void StateManager::cleanup(){
    
    // We delete our game state but not the asset manager since the game state is linked here only
    // and we were passed the asset manager by reference.
    delete gameState;
    
    gameState = NULL;
}

void StateManager::startGameplay(){
    gameState = new Gameplay;
    gameState->init();
}
