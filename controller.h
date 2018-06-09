#ifndef _CONTROLLER_H
#define _CONTROLLER_H

#include <iostream>
#include "board.h"
#include "player.h"

class Display;

#define NUM_SQUARE 40
class Controller{
	
	void init();   // initialize a new game? used in play?
	bool checkWin;

	protected:
		Rurc *r;
		Board * board;
		std::string playername[8];
		Player * players[8];
//		Player * currentp;
		int current;  // store the player who is currently playing
		int numPlayer;
		Display * display;

	public:
		Controller();
		~Controller();
		void play();
		void roll(Player *p);
		void improve(Player *p);
		void mortage(Player *p);
		void unmortage(Player *p);
		void bankrupt(Player *p);
		void assets(Player *p);
		void trade(Player *p);
//		void notifyDisplay();

};

#endif


