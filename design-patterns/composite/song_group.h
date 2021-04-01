#pragma once

#include "song_component.h"
#include <string>
#include <vector>

class SongGroup : public SongComponent {
    std::vector<SongComponent*> songComponents;
    std::string groupName;
    std::string groupDescription;

public:
    SongGroup(std::string groupName, std::string groupDescription) : groupName(groupName), groupDescription(groupDescription) {}

    std::string getGroupName() { return groupName; }
    std::string getGroupDescription() { return groupDescription; }
    std::vector<SongComponent*>& getSongComponents() { return songComponents; }

    void add(SongComponent& component);
    void remove(int index);
    SongComponent* get(int index);

    void displaySongInfo();
};