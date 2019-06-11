#pragma once
#include <string>
#include <SFML/Audio/Sound.hpp>

namespace Football
{
	class AudioManager
	{
	private:
		sf::Sound sound;
	public:
		AudioManager();
		~AudioManager();

		void playSound(std::string soundName);
	};
}
