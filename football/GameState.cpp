#include "GameState.hpp"
#include "UIItemExit.hpp"
#include "UIItemPlay.hpp"
#include "UIItemMenu.hpp"
#include "MatchTimer.hpp"
#include "ScorePrinter.hpp"

namespace Football
{
	GameState::GameState(const bool multiplayer) : multiplayer(multiplayer)
	{
	}

	void GameState::init()
	{
		GameData::getInstance()->assets.LoadTexture("pitch", TEX_PITCH);
		GameData::getInstance()->assets.LoadTexture("footballer_blue", TEX_FOOTBALLER_BLUE);
		GameData::getInstance()->assets.LoadTexture("footballer_red", TEX_FOOTBALLER_RED);
		GameData::getInstance()->assets.LoadTexture("fan_blue", TEX_FAN_BLUE);
		GameData::getInstance()->assets.LoadTexture("fan_red", TEX_FAN_RED);
		GameData::getInstance()->assets.LoadTexture("ball", TEX_BALL);
		GameData::getInstance()->assets.LoadTexture("bench", TEX_BENCH);

		GameData::getInstance()->assets.LoadFont("RobotoMedium", FONT_ROBOTO_MEDIUM);
		GameData::getInstance()->assets.LoadFont("RobotoBlack", FONT_ROBOTO_BLACK);

		background.setTexture(GameData::getInstance()->assets.GetTexture("pitch"));

		debug = false;
		pause = false;
		ended = false;
		reset = false;

		// Set teams points
		teamLeftPoints = 0;
		teamRightPoints = 0;

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

		// Fans
		gameObjects.push_back(std::make_shared<FansBench>(sf::Vector2f(140, 30), Team::Side::Left));
		gameObjects.push_back(std::make_shared<FansBench>(sf::Vector2f(140, 55), Team::Side::Left));
		gameObjects.push_back(std::make_shared<FansBench>(sf::Vector2f(320, 30), Team::Side::Left));
		gameObjects.push_back(std::make_shared<FansBench>(sf::Vector2f(320, 55), Team::Side::Left));
		gameObjects.push_back(std::make_shared<FansBench>(sf::Vector2f(GameData::getInstance()->window.getSize().x - 140, 30), Team::Side::Right));
		gameObjects.push_back(std::make_shared<FansBench>(sf::Vector2f(GameData::getInstance()->window.getSize().x - 140, 55), Team::Side::Right));
		gameObjects.push_back(std::make_shared<FansBench>(sf::Vector2f(GameData::getInstance()->window.getSize().x - 320, 30), Team::Side::Right));
		gameObjects.push_back(std::make_shared<FansBench>(sf::Vector2f(GameData::getInstance()->window.getSize().x - 320, 55), Team::Side::Right));

		// Ball
		ball = std::make_shared<Ball>(sf::Vector2f(GameData::getInstance()->window.getSize().x, GameData::getInstance()->window.getSize().y) / 2.f);
		gameObjects.push_back(ball);

		// Goals
		createGoal(
			sf::Vector2f(0, pitchSize.sidesHeightBig),
			teamLeft
		);

		createGoal(
			sf::Vector2f(GameData::getInstance()->window.getSize().x - pitchSize.goalWidth / 1.5f, pitchSize.sidesHeightBig),
			teamRight
			);

		// Footballers left
		if (multiplayer)
			createPlayer(sf::Vector2f(150, 100), teamLeft, { sf::Keyboard::W, sf::Keyboard::S, sf::Keyboard::D, sf::Keyboard::A, sf::Keyboard::LShift });
		else
			createStriker(sf::Vector2f(150, 100), teamLeft);

		createStriker(sf::Vector2f(150, 200), teamLeft);
		createGoalkeeperBot(teamLeft);

		// Footballers right
		createPlayer(sf::Vector2f(600, 100), teamRight);
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
			sf::Vector2f(GameData::getInstance()->window.getSize().x, pitchSize.topHeight)
		);

		// bottom
		createObstacle(
			sf::Vector2f(0, GameData::getInstance()->window.getSize().y - pitchSize.bottomHeight),
			sf::Vector2f(GameData::getInstance()->window.getSize().x, pitchSize.bottomHeight)
		);

		// left
		createObstacle(
			sf::Vector2f(0, 0),
			sf::Vector2f(pitchSize.sidesWidth, GameData::getInstance()->window.getSize().y)
		);

		// right
		createObstacle(
			sf::Vector2f(GameData::getInstance()->window.getSize().x - pitchSize.sidesWidth, 0),
			sf::Vector2f(pitchSize.sidesWidth, GameData::getInstance()->window.getSize().y)
		);

		// top left
		createObstacle(
			sf::Vector2f(0, 0),
			sf::Vector2f(pitchSize.sidesWidthBig, pitchSize.sidesHeightBig)
		);

		// bottom left
		createObstacle(
			sf::Vector2f(0, pitchSize.sidesHeightBig + pitchSize.goalHeight),
			sf::Vector2f(pitchSize.sidesWidthBig, pitchSize.sidesHeight)
		);

