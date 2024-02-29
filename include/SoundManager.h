#pragma once
#include <SFML/Audio.hpp>
#include <map>
#include <string>
#include <iostream>


class SoundManager {
public:
    SoundManager();
    ~SoundManager();
    //void loadSounds(); // Function to load sounds


    void loadSound(const std::string& name, const std::string& filename);
    void playSound(const std::string& name);
    //void stopSound(const std::string& name);
    //void stopAllSounds();
    //void loadSounds();

private:
    std::map<std::string, sf::SoundBuffer> soundBuffers;
    std::map<std::string, sf::Sound> sounds;
};

