#include "rocks.h"
#include "uiDraw.h"

Rock::Rock(Point point) : FlyingObject(point)
{
   angle = random(0, COMPLETE_ROTATION);
}

void Rock::draw()
{
}

void Rock::update()
{
   FlyingObject::update();
}

BigRock::BigRock(Point point) : Rock(point)
{
   type = LARGE;
   radius = 16;
   velocity.setDx(cos(radians(angle)));
   velocity.setDy(sin(radians(angle)));

}

void BigRock::draw()
{
   drawLargeAsteroid(point, angle);
}

void BigRock::update()
{
   Rock::update();
   rotateRight(2);
}

MediumRock::MediumRock(Point point, Velocity velocity) : Rock(point)
{
   type = MEDIUM;
   radius = 8;
   this->velocity = velocity;
}

void MediumRock::draw()
{
   drawMediumAsteroid(point, angle);
}

void MediumRock::update()
{
   Rock::update();
   rotateRight(5);
}

SmallRock::SmallRock(Point point, Velocity velocity) : Rock(point)
{
   type = SMALL;
   radius = 4;
   this->velocity = velocity;
}

void SmallRock::draw()
{
   drawSmallAsteroid(point, angle);
}

void SmallRock::update()
{
   Rock::update();
   rotateRight(10);
}
