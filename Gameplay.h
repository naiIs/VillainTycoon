/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Gameplay.h
 * Author: logan
 *
 * Created on May 17, 2017, 12:12 PM
 */

#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "GameState.h"
#include "AssetManager.h"
#include "Dungeon.h"
#include "DungeonNode.h"
#include "Hero.h"
#include "Button.h"
#include "Minion.h"
#include "Clickable.h"

class Gameplay : public GameState{
public:
    Gameplay();
    Gameplay(const Gameplay& orig);
    virtual ~Gameplay();
    void init();
    void handleEvents(sf::Event &event, sf::RenderWindow * window);
    void update();
    void draw(sf::RenderWindow &window);
private:
    AssetManager * assetManager;
    Dungeon * dungeon;
    Button * buttons;
    int buttonsCount;
    Clickable * clickables;
    int clickablesCount;
    bool mouseHeld;
};

#endif /* GAMEPLAY_H */

