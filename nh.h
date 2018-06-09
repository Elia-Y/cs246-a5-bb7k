#ifndef _NH_H_
#define _NH_H_
#include <iostream>
#include "nonproperty.h"

class NH: public Nonproperty{

	public:
		NH(std::string name);
		void action(Player *player);
};

#endif

