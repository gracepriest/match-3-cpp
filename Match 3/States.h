#pragma once
#include "BaseState.h"
#include "State.h"
#include "include/raylib.h"
//#include "GameBoard.h"
#include "LuaBoard.h"
#include "GameBoard.h"




class PlayState : public BaseState
{
public:
	
	void Init();
	void Exit();
	void Render();
	void Update(SceneManager&);
	/*void enter(int level, int score, const LBoard& board) 
	{
		this->level = level;
		this->score = score;
		this->board = board;
		scoreGoal = level * 1.25 * 1000;
	}*/
	//void SetState(State* newState);
	static BaseState& getInstance();


private:
	PlayState() 
	{
		/*transitionAlpha = 1;
		boardHighlightX = 0;
		boardHighlightY = 0;
		rectHighlighted = false;
		canInput = true;
		highlightedTile = nullptr;
		score = 0;
		timer = 60;
		level = 0;
		scoreGoal = 0;*/
	}
	PlayState(const PlayState& other);
	PlayState& operator = (const PlayState& other);
	~PlayState() {}

	/*int transitionAlpha;
	int boardHighlightX;
	int boardHighlightY;
	bool rectHighlighted;
	bool canInput;
	Tile* highlightedTile;
	int score;
	int timer;
	int level;
	LBoard board;
	int scoreGoal;*/

};



class TitleState : public BaseState
{

public:
	
	int highLighted=0;
	float backGroundScroll = 0;
	float groundScroll = 0;

	const double BACKGROUND_SCROLL_SPEED = 120;
	const double GROUND_SCROLL_SPEED = 60;
	
	const float BACKGROUND_LOOPING_POINT = -55;

	Rectangle gameOverRec;
	Rectangle StartButtonRec;
	Rectangle Button[2] = { 0 };
	int mouseHoverRec = -1;
	int placeHolder = 0;
	uint64_t eventLoopId;

	Sound mySound;
	
    void Init();
	void Exit();
	void Render();
	void Update(SceneManager&);
	//void SetState(State* newState);
	static BaseState& getInstance();
	

private:
	
	TitleState() {}
	TitleState(const TitleState& other);
	TitleState& operator = (const TitleState& other);
	~TitleState() {}

};


class BoardState : public BaseState
{

public:

	
	

	void Init();
	void Exit();
	void Render();
	void Update(SceneManager&);
	//void SetState(State* newState);
	static BaseState& getInstance();


private:

	BoardState() {}
	BoardState(const BoardState& other);
	BoardState& operator = (const BoardState& other);
	~BoardState() {}

};

class TransState : public BaseState
{
public:

	void Init();
	void Exit();
	void Render();
	void Update(SceneManager&);
	//void SetState(State* newState);
	static BaseState& getInstance();


private:
	TransState() {}
	TransState(const TransState& other);
	TransState& operator = (const TransState& other);
	~TransState() {}


};


class GameBoardState : public BaseState
{
public:
	//GameBoard gameBoard;

	void Init();
	void Exit();
	void Render();
	void Update(SceneManager&);
	void CalculateMatches();
    int score;
    int getScore() { return score; }
	//void SetState(State* newState);
	static BaseState& getInstance();
	static GameBoardState& getState();
	
private:
	//position in the grid which we're highlighting
	int boardHighlightX = 0;
	int boardHighlightY = 0;

 	//timer used to switch the highlight rect's color
	bool rectHighlighted;

	//flag to show whether we're able to process input (not swapping or clearing)
	

	//tile we're currently highlighting (preparing to swap)
	Tile *highlightedTile = nullptr;

	bool drop;
	int timer = 60;
	int boardWidth;
	int boardHeight;
	int level;
	int scoreGoal;
	bool canInput;
	bool hasMatches =false;
	LBoard lboard;
	GameBoardState() { ; }
	GameBoardState(const GameBoardState& other);
	GameBoardState& operator = (const GameBoardState& other);
	~GameBoardState() { ; }
	
};

class GameOverScreen : public BaseState
{
public:

	void Init();
	void Exit();
	void Render();
	void Update(SceneManager&);
	//void SetState(State* newState);
	static BaseState& getInstance();


private:
	GameOverScreen() {}
	GameOverScreen(const GameOverScreen& other);
	GameOverScreen& operator = (const GameOverScreen& other);
	~GameOverScreen() {}
};

class LEVELCOMPLETE : public BaseState
{
public:

	void Init();
	void Exit();
	void Render();
	void Update(SceneManager&);
	//void SetState(State* newState);
	static BaseState& getInstance();


private:
	LEVELCOMPLETE() {}
	LEVELCOMPLETE(const LEVELCOMPLETE& other);
	LEVELCOMPLETE& operator = (const LEVELCOMPLETE& other);
	~LEVELCOMPLETE() {}
};


	





