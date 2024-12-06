//#include "GameBoard.h"
//#include "Tween.h"
//#include "LuaBoard.h"



//static Tween<int> tweenDragged;
//static Tween<int> tweenDes;
//
//LBoard luaBoard;

//std::map<Stone*, Tween<float>> stoneTweens;
//bool finished = false;
//GameBoard::GameBoard()
//{
//	/*currentlyDraggedStone = nullptr;
//	IsDragging = false;	*/
//	
//}
//
////void GameBoard::Init(int level, int width, int height, int score)
////{   
////	this->Level = level;
////	this->score = score;
////	luaBoard = LBoard(width, height);
////	scoreGoal = level * 1.25 * 1000;
////	/*boardHighlightX = 0;
////	boardHighlightY = 0;
////	rectHighlighted = false;
////	canInput = true;
////	highlightedTile = nil;*/
////	
////	/*boardWidth = width;
////	boardHeight = height;
////
////	_gboard.clear();
////	_gboard.resize(height, {});
////	int level = 0;
////	int counter = 0;
////	int itemCounter = 0;
////	int Hspace = 0;
////	int Vspace = 0;
////
////	switch (level)
////	{
////	case 0:
////		counter = 0;
////		itemCounter = 0;
////		Hspace = 0;
////		Vspace = 0;
////		int randNum = rand() % 3;
////
////		for (int item = 0; item < height; item++)
////		{
////			for (int i = 0; i < width; i++)
////			{
////				randNum = rand() % 3;
////				Stone stone;
////				stone.brickImage = StoneTiles[randNum];
////				stone.x += Hspace;
////				stone.y += Vspace;
////				
////				stone.gridY = item;
////				stone.gridX = i;
////				stone.recMask.width = stone.brickImage.width;
////				stone.recMask.height = stone.brickImage.height;
////				stone.color = randNum;
////				stone.inPlay = true;
////				_gboard[item].emplace_back(std::move(stone));
////				
////
////				counter++;
////				Hspace += 75;
////				if (counter % 5 == 0)
////				{
////					Hspace = 0;
////					Vspace += 75;
////				}
////			}
////		}
////	}*/
////	
////}
////
//////Stone& GameBoard::GetStone(const Vector2& pos)
//////{
//////	////check to make sure not out of bound
//////	//if (pos.x < 0 || pos.x >= boardWidth ||
//////	//	pos.y < 0 || pos.y >= boardHeight)
//////	//{
//////	//	throw std::runtime_error("out of bound");
//////	//}
//////
//////	//return _gboard[pos.y][pos.x];
//////	return 
//////}
////
////void GameBoard::IterateStones(std::function<bool(Stone&)> callback)
////{
////	/*for (auto& row : _gboard)
////	{
////		for (auto& stone : row)
////		{
////			if (!callback(stone)) break;
////		}
////	}*/
////
////}
////
////void GameBoard::Render()
////{
////	luaBoard.Render();
////	////stop rendering currentlydragged stone
////	//IterateStones([](Stone& stone) {
////	//	stone.Render();
////	//	return true;
////	//});
////	//if (currentlyDraggedStone != nullptr)
////	//{
////	//	currentlyDraggedStone->Render();
////	//}
////}
////void GameBoard::Update(float deltaTime)
////{
////	//Stone temp;
////	//IterateStones([&deltaTime](Stone& stone) {
////	//	stone.Update(deltaTime);
////	//	return true;
////	//	});
////
////	//bool drop = false;
////	//IterateStones([&](Stone& stone) {
////	//	if (currentlyDraggedStone == &stone)
////	//	{
////	//		return true;
////	//	}
////	//	if (currentlyDraggedStone != nullptr)
////	//	{
////	//		if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
////	//		{
////	//			drop = true;
////	//			auto xx = stone.x;
////	//			auto yy = stone.y;
////	//			DesStone = &stone;
////	//			if (CheckCollisionRecs(currentlyDraggedStone->dragMask, stone.recMask))
////	//			{
////
////	//				tweenDragged = { (int)currentlyDraggedStone->prev_x, (int)xx,
////	//								 (int)currentlyDraggedStone->prev_y, (int)yy,0.7, lerp<int> };
////	//				tweenDes = { (int)xx, (int)currentlyDraggedStone->prev_x,
////	//							 (int)yy, (int)currentlyDraggedStone->prev_y, 0.7, lerp<int> };
////
////	//				stone.x = currentlyDraggedStone->prev_x;
////	//				stone.y = currentlyDraggedStone->prev_y;
////	//				//currentlyDraggedStone->x = xx;
////	//				//currentlyDraggedStone->y = yy;
////
////	//				currentStone = currentlyDraggedStone;
////	//				std::swap(stone, *currentlyDraggedStone);
////	//				currentlyDraggedStone->isDragging = false;
////	//				stone.isDragging = false;
////	//				CalculateMatches();
////	//				
////	//				currentlyDraggedStone = nullptr;
////	//				drop = false;
////
////	//				return false;
////	//			}
////	//		}
////	//		if (CheckCollisionRecs(currentlyDraggedStone->dragMask, stone.recMask))
////	//		{
////	//			stone.isDragging = true;
////	//		}
////	//		else
////	//		{
////	//			stone.isDragging = false;
////	//		}
////	//	}
////	//	return true;
////	//	});
////
////	//if (drop and currentlyDraggedStone != nullptr)
////	//{
////	//	currentlyDraggedStone->x = currentlyDraggedStone->prev_x;
////	//	currentlyDraggedStone->y = currentlyDraggedStone->prev_y;
////	//	currentlyDraggedStone->isDragging = false;
////	//	currentlyDraggedStone = nullptr;
////
////	//}
////
////	//if (currentStone != nullptr)
////	//{
////	//	if (!tweenDragged.update(deltaTime) and !tweenDes.update(deltaTime))
////	//	{
////	//		currentStone->x = tweenDes.getValueX();
////	//		currentStone->y = tweenDes.getValueY();
////	//		DesStone->x = tweenDragged.getValueX();
////	//		DesStone->y = tweenDragged.getValueY();
////	//		IsDragging = true;
////	//	}
////	//	else
////	//	{
////	//		IsDragging = false;
////	//		
////	//		RemoveMatches();
////	//		//currentStone = nullptr;
////	//		
////	//		
////	//		//finished = true;
////	//	}
////	//}
////	//
////		
////		//if (!stoneTweens.empty())
////		//{
////		//	Stone* stone;
////		//	
////		//	for (auto it = stoneTweens.begin(); it != stoneTweens.end();it++)
////		//	{
////		//		stone = it->first;
////		//		static Tween<float>& stoneTween = it->second;
////
////
////
////		//		if(!stoneTween.update(deltaTime))
////		//		{ 
////		//			//stone->inPlay = true;
////		//			stone->x = stone->x; // Assuming the x position does not change during falling animation
////		//			stone->y = it->second.getValueX(); // Use getValueX to get the interpolated y-coordinate
////		//			std::cout <<"stone location: "<< stone->y << std::endl;
////		//			std::cout << "tween value: "<<stoneTween.getValueY() << std::endl;
////		//		}
////		//		else
////		//		{
////		//			finished = true;
////		//		}
////
////
////		//		if (finished)
////		//		{
////		//		//	// Handle the case when the tween has finished, e.g., remove the stone from the map
////		//		//	// (You can also do this outside the loop to avoid modifying the map while iterating over it)
////		//			//stoneTweens.clear();
////		//			break;
////		//		}
////
////		//	}
////
////		//}
////	
////	
////		
////}
////
////
////void GameBoard::CalculateMatches()
////{
////	luaBoard.CalculateMatches();
////	//matches.clear();
////	//// How many colors we found
////	//int matchNum = 0;
////
////	//// Horizontal matches first
////	//for (int y = 0; y < 5; y++) {
////	//	int colorToMatch = GetStone( {0.f, float(y)} ).color;
////
////	//	matchNum = 1; // Set initial value to 1
////
////	//	// Every horizontal tile
////	//	for (int x = 1; x < 5; x++) {
////	//		// Color to match
////	//		if (GetStone({ float(x), float(y) }).color != -1)
////	//		{
////	//			if (colorToMatch == GetStone({ float(x), float(y) }).color) {
////	//				matchNum++;
////	//			}
////	//			else {
////	//				if (matchNum >= 3) {
////	//					match.clear();
////	//					// Go backwards from here by matchNum
////	//					for (int x2 = x - 1; x2 >= x - matchNum; x2--) {
////	//						match.push_back(&GetStone({ float(x2),float(y) }));
////	//						GetStone({ float(x2),float(y) }).color = -1;
////	//					}
////	//					matches.insert(matches.end(), match.begin(), match.end());
////	//				}
////	//				colorToMatch = GetStone({ float(x), float(y) }).color;
////	//				matchNum = 1; // Reset to 1
////
////	//				if (x >= 4) {
////	//					break;
////	//				}
////	//			}
////	//		}
////	//	}
////
////	//	// Account for the last row ending with a match
////	//	if (matchNum >= 3) {
////	//		match.clear();
////	//		// Go backwards from end of last row by matchNum
////	//		for (int x = 4; x >4 - matchNum; x--) {
////	//			match.push_back(&GetStone( {float(x), float(y)} ));
////	//			
////	//		}
////	//		matches.insert(matches.end(), match.begin(), match.end());
////	//	}
////	//}
////
////	//// Vertical matches
////	//for (int x = 0; x < 5; x++) {
////	//	int colorToMatch = GetStone( {float(x), 0.f} ).color;
////	//	matchNum = 1; // Set initial value to 1
////
////	//	// Every vertical tile
////	//	for (int y = 1; y < 5; y++) {
////	//		if (colorToMatch == GetStone( {float(x), float(y)} ).color) {
////	//			matchNum++;
////	//		}
////	//		else 
////	//		{
////	//			if (matchNum >= 3) 
////	//			{
////	//				match.clear();
////	//				for (int y2 = y - 1; y2 >= y - matchNum; y2--) 
////	//				{
////	//					match.push_back(&GetStone({ float(x), float(y2) }));
////	//				}
////	//				matches.insert(matches.end(), match.begin(), match.end());
////	//			}
////	//			
////	//			colorToMatch = GetStone( {float(x), float(y)} ).color;
////	//			matchNum = 1; // Reset to 1
////
////	//			if (y >= 4)
////	//			{
////	//				break;
////	//			}
////
////	//		}
////	//	}
////
////	//	// Account for the last column ending with a match
////	//	if (matchNum >= 3) {
////	//		match.clear();
////	//		// Go backwards from end of last row by matchNum
////	//		for (int y = 4; y > 4 - matchNum; y--) {
////	//			match.push_back(&GetStone({ float(x), float(y) }));
////	//		}
////	//		matches.insert(matches.end(), match.begin(), match.end());
////	//	}
////	//	
////	//}
////}
////
////void GameBoard::RemoveMatches()
////{
////	luaBoard.RemoveMatches();
////	//if (!matches.empty())
////	//{
////	//	for (auto& row : _gboard)
////	//	{
////	//		for (auto& stone : row)
////	//		{
////	//			//stone.isDragging2 = false;
////	//		}
////	//	}
////	//	for (auto& stone : matches)
////	//	{
////	//		stone->inPlay = false;
////	//		
////	//		//stone->isDragging2 = true;
////	//	}
////	//
////	//
////	//}
////	//matches.clear();
////	//stoneTweens = GetFallingStone();
////}
////
//////std::map<Stone*, Tween<float>> GameBoard::GetFallingStone() {
//////	std::map<Stone*, Tween<float>> tweens;
//////	auto& stones = _gboard;
//////
//////	for (int x = 0; x < 5; x++) {
//////		bool space = false;
//////		int spaceY = 0;
//////
//////		int y = 4;
//////		while (y >= 0) {
//////			Stone& stone = stones[y][x];
//////
//////			if (space) 
//////			{
//////				if (stone.inPlay) 
//////				{
//////					float newY = stones[spaceY][x].y;
//////					stones[spaceY][x] = stone;
//////					stone.gridY = spaceY;
//////					stones[y][x]= Stone(stone.x,stone.y);
//////					
//////					//tween here
//////					tweens[&stones[spaceY][x]] = Tween<float>((float)stone.x, (float)stone.x, (float)stone.y, (float)newY, 3, lerp<float>); // changed to spaceY
//////
//////					space = false;
//////					y = spaceY;
//////					spaceY = 0;
//////				}
//////			}
//////			else if (!stone.inPlay) {
//////				space = true;
//////				if (spaceY == 0) {
//////					spaceY = y;
//////				}
//////			}
//////
//////			y--;
//////		}
//////	}
//////
//////	/*std::random_device rd;
//////	std::mt19937 gen(rd());
//////	std::uniform_int_distribution<> color_dist(1, 3);
//////
//////	for (int x = 0; x < 5; x++) {
//////		for (int y = 4; y >= 0; y--) {
//////			Stone& stone = stones[y][x];
//////			if (!stone.inPlay) {
//////				Stone newStone;
//////				newStone.x = x;
//////				newStone.y = y;
//////				newStone.color = color_dist(gen);
//////				newStone.prev_y = -32;
//////				stones[y][x] = newStone;
//////
//////				tweens[&stones[y][x]] = Tween<float>(-32, y * 32, 0, 0, 0.5, lerp<float>);
//////			}
//////		}
//////	}*/
//////	return tweens;
//////}
////
////
////GameBoard::~GameBoard()
////{
////	 /*currentlyDraggedStone =nullptr;
////	 currentStone = nullptr;
////	 DesStone = nullptr;*/
////}
