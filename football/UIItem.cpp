#include "UIItem.hpp"

namespace Football
{
	UIItem::UIItem(sf::Vector2f centerAnchor, std::string textToDisplay, float bgPadding, unsigned fontSize, sf::Color color, sf::Color bgColor) : centerAnchor(centerAnchor)
	{
		background = nullptr;

		text = std::make_unique<sf::Text>();
		text->setFont(GameData::getInstance()->assets.GetFont("RobotoMedium"));
		text->setCharacterSize(fontSize);
		text->setFillColor(color);
		text->setString(textToDisplay);
		text->setPosition(centerAnchor - (sf::Vector2f(text->getGlobalBounds().width, text->getGlobalBounds().height) / 2.f));

		if(bgPadding > 0)
		{
			background = std::make_unique<sf::RectangleShape>(
				sf::Vector2f(text->getGlobalBounds().width, text->getGlobalBounds().height) + (sf::Vector2f(bgPadding, bgPadding) * 2.f)
				);
			background->setPosition(sf::Vector2f(0, text->getGlobalBounds().height / 4.f) + centerAnchor - (sf::Vector2f(text->getGlobalBounds().width, text->getGlobalBounds().height) / 2.f) - sf::Vector2f(bgPadding, bgPadding));
			background->setFillColor(bgColor);
		}
	}

	UIItem::~UIItem()
	{
	}

	void UIItem::update()
	{
		const auto textRect = sf::IntRect(text->getPosition().x, text->getPosition().y, text->getGlobalBounds().width, text->getGlobalBounds().height);

		if (GameData::getInstance()->inputs.isClicked(textRect, sf::Mouse::Button::Left, GameData::getInstance()->window))
		{
			onClick();
			return;
		}

		if (background == nullptr)
			return;

		const auto backgroundRect = sf::IntRect(background->getPosition().x, background->getPosition().y, background->getGlobalBounds().width, background->getGlobalBounds().height);

		if (GameData::getInstance()->inputs.isClicked(backgroundRect, sf::Mouse::Button::Left, GameData::getInstance()->window))
			onClick();
	}

	void UIItem::draw()
	{
		if(background != nullptr)
			GameData::getInstance()->window.draw(*background);

		GameData::getInstance()->window.draw(*text);
	}

	void UIItem::onClick()
	{
	}
}
