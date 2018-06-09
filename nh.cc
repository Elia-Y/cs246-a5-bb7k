#include <iostream>
#include "nh.h"
#include "player.h"
#include "nonproperty.h"
using namespace std;

NH:: NH(string name): Nonproperty(name){}

void NH:: action(Player *player){
	cout << "You get a card from Needles Hall!" << endl;
//	notify();
	return;
}

