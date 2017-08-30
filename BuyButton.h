/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BuyButton.h
 * Author: logan
 *
 * Created on August 29, 2017, 9:30 AM
 */

#ifndef BUYBUTTON_H
#define BUYBUTTON_H

#include "Button.h"

class BuyButton : public Button{
public:
    BuyButton();
    BuyButton(const BuyButton& orig);
    virtual ~BuyButton();
    void clicked(sf::Event &event);
private:

};

#endif /* BUYBUTTON_H */

