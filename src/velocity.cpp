#include "velocity.h"

/********************************************
 * Velocity :: CONSTRUCTOR with default values
 ********************************************/
Velocity::Velocity()
{
   this->dX = 0;
   this->dY = 0;
}

/********************************************
 * Velocity :: CONSTRUCTOR
 ********************************************/
Velocity::Velocity(float dX, float dY)
{
   this->dX = dX;
   this->dY = dY;
}

/********************************************
 * Getter :: Returns x direction of velocity
 ********************************************/
float Velocity::getDx() const
{
   return dX;
}

/********************************************
 * Getter :: Returns y direction of velocity
 ********************************************/
float Velocity::getDy() const
{
   return dY;
}

/********************************************
 * Setter :: Sets x direction of velocity
 ********************************************/
void Velocity::setDx(float dX)
{
   this->dX = dX;
}

/********************************************
 * Setter :: Sets y direction of velocity
 ********************************************/
void Velocity::setDy(float dY)
{
   this->dY = dY;
}

/********************************************
 * addDx :: Adds velocity to x direction
 ********************************************/
void Velocity::addDx(float dX)
{
   this->dX += dX;
}

/********************************************
 * addDy :: Adds velocity to y direction
 ********************************************/
void Velocity::addDy(float dY)
{
   this->dY += dY;
}