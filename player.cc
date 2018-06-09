#include <iostream>
#include "player.h"
#include "academic.h"
#include "residence.h"
#include "gym.h"
//   #include     or     forward declaration?
using namespace std;

class Rurc;   // if need to be included?

Player::Player(string name, int money, int worth, int numRurc, int numAcademic, int numResidence, int numGym, int index, int numDoubleroll, int numRoll): name(name), money(money), worth(worth), numRurc(numRurc), index(index), alreadyRoll(false), numAcademic(numAcademic), numResidence(numResidence), numDoubleroll(numDoubleroll), numRoll(numRoll) {
	for (int i = 0; i < 4; ++i) {
		residences[i] = NULL;
	}

	gyms[0] = NULL;
	gyms[1] = NULL;

	for (int i = 0; i < 22; ++i) {
		academics[i] = NULL;
	}
}

void Player::isBankrupt() {    // called when money < need to pay
	cout << "Would you like to declare bankruptcy?" << endl;	
}

int Player::getMoney() {
	return money;
}

string Player::getName() {
	return name;
}

int Player::getWorth() {
	return worth;
}

/*int Player::geyNumResidence () {
  return numResidence;
  }*/

int Player::getNumRurc() {
	return numRurc;
}

//Rurc * Player::getRurc() {}  // for Yang Lin

int Player::getIndex() {
	return index;
}

void Player::setMoney(int m) {
	money = m;
}

void Player::setWorth(int m) {
	worth = m;
}

void Player::setNumRurc(int m) {
	numRurc = m;
}

void Player::setResidence(Residence *r) {
	residences[numResidence] = r;
}

void Player::setGym(Gym *g) {
	gyms[numGym] = g;
}

void Player::setAcademic(Academic *a) {
	/* for(int i = 0; i < numAcademic; ++i) {
	   if (academics[i] == a) {       // improve 
	   academics[i]->setImproveLevel(a->getImproveLevel() + 1);
	   }
	   }   */

	//        if (academics[i] == NULL) {      // buy a new building
	academics[numAcademic] = a;
	//	}
}

void Player::rmAcademic(Academic *a) {
	int i = 0;
	for ( ; i < numAcademic; ++i) {
		if (academics[i] == a) {
			academics[i] = NULL;
			break; 
		}
	}

	--numAcademic;

	for ( ; i < numAcademic; ++i) {
		academics[i] = academics[i+1];
	}
}

void Player::rmResidence(Residence *r) {
	int i = 0;
	for ( ; i < numResidence; ++i) {
		if (residences[i] == r) {
			residences[i] = NULL;
			break;
		}
	}

	--numResidence;

	for ( ; i < numResidence; ++i) {
		residences[i] = residences[i+1];
	}
}

void Player::rmGym(Gym *g) {
	if (gyms[2] == g) {
		gyms[2] = NULL;
	} else {
		gyms[1] = gyms[2];
		gyms[2] = NULL;
	}

	--numGym;
} 

void Player::setRurc()  {}  // for Yang Lin

void Player::setIndex(int n) {    // n can be greater than 39
	index = n;

	if (index > 39) {          // when arriving 39, the index should be from 0 again
		index -= 39;
	}
}
Residence ** Player::getResidence(){
	return residences;
}
Gym ** Player::getGym(){
	return gyms;
}
Academic ** Player::getAcademic(){
	return academics;
}

