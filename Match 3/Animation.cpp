#include "Animation.h"

Animation::Animation(int Posx, int Posy, int w, int h, float count, float holdTime,Texture2D mygfx)
	:
	Posx(Posx),
	Posy(Posy),
	count(count),
	holdTime(holdTime)
	
{
	Setgfx(mygfx);
	setPos(Posx, Posy);
	setRecSize(w, h);
	setWidth(gfx.width / count);
	setHeight(gfx.height/2);
	//setCount(count);
	setHold(0.2f);

	int row = 0;
	for (int i = 0; i < count; i++)
	{
		frames.emplace_back(Rectangle{ (float)i * width, height * row, RecSize.x,RecSize.y });

	}
	row++;
	for (int i = 0; i < count; i++)
	{
		frames.emplace_back(Rectangle{ (float)i * width , height * row, RecSize.x,RecSize.y });

	}
	frames.size();
}

void Animation::setCount(int c)
{
	count = c;
}


void Animation::Update(float dt)
{
	currFrameTime += dt;
    if( currFrameTime >= holdTime)
	{
		Advance();
		currFrameTime -= holdTime;
	}
}
void Animation::Draw() const
{
		DrawTextureRec
		(
			gfx, 
			frames[iCurrentFrame],
			gfxPosition, 
			chroma 
		);
}
//use if the animation need to be moved
void Animation::Draw(Vector2 pos) const
{ 
	DrawTextureRec
	(
		gfx,
		frames[iCurrentFrame],
		pos,
		chroma
	);
}
void Animation::Advance()
{
	if (++iCurrentFrame >= frames.size())
	{
		iCurrentFrame = 0;
	}
}