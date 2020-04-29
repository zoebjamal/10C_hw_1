#include "Character.h"

Character::Character() {
	name = " ";
	health = 0;
	damage = 0;
	arrows = 0;
}

Character::Character(string newName, int newHealth, int newDamage, int newArrows) {
	name = newName;
	health = newHealth;
	damage = newDamage;
	arrows = newArrows;
}

