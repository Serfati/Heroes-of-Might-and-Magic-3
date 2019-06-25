# Heroes of Might and Magic III
The goal of this project is to create a simplified version of the combat mode of the famous Heroes Of Might and Magic. The full list of requirements is as follows:

### Description:

The aim is to make a simplified version of the HOM part of the battle. The main components here are: players, different types of units and the game menu. There will be two players in the game, each one going to play in succession as the game ends when a player's army is slaughtered.

## Menus:

When the game starts, the following happens: The first player has to enter his / her name A file is loaded for the first player information The second player has to enter his / her name A file is loaded for the second player information The first player must choose the race with which to play the second player must choose the race to play The first player buys units The second player buys units The first player chooses what type he is his character The second player chooses what type he is his character For every step to get adequate messages explain yavashti what to do player. When a player buys monsters, his gold is momentarily taken away only within this game.

### Army:

In their army, players can have different monsters. As all the monsters of one type are in the same field, move together and attack together. All monsters can attack and move on the map. Races and units: We have 2 races Heaven, Inferno. Each of them has 3 types of units each of which can be upgraded. All units have a range (attack, life points, bumper, attack points and stamina) (how many card margins can go for one move)

#### Heaven

Peasent may damage a group of monsters at a distance of one field on a wall or edge of it. Upgrade - Brute when attacking a monster damages everyone adjacent to the attacked (wall or edge) equal to 25% of the attack on the attacker. Archer can attack from a distance. Upgrade - Crossbowman is picking a field and attacking all units on him and his neighbor (by field or edge) Angel if killed monsters of this group are randomly selected how many of them are revived. Archnagel - if monsters are murdered from this group, it is randomly chosen how many of them are revived and, after attacking a monster, damages everyone behind it equal to 50% of the inflicted.

#### Inferno

Imp - can damage a group of monsters off a field on a wall or edge of it. Upgrade - Vermin when attacking a monster in the next 2 moves it gets damage equal to 25% of the original one. Horned demon - causes damage from a distance. Upgrade - Horned Grunt - causes damage from a distance and has a 50% chance of hitting twice. Devil - only causes damage to neighboring adversaries when it dies to damage all neighboring adversaries. Upgrade - Arch Demon keeps Devil's capabilities, but when moving, he can swap places with a monster.

### Heroes Heroes are two classes of Mage and Warrior. They also have extra fields: mana, crit, experience, nextLvlExperience, level, and can do different spells.

Mana - the mana that has the hero. Every magic requires a certain quantity. Each move is refunded 10%. crit - extra damage in% of the character's base Experiences - the hero's current experience nextLvlExperience - how much experience the hero needs to raise the level level - the hero level

#### Mage Attacks from a distance and can do the following spells.

Fire Ball - damages an opponent Ice ball - freezes an opponent and he can not move one move but can attack

#### Warrior

Attacks from a distance of a field and can do the following spells: Stun - attacks a monster and can not move or attack a move Shield - gives a shield to a monster and it can not be attacked After the battle the winner wins 500 gold lost 200 The heroes receive an experience equal to the number of killed enemy monsters. If heroes raise a level, they can choose whether to upload a crit or mana point. Each point of the crit increases the damage bonus by 0.05, each point rises the mana by 10 (for example). And NextLvlExperience multiplies by 1.5.

#### Files Each player must have one file with the player's name. The file holds the hero's gold, the hero's level, his current experience, the experience required for the next level, the mana points and the crit points, in whatever format you are most comfortable with.

#### Commands Buying, moving, and attacking will be done through the commands described below:

Buy (amount) (creature) where the amount is the amount of creature monsters you want to buy if the player's gold does not reach a message.

Example: Buy 10 Peasent Move (fromX) (fromY) To (toX) (toY) moves a monster. On from position (fromX, fromY) to position (toX, toY). If the entry is invalid to display a message and allow the player to repeat the move. The entry is invalid if there are no such fields if there is no monster of the player in position (fromX, fromY) if there is a monster (toX, toY) (exceptions are ArchDeamon, who in this case exchanges the place with the corresponding monster) or (toX, toY) is outside the scope of the monster (it does not reach stamina to get there). Move the whole group of monsters.

Example: Move 2 4 To 4 6 Attack (fromX) (fromY) At (atX) (atY) causes the monster of position (fromX, fromY) to attack the monster of position (toX, toY). If an invalid login signifies an error message and allows the player to repeat the move. Entry is invalid if there are no monsters at the entry positions if (fromX, fromY) has an opponent monster, (toX, toY) has a monster but is not an opponent. Or if (toX, toY) is outside the scope of the monster. The attack is bulk. Collect the points of damage to the attacking group of them by deducting the sum of the attack group's defense points if the number of the negative attacking group loses as many vital points as the difference and recalculates the group's number. If greater than zero of the total life points of the attacked group is deducted and the number of the group is recalculated.

Example: Attack 2 3 At 4 3 Cast (spell) At (atX) (atY) makes the hero do the magic spell. In case of invalid entry, a message appears and the player is allowed to make a move again.

Example: Cast Fireball At 3 4 For the prices of monsters, vital points, defense, range of striking and moving you invent some numbers they are not of great importance.
