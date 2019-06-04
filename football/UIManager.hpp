#pragma once
#include <vector>
#include <memory>
#include "UIItem.hpp"

namespace Football
{
	class UIManager
	{
	private:
		std::vector<std::shared_ptr<UIItem>> uiItems;
	public:
		UIManager();
		~UIManager();

		void addUIItem(std::shared_ptr<UIItem> item);
		void update();
		void draw();
	};

}
