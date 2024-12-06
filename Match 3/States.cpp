#include <iostream>
#include "include/raylib.h"
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
//#include "Sounds.h"
#include "State.h"
#include "States.h"

#include "Font.h"
#include "Graphics.h"
#include "Animation.h"
#include "Timer.h"
#include "Sound.h"
#include "GameTween.h"
#include "include/tweeny.h"
#include "Board.h"
#include "TextFiledb.h"
//#include "StoneTitle.h"
#include "LuaBoard.h"
#include "Tween.h"

const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 720;
static Tween<int> tweenDragged;
static Tween<int> tweenDes;
static Tile tempTile;

static void InitStone()
{
	StoneTiles.push_back(LoadTextureFromImage(LoadImageFromTexture(YELLOWSTONE)));
	StoneTiles.push_back(LoadTextureFromImage(LoadImageFromTexture(GREENSTONE)));
	//StoneTiles.push_back(LoadTextureFromImage(LoadImageFromTexture(PINKSTONE)));
	StoneTiles.push_back(LoadTextureFromImage(LoadImageFromTexture(BLUESTONE)));
}
static void InitGraphics()
{
	BACKGROUND = LoadTexture("graphics/titlescreen.png");
	BOARD = LoadTexture("graphics/board.png");
	BOARDVFX = LoadTexture("graphics/boardflare.png");
	BOARDVFX2 = LoadTexture("graphics/blueflame.png");
	BOARDVFX3 = LoadTexture("graphics/bgday.png");
	GREENSTONE = LoadTexture("graphics/stonegreen.png");
	BLUESTONE = LoadTexture("graphics/stoneblue.png");
	PINKSTONE = LoadTexture("graphics/stonepink.png");
	YELLOWSTONE = LoadTexture("graphics/stoneyellow.png");
	SCENE = LoadTexture("graphics/scene.png");
	PLAYBACKGROUND = LoadTexture("graphics/bgday.png");
	TIME = LoadTexture("graphics/time.png");
	POINT = LoadTexture("graphics/point.png");
	TIME_SCORE = LoadTexture("graphics/time_scores.png");
}
void drawBackGround()
{

	DrawTexture(PLAYBACKGROUND, 0, 0, WHITE);
	DrawTexture(TIME, 550, 5, WHITE);
	DrawTexture(POINT, 800, 5, WHITE);
	DrawTexture(TIME_SCORE, 630, 3, WHITE);
	DrawTexture(TIME_SCORE, 990, 3, WHITE);
	DrawTexture(SCENE, 550, 30, WHITE);
}

Font basicFont;

extern float deltaTime;
extern bool IsRunning;


Animation flame;
Animation blueflame;
Music TitleScreenSound;
Sound ERROR;
Sound MATCH;
Sound GAMEOVER;
Sound NEXTLEVEL;
Sound CLOCK;
Music BoardScreenSound;
Music GameScreenSound;
//std::vector<Texture2D> StoneTiles;

std::atomic_int i = 0;
int c = 0;
unsigned char calaph;
bool runflag = true;

int fadeTime = 0;
bool tranFlag = false;

Color gcolor[6] = {YELLOW,RED,PINK,PURPLE,GREEN,BLUE};
Color gameColor[6] = { 217 , 87 , 255,255 ,
                        95,  205 , 228 , 255 ,
	                    251 , 242 , 54 , 255 ,
                        118 , 66 , 138 , 255 ,
                        153 , 229, 80 , 255 ,
                        223 , 113 , 38 , 255 };
std::atomic<Color> matchTextColor;
std::atomic<Color> matchTextColor2;

auto fadeTween = tweeny::from(0).to(255).during(255);

float currFrameTime = 0;
float holdTime = 0.02f;
int frameCount = 0;

Board board;
Profile profile;
Stage  stage;


