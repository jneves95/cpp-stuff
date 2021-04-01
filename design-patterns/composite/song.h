#pragma once

#include "song_component.h"
#include <string>

class Song : public SongComponent {
    std::string songName;
    std::string bandName;
    int releaseYear;

public:
    Song(std::string songName, std::string bandName, int releaseYear) : songName(songName), bandName(bandName), releaseYear(releaseYear) {}

    std::string getSongName() { return songName; }
    std::string getBandName() { return bandName; }
    int getReleaseYear() { return releaseYear; }

    void displaySongInfo();
};