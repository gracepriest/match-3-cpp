#pragma once
#include "CommonHeaders.h"
#include "Button.h"
using namespace std;
class Board
{ 
    public:
	//called buttons
	vector<Buttonx> buttons;
	Board();
	float getPlayerPositition();
	void Draw();
};

