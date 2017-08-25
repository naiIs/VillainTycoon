/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Clickable.cpp
 * Author: logan
 * 
<<<<<<< HEAD
 * Created on June 20, 2017, 10:38 AM
=======
 * Created on June 27, 2017, 9:42 AM
>>>>>>> clickable
 */

#include "Clickable.h"

Clickable::Clickable() {
}

Clickable::Clickable(bool click, bool drag, bool select, sf::IntRect b){
    clickable = click;
    dragable = drag;
    selectable = select;
    bounds = b;
}

Clickable::Clickable(const Clickable& orig) {
}

Clickable::~Clickable() {
}

void Clickable::clicked(sf::Event &event){}

void Clickable::released(sf::Event &event){}

void Clickable::dragged(sf::Event &event){}
