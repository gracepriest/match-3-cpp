#pragma once
#include "CommonHeaders.h"
class Animation : public Drawable
{
	void Draw(Vector2, Texture2D);
	void Draw(Vector2, Texture2D, Rectangle clip);
public:

	Animation() =default;
	Animation(int Posx, int Posy, int width, int height, float count, float holdTime, Texture2D gfx);
	void Draw() const override;
	void Draw(Vector2) const;
	void Update(float dt);
	void setCount(int);
	void inline setHeight(float h) { height = h; }
	void inline setWidth(float h) { width = h; }
	void inline setHold(float h) { holdTime = h; }
	void inline setRecSize(float w, float h) { RecSize.x = w; RecSize.y = h; }

	void Advance();
	std::vector<Rectangle> frames;
	
	//current frame
	int iCurrentFrame = 0;
	//how long we hold the current frame before next
	float holdTime;
	//how long we displaying the current frame
	float currFrameTime = 0.0f;
	int Posx; int Posy; 
	//int width; int height; 
	int count; 
	Vector2 RecSize;

};
