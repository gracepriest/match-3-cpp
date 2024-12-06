#include "StoneTitle.h"
#include "States.h"

//const int WINDOW_WIDTH = 1200;
//const int WINDOW_HEIGHT = 720;
//void Stone::Render()
//{
//
//	if (inPlay)
//	{
//
//		//DrawTexture(Paddles[size + 4 * (skin -1)], x, y, WHITE);
//		DrawTextureEx(brickImage, Vector2{ x,y }, 0, 1, WHITE);
//		//testing
//		//DrawRectangleRec(recMask, Color{ 255, 255, 255, 100 });
//		if(isDragging == true)
//		 DrawRectangleLines(recMask.x, recMask.y, recMask.width, recMask.height, borderColor);
//		if(isDragging2 == true)
//			DrawRectangleLines(recMask.x, recMask.y, recMask.width, recMask.height, borderColor);
//
//	}
//}
//
//Stone::Stone()
//{
//	x = WINDOW_WIDTH / 3;
//	y = WINDOW_HEIGHT /3;
//	width = 32;
//	height = 16;
//	color = -1;
//	inPlay = false;
//	scale = 1;
//	recMask.height = height;
//	recMask.width = width;
//	recMask.x = x;
//	recMask.y = y;
//	isDragging = false;
//	isDragging2 = false;
//	ID = stoneId++;
//
//	dragMask.width = 16;
//	dragMask.height = 16;
// 
//}
//Stone::Stone(float x, float y)
//	:x(x), y(y)
//{
//	//x = WINDOW_WIDTH / 3;
//	//y = WINDOW_HEIGHT / 3;
//	prev_x = x;
//	prev_y = y;
//	width = 32;
//	height = 16;
//	color = -1;
//	inPlay = false;
//	scale = 1;
//	recMask.height = height;
//	recMask.width = width;
//	recMask.x = x;
//	recMask.y = y;
//	isDragging = false;
//	isDragging2 = false;
//	ID = stoneId++;
//
//	dragMask.width = 16;
//	dragMask.height = 16;
//
//}
//
//void Stone::Update(float dt)
//{
//	auto& gameBoard = GameBoardState::getState().gameBoard;
//	if (!gameBoard.IsDragging)
//	{
//		// Check if the mouse is pressed and the cursor is on the stone
//		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), recMask)) {
//			// If the stone is not being dragged, set the dragging flag
//			if (gameBoard.currentlyDraggedStone == nullptr)
//			{
//				gameBoard.currentlyDraggedStone = this;
//				prev_x = x;
//				prev_y = y;
//				if (!isDragging)
//				{
//					isDragging = true;
//				}
//			}
//		}
//		if (gameBoard.currentlyDraggedStone == this)
//		{
//			if (isDragging == true)
//			{
//				// Calculate the new position of the stone based on the mouse movement
//				Vector2 mouseDelta = GetMouseDelta();
//				x += mouseDelta.x;
//				y += mouseDelta.y;
//			}
//		}
//		dragMask.x = recMask.x = x;
//		dragMask.y = recMask.y = y;
//	}
//}
//void Stone::Tween(float x , float y)
//{
//
//}