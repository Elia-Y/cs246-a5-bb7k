#include <iostream>
#include "building.h"
#include "player.h"
#include "academic.h"
#include "block.h"
using namespace std;

Academic::Academic(string name, Block *block): Building(name), ImproveLevel(0), block(block), isMortaged(false) {
	for (int i = 0; i < maxlevel; ++i) {
		tuition[i] = 0;
	}
}

int Academic::getTuition() const {
	int result = 0;
	result = tuition[ImproveLevel];

	if ((block->isMonopoly) || (ImproveLevel == 0)) {  // check if the monopoly is owned by a single player
		result *= 2;
	}

	return result;
}

int Academic::getImproveLevel() {
	return ImproveLevel;
}

void Academic::setImproveLevel(int l) {
	ImproveLevel = l;
}

void Academic::purchase(Player *p) {  // if p buys/improves the building
	if (owner == NULL) {
		cout << "Do you want to buy " << getName() << " ?(y/n)" << endl;
		char in;
		cin >> in;

		if (in == 'y') {
			owner = p;
			p->setMoney(p->getMoney() - purchaseFee);
	
			if (p->getMoney() < 0) {      // player does not have enough money to buy the building
				p->setMoney(p->getMoney() + purchaseFee);
				cout << "You cannot buy the building because you do not have enough money" << endl;
				return;
			} 

			--block->numBuilding;

			if (block->numOwner == 0) {  //  no player buys the building in the block
				++block->numOwner;
				block->owner = p;
			}
 
			if (block->getImproveCost() != -1) { //  a block may be monopoly 
				if (block->numOwner == 1) {
					if (block->numBuilding == 0) { // check if the block is monopoly now
						block->isMonopoly = true;
					} else {
						++block->numOwner;
					}
				} else {    // the block is not monopoly, so the building can never be improved
					block->setImproveCost(-1);
					++block->numOwner;
				}
			}

			p->setAcademic(this);
			cout << "You bought " << getName() << " successfully" << endl;
		}
	}

	if ((owner == p) && (block->isMonopoly)) {     // owner and p? How to compare?
		cout << "Now you can improve " << getName() << endl;
/*		char in;
		cin >> in;

		if (in == 'y') {
			p->setMoney(p->getMoney() - block->getImproveCost());
			++ImproveLevel;
			cout << "You have improved your building to level " << ImproveLevel << endl;
		}      */
	}
//return;
//	notify();
}

void Academic::pay(Player *p) {  // p pays tuition to the buiding owner
	if (isMortaged) {
                return;
        }

	int tuition = getTuition();

	cout << "You need to pay " << tuition << " to " << owner->getName() << endl;

	if (p->getMoney() < tuition) {
		cout << "You don't have enough money to pay the tuition" << endl;
		p->isBankrupt();
		return;
	}

	p->setMoney(p->getMoney() - tuition);
	owner->setMoney(owner->getMoney() + tuition);
}

void Academic::action(Player *p) {
	if ((owner == NULL) || (owner == p)) {
		purchase(p);
	} else {
		pay(p);
	}
//	notify();
}

void Academic::setTuition(int * a){
	for(int i = 0; i < 5; i++){
		tuition[i] = a[i];
	}
}

/* void Academic:: setPurchaseFee(int n){
	purchaseCost = n;
}    // used in constructor */

Academic::~Academic(){
	if(block != NULL){
		delete block;
	}
}
