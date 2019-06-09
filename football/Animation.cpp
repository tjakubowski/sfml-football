#include "Animation.hpp"
#include <utility>
#include "GameData.hpp"

namespace Football
{

	Animation::Animation(std::string textureName, sf::Sprite* sprite, int columns, float switchTime) : sprite(sprite), columns(columns), switchTime(switchTime)
	{
		currentTime = 0;
		currentColumn = 0;

		this->sprite->setTexture(GameData::getInstance()->assets.GetTexture(std::move(textureName)));
		updateTexturePosition();
	}

	Animation::~Animation()
	{
	}

	void Animation::update(float dt)
	{
		currentTime += dt;

		if(currentTime >= switchTime)
		{
			currentTime = 0;
			if (++currentColumn == columns)
				currentColumn = 0;

			updateTexturePosition();
		}
	}

	void Animation::updateTexturePosition() const
	{
		const auto textureWidth = sprite->getTexture()->getSize().x;
		const auto textureHeight = sprite->getTexture()->getSize().y;

		const sf::IntRect textureRect(
			currentColumn * textureWidth / columns,
			0,
			textureWidth / columns,
			textureHeight
		);

		sprite->setTextureRect(textureRect);
		sprite->setOrigin(sprite->getGlobalBounds().width / 2, sprite->getGlobalBounds().height / 2);
	}
	
}
