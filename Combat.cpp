//Combat.cpp
#include "Combat.h"

Combat::Combat()
:hero("Hero", 30, 3, 5), NumberOfMonsters(1), tokens(2)
{
	Character M("Monster", 5, 2, 0);
	monsterList.push_back(M);
}

void Combat::start()
{
	int choice, iMonster;
	srand(time(0));

	while (NumberOfMonsters>0 && hero.get_health()>0)
	{
		for (int i = 0; i<NumberOfMonsters; i++)
			monsterList[i].attack(hero);
		cout << "----------------------\n";
		if (hero.get_health() <= 0)
			break;
		hero.display();
		cout << hero.get_name() << " has " << tokens << " tokens left.\n";
		cout << "----------------------\n";
		printMonsterList();
		cout << "What do you do? 1 attack, 2 fire arrow, 3 attack all,  Q exit: ";
		cin >> choice;
		if (choice == 1 || choice == 2)
		{
			cout << "Which monster do you want to attack? (0-" << NumberOfMonsters - 1 << "): " << endl;
			cin >> iMonster;
			if (cin.fail() || iMonster >= NumberOfMonsters)
			{
				cout << "Input Error!\n";
				break;
			}
		}
		cout << "----------------------\n";
		switch (choice)
		{
		case 1:
			hero.attack(monsterList[iMonster]);
			break;

		case 2:
			hero.rangedAttack(monsterList[iMonster]);
			break;

		case 3:
			attackAll();
			break;

		default:
			cout << "Input error!\n";
			break;
		}
		checkAliveMonster();
		cout << "----------------------\n";
	}
	if (NumberOfMonsters == 0)
		cout << "Congratulations! You have killed all the monster!" << endl;
	if (hero.get_health() <= 0)
		cout << "You have died! GAME OVER! " << endl;

	cout << "Thanks for playing!" << endl;

}
// Put your code below:
Combat::Combat(int newNumberOfMonsters) : hero("Hero", 30, 3, 5), tokens(1), NumberOfMonsters(newNumberOfMonsters) {
    for (int i = 0; i < NumberOfMonsters; i++) {
        Character M("Monster" + to_string(i), 5, 2, 0);
        monsterList.push_back(M);
    }
}

void Combat::attackAll() {
    if (tokens < 1) {
        cout << hero.get_name() << " is out of tokens!" << endl;
    } else {
        tokens = tokens - 1;
        for (size_t i = 0; i < monsterList.size(); i++) { //maybe use monsterList.size() instead of NumberOfMonsters?
            int newMonsterHealth = monsterList[i].get_health() - 3; //is there a better way to do hero damage?
            monsterList[i].set_health(newMonsterHealth);
            cout << hero.get_name() << " attacks " << monsterList[i].get_name() << " doing 3 damage" << endl;
            cout << monsterList[i].get_name() << " health: " << monsterList[i].get_health() << endl;
        }
        cout << "You attacked all monsters!" << endl;
    }
}

void Combat::checkAliveMonster() {
    size_t i = 0;
    while (i < monsterList.size()){
        if (monsterList[i].get_health() <= 0) {
            size_t lastpos = monsterList.size() - 1;
            monsterList[i] = monsterList[lastpos];
            monsterList.pop_back();
            int addedHeroHealth = hero.get_health() + 5;
            hero.set_health(addedHeroHealth);
            cout << "You killed a monster!" << endl;
            cout << hero.get_name() << " gets 5 health bonus points!" << endl;
            tokens = tokens + 1;
            cout << hero.get_name() << " gets 1 bonus token!" << endl;
            NumberOfMonsters = monsterList.size();
        } else {
            i++;
        }
    }
    
}

void Combat::printMonsterList() const {
    for (size_t i = 0; i < NumberOfMonsters; i++) {
        cout << monsterList[i].get_name() << "  health: " << monsterList[i].get_health() << endl;
    }
}
