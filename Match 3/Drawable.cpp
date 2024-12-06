#include "Drawable.h"

void Drawable::Draw() const
{
	if(gfx.mipmaps ==1)
		DrawTextureV(gfx, gfxPosition, chroma);
}