#ifndef _GYM_H_
#define _GYM_H_
#include <iostream>
#include "building.h"

class Player;

class Gym: public Building {
//	const int purchaseFee;
public:
	bool isMortaged;

	Gym(std::string);
//	int getpurchaseFee() const;
	int getUsageFee() const;
	void purchase(Player *);  // if player buys the building
	void pay(Player *);   // player pays usage fee to owner
	void action(Player *); 
};

#endif