		// top right
		createObstacle(
			sf::Vector2f(GameData::getInstance()->window.getSize().x - pitchSize.sidesWidthBig, 0),
			sf::Vector2f(pitchSize.sidesWidthBig, pitchSize.sidesHeightBig)
		);

		// bottom right
		createObstacle(
			sf::Vector2f(GameData::getInstance()->window.getSize().x - pitchSize.sidesWidthBig, pitchSize.sidesHeightBig + pitchSize.goalHeight),
			sf::Vector2f(pitchSize.sidesWidthBig, pitchSize.sidesHeight)
		);

		// top left corner
		createObstacle(
			sf::Vector2f(pitchSize.sidesWidthBig, pitchSize.topHeight) - sf::Vector2f(1,1) * pitchSize.cornerSize / 2.f,
			sf::Vector2f(1,1) * pitchSize.cornerSize,
			45.f
		);

		// top right corner
		createObstacle(
			sf::Vector2f(GameData::getInstance()->window.getSize().x - pitchSize.sidesWidthBig, pitchSize.topHeight) - sf::Vector2f(1, 1) * pitchSize.cornerSize / 2.f,
			sf::Vector2f(1, 1) * pitchSize.cornerSize,
			45.f
		);

		// bottom left corner
		createObstacle(
			sf::Vector2f(pitchSize.sidesWidthBig, GameData::getInstance()->window.getSize().y - pitchSize.bottomHeight) - sf::Vector2f(1, 1) * pitchSize.cornerSize / 2.f,
			sf::Vector2f(1, 1) * pitchSize.cornerSize,
			45.f
		);

		// bottom right corner
		createObstacle(
			sf::Vector2f(GameData::getInstance()->window.getSize().x - pitchSize.sidesWidthBig, GameData::getInstance()->window.getSize().y - pitchSize.bottomHeight) - sf::Vector2f(1, 1) * pitchSize.cornerSize / 2.f,
			sf::Vector2f(1, 1) * pitchSize.cornerSize,
			45.f
		);
	}

	void GameState::initUI()
	{
		const auto windowCenter = GameData::getInstance()->window.getSize().x / 2.f;
		menuManager = std::make_unique<UIContainer>();

		menuManager->addUIItem(std::make_shared<UIItemPlay>(
			false,
			sf::Vector2f(windowCenter, 200),
			"Graj z komputerem",
			20.f
			));

		menuManager->addUIItem(std::make_shared<UIItemPlay>(
			true,
			sf::Vector2f(windowCenter, 300),
			"Graj z innym graczem",
			20.f
			));

		menuManager->addUIItem(std::make_shared<UIItemMenu>(
			sf::Vector2f(windowCenter, 400),
			"Menu",
			20.f
			));

		menuManager->addUIItem(std::make_shared<UIItemExit>(
			sf::Vector2f(windowCenter, 500),
			"Wyjdz",
			20.f
			));


		uiManager = std::make_unique<UIContainer>();

		scorePrinter = std::make_shared<ScorePrinter>(
			sf::Vector2f(windowCenter, 25),
			"0:0",
			36.f,
			sf::Color::White
			);
		uiManager->addUIItem(scorePrinter);
		scorePrinter->update(teamLeftPoints, teamRightPoints);

		matchTimer = std::make_shared<MatchTimer>(
			sf::Vector2f(windowCenter, 55),
			"00:00",
			18.f,
			sf::Color::White
			);
		uiManager->addUIItem(matchTimer);
	}

	std::shared_ptr<Goal> GameState::createGoal(sf::Vector2f position, std::shared_ptr<Team> team)
	{
		const auto goal = std::make_shared<Goal>(
			position,
			pitchSize.goalWidth / 1.5f,
			pitchSize.goalHeight,
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

		GameData::getInstance()->inputs.updateKeyEvents();

		while (GameData::getInstance()->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
				GameData::getInstance()->window.close();

			if (sf::Event::KeyPressed == event.type)
				GameData::getInstance()->inputs.addKeyEvent(event.key.code);

			if (sf::Event::KeyReleased == event.type)
				GameData::getInstance()->inputs.removeKeyEvent(event.key.code);
		}
	}

	void GameState::update(float dt)
	{
		if(GameData::getInstance()->inputs.getKeyDown(sf::Keyboard::Key::F1))
			debug = !debug;

		if(GameData::getInstance()->inputs.getKeyDown(sf::Keyboard::Key::Escape))
		{
			pause = !pause;

			if (pause)
				matchTimer->stop();
			else
				matchTimer->start();
		}

		if(ended || pause)
		{
			menuManager->update();
			return;
		}

		sortAllGameObjects();

		for(auto& gameObject : gameObjects)
			gameObject->update(dt);

		world->Step(dt, 8, 3);

		uiManager->update();

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

		if (ended || pause)
			menuManager->draw();

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
	}

	void GameState::sortAllGameObjects()
	{
		std::sort(gameObjects.begin(), gameObjects.end());
	}

}
