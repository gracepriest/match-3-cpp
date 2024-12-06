#include "LuaBoard.h"
#include <vector>
#include <map>
#include <utility> 
#include <algorithm>
#include <random>
#include "Sound.h"



LBoard::LBoard(int x, int y)
	:
	x(x),
	y(y)
{
	matches.clear();
    InitTGraphics();
    InitTiles();
   
    
	
}

void LBoard::InitTiles()
{
    tiles.clear();
    for (int tileY = 0; tileY < 8; tileY++) {
        std::vector<Tile> row;
        for (int tileX = 0; tileX < 8; tileX++) {
            row.push_back(Tile(tileX, tileY, rand() % 4, 0));
        }
        tiles.push_back(row);
    }
    if (CalculateMatches()) {
        InitTiles();
    }


}

bool LBoard::CalculateMatches()
{
    matches.clear();

    int matchNum = 1;
    int numRows = tiles.size();
    int numCols = tiles[0].size();

    // Horizontal matches
    for (int y = 0; y < numRows; y++) {
        int colorToMatch = tiles[y][0].color;
        matchNum = 1;
        match.clear();

        for (int x = 1; x < numCols; x++) {
            if (tiles[y][x].color == colorToMatch) {
                matchNum++;
            }
            else {
                colorToMatch = tiles[y][x].color;

                if (matchNum >= 3) {
                    match.clear();
                    for (int x2 = x - 1; x2 >= x - matchNum; x2--) {
                        match.push_back(tiles[y][x2]);
                    }
                    matches.emplace_back(match);
                    PlaySound(MATCH);
                    
                }

                matchNum = 1;

                if (x >= numCols - 2) {
                    break;
                }
            }
        }

        if (matchNum >= 3) {
            match.clear();
            for (int x = numCols - 1; x >= numCols - matchNum; x--) {
                match.push_back(tiles[y][x]);
            }
            matches.emplace_back(match);
            PlaySound(MATCH);
        }
    }

    // Vertical matches
    for (int x = 0; x < numCols; x++) {
        int colorToMatch = tiles[0][x].color;
        matchNum = 1;
        match.clear();

        for (int y = 1; y < numRows; y++) {
            if (tiles[y][x].color == colorToMatch) {
                matchNum++;
            }
            else {
                colorToMatch = tiles[y][x].color;

                if (matchNum >= 3) {
                    match.clear();
                    for (int y2 = y - 1; y2 >= y - matchNum; y2--) {
                        match.push_back(tiles[y2][x]);
                    }
                    matches.emplace_back(match);
                    PlaySound(MATCH);
                    
                }

                matchNum = 1;

                if (y >= numRows - 2) {
                    break;
                }
            }
        }

        if (matchNum >= 3) {
            match.clear();
            for (int y = numRows - 1; y >= numRows - matchNum; y--) {
                match.push_back(tiles[y][x]);
            }
            matches.emplace_back(match);
            PlaySound(MATCH);
           
        }
    }
   // return true;
    if (matches.empty())
    {
        return false;
    }
    else
    {
        return true;
    }
   
}

void LBoard::RemoveMatches()
{
    if (!matches.empty()) {
        for (auto& row : tiles) {
            for (auto& tile : row) {
                for (auto& match : matches) {
                    for (auto& matchTile : match) {
                        if (tile == matchTile) {
                            tile.inPlay = false;
                        }
                    }
                }
            }
        }
        matches.clear();
    }
}
        
