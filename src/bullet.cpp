#include "bullet.h"
#include "uiDraw.h"


// Put your bullet methods here

Bullet::Bullet(Point point, Velocity velocity, int angle) : FlyingObject(point)
{
   radius = 2;
   velocity.addDx(BULLET_SPEED * cos(radians(angle)));
   velocity.addDy(BULLET_SPEED * sin(radians(angle)));
   this->velocity = velocity;
   this->angle = angle;
}

void Bullet::update()
{
   FlyingObject::update();
   life++;
   if (life > BULLET_LIFE)
      kill();
}

void Bullet::draw()
{
   drawDot(point);
}
