/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GameApp.h
 * Author: logan
 *
 * Created on May 17, 2017, 10:26 AM
 */

#ifndef GAMEAPP_H
#define GAMEAPP_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "StateManager.h"

class GameApp {
public:
    GameApp();
    GameApp(const GameApp& orig);
    virtual ~GameApp();
    void run();
    void init();
    void initRenderer();
    void initGamestate();
    void gameLoop();
    void cleanup();
private:
    int frameRate;
    sf::RenderWindow * window;
    StateManager * stateManager;
};

#endif /* GAMEAPP_H */

