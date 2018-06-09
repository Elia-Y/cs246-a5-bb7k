#ifndef _NONPROPERTY_H_
#define _NONPROPERTY_H_
#include <iostream>
#include "square.h"

class Player;

class Nonproperty: public Square {
	public:
		Nonproperty(std::string name);
		virtual void action(Player *) = 0;
};

#endif