void TitleState::Init()
{
	auto& eventTimer = SceneManager::Get().eventTimer;

	highLighted = 0;
	InitGraphics();
	InitSound();
	PlayMusicStream(TitleScreenSound);
	
	gameOverRec = { 330, 150, 600.0f, 230.0f };
	StartButtonRec = { 330, 500, 600.0f, 130.0f };
	

	matchTextColor = gcolor[0];
	for (int i = 0; i < 2; i++)
	{
		Button[i].x = 550;
		Button[i].y = 550 + placeHolder;
		Button[i].width = 130.0f + placeHolder *4/2;
		Button[i].height = 30.0f;
		placeHolder += 37;
	}
	eventLoopId = eventTimer.every([&](Timer::TimerInstance& self){
		matchTextColor = gameColor[i];
		if (i > 4)
		{
			matchTextColor2 = gameColor[i-1];		
		}
		else
			matchTextColor2 = gameColor[i+1];
		i++;
		if (i == 6)
			i = 0;
		}, 225);
}
void TitleState::Exit()
{

}
void TitleState::Render()
{
	DrawTextureEx(BACKGROUND, { 0, backGroundScroll -100}, 0.0f, 3, WHITE);
	//DrawRectangleRec(gameOverRec, Color{ 255,255,255,128 });
	DrawRectangleRounded(gameOverRec, 0.2f, 0, Color{ 255,255,255,128 });
	DrawRectangleRounded(StartButtonRec, 0.2f, 0, Color{ 255,255,255,128 });
	DrawTextEx(basicFont, "M", Vector2{ 353, 220 }, EXLARGE, 4, Color{ 34,32,52,255 });
	DrawTextEx(basicFont, "M", Vector2{ 355, 223 }, EXLARGE, 4, Color{ 34,32,52,255 });
	DrawTextEx(basicFont, "M", Vector2{ 350, 220 }, EXLARGE, 4, matchTextColor);
	DrawTextEx(basicFont, "A", Vector2{ 453, 220 }, EXLARGE, 4, Color{ 34,32,52,255 });
	DrawTextEx(basicFont, "A", Vector2{ 455, 223 }, EXLARGE, 4, Color{ 34,32,52,255 });
	DrawTextEx(basicFont, "A", Vector2{ 450, 220 }, EXLARGE, 4, matchTextColor2);
	DrawTextEx(basicFont, "T", Vector2{ 553, 220 }, EXLARGE, 4, Color{ 34,32,52,255 });
	DrawTextEx(basicFont, "T", Vector2{ 555, 223 }, EXLARGE, 4, Color{ 34,32,52,255 });
	DrawTextEx(basicFont, "T", Vector2{ 550, 220 }, EXLARGE, 4, matchTextColor);
	DrawTextEx(basicFont, "C", Vector2{ 653, 220 }, EXLARGE, 4, Color{ 34,32,52,255 });
	DrawTextEx(basicFont, "C", Vector2{ 655, 223 }, EXLARGE, 4, Color{ 34,32,52,255 });
	DrawTextEx(basicFont, "C", Vector2{ 650, 220 }, EXLARGE, 4, matchTextColor2);
	DrawTextEx(basicFont, "H", Vector2{ 753, 220 }, EXLARGE, 4, Color{ 34,32,52,255 });
	DrawTextEx(basicFont, "H", Vector2{ 755, 223 }, EXLARGE, 4, Color{ 34,32,52,255 });
	DrawTextEx(basicFont, "H", Vector2{ 750, 220 }, EXLARGE, 4, matchTextColor);
	DrawTextEx(basicFont, "3", Vector2{ 853, 220 }, EXLARGE, 4, Color{ 34,32,52,255 });
	DrawTextEx(basicFont, "3", Vector2{ 855, 220 }, EXLARGE, 4, Color{ 34,32,52,255 });
	DrawTextEx(basicFont, "3", Vector2{ 847, 223 }, EXLARGE, 4, Color{ 34,32,52,255 });
	//DrawTextEx(basicFont, "3", Vector2{ 84922300 }E, XXLARGE, 4, Color{ 34,32,52,255 });
	DrawTextEx(basicFont, "3", Vector2{ 850, 220 }, EXLARGE, 4, matchTextColor2);
	
	Color tarBlue = WHITE;
	if (highLighted == 1)
	{
		tarBlue = Color{ 103, 255, 255, 255 };
	}
	else
	{
		tarBlue = WHITE;
	}
	DrawText("START", 553, 553, LARGE, Color{ 34,32,52,255 });
	DrawText("START", 550, 550, LARGE, tarBlue);
	if (highLighted == 2)
	{
		tarBlue = Color{ 103, 255, 255, 255 };
	}
	else
	{
		tarBlue = WHITE;
	}
	/*DrawTextEx(basicFont, "QUIT GAME", Vector2{ 552, 535 }, LARGE, 4, Color{ 34,32,52,255 });
	DrawTextEx(basicFont, "QUIT GAME", Vector2{ 554, 535 }, LARGE, 4, Color{ 34,32,52,255 });*/
	DrawText("QUIT GAME", 553, 588, LARGE, Color{ 34,32,52,255 });
	DrawText("QUIT GAME", 550, 550 + 35, LARGE, tarBlue);

	
	if(highLighted == 1)
	{
		DrawRectangleRec(Button[0], ((mouseHoverRec == -1) || (mouseHoverRec == 0 )) ? Color{ 0, 82, 172, 100} : Color { 102, 191, 255,255 });
		//DrawText("", Button[i].x, (int)Button[i].y, MeasureText("", 10 / 2), RED);
	}
	else if(highLighted == 2)
	{
		DrawRectangleRec(Button[1], ((mouseHoverRec == -1) || (mouseHoverRec == 1)) ? Color{ 0, 82, 172, 100 } : Color{ 102, 191, 255,255 });
	}

		DrawRectangle(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, { 255,255,255,calaph });
		//board.Draw();
		

}
void TitleState::Update(SceneManager& state)
{
	auto& eventTimer = SceneManager::Get().eventTimer;

	UpdateMusicStream(TitleScreenSound);
	for (int i = 0; i < 2; i++)
	{
		if (CheckCollisionPointRec(GetMousePosition(), Button[i]))
		{
			mouseHoverRec = i;

			switch (i)
			{
			case 0:
				highLighted = 1;
				break;
			case 1:
				highLighted = 2;
				break;
			}
			if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && mouseHoverRec == 0)
			{
				eventTimer.every([&](Timer::TimerInstance& self)
					{
						currFrameTime += deltaTime;
						if (currFrameTime >= holdTime)
						{
							calaph = fadeTween.step(10);
							frameCount++;
							currFrameTime -= holdTime;
						}
						if (frameCount == 40)
						{
							state.SetState(TransState::getInstance());
							StopMusicStream(TitleScreenSound);
							////need to make a white screen transition screen to board map
							////nvm going to make a tranistion state

							self.stop(); // stop this loop
							eventTimer.stop(eventLoopId); // stop the other loop

							// eventTimer.stop_all(); // stop all running events
						}
					}, 100);
			}
			if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && mouseHoverRec == 1)
			{
				IsRunning = false;
			}
			break;
		}
		else
		{ 
			mouseHoverRec = -1;
			highLighted = 0;
		}
	}
		backGroundScroll += BACKGROUND_SCROLL_SPEED * deltaTime;
		if (backGroundScroll > 100)
		{
			backGroundScroll = BACKGROUND_LOOPING_POINT;
		}
		if (IsKeyPressed(KEY_UP) or IsKeyPressed(KEY_DOWN))
		{

			highLighted++;
			if (highLighted > 2)
			{
				highLighted = 1;
			}

		}
		if (highLighted == 1 and IsKeyPressed(KEY_ENTER))
		{
			state.SetState(BoardState::getInstance());
			state.Init();

		}
		if (highLighted == 2 and IsKeyPressed(KEY_ENTER))
		{

			state.SetState(BoardState::getInstance());
			state.Init();

		}
		c += deltaTime;	
}
BaseState& TitleState::getInstance()
{
	static TitleState singleton;
	return singleton;
}

