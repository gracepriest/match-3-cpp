#include "Button.h"

Buttonx::Buttonx(int x, int y, int width, int height, Texture2D image)
	:x(x),
	y(y),
	width(width),
	height(height),
	image(image)
	//Animation(x, y, width, height, 5, 0.2f, image)	
{
	
}
void Buttonx::Load(Texture2D mygfx)
{
	
}

void Buttonx::Update(float dt)
{
	//Buttonx::Animation::Update(dt);
}

void Buttonx::Draw()
{
}

void Buttonx::createAnimation(int Posx, int Posy, int w, int h, float count, float holdTime, Texture2D mygfx)
{
	a = { Posx, Posy, w, h,  count, holdTime,mygfx };
	rec = { (float)Posx,(float)Posy,(float)w,(float)h };
}