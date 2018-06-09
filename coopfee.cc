#include <iostream>
#include "coopfee.h"
#include "nonproperty.h"
#include "player.h"
using namespace std;


CoopFee:: CoopFee(string name): Nonproperty(name){}

void CoopFee:: action(Player *player){
	cout << "You have paid $150 for the co-op fee." << endl;
	player->setMoney(player->getMoney()-150);
	player->setWorth(player->getWorth()-150);
//	notify();
}

