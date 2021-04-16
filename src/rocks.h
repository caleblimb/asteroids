#include "flyingObject.h"
#ifndef rocks_h
#define rocks_h

#define BIG_ROCK_SIZE 16
#define MEDIUM_ROCK_SIZE 8
#define SMALL_ROCK_SIZE 4

#define BIG_ROCK_SPIN 2
#define MEDIUM_ROCK_SPIN 5
#define SMALL_ROCK_SPIN 10

enum RockType {
   SMALL,
   MEDIUM,
   LARGE
};

class Rock : public FlyingObject
{
protected:
   RockType type;
public:
   Rock(Point point);
   RockType getType() { return type; }
   virtual void draw();
   virtual void update();
};

class BigRock : public Rock
{
private:
public:
   BigRock(Point);
   virtual void draw();
   virtual void update();
};

class MediumRock : public Rock
{
private:
public:
   MediumRock(Point, Velocity);
   virtual void draw();
   virtual void update();
};

class SmallRock : public Rock
{
private:
public:
   SmallRock(Point, Velocity);
   virtual void draw();
   virtual void update();
};

#endif /* rocks_h */
