#include "AudioSound.hpp"

#include <iostream>

AudioSound::AudioSound()
{
	if( !m_sound.openFromFile( "res/audio/alarm-clock.wav" ) )
	{
		// Think about error logging system
		std::cout << "Error: cannot load audio file\n";
		return;
	}

	m_soundStatus = sf::SoundSource::Stopped;
}

AudioSound::~AudioSound()
{
	// Empty body
}

void AudioSound::play()
{
	m_sound.play();
}

void AudioSound::stop()
{
	m_sound.stop();
}

void AudioSound::changeSoundStatus( sf::SoundSource::Status soundStatus )
{
	m_soundStatus = soundStatus;
}

const sf::SoundSource::Status AudioSound::getSoundStatus() const
{
	return m_soundStatus;
}
