#include "GameObject.hpp"

namespace Football
{

	GameObject::GameObject(sf::Vector2f position, b2BodyType bodyType)
	{
		tag = "";

		b2BodyDef bodyDef;
		bodyDef.position = b2Vec2(position.x / PHYSICS_SCALE, position.y / PHYSICS_SCALE);
		bodyDef.type = bodyType;
		bodyDef.fixedRotation = true;
		body = GameData::getInstance()->worldManager.getWorld()->CreateBody(&bodyDef);
		body->SetUserData(this);

		sprite.setPosition(position);
	}

	void GameObject::draw()
	{
		sprite.setPosition(PHYSICS_SCALE * body->GetPosition().x, PHYSICS_SCALE * body->GetPosition().y);
		sprite.setRotation(body->GetAngle() * 180 / b2_pi);
		GameData::getInstance()->window.draw(sprite);
	}

	std::string GameObject::getTag() const
	{
		return tag;
	}

	void GameObject::setSpriteTexture(std::string textureName)
	{
		sprite.setTexture(GameData::getInstance()->assets.GetTexture(textureName));
		sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
	}
}
