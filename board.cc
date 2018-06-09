#include <iostream>
#include "board.h"
#include "square.h"
#include "player.h"
#include "nonproperty.h"
#include "building.h"
#include "academic.h"
#include "block.h"
#include "residence.h"
#include "gym.h"
#include "cosap.h"
#include "dctims.h"
#include "gotims.h"
#include "gooseattack.h"
#include "tuition.h"
#include "coopfee.h"
#include "slc.h"
#include "nh.h"
#include "rurc.h"
using namespace std;

Board:: Board(){
	init();
}

Board:: ~Board(){
	for(int i = 0; i < 40; i++){
		delete squares[i];
	}
}

void Board::init(){
	// new the goose attact square
	GooseAttack * gooseattack = new GooseAttack("Goose Nesting");
	squares[20] = gooseattack;
	// new needles hall square
	NH * nh = new NH("NEEDLES HALL");
	squares[22] = nh;
	//new SLC square
	SLC * slc = new SLC("SLC");
	squares[17] = slc;
	//new DC Tims Line square
	DcTims * dctims = new DcTims("DC Tims Line"); 
	squares[10] = dctims;
	//new Go To Tims square
	GoTims * gotims = new GoTims("Go To Tims");
	squares[30] = gotims;
	//new another SLC square
	SLC * anotherSLC = new SLC("SLC");
	squares[33] = anotherSLC;
	//new another NEEDLES HALL square
	NH * anotherNH = new NH("NEEDLES HALL");
	squares[36] = anotherNH;
	//new COOP FEE square
	CoopFee * coopfee = new CoopFee("CoopFee");
	squares[38] = coopfee;
	//new the third NEEDLES HALL
	NH * thethirdnh = new NH("NEEDLES HALL");
	squares[7] = thethirdnh;
	//new TUITION square
	Tuition * tuition = new Tuition("TUITION");
	squares[4] = tuition;
	//new the third SLC square
	SLC * thethirdSLC = new SLC("SLC");
	squares[2] = thethirdSLC;
	//new OSAP square
	Cosap * cosap = new Cosap("COLLECT OSAP");
	squares[0] = cosap;

	//init blocks
	Block * Arts1 = new Block("Arts1", 50, 2);
	Block * Arts2 = new Block("Arts2", 50,3);
    Block * Eng = new Block("Eng", 100,3);
    Block * Health = new Block("Health", 100,3);
    Block * Env = new Block("Env", 150,3);
    Block * Sci1 = new Block("Sci1", 150,3);
    Block * Sci2 = new Block("Sci2", 200,3);
    Block * Math = new Block("Math", 200,2);

    //init academic buildings
    Academic * EV1 = new Academic("EV1", Env);
    squares[21] = EV1;
    Academic * EV2 = new Academic("EV2", Env);
    squares[23] = EV2;
    Academic * EV3 = new Academic("EV3", Env);
    squares[24] = EV3;
    Academic * PHYS = new Academic("PHYS", Sci1);
    squares[26] = PHYS;
    Academic * B1 = new Academic("B1", Sci1);
    squares[27] = B1;
    Academic * B2 = new Academic("B2", Sci1);
    squares[29] = B2;
    Academic * EIT = new Academic("EIT", Sci2);
    squares[31] = EIT;
    Academic * ESC = new Academic("ESC", Sci2);
    squares[32] = ESC;
    Academic * C2 = new Academic("C2", Sci2);
    squares[34] = C2;
    Academic * MC = new Academic("MC", Math);
    squares[37] = MC;
    Academic * DC = new Academic("DC", Math);
    squares[39] = DC;
    Academic * AL = new Academic("AL", Arts1);
    squares[1] = AL;
    Academic * ML = new Academic("ML", Arts1);
    squares[3] = ML;
    Academic * ECH = new Academic("ECH", Arts2);
    squares[6] = ECH;
    Academic * PAS = new Academic("PAS", Arts2);
    squares[8] = PAS;
    Academic * HH = new Academic("HH", Arts2);
    squares[9] = HH;
    Academic * RCH = new Academic("RCH", Eng);
    squares[11] = RCH;
    Academic * DWE = new Academic("DWE", Eng);
    squares[13] = DWE;
    Academic * CPH = new Academic("CPH", Eng);
    squares[14] = CPH;
    Academic * LHI = new Academic("LHI", Health);
    squares[16] = LHI;
    Academic * BMH = new Academic("BMH", Health);
    squares[18] = BMH;
    Academic * OPT = new Academic("OPT", Health);
    squares[19] = OPT;

    //new Residence squares
    Residence * MKV = new Residence("MKV");
    squares[5] = MKV;
    Residence * UWP = new Residence("UWP");
    squares[15] = UWP;
    Residence * V1  = new Residence("V1");
    squares[25] = V1;
    Residence * REV = new Residence("REV");
    squares[35] = REV;

    //new Gym squares
    Gym * PAC = new Gym("PAC");
    squares[12] = PAC;
    Gym * CIF = new Gym("CIF");
    squares[28] = CIF;

    //setTuition fee array
    int a1[6] = {2, 10, 30, 90, 160, 250};
    int a2[6] = {4, 20, 60, 180, 320, 450};
    int a3[6] = {6, 30, 90, 270, 400, 550};
    int a4[6] = {8, 40, 100, 300, 450, 600};
    int a5[6] = {10, 50, 150, 450, 625, 750};
    int a6[6] = {12, 60, 180, 500, 700, 900};
    int a7[6] = {14, 70, 200, 550, 750, 950};
    int a8[6] = {16, 80, 220, 600, 800, 1000};
    int a9[6] = {18, 90, 250, 700, 875, 1050};
    int a10[6] = {20, 100, 300, 750, 925, 1100};
    int a11[6] = {22, 110, 330, 800, 975, 1150};
    int a12[6] = {24, 120, 360, 850, 1025, 1200};
    int a13[6] = {26, 130, 390, 900, 1100, 1275};
    int a14[6] = {28, 150, 450, 1000, 1200, 1400};
    int a15[6] = {35, 175, 500, 1100, 1300, 1500};
    int a16[6] = {50, 200, 600, 1400, 1700, 2000};


    AL->setTuition(a1);
    ML->setTuition(a2);
    ECH->setTuition(a3);
    PAS->setTuition(a3);
    HH->setTuition(a4);
    RCH->setTuition(a5);
    DWE->setTuition(a5);
    CPH->setTuition(a6);
    LHI->setTuition(a7);
    BMH->setTuition(a7);
    OPT->setTuition(a8);
    EV1->setTuition(a9);
    EV2->setTuition(a9);
    EV3->setTuition(a10);
    PHYS->setTuition(a11);
    B1->setTuition(a11);
    B2->setTuition(a12);
    EIT->setTuition(a13);
    ESC->setTuition(a13);
    C2->setTuition(a14);
    MC->setTuition(a15);
    DC->setTuition(a16);
    //new purchase cost for each building
    AL->setPurchaseFee(40);
    ML->setPurchaseFee(60);
    ECH->setPurchaseFee(100);
    PAS->setPurchaseFee(100);
    HH->setPurchaseFee(120);
    RCH->setPurchaseFee(140);
    DWE->setPurchaseFee(140);
    CPH->setPurchaseFee(160);
    LHI->setPurchaseFee(180);
    BMH->setPurchaseFee(180);
    OPT->setPurchaseFee(200);
    EV1->setPurchaseFee(220);
    EV2->setPurchaseFee(220);
    EV3->setPurchaseFee(240);
    PHYS->setPurchaseFee(260);
    B1->setPurchaseFee(260);
    B2->setPurchaseFee(280);
    EIT->setPurchaseFee(300);
    ESC->setPurchaseFee(300);
    C2->setPurchaseFee(320);
    MC->setPurchaseFee(350);
    DC->setPurchaseFee(400);

    //new 4 Roll Up the Rim cup cards
    //Rurc * rurcs = new Rurc("rurcs");
    return;
}

void Board::notifyMove(Player * player, int index){
    squares[player->getIndex()]->removePlayer(player);
    player->setIndex(index);
    squares[index]->addPlayer(player);
    squares[index]->action(player);
}

void Board::notifyGoToTims(Player *p) {
        cout << "So sad :( Now you are in DC Tims Line" << endl;
	squares[11]->addPlayer(p);
}