void BoardState::Init()
{
	InitGraphics();
	InitSound();
	
	FileHandler file;
	//flame = { 705, 500, 150, 200, 5, 1.0f, BOARDVFX };
	PlayMusicStream(BoardScreenSound);
	//blueflame = { 300, 0, 55, 200, 8, 0.2f, BOARDVFX2 };
	//flame = { 705, 300, 150, 200, 5, 1.0f, BOARDVFX };
	//create 13
	board.buttons[0].createAnimation(705, 500, 150, 200, 5, 1.0f, BOARDVFX);
	board.buttons[1].createAnimation(835, 388, 150, 200, 5, 1.0f, BOARDVFX);
	board.buttons[2].createAnimation(915, 190, 150, 200, 5, 1.0f, BOARDVFX);
	board.buttons[3].createAnimation(980, 2, 150, 200, 5, 1.0f, BOARDVFX);
	board.buttons[4].createAnimation(745, 0-12, 150, 200, 5, 1.0f, BOARDVFX);
	board.buttons[5].createAnimation(580, 0 - 14, 150, 200, 5, 1.0f, BOARDVFX);
	board.buttons[6].createAnimation(390, 25, 150, 200, 5, 1.0f, BOARDVFX);
	board.buttons[7].createAnimation(515, 145, 150, 200, 5, 1.0f, BOARDVFX);
	board.buttons[8].createAnimation(670, 310, 150, 200, 5, 1.0f, BOARDVFX);
	board.buttons[9].createAnimation(520, 425, 150, 200, 5, 1.0f, BOARDVFX);
	board.buttons[10].createAnimation(355, 490, 150, 200, 5, 1.0f, BOARDVFX);
	board.buttons[11].createAnimation(170, 470, 150, 200, 5, 1.0f, BOARDVFX);
	board.buttons[12].createAnimation(40, 310, 150, 200, 5, 1.0f, BOARDVFX);
	
}
void BoardState::Exit()
{

}
void BoardState::Render()
{
	DrawTexture(BOARD, 0, 0, WHITE);
	board.buttons[profile.currLevel].a.Draw();
	//DrawRectangleRec(board.buttons[profile.currLevel].rec, WHITE);
	/*board.buttons[1].a.Draw();
	board.buttons[2].a.Draw();
	board.buttons[3].a.Draw();
	board.buttons[4].a.Draw();
	board.buttons[5].a.Draw();
	board.buttons[6].a.Draw();
	board.buttons[7].a.Draw();
	board.buttons[8].a.Draw();
	board.buttons[9].a.Draw();
	board.buttons[10].a.Draw();
	board.buttons[11].a.Draw();
	board.buttons[12].a.Draw();*/
}
void BoardState::Update(SceneManager& state)
{
	UpdateMusicStream(BoardScreenSound);
	//board.buttons[0].Update(deltaTime);
	board.buttons[profile.currLevel].a.Update(deltaTime);

	for (int i = 0; i <= profile.currLevel; i++)
	{
		if (CheckCollisionPointRec(GetMousePosition(), board.buttons[i].rec))
		{
			//if(i <= profile.currLevel)
				if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
				{
					profile.currLevel = i;
					StopMusicStream(BoardScreenSound);
					state.SetState(GameBoardState::getInstance());
					state.Init();
				}
		}
	}
	/*board.buttons[1].a.Update(deltaTime);
	board.buttons[2].a.Update(deltaTime);
	board.buttons[3].a.Update(deltaTime);
	board.buttons[4].a.Update(deltaTime);
	board.buttons[5].a.Update(deltaTime);
	board.buttons[6].a.Update(deltaTime);
	board.buttons[7].a.Update(deltaTime);
	board.buttons[8].a.Update(deltaTime);
	board.buttons[9].a.Update(deltaTime);
	board.buttons[10].a.Update(deltaTime);
	board.buttons[11].a.Update(deltaTime);
	board.buttons[12].a.Update(deltaTime);*/
}
BaseState& BoardState::getInstance()
{
	static BoardState singleton;
	return singleton;
}

