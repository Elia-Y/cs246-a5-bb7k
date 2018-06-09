#include <iostream>
#include "gooseattack.h"
#include "player.h"
#include "nonproperty.h"
using namespace std;

GooseAttack:: GooseAttack(string name): Nonproperty(name){}

void GooseAttack:: action(Player *player){
	cout << "You are attacked by the GOOSE! :P" << endl;
//	notify();
	return;
}

