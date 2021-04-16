###############################################################
# Program:
#     Project 13, Asteroids, Asteroids
#     Brother Clements, CS165
# Author:
#     Caleb Limb
# Summary:
#     A simple Asteroinds game in which the user controls a
#          ship in order to shoot asteroids. The program draws
#          basic polygons using opengl and handles velocities
#          to move them. Collisions are handled for objects
#          and various forms of feedback are displayed on 
#          screen.
# Above and Beyond
#     Scrolling Background
#          The ship is in the center always and the background
#          moves instead
#     Life System
#          Whenever hit, the ship respawns unilt all lives are
#          lost
#     Comets
#          A faster small ateroid for extra challenge
#     Level System
#          After all asteroids are destroyed, a new wave spawns
#     Screen Shake
#          Screen shakes on certain collisions
#     Space Background
#          Draws stars and Earth
###############################################################


LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main game
###############################################################
asteroids.out: driver.o game.o uiInteract.o uiDraw.o point.o velocity.o flyingObject.o ship.o bullet.o rocks.o sky.o particleEmmiter.o
	g++ driver.o game.o uiInteract.o uiDraw.o point.o velocity.o flyingObject.o ship.o bullet.o rocks.o sky.o particleEmmiter.o $(LFLAGS)

###############################################################
# Individual files
#    uiDraw.o       Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o   Handles input events
#    point.o        The position on the screen
#    game.o         Handles the game interaction
#    velocity.o     Velocity (speed and direction)
#    flyingObject.o Base class for all flying objects
#    ship.o         The player's ship
#    bullet.o       The bullets fired from the ship
#    rocks.o        Contains all of the Rock classes
###############################################################
uiDraw.o: uiDraw.cpp uiDraw.h
	g++ -c uiDraw.cpp

uiInteract.o: uiInteract.cpp uiInteract.h
	g++ -c uiInteract.cpp

point.o: point.cpp point.h
	g++ -c point.cpp

driver.o: driver.cpp game.h
	g++ -c driver.cpp

game.o: game.cpp game.h uiDraw.h uiInteract.h point.h velocity.h flyingObject.h bullet.h rocks.h ship.h
	g++ -c game.cpp

velocity.o: velocity.cpp velocity.h point.h
	g++ -c velocity.cpp

flyingObject.o: flyingObject.cpp flyingObject.h point.h velocity.h uiDraw.h game.h
	g++ -c flyingObject.cpp

ship.o: ship.cpp ship.h flyingObject.h point.h velocity.h uiDraw.h game.h
	g++ -c ship.cpp

bullet.o: bullet.cpp bullet.h flyingObject.h point.h velocity.h uiDraw.h game.h
	g++ -c bullet.cpp

rocks.o: rocks.cpp rocks.h flyingObject.h point.h velocity.h uiDraw.h game.h
	g++ -c rocks.cpp

particleEmmiter.o: particleEmmiter.cpp particleEmmiter.h flyingObject.h point.h velocity.h uiDraw.h game.h
	g++ -c particleEmmiter.cpp

sky.o: sky.cpp sky.h flyingObject.h point.h velocity.h uiDraw.h game.h
	g++ -c sky.cpp

###############################################################
# General rules
###############################################################
clean:
	rm asteroids.out *.o
