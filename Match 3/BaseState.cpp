#include "BaseState.h"
#include "Drawable.h"
#include <memory>
#include <algorithm>

std::shared_ptr<Drawable> BaseState::PushDrawable(Drawable* drawable)
{
     drawables.emplace_back(drawable);
	 return drawables.back();
}
std::shared_ptr<Drawable> BaseState::PopDrawable(Drawable* drawable)
{
	auto it = std::find_if(drawables.begin(), drawables.end(), [&](const std::shared_ptr<Drawable>& d) { return d.get() == drawable; });
	if (it == drawables.end()) return nullptr;
	auto sptr = *it;
	drawables.erase(it);
	return sptr;
}

void BaseState::DrawDrawables()
{
	for (const auto& drawable : drawables)
	{
		if (drawable) drawable->Draw();
	}
}