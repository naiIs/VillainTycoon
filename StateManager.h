/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StateManager.h
 * Author: logan
 *
 * Created on May 17, 2017, 11:41 AM
 */

#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include "Gameplay.h"
#include "GameState.h"

class StateManager {
public:
    StateManager();
    StateManager(const StateManager& orig);
    virtual ~StateManager();
    void init();
    bool running();
    void handleEvents(sf::Event &event, sf::RenderWindow * window);
    void update();
    void draw(sf::RenderWindow &window);
    void cleanup();
    void startGameplay();
private:
    GameState * gameState;
};

#endif /* STATEMANAGER_H */

