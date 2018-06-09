#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <iostream>

class Residence;
class Gym;
class Academic;
class Rurc;

class Player{
		std::string name;
		int money;
		int worth;
//		int numResidence;
		int numRurc;
		Residence * residences[3];
		Gym * gyms[2];
		Academic * academics[22];
//		Rurc * rurc; // needed?
//		int row;
//		int column;
		int index;

	public:
		bool alreadyRoll;
		int numAcademic;
		int numResidence;
		int numGym;
		int numDoubleroll;
		int numRoll;

		Player(std:: string name, int money, int worth, int numRurc, int index, int numAcademic, int numResidence, int numGym, int numDoubleroll, int numRoll);
//		~Player;      needed or not ?
		void isBankrupt();
//		bool canLeave();
//		void droppingOut();       if needed?
//		void mortgage();

		//notify controller?
		//void notify(Player * player); 
		int getMoney();
		std::string getName();
		int getWorth();
//		int getNumResidence();
//		int getNumGym();
		int getNumRurc();
		Residence ** getResidence();
		Gym ** getGym();
		Academic ** getAcademic();
//		Rurc * getRurc(); // needed?
//		int getColumn();
//		int getRow();
		int getIndex();

		void setMoney(int m);
//		void setName();
		void setWorth(int m);
//		void setNumResidence();
//		void setNumGym();
		void setNumRurc(int m);
		void setResidence(Residence *);
		void setGym(Gym *);
		void setAcademic(Academic *);
		void rmAcademic(Academic *);
		void rmResidence(Residence *);
		void rmGym(Gym *);
		void setRurc(); // needed?
//		void setColumn();
//		void setRow();
		void setIndex(int n);
};

#endif

