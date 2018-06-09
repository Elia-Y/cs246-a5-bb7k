#ifndef _RURC_H_
#define _RURC_H_
#include <iostream>
#include "nonproperty.h"

class Player;

#define MAX_NUM_RURC 4;
class Rurc: public Nonproperty{
	public:
		 int num_card;
		 char rurcs[4];
		 Player * owners[4];
		 int current;

	public:
		Rurc(std::string name);
		//use a RURC card
		void action(Player *player);
		//get a RURC card 
		void addPlayer(Player *player);
};

#endif

