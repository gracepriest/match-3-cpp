#pragma once

#include "Animation.h"
class Buttonx : public Animation
{
public:
	Buttonx(int x, int y, int width, int height, Texture2D image);
	void Draw();
	void Load(Texture2D);
	void Update(float dt);
	Animation a;
	void createAnimation(int Posx, int Posy, int w, int h, float count, float holdTime, Texture2D mygfx);
	
	
	int x; int y; float width; float height; Texture2D image;
	Rectangle rec;
};

