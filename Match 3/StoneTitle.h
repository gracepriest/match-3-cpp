#pragma once
#include "include/raylib.h"
#include <vector>







class Stone
{
	
public:
	    int ID;
		float x;
		float y;
		float prev_x;
		float prev_y;
		float width;
		float height;
		bool isDragging;
		bool isDragging2;
		float gridX =0;
		float gridY =0;
		Color borderColor = RED;
		//float tier;
		int color;
		Texture2D brickImage;
		bool inPlay = true;
		Stone();
		Stone(float x, float y);
		void Update(float dt);
		//void Hit();
		Rectangle recMask;
		Rectangle dragMask;
		float scale;
		void Render();
		bool operator==(const Stone& other) const {
			if (typeid(*this) != typeid(other)) {
				return false; // Not the same type, return false
			}
			return true;
		}
		~Stone() {};
};

extern std::vector<Texture2D> StoneTiles;
static Image StoneTitleImage;
static Texture2D stoneTitleTexture;
static int stoneId = 0;



//std::vector<std::vector<Stone>> static creaeteGameBoard()
//{
//	int level = 0;
//	int counter = 0;
//	int itemCounter = 0;
//	int Hspace = 0;
//	int Vspace = 0;
//
//	switch (level)
//	{
//	case 0:
//		counter = 0;
//		itemCounter = 0;
//		Hspace = 0;
//		Vspace = 0;
//		for (int item = 0; item < 5; item++)
//		{
//			for (int i = 0; i < 5; i++)
//			{
//				gboard[item][i].brickImage = StoneTiles[(rand()% 3)];
//				gboard[item][i].x += Hspace;
//				gboard[item][i].y += Vspace;
//				gboard[item][i].recMask.x = gboard[item][i].x;
//				gboard[item][i].recMask.y = gboard[item][i].y;
//				gboard[item][i].recMask.width = gboard[item][i].brickImage.width;
//				gboard[item][i].recMask.height = gboard[item][i].brickImage.height;
//				
//
//				counter++;
//				Hspace += 75;
//				if (counter % 5 == 0)
//				{
//					Hspace = 0;
//					Vspace += 75;
//				}
//			}
//		}
//	}
//	return gboard;
//}
