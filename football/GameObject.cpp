#include "GameObject.hpp"
#include <utility>
#include "GameState.hpp"

namespace Football
{

	GameObject::GameObject(sf::Vector2f position, b2BodyType bodyType) : startPosition(position)
	{
		tag = "";

		const auto gameState = dynamic_cast<GameState*>(GameData::getInstance()->machine.GetActiveState().get());

		b2BodyDef bodyDef;
		bodyDef.position = b2Vec2(position.x / PHYSICS_SCALE, position.y / PHYSICS_SCALE);
		bodyDef.type = bodyType;
		bodyDef.fixedRotation = true;
		body = gameState->getWorld()->CreateBody(&bodyDef);
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

	sf::Vector2f GameObject::getPosition() const
	{
		return sf::Vector2f(body->GetPosition().x, body->GetPosition().y) * PHYSICS_SCALE;
	}

	float GameObject::getWidth() const
	{
		return sprite.getGlobalBounds().width;
	}

	float GameObject::getHeight() const
	{
		return sprite.getGlobalBounds().height;
	}

	void GameObject::resetPosition() const
	{
		body->SetTransform(
			b2Vec2(startPosition.x / PHYSICS_SCALE, startPosition.y / PHYSICS_SCALE),
			body->GetAngle()
		);
	}

	void GameObject::setSpriteTexture(std::string textureName)
	{
		sprite.setTexture(GameData::getInstance()->assets.GetTexture(std::move(textureName)));
		sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
	}

	bool operator<(std::shared_ptr<GameObject>& a, std::shared_ptr<GameObject>& b)
	{
		return a->getPosition().y < b->getPosition().y;
	}
}
