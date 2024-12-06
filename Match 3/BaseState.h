#pragma once
#include <memory>
#include <vector>

class State;

class SceneManager;
class Drawable;

class BaseState
{
public:
	virtual void Init() = 0;
	virtual void Exit() = 0;
	virtual void Render() = 0;
	virtual void Update(SceneManager&) = 0;
	//virtual void SetState(State* state) = 0;
	virtual ~BaseState() {};
	void DrawDrawables();
	//Used for drawing UI
	std::shared_ptr<Drawable> PushDrawable(Drawable*);
	std::shared_ptr<Drawable> PopDrawable(Drawable*);
protected:
	std::vector<std::shared_ptr<Drawable>> drawables;
};