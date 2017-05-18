#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "GameApp.h"

int main(){
    
    GameApp villainTycoon;
    
    villainTycoon.run();
    
    return 0;
}
    
    /*
    // Declare a window object
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
     
    // Spawn our asset manager, the service that will load our textures and assets
    AssetManager myManager;
    
    //Here is code for our animated sprite test.
    AnimatedSprite animSprite(12, 50, 99);
    animSprite.setTexture(*myManager.getTexture("AnimateTest.png"));
    animSprite.setPosition(0, 200);  
    
    // Here we create the dungeon data structure that we're going to be storing our dungeon in.
    // We pass in the texture that we want to be the default 'empty room' texture.
    Dungeon dungeon(*myManager.getTexture("DefaultTile.png"));
    
    // This is where we spawn the "free floating" dungeon tile that we can select
    // and then drop into our dungeon data structure.
    DungeonNode * spriteSpawn = new DungeonNode(0);    
    spriteSpawn->setTexture(*myManager.getTexture("DungeonTile.png"));
    
    // Load up the test hero that's going to navigate around the dungeon and drop him into
    // the first room.
    Hero myHero;
    myHero.setTexture(*myManager.getTexture("Hero.png"));
    myHero.move(dungeon.getEntrance());
    
    // This is our sprite offset, so that the sprite's corner doesn't jump to the
    // location of the mouse when it's clicked on.
    sf::Vector2i offset;    
    offset.x = 100;
    offset.y = 100;
        
    // We're starting the nodeID at 9 because there are nine nodes already in the dungeon
    // (nodes 0 - 8)
    int nodeID = 9;
    
    // Check to make sure things are linked correctly
    dungeon.soundOff();
    
    // This tracks whether our floater tile is currently selected and held by the mouse.
    bool held = false;
    
    // Here we set up our clock so that we can draw the screen at a specific framerate
    sf::Clock myClock;
    int framesPerSecond = 24;
    sf::Time fps = sf::milliseconds(1000 / framesPerSecond);
           
    // Run the program for as long as the window is open
    while (window.isOpen())
    {
        
        // check all the window's events that were triggered since the last
        // iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // On "close requested" event we close the window.
            if (event.type == sf::Event::Closed){
                window.close();
            }
            
            // When we click the mouse on the sprite we change the status to held
            if (event.type == sf::Event::MouseButtonPressed &&
                    spriteSpawn->getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
            {
                    held = true;
            }
            
            // This happens if an event is received and the mouse is pressed:
            if (held)
            {
                
                if (event.type == sf::Event::MouseMoved)
                {
                 
                    spriteSpawn->setPosition(sf::Mouse::getPosition(window).x - offset.x, sf::Mouse::getPosition(window).y - offset.y);
                }
                    
                // If the mouse is inside the sprite and currently held down, then released,
                // try to drop the currently held sprite into the appropriate array slot
                if (event.type == sf::Event::MouseButtonReleased)
                {
                    
                    // If it drops into an array slot then make a new node                         
                    if(dungeon.add(spriteSpawn))
                    {
                        spriteSpawn = new DungeonNode(nodeID);
                        nodeID++;
                        spriteSpawn->setTexture(*myManager.getTexture("DungeonTile.png"));
                        std::cout << "Creating a new sprite." << std::endl;
                        dungeon.soundOff();
                    } 
                     
                    // Irregardless if this is a new node (because the old node was dropped
                    // into the dungeon sucessfully) or not (because the old node didn't drop in) we put
                    // the sprite back up into the corner.
                    spriteSpawn->setPosition(0,0);
                        
                    held = false;
                }               
            }
            
            // This event manages our keyboard input. This is mainly to manually test some
            // movement stuff, once the game is live most movement things will be handled
            // by automation.
            
            // First we check to see if a key was pressed
            if(event.type == sf::Event::KeyPressed){
                                              
                // Then we check to see WHICH key was pressed when the KeyPressed event was fired
                if(event.key.code == sf::Keyboard::Up){
                    
                    // We check to see if there's actually a node in the desired direction
                    if(myHero.getLocation()->getLink(u)){
                        
                        // And if there is we move the hero to that node.
                        myHero.move(myHero.getLocation()->getLink(u));
                    }
                }
                
                if(event.key.code == sf::Keyboard::Down){
                    if(myHero.getLocation()->getLink(d)){
                        myHero.move(myHero.getLocation()->getLink(d));
                    }
                }
                
                if(event.key.code == sf::Keyboard::Left){
                    if(myHero.getLocation()->getLink(r)){
                        myHero.move(myHero.getLocation()->getLink(r));
                    }
                }
                
                if(event.key.code == sf::Keyboard::Right){
                    if(myHero.getLocation()->getLink(l)){
                        myHero.move(myHero.getLocation()->getLink(l));
                    }
                }
            }
            
            if(event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::D){
                    animSprite.nextFrame();
                }
            }
            
        //Draw draw everything
        
        } //if(window.PollEvents) 
        
        // This draws everything on screen. We only draw at our framerate, even though the
        // game logic executes much faster than that.
        if (myClock.getElapsedTime() >  fps){
            
            // Basic call to clear the window before re-drawing
            window.clear();
            
            // Draw the objects to our buffering frame
            dungeon.draw(window);
            spriteSpawn->draw(window);           
            myHero.draw(window);
            animSprite.draw(window);
            
            // Display the items that we've drawn to our buffering frame
            window.display();
            
            // Reset the clock to count up to our target framerate again
            myClock.restart();
        }
    }

    return 0;
}
*/