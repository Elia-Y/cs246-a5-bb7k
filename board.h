#ifndef _BOARD_H_
#define _BOARD_H_
#include <iostream>
//#include "player.h"
#include "square.h"

class Board{
//	protected:
		//Player * players[8]; // why store players?

	public:

		Square * squares[40];
		Board();
		~Board();
		void init();
		void notifyMove(Player * player,int index);
		void notifyGoToTims(Player *p);
		// void notifyPlayerBankruptcy(Player * player);
		// void isWon();

};

#endif

