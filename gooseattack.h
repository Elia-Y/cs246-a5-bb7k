#ifndef _GOOSEATTACK_H_
#define _GOOSEATTACK_H_
#include <iostream>
#include "nonproperty.h"

class Player;

class GooseAttack: public Nonproperty{

	public:
		GooseAttack(std::string name);
		void action(Player *player);
};

#endif

