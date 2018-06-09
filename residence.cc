#include <iostream>
#include "player.h"
#include "building.h"
#include "residence.h"
using namespace std;

Residence::Residence(string name): Building(name), isMortaged(false) {
	setPurchaseFee(200);
}

/*int Residence::getPurchaseFee() const {
	return purchaseFee;
}*/

void Residence::purchase(Player *p) {
//	if (owner == NULL) { 
		cout << "Do you want to buy " << getName() << "?(y/n)" <<endl;
		char in;
		cin >> in;

		if (in == 'y') {
			int price = getPurchaseFee();
			p->setMoney(p->getMoney() - price);
			if (p->getMoney() < 0) {
				cout << "You cannot buy the building because you do not have enough money" << endl;
				p->setMoney(p->getMoney() + price); // cannot buy the building
				return;
			}

			++p->numResidence;
			p->setResidence(this);
			cout << "You bought " << getName() << " successfully" << endl;	
		}
		if (in == 'n') cout << " Oh... Poor guy :p" << endl;
//	}
}

int Residence::getRent() const {
	int rent = 0;
	for (int i = 1; i <= owner->numResidence; ++i) {
		if (i == 1) {
			rent = 25;
		} else {
			rent *= 2;

		}
	}

	return rent;
}

void Residence::pay(Player *p) {
	if (isMortaged) {
                return;
        }

	int rent = getRent();

	cout << "You need to pay " << rent << " to " << owner->getName() << endl;

	if (p->getMoney() < rent) {
		cout << "You don't have enough money to pay the rent" << endl;
		p->isBankrupt();
		return;
	}

	p->setMoney(p->getMoney() - rent);
	owner->setMoney(owner->getMoney() + rent);
}

void Residence::action(Player *p) {
	if (owner == NULL) {
		purchase(p);
	} else {
		pay(p);
	}

//	notify();
}
