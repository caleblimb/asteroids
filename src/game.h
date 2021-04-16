/*********************************************************************
 * File: game.h
 * Description: Defines the game class for Asteroids
 *
 *********************************************************************/

#include "flyingObject.h"
#include "uiInteract.h"
#include <vector>
#include "bullet.h"
#include "rocks.h"
#include "ship.h"
#ifndef GAME_H
#define GAME_H

#define GAME_WIDTH 200
#define GAME_HEIGHT 200

class Game
{
private:
   Point topLeft;
   Point bottomRight;
   int score;

   std::vector<Bullet*> bullets;
   std::vector<Rock*> rocks;

   Ship* ship;

   void addRocks(Rock*);
   void removeEntities();
   void handleCollisions();
   bool checkCollision(FlyingObject *, FlyingObject *);
   //bool checkCollision(FlyingObject *, FlyingObject &);
   //bool checkCollision(FlyingObject &, FlyingObject &);

public:
   /*********************************************
    * Constructor
    * Initializes the game
    *********************************************/
   Game(Point tl, Point br);
   ~Game();

   /*********************************************
    * Function: handleInput
    * Description: Takes actions according to whatever
    *  keys the user has pressed.
    *********************************************/
   void handleInput(const Interface& ui);

   /*********************************************
    * Function: advance
    * Description: Move everything forward one
    *  step in time.
    *********************************************/
   void advance();

   /*********************************************
    * Function: draw
    * Description: draws everything for the game.
    *********************************************/
   void draw(const Interface& ui);


   float getClosestDistance(const FlyingObject& obj1, const FlyingObject& obj2) const;
};


#endif /* GAME_H */
