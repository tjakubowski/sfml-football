#include "GameObject.hpp"

namespace Football
{
	GameObject::GameObject(sf::Vector2f position, b2BodyType bodyType)
	{
		b2BodyDef bodyDef;
		bodyDef.position = b2Vec2(position.x / PHYSICS_SCALE, position.y / PHYSICS_SCALE);
		bodyDef.type = bodyType;
		bodyDef.fixedRotation = true;
		body = GameData::getInstance()->worldManager.getWorld()->CreateBody(&bodyDef);

		sprite.setPosition(position);
	}

	std::string GameObject::getTag() const
	{
		return tag;
	}
}
