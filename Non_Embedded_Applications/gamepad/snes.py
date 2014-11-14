#!/usr/bin/python
#Simple program taking input from snes controller using pygame library
#and sending this data serially over a uart using python.serial.
import sys, os, pygame
from contextlib import contextmanager
snes = 0

def main():
    controller_init()
    control()

def controller_init():
    #pygame initialziation
    pygame.init()
    pygame.joystick.init()
    global snes
    snes = pygame.joystick.Joystick(0)
    snes.init()
    if not snes.get_name() == "2Axes 11Keys Game  Pad":
        sys.exit("Error, wrong gamepad: " + snes.get_name())
    else:
        print "Initialization complete!"

def control():
    #Main control loop.
    global snes
    done=False
    while done==False:
        for event in pygame.event.get():
            if event.type == pygame.JOYBUTTONUP:
                print "Poop!"
            if event.type == pygame.JOYAXISMOTION:
                x = snes.get_axis(0)
                y = snes.get_axis(1)
                if x < 0:
                    print "left"
                if x > 0:
                    print "right"
                if y > 0:
                    print "down"
                if y < 0:
                    print "up"
                if x == 0 or y == 0:
                    print "direction button  released!"

if __name__ == "__main__":
    main()
