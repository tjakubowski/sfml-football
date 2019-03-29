#include "Game.hpp"
#include "SplashState.hpp"

namespace Football
{
	Game::Game(int width, int height, std::string title)
	{
		GameData::getInstance()->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
		GameData::getInstance()->machine.AddState(StateRef(new SplashState()));

		this->Run();
	}

	void Game::Run()
	{
		float newTime, frameTime, interpolation;

		float currentTime = this->clock.getElapsedTime().asSeconds();
		float accumulator = 0.0f;

		while(GameData::getInstance()->window.isOpen())
		{
			GameData::getInstance()->machine.ProcessStateChanges();
			newTime = this->clock.getElapsedTime().asSeconds();
			frameTime = newTime - currentTime;

			if (frameTime > .25f)
				frameTime = .25f;

			currentTime = newTime;
			accumulator += frameTime;

			while(accumulator >= dt)
			{
				GameData::getInstance()->machine.GetActiveState()->handleInput();
				GameData::getInstance()->machine.GetActiveState()->update(dt);

				accumulator -= dt;
			}

			interpolation = accumulator / dt;
			GameData::getInstance()->machine.GetActiveState()->draw(interpolation);
		}
	}





}
