#pragma once
#include "include/raylib.h"

class Drawable 
{
	
public:
	
	Drawable() :  gfxPosition({ 0,0 }), chroma(WHITE) {};
	Drawable(float x, float y, float width, float height, Texture2D gfx) :
		gfx(gfx),
		gfxPosition({ x,y }),
		width(width),
		height(height)
	{

	}
	virtual ~Drawable() = default;
	virtual void Draw() const;
	void inline Setgfx(Texture2D texture) { gfx = texture; height = gfx.height; width = gfx.width; }
	void inline Cleargfx() { UnloadTexture(gfx); }
	void inline setPos(float x, float y) { gfxPosition.x = x; gfxPosition.y = y;}
	Vector2 inline getPos() const { return gfxPosition;}
	
    Texture2D gfx;
	Vector2 gfxPosition;
	Color chroma;

	float width;
	float height;

};