#include "flyingObject.h"
#ifndef bullet_h
#define bullet_h

#define BULLET_SPEED 5
#define BULLET_LIFE 40

class Bullet : public FlyingObject
{
private:
   int life = 0;
public:
   Bullet(Point, Velocity, int);
   virtual void update();
   virtual void draw();
};

#endif /* bullet_h */