void TransState::Init()
{

	//InitGraphics();
	/*FileHandler file;
	 file.LoadStruct("mytext.txt", profile);
	if (strlen(profile.name) == 0)
	{
		stage = { "level 1",13 };
		profile = { "melvin",1,stage };
	}*/
	/*file.LoadStruct("mytext.txt", profile);
	if (sizeof(profile) == NULL)
	{
		stage = { "level 1",13 };
		profile = { "melvin",2,stage };
	}*/
	

}
void TransState::Exit()
{

}
void TransState::Render()
{
	DrawTexture(BOARDVFX3, 0, 0, RAYWHITE);
	DrawText("Loading...", WINDOW_WIDTH / 2-150, WINDOW_HEIGHT / 2, XXLARGE, RED);
}
void TransState::Update(SceneManager& state)
{
	auto& eventTimer = SceneManager::Get().eventTimer;

	eventTimer.after([&](Timer::TimerInstance& self)
		{
			fadeTime = 1;
		}, 3000);
	if (fadeTime == 1)
	{
		state.SetState(BoardState::getInstance());
		state.Init();
	}
}
BaseState& TransState::getInstance()
{
	static TransState singleton;
	return singleton;
}



void GameBoardState::Init()
{
	InitGraphics();
	InitSound();
	PlayMusicStream(GameScreenSound);
	//InitStone();
	//transitionAlpha = 1;
	boardHighlightX = 0;
	boardHighlightY = 0;
	rectHighlighted = false;
	canInput = true;
	//highlightedTile = nullptr;
	score = 0;
	timer = 60;
	//level = 0;
	scoreGoal = 0;
	drop = true;
	//Tile tempTile;
	

	/*--set our Timer class to turn cursor highlight onand off
		Timer.every(0.5, function()
			self.rectHighlighted = not self.rectHighlighted
			end)

		--subtract 1 from timer every second
		Timer.every(1, function()
			self.timer = self.timer - 1

			--play warning sound on timer if we get low
			if self.timer <= 5 then
				gSounds['clock']:play()
				end
				end)
				*/

	//this->level = gameBoard.getLevel();
	//this->score = gameBoard.getScore();
	//gameBoard.Init(gameBoard.getLevel(), 650, 100, gameBoard.getScore());
	level = profile.currLevel + 1;
	this->lboard =  LBoard( 650, 100);
	scoreGoal = level * 1.25 * 1000;
	auto& eventTimer = SceneManager::Get().eventTimer;


	//	if (IsKeyPressed(KEY_ESCAPE)) {
	//		CloseWindow();
	//	}
	//

	//subtract 1 from timer
	eventTimer.every([&](Timer::TimerInstance& self)
		{
			timer = timer - 1;
			if (timer <= 10)
			{
				PlaySound(CLOCK);
			}
			
		}, 1000);
	
	
}
void GameBoardState::Exit()
{
	
}
void GameBoardState::Render()
{
	drawBackGround();

	lboard.Render();
	// GUI text
	Rectangle rect = { 16, 16, 186, 116 };
	Color bgColor = { 56, 56, 56, 234 };
	DrawRectangleRec(rect, bgColor);

	Color textColorTimer = WHITE;
	Color textColor = { 99, 155, 1, 255 };
	
	string strLevel = ("Level: ") + to_string(level);
	string strGoal  = ("Goal: ") + to_string(scoreGoal);

	DrawTextEx(basicFont,strLevel.c_str(), { 20, 24 },LARGE, 1, textColor);
	//DrawTextEx(basicFont,"Score: ", score), { 20, 52 }, font.baseSize, 0, textColor);
	DrawTextEx(basicFont,strGoal.c_str(), { 20, 80 }, LARGE, 1, textColor);
	//DrawTextEx(basicFont,"Timer: ", timer), { 20, 108 }, font.baseSize, 0, textColor);
	string strScore = to_string(score);
	string strTimer = to_string(timer);

	if (timer <= 10) 
	{ 
		textColorTimer = RED;
	}
	DrawText(strTimer.c_str(), 655, 5, 50, textColorTimer);
	

	DrawText(strScore.c_str(), 1015, 5, 50, WHITE);

	if (highlightedTile)
	{

		//-- multiply so drawing white rect makes it brighter
		//love.graphics.setBlendMode('add')

		//love.graphics.setColor(1, 1, 1, 96 / 255)
		DrawRectangle(highlightedTile->gridX * 64 + 650,(highlightedTile->gridY * 64 + 100) ,64,64, Color{1,1,1,96});
		//DrawRectangleLinesEx(Rectangle{ (float)highlightedTile->gridX * 64 + 650,(float)(highlightedTile->gridY * 64 + 100) ,64,64 }, 100, Color{ 1,1,1,96 });
		

		//--back to alpha
		//love.graphics.setBlendMode('alpha')
	
	}
	
	//DrawRectangleLines(boardHighlightX * 64 +650 , boardHighlightY * 64 + 100, 64, 64, RED);
	DrawRectangleLinesEx(Rectangle{ (float)boardHighlightX * 64 + 650 ,(float)boardHighlightY * 64 + 100, 64, 64 }, 4, RED);
	
	
}
void GameBoardState::Update(SceneManager& state)
{
	UpdateMusicStream(GameScreenSound);
	auto& eventTimer = SceneManager::Get().eventTimer;
	static Tween<int> tweenDragged;
	static Tween<int> tweenDes;
	static Tile temphighlightedTile;

	
	//if timer <= 0 gameover
	
	if (timer <= 0)
	{
		PlaySound(GAMEOVER);
		eventTimer.stop_all();
		StopMusicStream(GameScreenSound);
		state.SetState(GameOverScreen::getInstance());
		state.Init();
	}
	
	
		if (score >= scoreGoal) {
			// Next level
			PlaySound(NEXTLEVEL);
			profile.currLevel++;
			StopMusicStream(GameScreenSound);
			state.SetState(LEVELCOMPLETE::getInstance());
			state.Init();
		}
	
	if (canInput) {
		if (IsKeyPressed(KEY_UP)) {
			boardHighlightY = max(0, boardHighlightY - 1);
		}
		else if (IsKeyPressed(KEY_DOWN)) {
			boardHighlightY = min(7, boardHighlightY + 1);
		}
		else if (IsKeyPressed(KEY_LEFT)) {
			boardHighlightX = max(0, boardHighlightX - 1);
		}
		else if (IsKeyPressed(KEY_RIGHT)) {
			boardHighlightX = min(7, boardHighlightX + 1);
		}

		if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_KP_ENTER)) {
			int x = boardHighlightX;
			int y = boardHighlightY;

			if (highlightedTile == nullptr) {
				highlightedTile = &lboard.tiles[y][x];
			}
			else if (highlightedTile == &lboard.tiles[y][x]) {
				highlightedTile = nullptr;
			}
			else if (abs(highlightedTile->gridX - x) + abs(highlightedTile->gridY - y) > 1) 
			{
				PlaySound(ERROR);
				highlightedTile = nullptr;
			}
			else {
				int tempX = highlightedTile->gridX;
				int tempY = highlightedTile->gridY;

				 tempTile = lboard.tiles[y][x];

				highlightedTile->gridX = tempTile.gridX;
				highlightedTile->gridY = tempTile.gridY;
				tempTile.gridX = tempX;
				tempTile.gridY = tempY;

				tweenDragged = { (int)lboard.tiles[highlightedTile->gridY][highlightedTile->gridX].x, (int)highlightedTile->x,
								 (int)lboard.tiles[highlightedTile->gridY][highlightedTile->gridX].y, (int)highlightedTile->y,0.7, lerp<int> };

				tweenDes = { (int)lboard.tiles[tempTile.gridY][tempTile.gridX].x, (int)tempTile.x,
							 (int)lboard.tiles[tempTile.gridY][tempTile.gridX].y, (int)tempTile.y, 0.7, lerp<int> };
				
				

				////TWEEN

				
				

				temphighlightedTile = *highlightedTile;

				//Swap tiles in the tiles table
				lboard.tiles[temphighlightedTile.gridY][temphighlightedTile.gridX] = *highlightedTile;
				lboard.tiles[tempTile.gridY][tempTile.gridX] = tempTile;
				highlightedTile = nullptr;

				drop = false;

				//highlightedTile = nullptr;

				// Calculate matches and update the board

				// Check for game over or next level conditions

				// Update score and timer
			}
			
		}

	}
	//gameBoard.Update(deltaTime);
	if (drop == false)
	{

		if (!tweenDragged.updateF(deltaTime) and !tweenDes.updateF(deltaTime))
				{
					lboard.tiles[temphighlightedTile.gridY][temphighlightedTile.gridX].x = tweenDes.getValueX();
					lboard.tiles[temphighlightedTile.gridY][temphighlightedTile.gridX].y = tweenDes.getValueY();
					lboard.tiles[tempTile.gridY][tempTile.gridX].x = tweenDragged.getValueX();
					lboard.tiles[tempTile.gridY][tempTile.gridX].y = tweenDragged.getValueY();
				}
		else
		{
			
			tweenDragged = {};
			tweenDes = {};
			//temphighlightedTile = {};
			//tempTile = {};
			drop = true;
			CalculateMatches();
			
			
		}
	}
	

}
void GameBoardState::CalculateMatches()
{
	highlightedTile = nullptr;

	int tempx = 0, tempy = 0;

	// if we have any matches, remove them and tween the falling blocks that result
	
	lboard.CalculateMatches();
	if (!lboard.matches.empty())
	{
	

		// add score for each match
		for (const auto& lmatch : lboard.matches)
		{
			score += lmatch.size() * 50;
		}
		if (score >= scoreGoal) 
		{
			return;
		}
		// remove any tiles that matched from the board, making empty spaces
		lboard.RemoveMatches();
		

		auto tilesToFall = lboard.GetFallingTiles();
		
		
		
		for (auto& [tile, TWEEN1] : tilesToFall)
		{
			float elapsedTime = 0.0f;
			float duration = 2.0f;
			
			while (elapsedTime < duration)
			{
				float dt = deltaTime;
				UpdateMusicStream(GameScreenSound);
				elapsedTime += dt;

				// Update the tween for the current tile
				bool isFinished = TWEEN1.update1(dt);
			    auto twValue = TWEEN1.getValue1();
				string strScore = to_string(score);
				string strTimer = to_string(timer);
				// GUI text
				string strLevel = ("Level: ") + to_string(level);
				string strGoal = ("Goal: ") + to_string(scoreGoal);

				// If the tween is finished, stop updating and move to the next tile
				if (isFinished)
				{
					
					lboard.tiles[tile->gridY][tile->gridX].isFalling = false;
					break;
				}

				// Update the position of the tile based on the current tween values
				
				tile->x = twValue.first;
				tile->y = twValue.second;
				//Tile newTile = *tile;
				
				
				

				//// Render the updated tile position
				tempx = twValue.first;
				tempy = twValue.second;
				
				tile->isFalling = false;
				
				Rectangle rect = { 16, 16, 186, 116 };
				Color bgColor = { 56, 56, 56, 234 };
				

				Color textColor = { 99, 155, 1, 255 };
				
				ClearBackground(BLACK);
				BeginDrawing();
				
				drawBackGround();
				lboard.Render();
				

				
				DrawRectangleRec(rect, bgColor);
				DrawTextEx(basicFont, strLevel.c_str(), { 20, 24 }, LARGE, 1, textColor);
				//DrawTextEx(basicFont,"Score: ", score), { 20, 52 }, font.baseSize, 0, textColor);
				DrawTextEx(basicFont, strGoal.c_str(), { 20, 80 }, LARGE, 1, textColor);
				
				DrawText(strTimer.c_str(), 655, 5, 50, WHITE);
				DrawText(strScore.c_str(), 1015, 5, 50, WHITE);
				tile->Render();
		
				EndDrawing();
				
			}
			
			// After the tween is finished, set the final position for the tile
			tile->x = tempx;
			tile->y = tempy;
			
			lboard.tiles[tile->gridY][tile->gridX].isFalling = false;
			
			
			
			// Recursively call the function in case new matches have been created
			// as a result of falling blocks once new blocks have finished falling
			
			
		}
		CalculateMatches();
	}
	else
	{
		canInput = true;
		
	}
	
}
BaseState& GameBoardState::getInstance()
{
	static GameBoardState singleton;
	return singleton;
}
GameBoardState& GameBoardState::getState()
{
	return *static_cast<GameBoardState*>(&getInstance());
}


