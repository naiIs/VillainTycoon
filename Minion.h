/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Minion.h
 * Author: logan
 *
 * Created on June 12, 2017, 10:25 AM
 */

#ifndef MINION_H
#define MINION_H

#include "AnimatedSprite.h"
#include <string>

class Minion : public AnimatedSprite{
public:
    Minion();
    Minion(const Minion& orig);
    virtual ~Minion();
    std::string getDefaultTexture();
private:
    std::string defaultTexture;

};

#endif /* MINION_H */

