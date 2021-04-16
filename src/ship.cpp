#include "ship.h"
#include "uiDraw.h"

Ship::Ship() : FlyingObject(Point(0,0))
{
   radius = 10;
}

void Ship::draw()
{
   drawShip(point, angle - 90, isThrusting);
}

void Ship::moveLeft()
{
   rotateLeft(ROTATE_AMOUNT);
}

void Ship::moveRight()
{
   rotateRight(ROTATE_AMOUNT);
}

void Ship::thrust()
{
   velocity.addDx(THRUST_AMOUNT * cos(radians(angle)));
   velocity.addDy(THRUST_AMOUNT * sin(radians(angle)));
}

void Ship::setThrust(bool isThrusting)
{
   this->isThrusting = isThrusting;
}

void Ship::kill()
{
   FlyingObject::kill();
}

void Ship::update()
{
   FlyingObject::update();
}
