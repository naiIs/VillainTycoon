/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Clickable.cpp
 * Author: logan
 * 
 * Created on June 20, 2017, 10:38 AM
 */

#include "Clickable.h"

// Clickable methods

Clickable::Clickable(){
    clickable = true;
    dragable = false;
    selected = false;
    held = false;
}

Clickable::Clickable(bool click, bool drag){
    clickable = click;
    dragable = drag;
    selected = false;
    held = false;
}

Clickable::~Clickable(){
    
}

void Clickable::click(){
    
}

void Clickable::release(){
}

void Clickable::drag(int x, int y){
    
}

// end Clickable methods
