cmake_minimum_required(VERSION 3.13)
project(src)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(src
        Archer.cpp
        Archer.h
        Army.cpp
        Army.h
        BlackDragon.cpp
        BlackDragon.h
        Creature.cpp
        Creature.h
        GameUnit.h
        Hero.cpp
        Hero.h
        main.cpp
        Necomancer.cpp
        Necomancer.h
        Thief.cpp
        Thief.h
        Vampire.cpp
        Vampire.h
        Warrior.cpp
        Warrior.h
        Wizard.cpp
        Wizard.h
        Zombie.cpp
        Zombie.h GameUnit.cpp)
