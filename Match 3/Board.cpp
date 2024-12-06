#include "Board.h"
#include "Graphics.h"
#include "Button.h"

Board::Board()
{
	//make 13 for each board place
	//only use the one the player is current on
	//and don't allow for a place to be use that's higher than current
	//level
	buttons.emplace_back(Buttonx{ 705, 500, 150, 200, BOARDVFX });
	buttons.emplace_back(Buttonx{ 500, 500, 150, 200, BOARDVFX });
	buttons.emplace_back(Buttonx{ 705, 500, 150, 200, BOARDVFX });
	buttons.emplace_back(Buttonx{ 705, 500, 150, 200, BOARDVFX });
	buttons.emplace_back(Buttonx{ 705, 500, 150, 200, BOARDVFX });
	buttons.emplace_back(Buttonx{ 705, 500, 150, 200, BOARDVFX });
	buttons.emplace_back(Buttonx{ 705, 500, 150, 200, BOARDVFX });
	buttons.emplace_back(Buttonx{ 705, 500, 150, 200, BOARDVFX });
	buttons.emplace_back(Buttonx{ 705, 500, 150, 200, BOARDVFX });
	buttons.emplace_back(Buttonx{ 705, 500, 150, 200, BOARDVFX });
	buttons.emplace_back(Buttonx{ 705, 500, 150, 200, BOARDVFX });
	buttons.emplace_back(Buttonx{ 705, 500, 150, 200, BOARDVFX });
	buttons.emplace_back(Buttonx{ 705, 500, 150, 200, BOARDVFX });
}

void Board::Draw()
{
	
}