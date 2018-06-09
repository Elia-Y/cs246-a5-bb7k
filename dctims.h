#ifndef _DCTIMS_H_
#define _DCTIMS_H_
#include <iostream>
#include "nonproperty.h"

class Player;

class DcTims: public Nonproperty{

	public:
		DcTims(std::string name);
		void action(Player *player);
};

#endif

