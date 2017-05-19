/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GameApp.cpp
 * Author: logan
 * 
 * Created on May 17, 2017, 10:26 AM
 */

#include "GameApp.h"

GameApp::GameApp() {
}

GameApp::GameApp(const GameApp& orig) {
}

GameApp::~GameApp() {
}

// This is the basic game application, it manages our assets, the game state, and the
// game loop
void GameApp::run(){
    
    // Initialize our game
    init();
    
    // Run our game loop
    gameLoop();
    
    // Run cleanup on our objects
    cleanup();
  
}

void GameApp::init(){
    // Set the frame rate for the game
    frameRate = 24;  
        
    // Initialize our render window
    initRenderer();
    
    // Initialize our game state
    initGamestate();
}

// Initialize our render window
void GameApp::initRenderer(){
    window = new sf::RenderWindow(sf::VideoMode(800, 600), "Villain Tycoon");
}

// Initialize our first game state
void GameApp::initGamestate(){
    
    // Initialize our state manager
    stateManager = new StateManager;
    stateManager->init();
    
    // For now we're just going to jump right into our gameplay game state
    stateManager->startGameplay();
}

// This is the game loop that will run the main game until we're ready to quit
void GameApp::gameLoop(){
        
    //Here we set up the timer to run our loop at a specific framerate
    sf::Clock clock;
    sf::Time fps = sf::milliseconds(1000 / frameRate);   
    
    // We'll do this loop as long as we have an active game state
    while(stateManager->running()){
        
        // Handle any events generated by the user interacting with the window
        sf::Event event;
        while(window->pollEvent(event)){
            stateManager->handleEvents(event, window);
        }      
        
        // In this smaller loop we only handle the actions that we want to happen in
        // sync with the framerate of the game.        
        if (clock.getElapsedTime() > fps){
            
            // Update the game logic
            stateManager->update();
            
            // Draw the current game state
            window->clear();
            stateManager->draw(*window);
            window->display();
            
            // Reset the clock to count up to the next frame
            clock.restart();
        }
    }
}

void GameApp::cleanup(){
    
    // Clean up our game state
    stateManager->cleanup();
    delete stateManager;
    stateManager = NULL;
    
    // Clean up our render window
    window->close();
    delete window;
    window = NULL;
}