#ifndef _BUILDING_H_
#define _BUILDING_H_
#include <iostream>
#include "square.h"

class Player;

class Building: public Square {
	protected:
//		Player *owner;
		int purchaseFee;

	public:
		Player *owner;

		bool isMortaged;
		Building(std::string name);
		Player * getOwner() const;    // needed?
		int getPurchaseFee() const;
		void setPurchaseFee(int f);     // set purchaseCost
		int getImproveLevel() const;
		virtual void purchase(Player *) = 0;    // How are mortages and dropping out achieved?
		virtual void pay(Player *) = 0;
		virtual void action(Player *) = 0;
};

#endif

