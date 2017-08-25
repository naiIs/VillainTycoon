/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Clickable.h
 * Author: logan
 *
 * Created on June 27, 2017, 9:42 AM
 */

#ifndef CLICKABLE_H
#define CLICKABLE_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Clickable {
public:
    Clickable();
    Clickable(bool click, bool drag, bool select, sf::IntRect bounds);
    Clickable(const Clickable& orig);
    virtual ~Clickable();
    virtual void clicked(sf::Event &event);
    virtual void released(sf::Event &event);
    virtual void dragged(sf::Event &event);
private:
    bool clickable;
    bool dragable;
    bool selectable;
    bool selected;
    sf::IntRect bounds;

};

#endif /* CLICKABLE_H */
