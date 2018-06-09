#ifndef _COOPFEE_H_
#define _COOPFEE_H_
#include <iostream>
#include "nonproperty.h"

class Player;

class CoopFee: public Nonproperty{

	public:
		CoopFee(std::string name);
		void action(Player *player);
};

#endif

