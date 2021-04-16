#ifndef VELOCITY_H
#define VELOCITY_H

class Velocity
{
private:
   float dX;
   float dY;
public:
   Velocity();
   Velocity(float, float);
   float getDx() const;
   float getDy() const;
   void setDx(float);
   void setDy(float);
   void addDx(float);
   void addDy(float);
};

#endif /* velocity_h */
