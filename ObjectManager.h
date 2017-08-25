/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ObjectManager.h
 * Author: logan
 *
 * Created on June 22, 2017, 2:04 PM
 */

#include "Button.h"
#include "Dungeon.h"
#include "Clickable.h"
#include "DungeonNode.h"

#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

// This is a manager object that manages the on-screen objects.
class ObjectManager {
public:
    ObjectManager();
    ObjectManager(const ObjectManager& orig);
    virtual ~ObjectManager();
private:
    Dungeon * dungeon;
    Button * buttons;
    Clickable * clickables;
};

#endif /* OBJECTMANAGER_H */

