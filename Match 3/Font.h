#pragma once
#include "CommonHeaders.h"

static float SMALLFONT = 16;
static float MEDIUM = 24;
static float LARGE = 32;
static float XLARGE = 64;
static float EXLARGE = 100;
static float XXLARGE = 128;


static Font DEFAULT;
extern Font basicFont;

static void InitFont()
{
	DEFAULT = GetFontDefault();
	basicFont = LoadFont("Fonts/font.ttf");
}