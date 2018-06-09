#include <iostream>
#include "block.h"
using namespace std;

Block::Block(string s, int impcost, int numBuilding): Building(s), improveCost(impcost), numOwner(0), numBuilding(numBuilding), isMonopoly(false) {
	for(int i = 0; i < 3; ++i) {
		blo[i] = NULL;
	}
}

int Block::getImproveCost() {
  return improveCost;
}

void Block::setImproveCost(int imp) {
	improveCost = imp;
}

void Block::purchase(Player *p) {}   // see .h file for more details

void Block::pay(Player *p) {}

void Block::action(Player *p) {}
