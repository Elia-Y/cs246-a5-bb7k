#include <iostream>
#include "slc.h"
#include "player.h"
#include "nonproperty.h"
using namespace std;

SLC:: SLC(string name): Nonproperty(name){}

void SLC:: action(Player *player){
	cout << "You get a card from SLC" << endl;
	//notify();
	return;
}

