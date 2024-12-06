#pragma once
#include "LuaTitle.h"
#include <vector>
#include <unordered_map>
#include "Tween.h"

using namespace std;


class LBoard
{
public:
	int x, y;
	vector<Tile> match;
	vector<vector<Tile>> matches;
	vector<vector<Tile>> tiles;
	unordered_map<Tile*, Tween1> GetFallingTiles();
	LBoard() = default;
	LBoard(int x, int y);
	void InitTiles();
	bool CalculateMatches();
	void RemoveMatches();
	
	void Render();

};