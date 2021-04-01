#pragma once

#include "song_component.h"

class Player {
    SongComponent& songList;    // Has to be a reference, or else the compiler treats the object as an instance of the abstract class

public:
    Player(SongComponent& songList) : songList(songList) {}

    void getSongList() { songList.displaySongInfo(); }  // If it wasn't a reference, the method called would not be overridden by the subclass
};