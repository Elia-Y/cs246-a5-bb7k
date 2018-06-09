#ifndef _COSAP_H_
#define _COSAP_H_
#include <iostream>
#include "nonproperty.h"

class Player;

class Cosap: public Nonproperty{
	public:
		Cosap(std::string name);
		void action(Player *player);
};

#endif

