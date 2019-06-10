#pragma once
#include <vector>
#include <memory>
#include "UIItem.hpp"

namespace Football
{
	class UIContainer
	{
	private:
		std::vector<std::shared_ptr<UIItem>> uiItems;
	public:
		UIContainer();
		~UIContainer();

		void addUIItem(std::shared_ptr<UIItem> item);
		void update();
		void draw();
	};

}
