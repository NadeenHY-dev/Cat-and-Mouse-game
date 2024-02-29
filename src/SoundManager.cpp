#include "SoundManager.h"

SoundManager::SoundManager() {}

SoundManager::~SoundManager() {
    /*stopAllSounds();*/
}

void SoundManager::loadSound(const std::string& name, const std::string& filename) {
    sf::SoundBuffer buffer;
    if (buffer.loadFromFile(filename)) {
        soundBuffers[name] = buffer;
        sf::Sound sound;
        sound.setBuffer(soundBuffers[name]);
        sounds[name] = sound;
    }
    else {
        std::cerr << "Failed to load sound from file: " << filename << std::endl;
    }
}

void SoundManager::playSound(const std::string& name) {
    auto found = sounds.find(name);
    if (found != sounds.end()) {
        found->second.play();
    }
}

//void SoundManager::stopSound(const std::string& name) {
//    auto found = sounds.find(name);
//    if (found != sounds.end()) {
//        found->second.stop();
//    }
//}
//
//void SoundManager::stopAllSounds() {
//    for (auto& sound : sounds) {
//        sound.second.stop();
//    }
//}

//void SoundManager::loadSounds() {
//    // Load all the sounds you need for the game
//    loadSound("click", "menuclick.ogg");
//    loadSound("catMouse", "catmouse.ogg"); // Example: sound for cat-mouse interaction
//    // Add more sounds as needed
//}