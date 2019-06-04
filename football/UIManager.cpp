#include "UIManager.hpp"

namespace Football
{
	UIManager::UIManager()
	{
	}

	UIManager::~UIManager()
	{
	}

	void UIManager::addUIItem(std::shared_ptr<UIItem> item)
	{
		uiItems.push_back(item);
	}

	void UIManager::update()
	{
		for (auto& item : uiItems)
			item->update();
	}

	void UIManager::draw()
	{
		for (auto& item : uiItems)
			item->draw();
	}
}
