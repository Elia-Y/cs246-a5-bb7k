#ifndef _DISPLAY_H_
#define _DISPLAY_H_
#include <iostream>
#include <string>
#include "controller.h"

class Board;
class Academic;

#define ROW 56
#define COL 89
class Display{
        std::string a[ROW];
	char disp[ROW][COL];


	public:
		Display();
		~Display();
		void notifyImplove(Academic *acd, int index);
		void notifyPurchase(Board *b, int index);
		void notifyBankrupcy(Board *b, Player *p);
		void print();

};

#endif



