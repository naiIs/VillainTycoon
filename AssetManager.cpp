/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AssetManager.cpp
 * Author: logan
 * 
 * Created on May 16, 2017, 8:41 AM
 */

#include "AssetManager.h"

AssetManager::AssetManager() {
    
    textureCount = 0;
    
    maxTextures = 5;
    
    textures = new sf::Texture[maxTextures];
    textureIndex = new std::string[maxTextures];
    
    loadTexture("DungeonTile.png");
    loadTexture("DefaultTile.png");
    loadTexture("Hero.png");
    loadTexture("TextureNotFound.png");
    loadTexture("AnimateTest.png");
}

AssetManager::AssetManager(const AssetManager& orig) {
}

AssetManager::~AssetManager() {
}

// Here we load our textures from the hdd to program memory
void AssetManager::loadTexture(std::string texture){
    textures[textureCount].loadFromFile(texture);
    textureIndex[textureCount] = texture;
    textureCount++;
}

// Returns a pointer to one of our stored textures
sf::Texture * AssetManager::getTexture(std::string texture){
    
    // Here we iterate through our array of textures to see if one of them matches the 
    // requested texture
    for (int i = 0; i < textureCount; i++){
        if(textureIndex[i] == texture){
            return &textures[i];
        }
    }
    
    // If the desired texture wasn't found we return our "texture not found" texture
    return &textures[3];
}