#ifndef _BLOCK_H_
#define _BLOCK_H_
#include <iostream>
#include "building.h"

class Player;
class Academic;

class Block: public Building {
        int improveCost;
public:
	Academic *blo[3];
	int numOwner;    // the # of players who own the building in the block
	int numBuilding;   // the # of buildings that have not been purchased in the block
	bool isMonopoly;  

	Block(std::string s, int impcost, int numBuilding);
	int getImproveCost();
	void setImproveCost(int imp);
	void purchase(Player *);    // Do we need these three methods?  ?  ?
	void pay(Player *);   // ?
	void action(Player *);  // ?
};

#endif

