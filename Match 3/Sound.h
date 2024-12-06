#pragma once
#include "include/raylib.h"

extern Music TitleScreenSound;
extern Music BoardScreenSound;
extern Music GameScreenSound;



//extern Sound HIT_PADDLE;
extern Sound ERROR;
extern Sound MATCH;
extern Sound GAMEOVER;
extern Sound NEXTLEVEL;
extern Sound CLOCK;
//extern Sound HIT_BRICK_1;
//extern Sound HIT_BRICK_2;
//extern Sound PAUSE;
//extern Sound HIT_WALL;

void static InitSound()
{
	TitleScreenSound = LoadMusicStream("Sounds/Cipher2.mp3");
	BoardScreenSound = LoadMusicStream("Sounds/Space-Jazz.mp3");
	GameScreenSound  = LoadMusicStream("Sounds/music3.mp3");
	MATCH = LoadSound("Sounds/match.wav");
	GAMEOVER = LoadSound("Sounds/game-over.wav");
	NEXTLEVEL = LoadSound("Sounds/next-level.wav");
	CLOCK = LoadSound("Sounds/clock.wav");
	//HIT_PADDLE = LoadSound("Sounds/paddle_hit.wav");
	////const Sound SCORE = LoadSound("Sounds/score.wav");
	//HIT_WALL = LoadSound("Sounds/wall_hit.wav");
	////const Sound CONFIRM = LoadSound("Sounds/confirm.wav ");
	////const Sound SELECT = LoadSound("Sounds/select.wav ");
	////const Sound NO_SELECT = LoadSound("Sounds/no-select.wav ");
	//HIT_BRICK_1 = LoadSound("Sounds/brick-hit-1.wav");
	//HIT_BRICK_2 = LoadSound("Sounds/brick-hit-2.wav");
	ERROR = LoadSound("Sounds/error.wav");
	////const Sound VICTORY = LoadSound("Sounds/victory");
	////const Sound RECOVER = LoadSound("Sounds/recover");
	////const Sound HIGH_SCORE = LoadSound("Sounds/high-score");
	//PAUSE = LoadSound("Sounds/pause.wav");
	////const Sound MUSIC = LoadSound("Sounds/music");
}