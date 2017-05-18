/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GameState.h
 * Author: logan
 *
 * Created on May 17, 2017, 11:43 AM
 */

#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "AssetManager.h"

class GameState {
public:
    GameState();
    GameState(const GameState& orig);
    virtual ~GameState();
    virtual void init();
    virtual void handleEvents(sf::Event &event, sf::RenderWindow * window);
    virtual void update();
    virtual void draw(sf::RenderWindow &window);
private:
    AssetManager * assetManager;
};

#endif /* GAMESTATE_H */

