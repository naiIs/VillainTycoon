/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tile.h
 * Author: logan
 *
 * Created on April 14, 2017, 1:21 PM
 */

#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>

class Tile : public sf::Sprite{
public:
    Tile();
    virtual ~Tile();
    void drawTile(sf::RenderWindow &window);
private:
    sf::Vector2i size;
    bool selected;
};

#endif /* TILE_H */

