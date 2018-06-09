#ifndef _GOTIMS_H_
#define _GOTIMS_H_
#include <iostream>
#include "nonproperty.h"

class Player;

class GoTims: public Nonproperty{
	public:
		GoTims(std::string name);
		void action(Player *player);
};

#endif

