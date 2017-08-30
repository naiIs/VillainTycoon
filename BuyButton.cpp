/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BuyButton.cpp
 * Author: logan
 * 
 * Created on August 29, 2017, 9:30 AM
 */

#include "BuyButton.h"
#include <string>
#include <iostream>

BuyButton::BuyButton() {
    
    buttonTexture = "Images/BuyButton.png";
}

BuyButton::BuyButton(const BuyButton& orig) {
}

BuyButton::~BuyButton() {
}

void BuyButton::clicked(sf::Event &event){
    if (this->getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)){
        
        std::cout << "You clicked inside the thing" << std::endl;
    } else {
        std::cout << "You clicked outside the thing" << std::endl;
    }
}