void GameOverScreen::Init()
{



}
void GameOverScreen::Exit()
{

}
void GameOverScreen::Render()
{
	// Set colors
	Color bgRectColor = { 56, 56, 56, 234 };
	Color textColor = { 0, 0, 0, 255 };

	// Draw background rectangle
	DrawRectangle(WINDOW_WIDTH / 2 - 64, 164, 450, 250, bgRectColor);

	// Draw "GAME OVER" text
	DrawTextEx(basicFont, "GAME OVER", { (float)(WINDOW_WIDTH / 2), 164 },LARGE, 1, textColor);

	GameBoardState& g = GameBoardState::getState();
	// Draw score text
	std::string scoreText = "Your Score : " + std::to_string(g.score);
	DrawTextEx(basicFont, scoreText.c_str(), { (float)(WINDOW_WIDTH / 2), 220 },LARGE, 1, textColor);

	// Draw "Press Enter" text
	DrawTextEx(basicFont, "Press Enter", { (float)(WINDOW_WIDTH / 2 ), 320},LARGE +20, 1, textColor);
	
}
void GameOverScreen::Update(SceneManager& state)
{
	if (IsKeyPressed(KEY_ENTER)) {

		state.SetState(BoardState::getInstance());
		state.Init();
	}
	
}
BaseState& GameOverScreen::getInstance()
{
	static GameOverScreen singleton;
	return singleton;
}

