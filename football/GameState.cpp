#include "GameState.hpp"
#include "UIItemExit.hpp"
#include "UIItemPlay.hpp"
#include "UIItemMenu.hpp"

namespace Football
{
	GameState::GameState()
	{
	}

	void GameState::init()
	{
		GameData::getInstance()->assets.LoadTexture("Football pitch", TEX_FOOTBALL_PITCH);
		GameData::getInstance()->assets.LoadTexture("Footballer blue", TEX_FOOTBALLER_BLUE);
		GameData::getInstance()->assets.LoadTexture("Footballer red", TEX_FOOTBALLER_RED);
		GameData::getInstance()->assets.LoadTexture("Player", TEX_PLAYER);
		GameData::getInstance()->assets.LoadTexture("Ball", TEX_BALL);

		GameData::getInstance()->assets.LoadFont("RobotoMedium", FONT_ROBOTO_MEDIUM);

		background.setTexture(GameData::getInstance()->assets.GetTexture("Football pitch"));

		debug = false;
		pause = false;
		ended = false;
		reset = false;

		// Goals dimensions
		goalWidth = 30.f;
		goalHeight = 147.f;

		// Set teams points
		teamLeftPoints = 0;
		teamRightPoints = 0;

		// Set match timer
		matchTimer = std::make_unique<MatchTimer>();

		// Set Score Printer
		scorePrinter = std::make_unique<ScorePrinter>(teamLeftPoints, teamRightPoints);

		// Set Box2D world
		world = std::make_shared<b2World>(b2Vec2(0.f, 0.f));
		listener = new CollisionListener();
		world->SetContactListener(listener);

		// Add debug drawing
		debugDraw = new SFMLDebugDraw(GameData::getInstance()->window);
		world->SetDebugDraw(debugDraw);
		uint32 flags = 0;
		flags += b2Draw::e_jointBit;
		flags += b2Draw::e_aabbBit;
		flags += b2Draw::e_centerOfMassBit;
		flags += b2Draw::e_pairBit;
		flags += b2Draw::e_shapeBit;
		debugDraw->SetFlags(flags);

		initGameObjects();
		initObstacles();
		initUI();
	}

	void GameState::initGameObjects()
	{
		// Teams
		teamLeft = std::make_shared<Team>(Team::Side::Left);
		teamRight = std::make_shared<Team>(Team::Side::Right);

		// Ball
		ball = std::make_shared<Ball>(sf::Vector2f(GameData::getInstance()->window.getSize().x, GameData::getInstance()->window.getSize().y) / 2.f);
		gameObjects.push_back(ball);

		// Goals
		createGoal(
			sf::Vector2f(10, 220),
			teamLeft
		);

		createGoal(
			sf::Vector2f(GameData::getInstance()->window.getSize().x - 10 - goalWidth, 220),
			teamRight
			);

		// Footballers left
		createPlayer(sf::Vector2f(150, 100), teamLeft);
		createStriker(sf::Vector2f(150, 200), teamLeft);
		createGoalkeeperBot(teamLeft);

		// Footballers right
		// createStriker(sf::Vector2f(600, 100), teamRight);
		createPlayer(sf::Vector2f(600, 100), teamRight, {sf::Keyboard::W, sf::Keyboard::S, sf::Keyboard::D, sf::Keyboard::A, sf::Keyboard::LShift});
		createStriker(sf::Vector2f(600, 200), teamRight);
		createGoalkeeperBot(teamRight);

		teamLeft->setFootballersGoalPart();
		teamRight->setFootballersGoalPart();
	}

	void GameState::initObstacles()
	{
		// top
		createObstacle(
			sf::Vector2f(0, 0),
			sf::Vector2f(GameData::getInstance()->window.getSize().x, 15)
		);

		// bottom
		createObstacle(
			sf::Vector2f(0, GameData::getInstance()->window.getSize().y - 15),
			sf::Vector2f(GameData::getInstance()->window.getSize().x, 15)
		);

		// left
		createObstacle(
			sf::Vector2f(0, 0),
			sf::Vector2f(10, GameData::getInstance()->window.getSize().y)
		);

		// right
		createObstacle(
			sf::Vector2f(GameData::getInstance()->window.getSize().x - 10, 0),
			sf::Vector2f(10, GameData::getInstance()->window.getSize().y)
		);

		// top left
		createObstacle(
			sf::Vector2f(0, 0),
			sf::Vector2f(40, 220)
		);

		// bottom left
		createObstacle(
			sf::Vector2f(0, 367),
			sf::Vector2f(40, 220)
		);

		// top right
		createObstacle(
			sf::Vector2f(GameData::getInstance()->window.getSize().x - 40, 0),
			sf::Vector2f(40, 220)
		);

		// bottom right
		createObstacle(
			sf::Vector2f(GameData::getInstance()->window.getSize().x - 40, 367),
			sf::Vector2f(40, 220)
		);

		// top left corner
		createObstacle(
			sf::Vector2f(25, 0),
			sf::Vector2f(30, 30),
			45.f
		);

		// top right corner
		createObstacle(
			sf::Vector2f(GameData::getInstance()->window.getSize().x - 55, 0),
			sf::Vector2f(30, 30),
			45.f
		);

		// bottom left corner
		createObstacle(
			sf::Vector2f(25, GameData::getInstance()->window.getSize().y - 30),
			sf::Vector2f(30, 30),
			45.f
		);

		// bottom right corner
		createObstacle(
			sf::Vector2f(GameData::getInstance()->window.getSize().x - 55, GameData::getInstance()->window.getSize().y - 30),
			sf::Vector2f(30, 30),
			45.f
		);
	}