unordered_map<Tile*, Tween1> LBoard::GetFallingTiles()
{
    unordered_map<Tile*, Tween1> tweens;
    int spaceY = 0;
    

    for (int x = 0; x < 8; x++)
    {
        bool space = false;
        spaceY = 0;

        for (int y = 7; y >= 0; y--)
        {
            Tile tile = tiles[y][x];

            if (space)
            {
                if (tile.inPlay)
                {
                    //one variable out of place 3 hours of debugging
                    
                    tile.gridY = spaceY;
                    tiles[spaceY][x] = tile;
                    
                    tiles[spaceY][x].isFalling = true;
                    tiles[y][x].inPlay = false;
                    tiles[y][x].isFalling = true;

                    std::pair<float, float> startPos;
                    startPos.first = tile.x;
                    startPos.second = -64;

                    std::pair<float, float> endPos;
                    endPos.first = tile.x;
                    endPos.second = 104 + (spaceY * 64);

                    tweens[&tiles[spaceY][x]] = Tween1(startPos, endPos, 0.7f, lerpF);
                    

                    space = false;
                }
            }
            else if (!tile.inPlay)
            {
                space = true;

                if (spaceY == 0)
                {
                    spaceY = y;
                }
            }
        }
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 3);

    for (int x = 0; x < 8; x++)
    {
        for (int y = 7; y >= 0; y--)
        {
            Tile* tile = &tiles[y][x];

            if (!tile->inPlay)
            {
                int cv = dist(gen);

                Tile* newTile = new Tile(x, y, cv, cv);
                newTile->x = (newTile->gridX * 64) + 650;
                newTile->y = (newTile->gridY * 64) + 100;
                newTile->inPlay = true;
                newTile->isFalling = true;

                tiles[y][x] = *newTile;

                std::pair<float, float> startPos;
                startPos.first = newTile->x;
                startPos.second = -64;

                std::pair<float, float> endPos;
                endPos.first = newTile->x;
                endPos.second = newTile->y;

                tweens[newTile] = Tween1(startPos, endPos, 0.7f, lerpF);
               
            }
        }
    }

    return tweens;
}


//unordered_map<Tile*, Tween<std::pair<float, float>>> LBoard::GetFallingTiles()
//{
//    unordered_map<Tile*, Tween<std::pair<float, float>>> tweens;
//
//    for (int x = 0; x < 8; x++)
//    {
//        bool space = false;
//        int spaceY = 0;
//
//        for (int y = 7; y >= 0; y--)
//        {
//            Tile* tile = &tiles[y][x];
//
//            if (space)
//            {
//                if (tile->inPlay)
//                {
//                    tiles[spaceY][x] = *tile;
//                    tile->gridY = spaceY;
//
//                    tiles[y][x] = Tile();  // Set the tile at the current position to a default Tile
//
//                    std::pair<float, float> startPos;
//                    startPos.first = tile->x;
//                    startPos.second = (tile->gridY - 1) * 64;
//
//                    std::pair<float, float> endPos;
//                    endPos.first = tile->x;
//                    endPos.second = tile->gridY * 64;
//
//                    tweens[tile] = Tween<std::pair<float, float>>(startPos, endPos, 0.5f, lerpF);
//
//                    space = false;
//                    y = spaceY;
//                    spaceY = 0;
//                }
//            }
//            else if (!tile)
//            {
//                space = true;
//
//                if (spaceY == 0)
//                {
//                    spaceY = y;
//                }
//            }
//        }
//    }
//
//    for (int x = 0; x < 8; x++)
//    {
//        for (int y = 7; y >= 0; y--)
//        {
//            Tile* tile = &tiles[y][x];
//
//            if (!tile->inPlay)
//            {
//                int cv = std::rand() % 4 + 1;
//
//                tile = new Tile(x, y, cv, cv);
//                tile->x = (tile->gridX * 64) + 650;
//                tile->y = (tile->gridY * 64) + 100;
//
//                tiles[y][x] = *tile;
//
//                std::pair<float, float> startPos;
//                startPos.first = tile->x;
//                startPos.second = -64;
//
//                std::pair<float, float> endPos;
//                endPos.first = tile->x;
//                endPos.second = tile->y;
//
//                tweens[tile] = Tween<std::pair<float, float>>(startPos, endPos, 4.0f, lerpF);
//            }
//        }
//    }
//
//    return tweens;
//}

void LBoard::Render()
{

   
        for (int y = 0; y < tiles.size(); ++y) {
            for (int x = 0; x < tiles[y].size(); ++x) {
                tiles[y][x].Render();
            }
        }
    
}
