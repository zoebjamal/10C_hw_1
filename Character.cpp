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
	health = newHealth
}

void Character::attack(Character& target) {
	target.health -= damage;
	std::cout << name << "attacks" << target.name << " doing " << damage << " damage!" << std::endl;
	std::cout << target.name << " Health: " << target.health << std::endl;
}

void Character::rangedAttack(Character& target) {
	if (arrows == 0) {
		std::cout << name << " is out of arrows!" << std::endl;
	} else {
		int rangedDamage = rand() % 5 + 1;
		target.health -= rangedDamage;
		arrows--;
		std::cout << name << " shoots" << target.name << " doing " << rangedDamage << "damage!" << std::endl;
		std::cout << target.name << "health: " << target.health << std::endl;
	}
}

void Character::display() const {
	std::cout << name << " health: " << health << " arrows: " << arrows << std::endl;
}

void Character::get_name() const {
	return name;
}

void Character::get_health() const {
	return health;
}
