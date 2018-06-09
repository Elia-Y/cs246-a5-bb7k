#include <iostream>
#include <iomanip>
#include "building.h"
#include "square.h"
using namespace std;

Building::Building(string name): Square(name), purchaseFee(0), owner(NULL) {}

Player * Building::getOwner() const {
	return owner;
}

int Building::getPurchaseFee() const {
	return purchaseFee;
}

void Building::setPurchaseFee(int f) {
	purchaseFee= f;
}

int Building::getImproveLevel()  const {
	return 0;
}
