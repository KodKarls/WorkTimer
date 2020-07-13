#ifndef AUDIOSOUND_HPP
#define AUDIOSOUND_HPP

#include <SFML/Audio/Music.hpp>

class AudioSound
{
public:
	// Constructors
	AudioSound();

 	// Destruktor
	~AudioSound();

	// Regular function
	void play();
	void stop();
	void changeSoundStatus( sf::SoundSource::Status soundStatus );
	const sf::SoundSource::Status getSoundStatus() const;

private:
	// Audio sound
	sf::Music					m_sound;

	sf::SoundSource::Status		m_soundStatus;

	std::string					m_fileName;
};

#endif
