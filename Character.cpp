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

void Character::set_health(int newHealth) {
	health = newHealth;
}

void Character::attack(Character& target) {
	target.health -= damage;
	std::cout << name << "attacks" << target.name << " doing " << damage << " damage!" << endl;
	std::cout << target.name << " Health: " << target.health << std::endl;
}
