#include "Game.h"
#include "Graphics.h"
#include <iostream>
#include "include/raylib.h"
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
//#include "Sounds.h"
#include "State.h"
#include "States.h"
#include "Sound.h"
#include "LuaTitle.h"
//#include "Fonts.h"
//#include "Graphics.h"
const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 720;

//is game running
extern bool IsRunning = true;

//global DT
float deltaTime;

//FOR TESTING ANIMATION
float frameWidth;
float frameHeight = 0;
float timer = 0.0f;
int frame = 0;
int maxframe;
int frameLeft = 25;
extern vector<Texture2D> gFrames;



/********************************************************/
//Load starting state
void Init()
{
	auto& sceneManager = SceneManager::Get();

	if (sceneManager.getCurrrentState() == nullptr)
	{
		sceneManager.SetState(TitleState::getInstance());
		
	}
	else
	{
		sceneManager.Init();
	}
}
int Game::Load()
{
	auto& sceneManager = SceneManager::Get();

	SetConfigFlags(FLAG_MSAA_4X_HINT);
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Match 3");
	InitAudioDevice();     // Initialize audio device
	Init();
	InitTGraphics();
	
	BOARDVFX = LoadTexture("graphics/blueflame.png");
	frameWidth = (float)(BOARDVFX.width / 9);
	maxframe = 16;
	srand(time(NULL));
	sceneManager.Init();
	SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
	
	//PlaySound(HURT);
	
	return 0;
}
void Game::Update()
{
	auto& sceneManager = SceneManager::Get();

	while (IsRunning)    // Detect window close button or ESC key windowshouldclose will be replaced by iskeypress
	{
	
		if (WindowShouldClose())
	    {
			IsRunning = false;
	    }
		deltaTime = GetFrameTime();
		
		sceneManager.Update();
		//player.Update(deltaTime);
		Draw(deltaTime);
	}
}
void Game::Draw(float dt)
{
	auto& sceneManager = SceneManager::Get();

	timer += dt;
	if (timer >= 0.2f)
	{
		timer = 0.0f;
		frame += 1;
	}
	
	if (frame % 9 == 0)
	{
		frameHeight = ((float)BOARDVFX.height / 2) -10;
		frameLeft = 15;
	}
	
	 if (frame % 17 ==0)
	{
		frameHeight = 0;
		frameLeft = 30;
		frame = 0;
	}

	ClearBackground(BLACK);
	BeginDrawing();
	DrawFPS(0, 0);
	sceneManager.Render();
	/*DrawTextureRec(
		BOARDVFX, 
		Rectangle{(frameWidth * frame)-frameLeft,frameHeight,frameWidth, (float)BOARDVFX.height/2},
		Vector2{ 20, 20, },
		RAYWHITE);*/
	EndDrawing();
}
void render()
{

}
void Game::Start()
{
	Load();
	Update();
}
Game::~Game()  
{
	CloseAudioDevice();
	CloseWindow();
}