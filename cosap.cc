#include <iostream>
#include "cosap.h"
#include "player.h"
#include "nonproperty.h"
using namespace std;

Cosap:: Cosap(string name): Nonproperty(name){}

void Cosap:: action(Player *player){
			player->setMoney(player->getMoney()+200);
			player->setWorth(player->getWorth()+200);
			addPlayer(player);
			//notify();
}

