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
    textures = NULL;
    textureIndex = NULL;
    maxTextures = 0;
}

AssetManager::AssetManager(const AssetManager& orig) {
}

AssetManager::~AssetManager() {
}

void AssetManager::init(){
    
    // Set up our texture managing architecture
    maxTextures = 20;
    
    textures = new sf::Texture[maxTextures];
    textureIndex = new std::string[maxTextures];
    
    loadTexture("TextureNotFound.png");
    
    // Set up our font managing architecture    
    loadFont("PixelCowboy.otf");
}

// For now the asset manager only supports one font, since we'll presumably only be
// using one

void AssetManager::loadFont(std::string f){
    
    font.loadFromFile(f);
}

sf::Font * AssetManager::getFont(std::string f){
    return &font;
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
    return &textures[0];
}

void AssetManager::cleanup(){
    //for (int i = 0; i < textureCount; i++){
    //    delete textures[i];
    //    delete textureIndex[i];
    //}
    
    textures = NULL;
    textureIndex = NULL;
    
    textureCount = 0;
}