#ifndef _RESIDENCE_H_
#define _RESIDENCE_H_
#include <iostream>
#include "building.h"

class Player;

class Residence: public Building {
//	const int purchaseFee;

	public:
	bool isMortaged;

	Residence(std::string);
//	int getPurchaseFee() const;    // get the price for the building
	int getRent() const;	// rent player need to pay to owner
	void purchase(Player *);       // if p buys the building
	void pay(Player *);      // p pays rent to the owner
	void action(Player *);
};

#endif
