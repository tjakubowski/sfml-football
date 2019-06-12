#include "Striker.hpp"
#include "GameState.hpp"

namespace Football
{

	Striker::Striker(sf::Vector2f position, std::shared_ptr<Team> team) : Bot(position, team)
	{
		nearBallDistance = 110.f;
		
		maxTimeOnEdge = 1;
		currentTimeOnEdge = 0;
		goBack = false;
	}

	Striker::~Striker()
	{
	}

	bool Striker::isOnPitchEdge()
	{
		float const distance = 20;

		std::vector<GameObject*> v = {
			raycastTo(getPosition() + sf::Vector2f(0, distance * 1.5)),
			raycastTo(getPosition() + sf::Vector2f(0, -distance)),
			raycastTo(getPosition() + sf::Vector2f(-distance, 0)),
			raycastTo(getPosition() + sf::Vector2f(distance, 0))
		};

		for (auto& i : v)
			if (i != nullptr && i->getTag() == "obstacle")
				return true;

		return false;
	}

	void Striker::update(float dt)
	{
		Bot::update(dt);

		bool isOnEdge = isOnPitchEdge();

		if (isOnEdge && !goBack)
			currentTimeOnEdge += dt;

		if (currentTimeOnEdge >= maxTimeOnEdge)
			goBack = true;

		if(goBack)
		{
			currentTimeOnEdge -= dt;
			moveTowards(calculatePositionNearBall(.4));

			if (currentTimeOnEdge <= 0)
			{
				currentTimeOnEdge = 0;
				goBack = false;
			}
			return;
		}

		// Shoot if is on edge
		if(isOnEdge && isPreparedToShoot() && isCloseToBall())
		{
			shoot(.4);
			return;
		}

		if(isTeammateNearBall())
		{
			moveTowards(calculatePositionNearBall());
		}
		else
		{
			moveTowards(getBotToBallPosition());

			if (isPreparedToShoot() && isInShootDistance() && isCloseToBall())
				shoot();
		}
	}

	void Striker::draw()
	{
		Footballer::draw();

		if(dynamic_cast<GameState*>(GameData::getInstance()->machine.GetActiveState().get())->isDebug())
		{
			auto shootPosition = calculateShootPosition();

			sf::Vertex line2[] =
			{
				sf::Vertex(getPosition(), sf::Color::Yellow),
				sf::Vertex(shootPosition, sf::Color::Yellow)
			};

			GameData::getInstance()->window.draw(line2, 2, sf::Lines);

			// Shoot raycast to shoot position
			const auto raycastHit = raycastTo(shootPosition);

			// If Ball between shootPosition and Striker
			if (raycastHit != nullptr && raycastHit->getTag() == "ball")
			{
				const auto perpendicularExtension = normalize(sf::Vector2f(shootPosition.y, -shootPosition.x)) * ballShootDistance;
				shootPosition = raycastHit->getPosition() + perpendicularExtension;

				const auto checkRaycastHit = raycastTo(shootPosition);
				if (checkRaycastHit != nullptr && checkRaycastHit->getTag() == "obstacle")
					shootPosition -= perpendicularExtension * 2.f;
			}

			sf::Vertex line[] =
			{
				sf::Vertex(getPosition()),
				sf::Vertex(shootPosition)
			};

			GameData::getInstance()->window.draw(line, 2, sf::Lines);
		}
	}

	bool Striker::isTeammateNearBall()
	{
		for (std::shared_ptr<Footballer> &footballer : team->getFootballers())
		{
			if (footballer.get() == this || footballer->getTag() == "goalkeeper")
				continue;

			if (footballer->isNearBall())
				return true;
		}

		return false;
	}

	sf::Vector2f Striker::calculateGoalPosition() const
	{
		const auto opponentGoal = team->getOpponentGoal();

		const auto goalHeight = opponentGoal->getHeight();
		const auto goalSegmentHeight = goalHeight / (team->getFootballers().size() - 1);
		const auto goalTopPositionY = opponentGoal->getPosition().y - goalHeight / 2;
		const auto goalPositionY = goalTopPositionY + goalSegmentHeight * static_cast<float>(goalPart) + goalSegmentHeight / 2;

		return sf::Vector2f(opponentGoal->getPosition().x, goalTopPositionY + goalHeight / 2);

		return sf::Vector2f(opponentGoal->getPosition().x, goalPositionY);
	}

	sf::Vector2f Striker::calculatePositionNearBall(float factor) const
	{
		const auto ball = dynamic_cast<GameState*>(GameData::getInstance()->machine.GetActiveState().get())->getBall();

		return ball->getPosition() + normalize(getPosition() - ball->getPosition()) * nearBallDistance * factor;
	}

	sf::Vector2f Striker::calculateShootPosition() const
	{
		const auto goalPosition = calculateGoalPosition();
		const auto ballPosition = dynamic_cast<GameState*>(GameData::getInstance()->machine.GetActiveState().get())->getBall()->getPosition();
		const auto extensionVector = normalize(ballPosition - goalPosition) * 15.f;

		return ballPosition + extensionVector;
	}

	sf::Vector2f Striker::getBotToBallPosition()
	{
		auto shootPosition = calculateShootPosition();

		// Shoot raycast to shoot position
		const auto raycastHit = raycastTo(shootPosition);

		// If Ball between shootPosition and Striker
		if (raycastHit != nullptr && raycastHit->getTag() == "ball")
		{
			const auto footballerToBall = raycastHit->getPosition() - getPosition();
			const auto perpendicularExtension = normalize(sf::Vector2f(footballerToBall.y, -footballerToBall.x)) * ballShootDistance;
			shootPosition = raycastHit->getPosition() + perpendicularExtension;

			const auto checkRaycastHit = raycastTo(shootPosition);
			if (checkRaycastHit != nullptr && checkRaycastHit->getTag() == "obstacle")
				shootPosition -= perpendicularExtension * 2.f;
		}

		return shootPosition;
	}
}
