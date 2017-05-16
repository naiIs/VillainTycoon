/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tile.cpp
 * Author: logan
 * 
 * Created on April 14, 2017, 1:21 PM
 */

#include "Tile.h"


Tile::Tile()
{
    size.x = 200;
    size.y = 200;
    selected = false;
}

Tile::~Tile() 
{
    
}

void Tile::drawTile(sf::RenderWindow &window){
    window.draw(*this);
}