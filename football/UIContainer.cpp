#include "UIContainer.hpp"

namespace Football
{
	UIContainer::UIContainer()
	{
	}

	UIContainer::~UIContainer()
	{
	}

	void UIContainer::addUIItem(std::shared_ptr<UIItem> item)
	{
		uiItems.push_back(item);
	}

	void UIContainer::update()
	{
		for (auto& item : uiItems)
			item->update();
	}

	void UIContainer::draw()
	{
		for (auto& item : uiItems)
			item->draw();
	}
}