void LEVELCOMPLETE::Init()
{
	InitGraphics();


}
void LEVELCOMPLETE::Exit()
{

}
void LEVELCOMPLETE::Render()
{
	// Set colors
	Color bgRectColor = { 56, 56, 56, 234 };
	Color textColor = PURPLE;//{ 99, 155, 1, 255 };
	DrawTexture(PLAYBACKGROUND,0, 0, WHITE);
	// Draw background rectangle
	DrawRectangle(WINDOW_WIDTH / 2-160, 164, 650, 250, bgRectColor);

	// Draw "GAME OVER" text
	DrawTextEx(basicFont, "Level Complete", { (float)(WINDOW_WIDTH / 2 -70), 190 }, XLARGE, 1, textColor);

	GameBoardState& g = GameBoardState::getState();
	// Draw score text
	std::string scoreText = "Your Score : " + std::to_string(g.score);
	DrawTextEx(basicFont, scoreText.c_str(), { (float)(WINDOW_WIDTH / 2-70), 260 }, XLARGE, 1, textColor);

	// Draw "Press Enter" text
	DrawTextEx(basicFont, "Press Enter", { (float)(WINDOW_WIDTH / 2-50), 350 }, LARGE + 20, 1, textColor);

}
void LEVELCOMPLETE::Update(SceneManager& state)
{
	if (IsKeyPressed(KEY_ENTER)) {

		state.SetState(BoardState::getInstance());
		state.Init();
	}

}
BaseState& LEVELCOMPLETE::getInstance()
{
	static LEVELCOMPLETE singleton;
	return singleton;
}
