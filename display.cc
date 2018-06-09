#include "display.h"
#include <string>
#include "board.h"
#include "building.h"
#include "academic.h"
#include <iostream>
using namespace std;


Display::Display(){
	 a[0] = "_________________________________________________________________________________________";
	 a[1] = "|Goose  |       |NEEDLES|       |       |V1     |       |       |CIF    |       |GO TO  |";
	 a[2] = "|Nesting|-------|HALL   |-------|-------|       |-------|-------|       |-------|TIMS   |";
	 a[3] = "|       |EV1    |       |EV2    |EV3    |       |PHYS   |B1     |       |B2     |       |";
	 a[4] = "|       |       |       |       |       |       |       |       |       |       |       |"; 
	 a[5] = "|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|"; 
	 a[6] = "|       |                                                                       |       |"; 
	 a[7] = "|-------|                                                                       |-------|"; 
	 a[8] = "|OPT    |                                                                       |EIT    |"; 
	 a[9] = "|       |                                                                       |       |";
	a[10] = "|_______|                                                                       |_______|";
    a[11] = "|       |                                                                       |       |";
    a[12] = "|-------|                                                                       |-------|";
    a[13] = "|BMH    |                                                                       |ESC    |";
    a[14] = "|       |                                                                       |       |";
    a[15] = "|_______|                                                                       |_______|";
    a[16] = "|SLC    |                                                                       |SLC    |";
    a[17] = "|       |                                                                       |       |";
    a[18] = "|       |                                                                       |       |";
    a[19] = "|       |                                                                       |       |";
    a[20] = "|_______|                                                                       |_______|";
    a[21] = "|       |                                                                       |       |";
    a[22] = "|-------|                                                                       |-------|";
    a[23] = "|LHI    |            _________________________________________                  |C2     |";
    a[24] = "|       |            |                                       |                  |       |";
    a[25] = "|_______|            |  ###   ###   #####  ###   ###   ###   |                  |_______|";
    a[26] = "|UWP    |            |  #  #  #  #     #  #   # #   # #   #  |                  |REV    |";
    a[27] = "|       |            |  ####  ####    #   #   # #   # #   #  |                  |       |";
    a[28] = "|       |            |  #  #  #  #   #    #   # #   # #   #  |                  |       |";
    a[29] = "|       |            |  ####  ####  #      ###   ###   ###   |                  |       |";
    a[30] = "|_______|            |_______________________________________|                  |_______|";
    a[31] = "|       |                                                                       |NEEDLES|";
    a[32] = "|-------|                                                                       |HALL   |";
    a[33] = "|CPH    |                                                                       |       |";
    a[34] = "|       |                                                                       |       |";
    a[35] = "|_______|                                                                       |_______|";
    a[36] = "|       |                                                                       |       |";
    a[37] = "|-------|                                                                       |-------|";
    a[38] = "|DWE    |                                                                       |MC     |";
    a[39] = "|       |                                                                       |       |";
    a[40] = "|_______|                                                                       |_______|";
    a[41] = "|PAC    |                                                                       |COOP   |";
    a[42] = "|       |                                                                       |FEE    |";
    a[43] = "|       |                                                                       |       |";
    a[44] = "|       |                                                                       |       |";
    a[45] = "|_______|                                                                       |_______|";
    a[46] = "|       |                                                                       |       |";
    a[47] = "|-------|                                                                       |-------|";
    a[48] = "|RCH    |                                                                       |DC     |";
    a[49] = "|       |                                                                       |       |";
    a[50] = "|_______|_______________________________________________________________________|_______|";
    a[51] = "|DC Tims|       |       |NEEDLES|       |MKV    |TUITION|       |SLC    |       |COLLECT|";
    a[52] = "|Line   |-------|-------|HALL   |-------|       |       |-------|       |-------|OSAP   |";
    a[53] = "|       |HH     |PAS    |       |ECH    |       |       |ML     |       |AL     |       |";
    a[54] = "|       |       |       |       |       |       |       |       |       |       |       |";
    a[55] = "|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|";

    for(int i = 0; i < ROW; i++){
    	for(int j = 0; j < COL; j++){
    		disp[i][j] = a[i][j];
    	}
    }
}

//need a destructure?
Display::~Display(){
	/*
	for(int i = 0; i < 56; i++){
		delete [] a[i];
	}
	delete [] a;
	*/
}

//
void Display::notifyImplove(Academic *acd, int index){
	int level = acd->getImproveLevel();
	char c = 'I';
	if(index <= 10){
		disp[52][(10-index)*8+1+level] = c;
	}else if(index>10 && index<=20){
		disp[(20-index)*5+2][level] = c;
	}else if(index>20 && index<=30){
		disp[2][(index-20)*8+1+level] = c;
	}else{
		disp[(index-30)*5+2][80+level] = c;
	}
}

void Display::notifyPurchase(Board *b, int index){
	Building *temp = dynamic_cast<Building *>(b->squares[index]);
	if(temp->getOwner() == NULL){
		return;
	}
	char c = temp->getOwner()->getName()[0];
	if(index <= 10){
		disp[54][(10-index)*8+4] = c;
	}else if(index>10 && index<=20){
		disp[(20-index)*5+4][4] = c;
	}else if(index>20 && index<=30){
		disp[4][(index-20)*8+4] = c;
	}else{
		disp[(index-30)*5+4][84] = c;
	}	
}

void Display::notifyBankrupcy(Board *b, Player *p){
	
	string c;
	char ch = ' ';
	Building *temp = NULL;
	for(int index = 0; index < 40; index++){
		temp = dynamic_cast<Building *>(b->squares[index]);
		c = temp->getOwner()->getName();
		if(c==p->getName()){
			if(index <= 10){
				disp[54][(10-index)*8+4] = ch;
			}else if(index>10 && index<=20){
				disp[(20-index)*5+4][4] = ch;
			}else if(index>20 && index<=30){
				disp[4][(index-20)*8+4] = ch;
			}else{
				disp[(index-30)*5+4][84] = ch;
			}
		}
	}
}

void Display::print(){
	for(int i= 0; i < 56; i++){
		for(int j =0; j < 89; j++){
			cout << disp[i][j];
		}
		cout << endl;
	}
}
