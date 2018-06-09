#include <iostream>
#include "rurc.h"
#include "player.h"
#include "nonproperty.h"
using namespace std;

Rurc::Rurc(string name): Nonproperty(name){
	num_card = MAX_NUM_RURC;
	rurcs[0] = 'A';
	rurcs[1] = 'B';
	rurcs[2] = 'C';
	rurcs[3] = 'D';
	current = 0;
	owners[0] = 0; 
	owners[1] = 0; 
	owners[2] = 0; 
	owners[3] = 0;
}

void Rurc::action(Player *player){
	for(int i = 0; i < 4; i++){
		if(player == owners[i]){
			owners[i] = 0;
			current--;
			player->setNumRurc(player->getNumRurc()-1);
			cout<< "You have used a Roll Up the Rim cup card." << endl;
			return;
		}
	}
	cout << "Sorry, you don't have any Roll Up the Rim cup card." << endl;
	return;
}

void Rurc::addPlayer(Player *player){
	if(current == 4){
		cout << "Sorry, there is no Roll Up the Rim cup card left." << endl;
		return;
	}
	for(int i = 0; i < 4; i++){
		if(0 == owners[i]){
			owners[i] = player;
			player->setNumRurc(player->getNumRurc()-1);
			current++;
			cout<< "You have got a Roll Up the Rim cup card." << endl;
			return;
		}
	}
	cout << "Sorry, there is no Roll Up the Rim cup card left." << endl;
	return;
}
