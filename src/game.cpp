/*********************************************************************
 * File: game.cpp
 * Description: Contains the implementaiton of the game class
 *  methods.
 *
 *********************************************************************/

#include "game.h"

// These are needed for the getClosestDistance function...
#include <limits>
#include <algorithm>
using namespace std;

/***************************************
 * GAME CONSTRUCTOR
 ***************************************/
Game::Game(Point tl, Point br) : topLeft(tl), bottomRight(br)
{
   ship = new Ship();
   // Set up the initial conditions of the game
   score = 0;
   for (int i = 0; i < 5; i++)
   {
      //rocks.push_back(BigRock(Point(50*cos(i), 50*sin(i))));
      rocks.push_back(new BigRock(Point(50, 50)));
   }
}

/****************************************
 * GAME DESTRUCTOR
 ****************************************/
Game :: ~Game()
{

}

/***************************************
 * GAME :: ADVANCE
 * advance the game one unit of time
 ***************************************/
void Game::advance()
{
   ship->update();
   for (unsigned int i = 0; i < rocks.size(); i++)
      rocks[i]->update();
   for (unsigned int i = 0; i < bullets.size(); i++)
      bullets[i]->update();

   handleCollisions();
   removeEntities();
}



/***************************************
 * GAME :: HANDLE INPUT
 * accept input from the user
 ***************************************/
void Game::handleInput(const Interface& ui)
{
   // Change the direction of the rifle
   if (ui.isLeft())
   {
      ship->moveLeft();
   }

   if (ui.isRight())
   {
      ship->moveRight();
   }

   if (ui.isUp())
   {
      ship->thrust();
      ship->setThrust(true);
   }
   else
      ship->setThrust(false);

   // Check for "Spacebar
   if (ui.isSpace())
   {
      //Bullet newBullet = ;
      //shake(1.0, 3);
      bullets.push_back(new Bullet(ship->getPoint(), ship->getVelocity(), ship->getAngle()));
   }
}


/**********************************************************
 * Function: getClosestDistance
 * Description: Determine how close these two objects will
 *   get in between the frames.
 **********************************************************/

void Game::draw(const Interface& ui)
{
   ship->draw();
   for (unsigned int i = 0; i < rocks.size(); i++)
      rocks[i]->draw();
   for (unsigned int i = 0; i < bullets.size(); i++)
      bullets[i]->draw();
}

void Game::removeEntities()
{
   vector<Rock*>::iterator rockIt = rocks.begin();
   while (rockIt != rocks.end())
   {
      //Rock* rock = *rockIt;
      if (!dynamic_cast<Rock*> (*rockIt)->isAlive())
      {
         rockIt = rocks.erase(rockIt);
      }
      else
      {
         rockIt++; // advance
      }
   }

   vector<Bullet*>::iterator bulletIt = bullets.begin();
   while (bulletIt != bullets.end())
   {
      if (!dynamic_cast<Bullet*> (*bulletIt)->isAlive())
      {
         bulletIt = bullets.erase(bulletIt);
      }
      else
      {
         bulletIt++; // advance
      }
   }
}

void Game::handleCollisions()
{
   for (unsigned int i = 0; i < rocks.size(); i++)
   {
      if (checkCollision(rocks[i], ship))
      {
         ship->kill();
      }
      for (unsigned int j = 0; j < bullets.size(); j++)
      {
         if (checkCollision(rocks[i], bullets[j]))
         {
            addRocks(rocks[i]);
            rocks[i] -> kill();
            bullets[j] -> kill();
         }
      }
   }
}

bool Game::checkCollision(FlyingObject *a, FlyingObject *b)
{
   return (
      sqrt(
         ((a->getPoint().getX() - b->getPoint().getX()) *
          (a->getPoint().getX() - b->getPoint().getX()))
      +  ((a->getPoint().getY() - b->getPoint().getY()) *
          (a->getPoint().getY() - b->getPoint().getY())))
      <=  (a->getRadius()       + b->getRadius())
      );
}

void Game::addRocks(Rock* oldRock)
{
   if (oldRock->getType() == LARGE)
   {
      rocks.push_back(new MediumRock(oldRock->getPoint(), Velocity(oldRock->getVelocity().getDx(),     oldRock->getVelocity().getDy() + 1.0f)));
      rocks.push_back(new MediumRock(oldRock->getPoint(), Velocity(oldRock->getVelocity().getDx(),     oldRock->getVelocity().getDy() - 1.0f)));
      rocks.push_back(new SmallRock (oldRock->getPoint(), Velocity(oldRock->getVelocity().getDx() + 2, oldRock->getVelocity().getDy()       )));
   }
   if (oldRock->getType() == MEDIUM)
   {
      rocks.push_back(new SmallRock(oldRock->getPoint(), Velocity(oldRock->getVelocity().getDx() - 3, oldRock->getVelocity().getDy())));
      rocks.push_back(new SmallRock(oldRock->getPoint(), Velocity(oldRock->getVelocity().getDx() + 3, oldRock->getVelocity().getDy())));
   }
}

/*
bool Game::checkCollision(FlyingObject* a, FlyingObject& b)
{
   return (
      sqrt(
      ((a->getPoint().getX() - b.getPoint.getX()) *
         (a->getPoint().getX() - b.getPoint.getX())))
      + ((a->getPoint().getY() - b.getPoint.getY()) *
      (a->getPoint().getY() - b.getPoint.getY()))
      <= (a->getRadius() + b.getRadius())
      );
}

bool Game::checkCollision(FlyingObject &a, FlyingObject &b)
{
   return (
      sqrt(
      ((a.getPoint().getX() - b.getPoint.getX()) *
         (a.getPoint().getX() - b.getPoint.getX())))
      + ((a.getPoint().getY() - b.getPoint.getY()) *
      (a.getPoint().getY() - b.getPoint.getY()))
      <= (a.getRadius() + b.getRadius())
      );
}*/

float Game :: getClosestDistance(const FlyingObject &obj1, const FlyingObject &obj2) const
{
   // find the maximum distance traveled
   float dMax = max(abs(obj1.getVelocity().getDx()), abs(obj1.getVelocity().getDy()));
   dMax = max(dMax, abs(obj2.getVelocity().getDx()));
   dMax = max(dMax, abs(obj2.getVelocity().getDy()));
   dMax = max(dMax, 0.1f); // when dx and dy are 0.0. Go through the loop once.
   
   float distMin = std::numeric_limits<float>::max();
   for (float i = 0.0; i <= dMax; i++)
   {
      Point point1(obj1.getPoint().getX() + (obj1.getVelocity().getDx() * i / dMax),
                     obj1.getPoint().getY() + (obj1.getVelocity().getDy() * i / dMax));
      Point point2(obj2.getPoint().getX() + (obj2.getVelocity().getDx() * i / dMax),
                     obj2.getPoint().getY() + (obj2.getVelocity().getDy() * i / dMax));
      
      float xDiff = point1.getX() - point2.getX();
      float yDiff = point1.getY() - point2.getY();
      
      float distSquared = (xDiff * xDiff) +(yDiff * yDiff);
      
      distMin = min(distMin, distSquared);
   }
   
   return sqrt(distMin);
}


