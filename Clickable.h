/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Clickable.h
 * Author: logan
 *
 * Created on June 20, 2017, 10:38 AM
 */

// The Clickable class. Clickable objects will be interactable by the cursor in the
// gamestate.

#ifndef CLICKABLE_H
#define CLICKABLE_H

class Clickable{
public:
    Clickable();
    Clickable(bool click, bool drag);
    virtual ~Clickable();
    virtual void click();
    virtual void release();
    virtual void drag(int x, int y);
private:
    bool clickable;
    bool dragable;
    bool selected;
    bool held;    
};

#endif // CLICKABLE_H
