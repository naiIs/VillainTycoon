/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AssetManager.h
 * Author: logan
 *
 * Created on May 16, 2017, 8:41 AM
 */

/*
 * The AssetManager is a class for handling the textures, audio, and other game
 * assets that other portions of the program will use
 */

#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include <SFML/Graphics.hpp>
#include <string>

class AssetManager {
public:
    AssetManager();
    AssetManager(const AssetManager& orig);
    virtual ~AssetManager();
    void init();
    void loadFont(std::string font);
    sf::Font * getFont(std::string font);
    void loadTexture(std::string texture);
    sf::Texture * getTexture(std::string texture);
    void cleanup();
private:
    sf::Texture * textures; // An array to hold the texture assets that the game will use
    std::string * textureIndex; // An array to hold the index of the textures that we're using
    int textureCount; // a count of the number of textures that we've loaded.
    int maxTextures; // The maximum number of textures that our game supports
    sf::Font font;
};

#endif /* ASSETMANAGER_H */

