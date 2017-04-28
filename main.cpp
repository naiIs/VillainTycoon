#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <string>
#include "Tile.h"
#include "DungeonNode.h"

int main()
{
    // Declare a window object
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    
    // Load our textures and create our sprite
    sf::Texture texture;
    texture.loadFromFile("DungeonTile.png");
        
    Tile sprite;
    sprite.setTexture(texture);
    
    //This is our sprite offset, so that the sprite's corner doesn't jump to the
    //location of the mouse.
    sf::Vector2i offset;    
    offset.x = 100;
    offset.y = 100;
    
    //Here we'll create our room data structure, a series of linked DungeonNodes
    //stored in a 2d array
    int dungeonHeight = 3;
    int dungeonWidth = 3;
    DungeonNode dungeon[dungeonHeight][dungeonWidth];
    
    for (int i = 0; i > dungeonHeight; i++) {
        for (int j = 0; j > dungeonWidth ; j++){
            if(j - 1 > 0){}
        }
    }
    
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
            
            // This happens if an event is received and the mouse is pressed
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                // Additionally, if the mouse is inside the bounds of the sprite
                if (sprite.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
                {
                    
                    // Finally, if the mouse is inside the sprite and clicked and then moved,
                    // update the location of the sprite to the location of the mouse
                    // separated by an offset (so that the mouse doesn't go to the corner of
                    // the sprite)
                    if (event.type == sf::Event::MouseMoved)
                    {
                        sprite.setPosition(sf::Mouse::getPosition(window).x - offset.x, sf::Mouse::getPosition(window).y - offset.y);
                    }
                    
                    // If the mouse is inside the sprite and currently held down, then released
                    // drop the currently held sprite into the appropriate array slot
                    if (event.type == sf::Event::MouseButtonReleased)
                    {
                        sprite.setPosition(0,0);
                        //if (event.mouseButton.button == sf::Mouse::Left)
                        //{
                        //    sprite.setPosition(0, 0);
                        //}
                    }
                        
                }
            }
            
            //Draw the sprite that we defined above
            window.clear();
            window.draw(sprite);
            window.display();
        }
    }

    return 0;
}