#include "FansBench.hpp"

namespace Football
{

	FansBench::FansBench(sf::Vector2f position, Team::Side side) : GameObject(position, b2_staticBody)
	{
		tag = "bench";

		GameObject::setSpriteTexture("bench");

		initFans(side);
	}

	FansBench::~FansBench()
	{
	}

	void FansBench::update(float dt)
	{
		for (auto& fan : fans)
			fan->update(dt);
	}

	void FansBench::draw()
	{
		GameObject::draw();

		for (auto& fan : fans)
			fan->draw();
	}

	void FansBench::onCollision(GameObject* collisionObject)
	{
	}

	void FansBench::initFans(Team::Side& side)
	{
		float x = 0;
		float y = 0;

		do
		{
			x += randomBetween(25.f, 40.f);
			y = randomBetween(1.f, 5.f);
			sf::Vector2f fanPosition = getPosition() + sf::Vector2f(x - (getWidth() / 2), y);

			fans.push_back(std::make_unique<Fan>(fanPosition, side));
		} while (x <= getWidth() - 50);
	}
}
