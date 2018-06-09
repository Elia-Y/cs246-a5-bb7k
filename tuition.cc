#include <iostream>
#include "tuition.h"
#include "nonproperty.h"
#include "player.h"
using namespace std;

Tuition:: Tuition(string name): Nonproperty(name){}

void Tuition:: action(Player *player){
	cout << "How would you like to pay for the tuition fee?" << endl;
	cout << "A: $300  B: 10\% of your total worth (Please enter A or B)" << endl;
	char c;
	cin >> c;
	if(c == 'A'){
		player->setMoney(player->getMoney()-300);
		player->setWorth(player->getWorth()-300);
		//bank add 300
	}else if(c == 'B'){
		player->setMoney(player->getMoney()-(player->getWorth()/10));
		player->setWorth(player->getWorth()*0.9);
		//bank add money
	}
	addPlayer(player);
	//notify();
}

