#ifndef _ACADEMIC_H_
#define _ACADEMIC_H_
#include "building.h"

class Player;
class Block;

const int maxlevel = 6;

class Academic: public Building {
//	Block *block;
//	int purchaseCost;
        int ImproveLevel;
        int tuition[maxlevel];

	public:
	Block *block;
	bool isMortaged;

        Academic(std::string, Block *); // how to get block?  ?  ?
	int getTuition() const;
	int getImproveLevel();  
	void setImproveLevel(int l);     // change the improvelevel
	void purchase(Player *);  // ask if player want to buy the building
	void pay(Player *);   // player pays tuition for owner
	void action(Player *);  // action of player arriving here
	void setTuition(int *); // set the tuition fee of every level of a academic building
//	void setPurchaseCost(int n);//set the purchaseCost
	virtual ~Academic();
};

#endif
