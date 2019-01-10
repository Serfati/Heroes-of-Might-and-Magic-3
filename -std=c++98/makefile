run: main.o GameUnit.o Army.o Hero.o Creature.o BlackDragon.o Wizard.o Archer.o Vampire.o Zombie.o Thief.o Warrior.o Necromancer.o
	g++ main.o GameUnit.o Army.o Hero.o Creature.o BlackDragon.o Wizard.o Archer.o Vampire.o Zombie.o Thief.o Warrior.o Necromancer.o -o Heroes

main.o: main.cpp GameUnit.h
	g++ -c main.cpp

GameUnit.o: GameUnit.cpp GameUnit.h Hero.h Army.h Creature.h BlackDragon.h Zombie.h Vampire.h Archer.h Wizard.h Warrior.h Thief.h Necromancer.h
	g++ -c GameUnit.cpp

Hero.o: Hero.cpp Hero.h Creature.h Army.h
	g++ -c Hero.cpp

Creature.o: Creature.cpp Creature.h
	g++ -c Creature.cpp

Army.o:  Army.cpp Army.h Creature.h BlackDragon.h Zombie.h Vampire.h Archer.h Wizard.h
	g++ -c Army.cpp

Warrior.o: Warrior.cpp Warrior.h Hero.h
	g++ -c Warrior.cpp

Thief.o: Thief.cpp Thief.h Hero.h
	g++ -c Thief.cpp

Necromancer.o: Necromancer.cpp Necromancer.h Hero.h
	g++ -c Necromancer.cpp

BlackDragon.o: BlackDragon.cpp BlackDragon.h Creature.h
	g++ -c BlackDragon.cpp

Wizard.o: Wizard.cpp Wizard.h Creature.h
	g++ -c Wizard.cpp

Archer.o: Archer.cpp Archer.h Creature.h
	g++ -c Archer.cpp

Vampire.o: Vampire.cpp Vampire.h Creature.h
	g++ -c Vampire.cpp

Zombie.o: Zombie.cpp Zombie.h Creature.h
	g++ -c Zombie.cpp

clean :
	rm -f *.o Heroes
	echo Clean done