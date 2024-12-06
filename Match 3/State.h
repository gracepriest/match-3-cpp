#pragma once
#include "BaseState.h"
#include "Timer.h"
#include <vector>
#include "Drawable.h"
#include <memory>

//class BaseState;

class SceneManager
{

public:
	SceneManager() : currentState(nullptr) {}
	inline static SceneManager& Get() { static SceneManager mgr; return mgr; };
	
	inline BaseState* getCurrrentState() const { return currentState; }

	Timer eventTimer; // Main Scene Event Timer

	void Init()
	{
		if (currentState != nullptr)
		{
			currentState->Init();
		}
		
	}
	virtual void Exit()
	{
		currentState->Exit();
	}

	void Update()
	{
		eventTimer.Update(); // run all timer events
		currentState->Update(*this); // run current state
	}

	void SetState(BaseState& newState)
	{
		currentState = &newState;
	}

	void Render()
	{
		if (currentState != nullptr)
		{
			
			currentState->Render();
			
			
		}
	}


private:
	BaseState* currentState;
	SceneManager& operator = (const SceneManager& other);
};