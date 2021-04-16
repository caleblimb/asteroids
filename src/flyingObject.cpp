#include "flyingObject.h"
#include "game.h"

void FlyingObject::rotateRight(int amount)
{
   angle -= amount;
   if (angle < COMPLETE_ROTATION)
      angle += COMPLETE_ROTATION;
}

void FlyingObject::rotateLeft(int amount)
{
   angle += amount;
   if (angle > COMPLETE_ROTATION)
      angle -= COMPLETE_ROTATION;
}

FlyingObject::FlyingObject(Point point)
{
   this->point = point;
}

FlyingObject::FlyingObject(Point, Velocity)
{
   this->point = point;
   this->velocity = velocity;
}

FlyingObject::FlyingObject(Point, Velocity, int angle)
{
   this->point = point;
   this->velocity = velocity;
   this->angle = angle;
}

void FlyingObject::kill()
{
   alive = false;
}

void FlyingObject::draw()
{
}

void FlyingObject::update()
{
   point.addX(velocity.getDx());
   point.addY(velocity.getDy());
   if (point.getX() < -(float) GAME_WIDTH)
      point.addX((float) GAME_WIDTH * 2.0f);
   if (point.getX() > (float) GAME_WIDTH)
      point.addX(-(float) GAME_WIDTH * 2.0f);
   if (point.getY() < -(float) GAME_HEIGHT)
      point.addY((float) GAME_HEIGHT * 2.0f);
   if (point.getY() > (float) GAME_HEIGHT)
      point.addY(-(float) GAME_HEIGHT * 2.0f);
}
