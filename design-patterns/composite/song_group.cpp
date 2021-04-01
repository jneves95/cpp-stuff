#include "song_group.h"
#include "song_component.h"
#include <iostream>

void SongGroup::add(SongComponent& component) { // Be sure to pass by reference, or else we would be saving a pointer to a copy of an object - deleted at end of scope (function)
    this->songComponents.push_back(&component);
}

void SongGroup::remove(int index) {
    this->songComponents.erase(this->songComponents.begin() + index);
}

SongComponent* SongGroup::get(int index) {
    return this->songComponents[index];
}

void SongGroup::displaySongInfo() {
    std::cout << getGroupName() << "(" << getGroupDescription() << ")" << std::endl;
    
    for (SongComponent* component : getSongComponents()) {
        component->displaySongInfo();
    }
}