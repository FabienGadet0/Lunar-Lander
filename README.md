# Lunar Lander in c++ / SFML

Little game made for a class in Beijing Jiaotong University.

# Installation

You just need to install SFML https://www.sfml-dev.org/download.php
clone this Repo and run "make -j4 && ./LunarLander"
It runs only on Linux.

# Informations about the game

The goal is to land on a platform (white Rectangle)

USE ARROWS FOR MOVING.

There is an itertia and Gravity , the spacecraft will not stop all of a sudden when you press the down arrow.

Everything in the background is random .

A lot of informations can be change in the file "incs/define.h" like the speed of the ship, gravity , nb of platforms etc...

Acceleration is faster than braking.

When there is no fuel anymore the spacecraft can't accelerate of brake , only itertia and
gravity are applied to it , so you must find a platform before that case .

you can find a really simple UML of the project named "lunarLanderUML.pdf"

![Alt text](./assets/game.png?raw=true "Lunar Lander")