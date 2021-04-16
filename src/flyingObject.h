#include "point.h"
#include "velocity.h"
#ifndef flyingObject_h
#define flyingObject_h

#define COMPLETE_ROTATION 360

class FlyingObject 
{
protected:
   Point point;
   Velocity velocity;
   /**********************************************************
    * angle - The angle of the ship in degrees.
    **********************************************************/
   int angle = 0;

   bool alive = true;

   void rotateRight(int);
   void rotateLeft(int);
   
   int radius;

public:
   FlyingObject(Point);
   FlyingObject(Point, Velocity);
   FlyingObject(Point, float speed, int angle);
   FlyingObject(Point, Velocity, int);
  
   void setPoint(Point point) { this->point = point; }
   Point getPoint() const { return point; }
   void setVelocity(Velocity velocity) { this->velocity = velocity; }
   Velocity getVelocity() const { return velocity; }
   int getAngle() const { return angle; }
   int getRadius() const { return radius; };

   bool isAlive() { return alive; }
   void kill();

   virtual void draw();
   virtual void update();
};

#endif /* flyingObject_h */