	void GameState::initUI()
	{
		const auto windowCenter = GameData::getInstance()->window.getSize().x / 2.f;
		uiManager = std::make_unique<UIManager>();

		uiManager->addUIItem(std::make_shared<UIItemPlay>(
			sf::Vector2f(windowCenter, 200),
			"Graj",
			20.f
			));

		uiManager->addUIItem(std::make_shared<UIItemMenu>(
			sf::Vector2f(windowCenter, 300),
			"Menu",
			20.f
			));

		uiManager->addUIItem(std::make_shared<UIItemExit>(
			sf::Vector2f(windowCenter, 400),
			"Wyjdz",
			20.f
			));
	}

	std::shared_ptr<Goal> GameState::createGoal(sf::Vector2f position, std::shared_ptr<Team> team)
	{
		const auto goal = std::make_shared<Goal>(
			position,
			goalWidth,
			goalHeight,
			team
			);

		team->setGoal(goal);
		gameObjects.push_back(goal);

		return goal;
	}

	std::shared_ptr<Striker> GameState::createStriker(sf::Vector2f position, std::shared_ptr<Team> team)
	{
		const auto striker = std::make_shared<Striker>(position, team);
		team->addFootballer(striker);
		gameObjects.push_back(striker);

		return striker;
	}

	std::shared_ptr<Goalkeeper> GameState::createGoalkeeperBot(std::shared_ptr<Team> team)
	{
		const auto goalkeeperBot = std::make_shared<Goalkeeper>(team);
		team->addFootballer(goalkeeperBot);
		gameObjects.push_back(goalkeeperBot);

		return goalkeeperBot;
	}

	std::shared_ptr<Player> GameState::createPlayer(sf::Vector2f position, std::shared_ptr<Team> team, AxisKeys keys)
	{
		const auto player = std::make_shared<Player>(position, team, keys);
		team->addFootballer(player);
		gameObjects.push_back(player);

		return player;
	}

	std::shared_ptr<Obstacle> GameState::createObstacle(sf::Vector2f position, sf::Vector2f dimensions, float angleDegrees)
	{
		const auto obstacle = std::make_shared<Obstacle>(
			position,
			dimensions.x,
			dimensions.y,
			angleDegrees
			);
		gameObjects.push_back(obstacle);

		return obstacle;
	}

	std::vector<std::shared_ptr<GameObject>> GameState::getGameObjects() const
	{
		return gameObjects;
	}

	void GameState::handleInput()
	{
		sf::Event event;

		while (GameData::getInstance()->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
				GameData::getInstance()->window.close();

			if (sf::Event::KeyPressed == event.type || sf::Event::KeyReleased == event.type)
				GameData::getInstance()->inputs.update();
		}
	}

	void GameState::update(float dt)
	{
		if(GameData::getInstance()->inputs.isPressed(sf::Keyboard::Key::F1))
			debug = !debug;

		if(GameData::getInstance()->inputs.isPressed(sf::Keyboard::Key::Escape))
		{
			pause = !pause;

			if (pause)
				matchTimer->stop();
			else
				matchTimer->start();
		}

		if(ended || pause)
		{
			uiManager->update();
			return;
		}

		sortAllGameObjects();

		for(auto& gameObject : gameObjects)
			gameObject->update(dt);

		matchTimer->update();
		world->Step(dt, 8, 3);

		if(reset && !world->IsLocked())
			resetGameObjectsPositions();

	}

	void GameState::draw(float dt)
	{
		GameData::getInstance()->window.clear();

		GameData::getInstance()->window.draw(background);

		for (auto& object : gameObjects)
			object->draw();

		if(debug)
			world->DrawDebugData();

		matchTimer->draw();
		scorePrinter->draw();

		if (ended || pause)
			uiManager->draw();

		GameData::getInstance()->window.display();
	}

	std::shared_ptr<b2World> GameState::getWorld() const
	{
		return world;
	}

	std::shared_ptr<Ball> GameState::getBall() const
	{
		return ball;
	}

	std::shared_ptr<Team> GameState::getTeam(Team::Side side) const
	{
		return side == Team::Side::Left ? teamLeft : teamRight;
	}

	void GameState::scoreGoal(Team::Side side)
	{
		if (side == Team::Side::Left)
			teamRightPoints++;
		else
			teamLeftPoints++;

		scorePrinter->update(teamLeftPoints, teamRightPoints);

		teamLeft->setFootballersGoalPart();
		teamRight->setFootballersGoalPart();

		reset = true;
	}

	void GameState::resetGameObjectsPositions()
	{
		ball->resetPosition();
		teamLeft->resetPosition();
		teamRight->resetPosition();

		reset = false;
	}

	void GameState::endGame()
	{
		ended = true;
		std::stringstream ss;
		ss << teamLeftPoints << ":" << teamRightPoints;

		uiManager->addUIItem(std::make_shared<UIItem>(
			sf::Vector2f(GameData::getInstance()->window.getSize().x / 2.f, 100),
			ss.str(),
			20.f
			));
	}

	void GameState::sortAllGameObjects()
	{
		std::sort(gameObjects.begin(), gameObjects.end());
	}

}
