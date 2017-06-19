/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Minion.cpp
 * Author: logan
 * 
 * Created on June 12, 2017, 10:26 AM
 */

#include "Minion.h"

Minion::Minion() : AnimatedSprite(10, 70, 67, 1) {
    defaultTexture = "BanditSprite.png";
}

Minion::Minion(const Minion& orig) {
}

Minion::~Minion() {
}

std::string Minion::getDefaultTexture(){
    return defaultTexture;
}