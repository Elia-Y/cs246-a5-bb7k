#include <iostream>
#include <cstdlib>
#include "building.h"
#include "gym.h"
#include "player.h"
using namespace std;

Gym::Gym(string name): Building(name), isMortaged(false) {
	setPurchaseFee(150);
}

/*int Gym::getpurchaseFee() const {
	return purchaseFee;
}*/

int Gym::getUsageFee() const {
	cout << "Rolling the dices please(enter yes)" << endl;
	string in;
	cin >> in;

	if (in == "yes") {
		int d1 = rand() % 6 + 1;
		int d2 = rand() % 6 + 1;     // get two random numbers from 1 to 6

		cout << "You get " << d1 << " and " << d2 << endl;

		int sum = d1 + d2;

		if (owner->numGym == 1) {
			return 4 * sum;
		} else {
			return 10 * sum;
		}
	} else {
		cout << "Please try again" << endl;
		return getUsageFee();
	}
}

void Gym::purchase(Player *p) {
	cout << "Do you want to buy " << getName() << " ?(y/n)" << endl;
	char in;
	cin >> in;

	if (in == 'y') {
		p->setMoney(p->getMoney() - purchaseFee);

		if (p->getMoney() < 0) {
			cout << "You cannot buy the building because you don't have enough money" << endl;
			p->setMoney(p->getMoney() + purchaseFee);		
			return;
		}

		++p->numGym;
		p->setGym(this);
		cout << "You bought " << getName() << " successfully" << endl;
	}

	// How to think the case when in = 'n'?  ?  ? (consider display)
}

void Gym::pay(Player *p) {
	if (isMortaged) {
                return;
        }

	int usage = getUsageFee();

	cout << "You need to pay " << usage << " to " << owner->getName() << endl;

	if (p->getWorth() < usage) {
		cout << "You cannot pay the usage fee because you don't have enough money" << endl;
		p->isBankrupt();
		return;
	}
	
	p->setMoney(p->getMoney() - usage);
	owner->setMoney(owner->getMoney() + usage);
}

void Gym::action(Player *p) {
	if (owner == NULL) {
		purchase(p);
	} else {
		pay(p);
	}

//	notify();
}

