#ifndef _TUITION_H_
#define _TUITION_H_
#include <iostream>
#include "nonproperty.h"

class Player;

class Tuition: public Nonproperty{
	public:
		Tuition(std::string name);
		void action(Player *player);
};

#endif


