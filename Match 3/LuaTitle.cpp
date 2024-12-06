#include "LuaTitle.h"
#include "Graphics.h"


using namespace std;
vector<Texture2D> gFrames;


Tile::Tile(float X, float Y, int color, int variety)
	: 
	  color(color),
	  variety(variety)

{
	x = X;
	y = Y;
	gridX = x;
	gridY = y;
	x = (gridX  * 64) + 650;
	y = (gridY  * 64) + 100;
	//might have to coordinate positions
	


}
void Tile::Render(int x, int y)
{
	if (inPlay == true and !isFalling)
	{

		//draw a shadow

		//draw title itself
		DrawTextureEx(gFrames[color], Vector2{ (float)x,(float)y }, 0, 1, WHITE);
	}

}
void Tile::Render()
{
	if (inPlay == true and !isFalling)
	{

	//draw a shadow

	//draw title itself
	DrawTextureEx(gFrames[color], Vector2{ (float)x,(float)y }, 0, 1, WHITE);
	}

}