#include <iostream>
#include "gotims.h"
#include "player.h"
#include "nonproperty.h"
using namespace std;

GoTims:: GoTims(string name): Nonproperty(name){}

void GoTims:: action(Player *player){
			player->setIndex(11);
		}

