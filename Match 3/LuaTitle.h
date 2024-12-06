#pragma once
#include "include/raylib.h"

#include <vector>

using namespace std;
extern vector<Texture2D> gFrames;

static void InitTGraphics()
{
	//gFrames.emplace_back(LoadTexture("graphics/titlescreen.png"));               
	//gFrames.emplace_back(LoadTexture("graphics/board.png"));					
	//gFrames.emplace_back(LoadTexture("graphics/boardflare.png"));			
	//gFrames.emplace_back(LoadTexture("graphics/blueflame.png"));
	//gFrames.emplace_back(LoadTexture("graphics/bgday.png"));
	gFrames.emplace_back(LoadTexture("graphics/stonegreen.png"));			//1 green
	gFrames.emplace_back(LoadTexture("graphics/stoneblue.png"));			//2 blue
	gFrames.emplace_back(LoadTexture("graphics/stonepink.png"));			//3 pink
	gFrames.emplace_back(LoadTexture("graphics/stoneyellow.png"));			//4 yellow
}
class Tile
{
public:
	int gridX;
	int gridY;
	float x;
	float y;
	int color;
	int variety;
	bool inPlay = true;
	bool isFalling = false;
	Tile() = default;
	Tile(float x, float y, int color, int variety);
	void Render(int x, int y);
	void Render();

	bool operator==(Tile& other)  {
		// Define your comparison logic here
		return (gridX == other.gridX) && (gridY == other.gridY);
	}
	
};

