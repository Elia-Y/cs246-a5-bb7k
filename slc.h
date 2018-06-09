#ifndef _SLC_H_
#define _SLC_H_
#include <iostream>
#include "nonproperty.h"

class Player;

class SLC: public Nonproperty{

	public:
		SLC(std::string name);
		void action(Player *player);
};

#endif

