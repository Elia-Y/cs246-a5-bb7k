#ifndef _SQUARE_H_
#define _SQUARE_H_
#include <iostream>

class Player;
class Board;

class Square {
	Player *current[8];
//	Board *board;
	std::string name;

	public:
	Square(std::string name);
//	void notify();
	void addPlayer(Player *);
    void removePlayer(Player *);
//	Square * getCurrent() const;    // Do we need it? what's the return?  ?  ?
	std::string getName() const;
	virtual void action(Player *) = 0;  // action of player arriving this square
	virtual ~Square();
};

#endif


