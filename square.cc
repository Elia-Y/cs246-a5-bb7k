#include <iostream>
#include <string>
#include "square.h"
#include "board.h"
#include "player.h"
using namespace std;

Square::Square(string name): name(name) {
//	current = new Player*[8];   create the array in heap or stack?  ?  ?
	for(int i = 0; i < 8; ++i) {
		current[i] = NULL;
	}
}

/*void Square::notify() {
	board.notifyDisplay();
	board.notifyControler();
}*/

void Square::addPlayer(Player *p) {
	for(int i = 0; i < 8; ++i) {
		if (current[i] == NULL) {
			current[i] = p;
			break;
		}
	}
}

void Square::removePlayer(Player *p) {
	for(int i = 0; i < 8; ++i) {
		if (current[i] == p) {
			current[i] = NULL;
			break;
		}
	}
}

// return a list of player's abbreviated name （who are standing in the square）
/*string Square::getCurrent() const {  
	string s = "       ";   
	for(int i = 0; i < 8; ++i) {
		s[i] = current[i].getName();
	}
	return s;
} */

string Square::getName() const {
	return name;
}

Square::~Square() {}
